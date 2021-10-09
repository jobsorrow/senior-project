/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_algorithm.h
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

#ifndef RTW_HEADER_control_algorithm_h_
#define RTW_HEADER_control_algorithm_h_
#include <math.h>
#include <string.h>
#ifndef control_algorithm_COMMON_INCLUDES_
#define control_algorithm_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* control_algorithm_COMMON_INCLUDES_ */

#include "control_algorithm_types.h"

/* Shared type includes */
#include "model_reference_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

void MW_InitSysPll(uint16_T clock_source, uint16_T imult, uint16_T fmult,
                   uint16_T odiv, uint16_T divsel);
extern void configureIXbar(void);

/* Block signals for model 'control_algorithm' */
typedef struct {
  real_T Zero_Sequence_Offset;
                       /* '<S2>/Two Arm Modulator and First Quadrant Tracker' */
} B_control_algorithm_c_T;

/* Block states (default storage) for model 'control_algorithm' */
typedef struct {
  real_T lastSin;                      /* '<S1>/Sine Wave' */
  real_T lastCos;                      /* '<S1>/Sine Wave' */
  real_T lastSin_o;                    /* '<S1>/Sine Wave1' */
  real_T lastCos_p;                    /* '<S1>/Sine Wave1' */
  real_T lastSin_a;                    /* '<S1>/Sine Wave2' */
  real_T lastCos_j;                    /* '<S1>/Sine Wave2' */
  real_T switchCount;  /* '<S2>/Two Arm Modulator and First Quadrant Tracker' */
  int32_T systemEnable;                /* '<S1>/Sine Wave' */
  int32_T systemEnable_b;              /* '<S1>/Sine Wave1' */
  int32_T systemEnable_c;              /* '<S1>/Sine Wave2' */
  int32_T maxPhase;    /* '<S2>/Two Arm Modulator and First Quadrant Tracker' */
  int32_T minPhase;    /* '<S2>/Two Arm Modulator and First Quadrant Tracker' */
  int32_T switchCommand;
                       /* '<S2>/Two Arm Modulator and First Quadrant Tracker' */
  uint16_T is_active_c3_control_algorithm;
                       /* '<S2>/Two Arm Modulator and First Quadrant Tracker' */
  boolean_T isLowerInQ1;
                       /* '<S2>/Two Arm Modulator and First Quadrant Tracker' */
  boolean_T isUpperInQ1;
                       /* '<S2>/Two Arm Modulator and First Quadrant Tracker' */
  boolean_T done;      /* '<S2>/Two Arm Modulator and First Quadrant Tracker' */
} DW_control_algorithm_f_T;

/* Parameters (default storage) */
struct P_control_algorithm_T_ {
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<S1>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<S1>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<S1>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<S1>/Sine Wave'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave1'
                                        */
  real_T SineWave1_Hsin;               /* Computed Parameter: SineWave1_Hsin
                                        * Referenced by: '<S1>/Sine Wave1'
                                        */
  real_T SineWave1_HCos;               /* Computed Parameter: SineWave1_HCos
                                        * Referenced by: '<S1>/Sine Wave1'
                                        */
  real_T SineWave1_PSin;               /* Computed Parameter: SineWave1_PSin
                                        * Referenced by: '<S1>/Sine Wave1'
                                        */
  real_T SineWave1_PCos;               /* Computed Parameter: SineWave1_PCos
                                        * Referenced by: '<S1>/Sine Wave1'
                                        */
  real_T SineWave2_Bias;               /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave2'
                                        */
  real_T SineWave2_Hsin;               /* Computed Parameter: SineWave2_Hsin
                                        * Referenced by: '<S1>/Sine Wave2'
                                        */
  real_T SineWave2_HCos;               /* Computed Parameter: SineWave2_HCos
                                        * Referenced by: '<S1>/Sine Wave2'
                                        */
  real_T SineWave2_PSin;               /* Computed Parameter: SineWave2_PSin
                                        * Referenced by: '<S1>/Sine Wave2'
                                        */
  real_T SineWave2_PCos;               /* Computed Parameter: SineWave2_PCos
                                        * Referenced by: '<S1>/Sine Wave2'
                                        */
  real_T AvoidDivisionByZero_UpperSat; /* Expression: 24
                                        * Referenced by: '<S3>/Avoid Division By Zero'
                                        */
  real_T AvoidDivisionByZero_LowerSat; /* Expression: 0.1
                                        * Referenced by: '<S3>/Avoid Division By Zero'
                                        */
  real_T Bias_Bias;                    /* Expression: 0.5
                                        * Referenced by: '<S3>/Bias'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_control_algorithm_T {
  const char_T **errorStatus;
  const rtTimingBridge *timingBridge;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    int_T mdlref_GlobalTID[1];
  } Timing;
};

typedef struct {
  B_control_algorithm_c_T rtb;
  DW_control_algorithm_f_T rtdw;
  RT_MODEL_control_algorithm_T rtm;
} MdlrefDW_control_algorithm_T;

/* Model block global parameters (default storage) */
extern real_T rtP_PWM_TIM_BASE_PRD;    /* Variable: PWM_TIM_BASE_PRD
                                        * Referenced by: '<S3>/Gain2'
                                        */
extern real_T rtP_VSI_AMP;             /* Variable: VSI_AMP
                                        * Referenced by:
                                        *   '<S1>/Sine Wave'
                                        *   '<S1>/Sine Wave1'
                                        *   '<S1>/Sine Wave2'
                                        */
extern real_T rtP_VSI_FREQ;            /* Variable: VSI_FREQ
                                        * Referenced by:
                                        *   '<S1>/Sine Wave'
                                        *   '<S1>/Sine Wave1'
                                        *   '<S1>/Sine Wave2'
                                        */

/* Model reference registration function */
extern void control_algorithm_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, RT_MODEL_control_algorithm_T *
  const control_algorithm_M, B_control_algorithm_c_T *localB,
  DW_control_algorithm_f_T *localDW);
extern void control_algorithm_Init(B_control_algorithm_c_T *localB,
  DW_control_algorithm_f_T *localDW);
extern void control_algorithm_Enable(DW_control_algorithm_f_T *localDW);
extern void control_algorithm(RT_MODEL_control_algorithm_T * const
  control_algorithm_M, const real_T rtu_LineCurrent[3], const real_T
  *rtu_BatteryVoltage, uint32_T rty_CompareValue[3], B_control_algorithm_c_T
  *localB, DW_control_algorithm_f_T *localDW);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'control_algorithm'
 * '<S1>'   : 'control_algorithm/MPPT Algorithm'
 * '<S2>'   : 'control_algorithm/Signal Conditioner'
 * '<S3>'   : 'control_algorithm/Signal Conditioner/To Compare Value'
 * '<S4>'   : 'control_algorithm/Signal Conditioner/Two Arm Modulator and First Quadrant Tracker'
 */
#endif                                 /* RTW_HEADER_control_algorithm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
