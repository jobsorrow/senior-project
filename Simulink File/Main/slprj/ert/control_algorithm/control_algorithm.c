/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_algorithm.c
 *
 * Code generated for Simulink model 'control_algorithm'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Oct 10 00:32:29 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "control_algorithm.h"
#include "control_algorithm_private.h"

P_control_algorithm_T control_algorithm_P = {
  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave'
   */
  0.0,

  /* Computed Parameter: SineWave_Hsin
   * Referenced by: '<S1>/Sine Wave'
   */
  0.015707317311820675,

  /* Computed Parameter: SineWave_HCos
   * Referenced by: '<S1>/Sine Wave'
   */
  0.99987663248166059,

  /* Computed Parameter: SineWave_PSin
   * Referenced by: '<S1>/Sine Wave'
   */
  -0.015707317311820675,

  /* Computed Parameter: SineWave_PCos
   * Referenced by: '<S1>/Sine Wave'
   */
  0.99987663248166059,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave1'
   */
  0.0,

  /* Computed Parameter: SineWave1_Hsin
   * Referenced by: '<S1>/Sine Wave1'
   */
  0.015707317311820675,

  /* Computed Parameter: SineWave1_HCos
   * Referenced by: '<S1>/Sine Wave1'
   */
  0.99987663248166059,

  /* Computed Parameter: SineWave1_PSin
   * Referenced by: '<S1>/Sine Wave1'
   */
  0.87377222303546531,

  /* Computed Parameter: SineWave1_PCos
   * Referenced by: '<S1>/Sine Wave1'
   */
  -0.48633538042349039,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave2'
   */
  0.0,

  /* Computed Parameter: SineWave2_Hsin
   * Referenced by: '<S1>/Sine Wave2'
   */
  0.015707317311820675,

  /* Computed Parameter: SineWave2_HCos
   * Referenced by: '<S1>/Sine Wave2'
   */
  0.99987663248166059,

  /* Computed Parameter: SineWave2_PSin
   * Referenced by: '<S1>/Sine Wave2'
   */
  -0.85806490572364469,

  /* Computed Parameter: SineWave2_PCos
   * Referenced by: '<S1>/Sine Wave2'
   */
  -0.51354125205816981,

  /* Expression: 24
   * Referenced by: '<S3>/Avoid Division By Zero'
   */
  24.0,

  /* Expression: 0.1
   * Referenced by: '<S3>/Avoid Division By Zero'
   */
  0.1,

  /* Expression: 0.5
   * Referenced by: '<S3>/Bias'
   */
  0.5
};

/* Forward declaration for local functions */
static void co_enter_internal_parallelState(const real_T
  TmpSignalConversionAtSFunctionI[3], const real_T rtu_LineCurrent[3], const
  real_T *rtu_BatteryVoltage, B_control_algorithm_c_T *localB,
  DW_control_algorithm_f_T *localDW);

