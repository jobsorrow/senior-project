/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: genpath_firmware_data.c
 *
 * Code generated for Simulink model 'genpath_firmware'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr  7 11:34:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#include "genpath_firmware.h"

/* Invariant block signals (default storage) */
const ConstB_genpath_firmware_T genpath_firmware_ConstB = {
  16U                                  /* '<S7>/Width' */
};

/* Block parameters (default storage) */
P_genpath_firmware_T genpath_firmware_P = {
  /* Variable: HW_BLDC_LQ
   * Referenced by: '<S6>/Gain2'
   */
  0.016F,

  /* Mask Parameter: CounterLimited_uplimit
   * Referenced by: '<S33>/FixPt Switch'
   */
  500U,

  /* Mask Parameter: CounterLimited_uplimit_k
   * Referenced by: '<S51>/FixPt Switch'
   */
  999U,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S37>/Gain'
   */
  0.5F,

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S36>/Gain'
   */
  0.5F,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S35>/Constant'
   */
  0.0F,

  /* Computed Parameter: Bias_Bias
   * Referenced by: '<S3>/Bias'
   */
  -1.65F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S3>/Gain3'
   */
  -10.0F,

  /* Computed Parameter: Filter_Constant_Value
   * Referenced by: '<S20>/Filter_Constant'
   */
  0.02F,

  /* Computed Parameter: One_Value
   * Referenced by: '<S20>/One'
   */
  0.98F,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S20>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S6>/Gain1'
   */
  -0.28F,

  /* Computed Parameter: UnitDelay_InitialCondition_j
   * Referenced by: '<S38>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_a
   * Referenced by: '<S38>/Gain'
   */
  0.0001F,

  /* Computed Parameter: Filter_Constant_Value_c
   * Referenced by: '<S42>/Filter_Constant'
   */
  0.1F,

  /* Computed Parameter: One_Value_f
   * Referenced by: '<S42>/One'
   */
  0.9F,

  /* Computed Parameter: UnitDelay_InitialCondition_i
   * Referenced by: '<S42>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Filter_Constant_Value_m
   * Referenced by: '<S17>/Filter_Constant'
   */
  0.02F,

  /* Computed Parameter: One_Value_o
   * Referenced by: '<S17>/One'
   */
  0.98F,

  /* Computed Parameter: UnitDelay_InitialCondition_b
   * Referenced by: '<S17>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Ifthecurrentispositive_OnVal
   * Referenced by: '<S26>/If the current is positive '
   */
  0.05F,

  /* Computed Parameter: Ifthecurrentispositive_OffVal
   * Referenced by: '<S26>/If the current is positive '
   */
  -0.05F,

  /* Computed Parameter: Ifthecurrentisnegative_OnVal
   * Referenced by: '<S26>/If the current is negative'
   */
  0.05F,

  /* Computed Parameter: Ifthecurrentisnegative_OffVal
   * Referenced by: '<S26>/If the current is negative'
   */
  -0.05F,

  /* Computed Parameter: PreventDivisionByZero_UpperSat
   * Referenced by: '<S24>/Prevent Division By Zero'
   */
  81.5F,

  /* Computed Parameter: PreventDivisionByZero_LowerSat
   * Referenced by: '<S24>/Prevent Division By Zero'
   */
  0.1F,

  /* Computed Parameter: Bias_Bias_a
   * Referenced by: '<S24>/Bias'
   */
  0.5F,

  /* Computed Parameter: PreventOvermodulation_UpperSat
   * Referenced by: '<S24>/Prevent Overmodulation'
   */
  1.0F,

  /* Computed Parameter: PreventOvermodulation_LowerSat
   * Referenced by: '<S24>/Prevent Overmodulation'
   */
  0.0F,

  /* Computed Parameter: TimeBasePeriod_Gain
   * Referenced by: '<S24>/Time Base Period'
   */
  5000.0F,

  /* Computed Parameter: CommandedSignal_Y0
   * Referenced by: '<S2>/Commanded Signal'
   */
  0.0F,

  /* Computed Parameter: RateTransitionSCIADC_InitialCon
   * Referenced by: '<Root>/Rate Transition SCI-ADC'
   */
  0.0F,

  /* Computed Parameter: DCBusVoltageADCGain_Gain
   * Referenced by: '<S3>/DC Bus Voltage ADC Gain'
   */
  41733U,

  /* Computed Parameter: PhaseCurrentADCGain_Gain
   * Referenced by: '<S3>/Phase Current ADC Gain'
   */
  54067U,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S33>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_n
   * Referenced by: '<S28>/Constant'
   */
  250U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S31>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S32>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S51>/Constant'
   */
  0U,

  /* Computed Parameter: End_Value
   * Referenced by: '<S46>/End'
   */
  65535U,

  /* Computed Parameter: Start_Value
   * Referenced by: '<S46>/Start'
   */
  61166U,

  /* Computed Parameter: Bias_Bias_c
   * Referenced by: '<S46>/Bias'
   */
  2U,

  /* Computed Parameter: Start_Value_i
   * Referenced by: '<S45>/Start'
   */
  0U,

  /* Computed Parameter: Start1_Value
   * Referenced by: '<S45>/Start1'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition_a
   * Referenced by: '<S44>/Output'
   */
  0U,

  /* Computed Parameter: Bias_Bias_p
   * Referenced by: '<S11>/Bias'
   */
  5U,

  /* Computed Parameter: Bias1_Bias
   * Referenced by: '<S11>/Bias1'
   */
  5U,

  /* Computed Parameter: Bias2_Bias
   * Referenced by: '<S11>/Bias2'
   */
  5U,

  /* Computed Parameter: PreventPWMCounterOverrun_UpperS
   * Referenced by: '<S24>/Prevent PWM Counter Overrun'
   */
  4995U,

  /* Computed Parameter: PreventPWMCounterOverrun_LowerS
   * Referenced by: '<S24>/Prevent PWM Counter Overrun'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value_j
   * Referenced by: '<S50>/FixPt Constant'
   */
  1U,

  /* Expression: true
   * Referenced by: '<S26>/If the current is positive '
   */
  true,

  /* Expression: false
   * Referenced by: '<S26>/If the current is positive '
   */
  false,

  /* Expression: false
   * Referenced by: '<S26>/If the current is negative'
   */
  false,

  /* Expression: true
   * Referenced by: '<S26>/If the current is negative'
   */
  true,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S26>/Merge'
   */
  false,

  /* Start of '<S43>/CoreSubsys' */
  {
    /* Start of '<S43>/If Action Subsystem1' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S48>/Constant'
       */
      515U
    }
    ,

    /* End of '<S43>/If Action Subsystem1' */

    /* Start of '<S43>/If Action Subsystem' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S47>/Constant'
       */
      258U
    }
    /* End of '<S43>/If Action Subsystem' */
  }
  ,

  /* End of '<S43>/CoreSubsys' */

  /* Start of '<S26>/Lower Always On' */
  {
    /* Expression: false
     * Referenced by: '<S29>/Constant'
     */
    false
  }
  ,

  /* End of '<S26>/Lower Always On' */

  /* Start of '<S26>/Upper Always On' */
  {
    /* Expression: true
     * Referenced by: '<S30>/Constant'
     */
    true
  }
  /* End of '<S26>/Upper Always On' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