/* Function for Chart: '<S2>/Two Arm Modulator and First Quadrant Tracker' */
static void co_enter_internal_parallelState(const real_T
  TmpSignalConversionAtSFunctionI[3], const real_T rtu_LineCurrent[3], const
  real_T *rtu_BatteryVoltage, B_control_algorithm_c_T *localB,
  DW_control_algorithm_f_T *localDW)
{
  real_T b_ex;
  int16_T b_idx;
  int16_T c_k;
  boolean_T exitg1;
  if ((TmpSignalConversionAtSFunctionI[0] >= TmpSignalConversionAtSFunctionI[1])
      && (TmpSignalConversionAtSFunctionI[0] >= TmpSignalConversionAtSFunctionI
          [2])) {
    localDW->maxPhase = 1L;
  } else if ((TmpSignalConversionAtSFunctionI[1] >=
              TmpSignalConversionAtSFunctionI[0]) &&
             (TmpSignalConversionAtSFunctionI[1] >=
              TmpSignalConversionAtSFunctionI[2])) {
    localDW->maxPhase = 2L;
  } else if ((TmpSignalConversionAtSFunctionI[2] >=
              TmpSignalConversionAtSFunctionI[0]) &&
             (TmpSignalConversionAtSFunctionI[2] >=
              TmpSignalConversionAtSFunctionI[1])) {
    localDW->maxPhase = 3L;
  } else {
    localDW->maxPhase = 0L;
  }

  /* Chart: '<S2>/Two Arm Modulator and First Quadrant Tracker' */
  if (rtu_LineCurrent[(int16_T)((int16_T)localDW->maxPhase - 1)] >= 0.0) {
    localDW->isUpperInQ1 = true;
  } else {
    localDW->isUpperInQ1 = false;
  }

  if (localDW->isUpperInQ1 && (!localDW->isLowerInQ1)) {
    localDW->switchCommand = 1L;
  } else if ((!localDW->isUpperInQ1) && localDW->isLowerInQ1) {
    localDW->switchCommand = 2L;
  } else {
    localDW->switchCommand = 3L;
  }

  if (localDW->switchCount > 5000.0) {
    localDW->switchCount = -1.0;
  } else if (localDW->switchCount < -5000.0) {
    localDW->switchCount = 1.0;
  }

  localDW->done = true;
  if ((localDW->switchCommand == 2L) || ((localDW->switchCommand != 1L) &&
       (localDW->switchCount < 0.0))) {
    if (!rtIsNaN(TmpSignalConversionAtSFunctionI[0])) {
      b_idx = 1;
    } else {
      b_idx = 0;
      c_k = 2;
      exitg1 = false;
      while ((!exitg1) && (c_k < 4)) {
        if (!rtIsNaN(TmpSignalConversionAtSFunctionI[(int16_T)(c_k - 1)])) {
          b_idx = c_k;
          exitg1 = true;
        } else {
          c_k++;
        }
      }
    }

    if (b_idx == 0) {
      b_ex = TmpSignalConversionAtSFunctionI[0];
    } else {
      b_ex = TmpSignalConversionAtSFunctionI[(int16_T)(b_idx - 1)];
      while ((int16_T)(b_idx + 1) <= 3) {
        if (b_ex > TmpSignalConversionAtSFunctionI[b_idx]) {
          b_ex = TmpSignalConversionAtSFunctionI[b_idx];
        }

        b_idx++;
      }
    }

    /* Chart: '<S2>/Two Arm Modulator and First Quadrant Tracker' */
    localB->Zero_Sequence_Offset = -(*rtu_BatteryVoltage / 2.0) - b_ex;
    localDW->switchCount--;
  } else {
    if (!rtIsNaN(TmpSignalConversionAtSFunctionI[0])) {
      b_idx = 1;
    } else {
      b_idx = 0;
      c_k = 2;
      exitg1 = false;
      while ((!exitg1) && (c_k < 4)) {
        if (!rtIsNaN(TmpSignalConversionAtSFunctionI[(int16_T)(c_k - 1)])) {
          b_idx = c_k;
          exitg1 = true;
        } else {
          c_k++;
        }
      }
    }

    if (b_idx == 0) {
      b_ex = TmpSignalConversionAtSFunctionI[0];
    } else {
      b_ex = TmpSignalConversionAtSFunctionI[(int16_T)(b_idx - 1)];
      while ((int16_T)(b_idx + 1) <= 3) {
        if (b_ex < TmpSignalConversionAtSFunctionI[b_idx]) {
          b_ex = TmpSignalConversionAtSFunctionI[b_idx];
        }

        b_idx++;
      }
    }

    /* Chart: '<S2>/Two Arm Modulator and First Quadrant Tracker' */
    localB->Zero_Sequence_Offset = *rtu_BatteryVoltage / 2.0 - b_ex;
    localDW->switchCount++;
  }

  if ((TmpSignalConversionAtSFunctionI[0] <= TmpSignalConversionAtSFunctionI[1])
      && (TmpSignalConversionAtSFunctionI[0] <= TmpSignalConversionAtSFunctionI
          [2])) {
    localDW->minPhase = 1L;
  } else if ((TmpSignalConversionAtSFunctionI[1] <=
              TmpSignalConversionAtSFunctionI[0]) &&
             (TmpSignalConversionAtSFunctionI[1] <=
              TmpSignalConversionAtSFunctionI[2])) {
    localDW->minPhase = 2L;
  } else if ((TmpSignalConversionAtSFunctionI[2] <=
              TmpSignalConversionAtSFunctionI[0]) &&
             (TmpSignalConversionAtSFunctionI[2] <=
              TmpSignalConversionAtSFunctionI[1])) {
    localDW->minPhase = 3L;
  } else {
    localDW->minPhase = 0L;
  }

  /* Chart: '<S2>/Two Arm Modulator and First Quadrant Tracker' */
  if (rtu_LineCurrent[(int16_T)((int16_T)localDW->minPhase - 1)] <= 0.0) {
    localDW->isLowerInQ1 = true;
  } else {
    localDW->isLowerInQ1 = false;
  }
}

/* System initialize for referenced model: 'control_algorithm' */
void control_algorithm_Init(B_control_algorithm_c_T *localB,
  DW_control_algorithm_f_T *localDW)
{
  /* SystemInitialize for Chart: '<S2>/Two Arm Modulator and First Quadrant Tracker' */
  localDW->is_active_c3_control_algorithm = 0U;
  localDW->maxPhase = 0L;
  localDW->isLowerInQ1 = false;
  localDW->isUpperInQ1 = false;
  localDW->minPhase = 0L;
  localDW->switchCommand = 0L;
  localDW->done = false;
  localDW->switchCount = 0.0;
  localB->Zero_Sequence_Offset = 0.0;
}

/* Enable for referenced model: 'control_algorithm' */
void control_algorithm_Enable(DW_control_algorithm_f_T *localDW)
{
  /* Enable for Sin: '<S1>/Sine Wave' */
  localDW->systemEnable = 1L;

  /* Enable for Sin: '<S1>/Sine Wave1' */
  localDW->systemEnable_b = 1L;

  /* Enable for Sin: '<S1>/Sine Wave2' */
  localDW->systemEnable_c = 1L;
}

/* Output and update for referenced model: 'control_algorithm' */
void control_algorithm(RT_MODEL_control_algorithm_T * const control_algorithm_M,
  const real_T rtu_LineCurrent[3], const real_T *rtu_BatteryVoltage, uint32_T
  rty_CompareValue[3], B_control_algorithm_c_T *localB, DW_control_algorithm_f_T
  *localDW)
{
  real_T TmpSignalConversionAtSFunctionI[3];
  real_T rtb_AvoidDivisionByZero;
  real_T rtb_SineWave;
  real_T rtb_SineWave1;
  real_T rtb_SineWave2;

  /* Sin: '<S1>/Sine Wave' */
  if (localDW->systemEnable != 0L) {
    rtb_SineWave1 = rtP_VSI_FREQ * 2.0 * 3.1415926535897931 * (rtmGetClockTick0
      (control_algorithm_M) * 5.0E-5);
    localDW->lastSin = sin(rtb_SineWave1);
    localDW->lastCos = cos(rtb_SineWave1);
    localDW->systemEnable = 0L;
  }

  rtb_SineWave = ((localDW->lastSin * control_algorithm_P.SineWave_PCos +
                   localDW->lastCos * control_algorithm_P.SineWave_PSin) *
                  control_algorithm_P.SineWave_HCos + (localDW->lastCos *
    control_algorithm_P.SineWave_PCos - localDW->lastSin *
    control_algorithm_P.SineWave_PSin) * control_algorithm_P.SineWave_Hsin) *
    rtP_VSI_AMP + control_algorithm_P.SineWave_Bias;

  /* End of Sin: '<S1>/Sine Wave' */

  /* Sin: '<S1>/Sine Wave1' */
  if (localDW->systemEnable_b != 0L) {
    localDW->lastSin_o = sin(rtP_VSI_FREQ * 2.0 * 3.1415926535897931 *
      (rtmGetClockTick0(control_algorithm_M) * 5.0E-5));
    localDW->lastCos_p = cos(rtP_VSI_FREQ * 2.0 * 3.1415926535897931 *
      (rtmGetClockTick0(control_algorithm_M) * 5.0E-5));
    localDW->systemEnable_b = 0L;
  }

  rtb_SineWave1 = ((localDW->lastSin_o * control_algorithm_P.SineWave1_PCos +
                    localDW->lastCos_p * control_algorithm_P.SineWave1_PSin) *
                   control_algorithm_P.SineWave1_HCos + (localDW->lastCos_p *
    control_algorithm_P.SineWave1_PCos - localDW->lastSin_o *
    control_algorithm_P.SineWave1_PSin) * control_algorithm_P.SineWave1_Hsin) *
    rtP_VSI_AMP + control_algorithm_P.SineWave1_Bias;

  /* End of Sin: '<S1>/Sine Wave1' */

  /* Sin: '<S1>/Sine Wave2' */
  if (localDW->systemEnable_c != 0L) {
    localDW->lastSin_a = sin(rtP_VSI_FREQ * 2.0 * 3.1415926535897931 *
      (rtmGetClockTick0(control_algorithm_M) * 5.0E-5));
    localDW->lastCos_j = cos(rtP_VSI_FREQ * 2.0 * 3.1415926535897931 *
      (rtmGetClockTick0(control_algorithm_M) * 5.0E-5));
    localDW->systemEnable_c = 0L;
  }

  rtb_SineWave2 = ((localDW->lastSin_a * control_algorithm_P.SineWave2_PCos +
                    localDW->lastCos_j * control_algorithm_P.SineWave2_PSin) *
                   control_algorithm_P.SineWave2_HCos + (localDW->lastCos_j *
    control_algorithm_P.SineWave2_PCos - localDW->lastSin_a *
    control_algorithm_P.SineWave2_PSin) * control_algorithm_P.SineWave2_Hsin) *
    rtP_VSI_AMP + control_algorithm_P.SineWave2_Bias;

  /* End of Sin: '<S1>/Sine Wave2' */

  /* SignalConversion generated from: '<S4>/ SFunction ' incorporates:
   *  Chart: '<S2>/Two Arm Modulator and First Quadrant Tracker'
   */
  TmpSignalConversionAtSFunctionI[0] = rtb_SineWave;
  TmpSignalConversionAtSFunctionI[1] = rtb_SineWave1;
  TmpSignalConversionAtSFunctionI[2] = rtb_SineWave2;

  /* Chart: '<S2>/Two Arm Modulator and First Quadrant Tracker' */
  if (localDW->is_active_c3_control_algorithm == 0U) {
    localDW->is_active_c3_control_algorithm = 1U;
    co_enter_internal_parallelState(TmpSignalConversionAtSFunctionI,
      rtu_LineCurrent, rtu_BatteryVoltage, localB, localDW);
  } else if (localDW->done) {
    co_enter_internal_parallelState(TmpSignalConversionAtSFunctionI,
      rtu_LineCurrent, rtu_BatteryVoltage, localB, localDW);
  }

  /* Saturate: '<S3>/Avoid Division By Zero' */
  if (*rtu_BatteryVoltage > control_algorithm_P.AvoidDivisionByZero_UpperSat) {
    rtb_AvoidDivisionByZero = control_algorithm_P.AvoidDivisionByZero_UpperSat;
  } else if (*rtu_BatteryVoltage <
             control_algorithm_P.AvoidDivisionByZero_LowerSat) {
    rtb_AvoidDivisionByZero = control_algorithm_P.AvoidDivisionByZero_LowerSat;
  } else {
    rtb_AvoidDivisionByZero = *rtu_BatteryVoltage;
  }

  /* End of Saturate: '<S3>/Avoid Division By Zero' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Bias: '<S3>/Bias'
   *  Gain: '<S3>/Gain2'
   *  Product: '<S3>/Divide'
   *  Sum: '<S2>/Add'
   */
  rtb_SineWave = ((rtb_SineWave + localB->Zero_Sequence_Offset) /
                  rtb_AvoidDivisionByZero + control_algorithm_P.Bias_Bias) *
    rtP_PWM_TIM_BASE_PRD;
  if (rtb_SineWave < 4.294967296E+9) {
    if (rtb_SineWave >= 0.0) {
      rty_CompareValue[0] = (uint32_T)rtb_SineWave;
    } else {
      rty_CompareValue[0] = 0UL;
    }
  } else {
    rty_CompareValue[0] = MAX_uint32_T;
  }

  rtb_SineWave = ((rtb_SineWave1 + localB->Zero_Sequence_Offset) /
                  rtb_AvoidDivisionByZero + control_algorithm_P.Bias_Bias) *
    rtP_PWM_TIM_BASE_PRD;
  if (rtb_SineWave < 4.294967296E+9) {
    if (rtb_SineWave >= 0.0) {
      rty_CompareValue[1] = (uint32_T)rtb_SineWave;
    } else {
      rty_CompareValue[1] = 0UL;
    }
  } else {
    rty_CompareValue[1] = MAX_uint32_T;
  }

  rtb_SineWave = ((rtb_SineWave2 + localB->Zero_Sequence_Offset) /
                  rtb_AvoidDivisionByZero + control_algorithm_P.Bias_Bias) *
    rtP_PWM_TIM_BASE_PRD;
  if (rtb_SineWave < 4.294967296E+9) {
    if (rtb_SineWave >= 0.0) {
      rty_CompareValue[2] = (uint32_T)rtb_SineWave;
    } else {
      rty_CompareValue[2] = 0UL;
    }
  } else {
    rty_CompareValue[2] = MAX_uint32_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* Update for Sin: '<S1>/Sine Wave' */
  rtb_SineWave1 = localDW->lastSin;
  localDW->lastSin = localDW->lastSin * control_algorithm_P.SineWave_HCos +
    localDW->lastCos * control_algorithm_P.SineWave_Hsin;
  localDW->lastCos = localDW->lastCos * control_algorithm_P.SineWave_HCos -
    rtb_SineWave1 * control_algorithm_P.SineWave_Hsin;

  /* Update for Sin: '<S1>/Sine Wave1' */
  rtb_SineWave1 = localDW->lastSin_o;
  localDW->lastSin_o = localDW->lastSin_o * control_algorithm_P.SineWave1_HCos +
    localDW->lastCos_p * control_algorithm_P.SineWave1_Hsin;
  localDW->lastCos_p = localDW->lastCos_p * control_algorithm_P.SineWave1_HCos -
    rtb_SineWave1 * control_algorithm_P.SineWave1_Hsin;

  /* Update for Sin: '<S1>/Sine Wave2' */
  rtb_SineWave1 = localDW->lastSin_a;
  localDW->lastSin_a = localDW->lastSin_a * control_algorithm_P.SineWave2_HCos +
    localDW->lastCos_j * control_algorithm_P.SineWave2_Hsin;
  localDW->lastCos_j = localDW->lastCos_j * control_algorithm_P.SineWave2_HCos -
    rtb_SineWave1 * control_algorithm_P.SineWave2_Hsin;
}

/* Model initialize function */
void control_algorithm_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, RT_MODEL_control_algorithm_T *
  const control_algorithm_M, B_control_algorithm_c_T *localB,
  DW_control_algorithm_f_T *localDW)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)control_algorithm_M, 0,
                sizeof(RT_MODEL_control_algorithm_T));

  /* setup the global timing engine */
  control_algorithm_M->Timing.mdlref_GlobalTID[0] = mdlref_TID0;
  control_algorithm_M->timingBridge = (timingBridge);

  /* initialize error status */
  rtmSetErrorStatusPointer(control_algorithm_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(B_control_algorithm_c_T));

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_control_algorithm_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
