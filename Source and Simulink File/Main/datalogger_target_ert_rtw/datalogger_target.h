/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: datalogger_target.h
 *
 * Code generated for Simulink model 'datalogger_target'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Feb 16 12:58:16 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_datalogger_target_h_
#define RTW_HEADER_datalogger_target_h_
#include <math.h>
#include <stddef.h>
#ifndef datalogger_target_COMMON_INCLUDES_
#define datalogger_target_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "f28004x_device.h"
#include "DSP28xx_SciUtil.h"
#include "f28004x_examples.h"
#include "f28004x_gpio.h"
#include "IQmathLib.h"
#endif                                 /* datalogger_target_COMMON_INCLUDES_ */

#include "datalogger_target_types.h"
#include "MW_target_hardware_resources.h"
#include "mw_C28x_s16.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

void MW_InitSysPll(uint16_T clock_source, uint16_T imult, uint16_T fmult,
                   uint16_T odiv, uint16_T divsel);
extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void initializeOverrunService();
extern void executeOverrunService();
extern void config_ePWM_GPIO (void);
extern void config_ePWM_XBAR(void);
extern void configureIXbar(void);

/* Block signals (default storage) */
typedef struct {
  real32_T RateTransition[3];          /* '<Root>/Rate Transition' */
  real32_T ReplicaOfSource[3];         /* '<S40>/ReplicaOfSource' */
  real32_T DTC_output_1[3];            /* '<S40>/DTC_output_1' */
  uint16_T ReplicaOfSource_o;          /* '<S15>/ReplicaOfSource' */
  uint16_T ReplicaOfSource_b;          /* '<S16>/ReplicaOfSource' */
  uint16_T ReplicaOfSource_e;          /* '<S17>/ReplicaOfSource' */
  uint16_T ReplicaOfSource_p;          /* '<S9>/ReplicaOfSource' */
  uint16_T IndexVector;                /* '<S19>/Index Vector' */
  int16_T ReplicaOfSource_d;           /* '<S12>/ReplicaOfSource' */
  int16_T ReplicaOfSource_i;           /* '<S13>/ReplicaOfSource' */
  int16_T ReplicaOfSource_dp;          /* '<S14>/ReplicaOfSource' */
  boolean_T NOT;                       /* '<S1>/NOT' */
} B_datalogger_target_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  volatile real32_T RateTransition_Buffer[6];/* '<Root>/Rate Transition' */
  uint16_T Output_DSTATE;              /* '<S20>/Output' */
  volatile int16_T RateTransition_ActiveBufIdx;/* '<Root>/Rate Transition' */
} DW_datalogger_target_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T Width;                /* '<S18>/Width' */
} ConstB_datalogger_target_T;

/* Parameters for system: '<S22>/If Action Subsystem' */
struct P_IfActionSubsystem_datalogge_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S26>/Constant'
                                        */
};

/* Parameters for system: '<S18>/For Each Subsystem' */
struct P_CoreSubsys_datalogger_targe_T_ {
  P_IfActionSubsystem_datalogge_T IfActionSubsystem1;/* '<S22>/If Action Subsystem1' */
  P_IfActionSubsystem_datalogge_T IfActionSubsystem;/* '<S22>/If Action Subsystem' */
};

/* Parameters (default storage) */
struct P_datalogger_target_T_ {
  uint16_T CounterLimited_uplimit;     /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S25>/FixPt Switch'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S34>/Gain'
                                        */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S33>/Gain'
                                        */
  real32_T one_by_sqrt3_Gain;          /* Computed Parameter: one_by_sqrt3_Gain
                                        * Referenced by: '<S35>/one_by_sqrt3'
                                        */
  real32_T Bias_Bias;                  /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S3>/Bias'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S36>/one_by_two'
                                        */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S36>/sqrt3_by_two'
                                        */
  real32_T AvoidDivisionByZero_UpperSat;
                             /* Computed Parameter: AvoidDivisionByZero_UpperSat
                              * Referenced by: '<S29>/Avoid Division By Zero'
                              */
  real32_T AvoidDivisionByZero_LowerSat;
                             /* Computed Parameter: AvoidDivisionByZero_LowerSat
                              * Referenced by: '<S29>/Avoid Division By Zero'
                              */
  real32_T Bias_Bias_a;                /* Computed Parameter: Bias_Bias_a
                                        * Referenced by: '<S29>/Bias'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S29>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S29>/Saturation'
                                       */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S29>/Gain2'
                                        */
  real32_T CommandedValue_Y0;          /* Computed Parameter: CommandedValue_Y0
                                        * Referenced by: '<S2>/Commanded Value'
                                        */
  real32_T RateTransition_InitialCondition;
                          /* Computed Parameter: RateTransition_InitialCondition
                           * Referenced by: '<Root>/Rate Transition'
                           */
  int16_T Bias_Bias_p;                 /* Computed Parameter: Bias_Bias_p
                                        * Referenced by: '<S12>/Bias'
                                        */
  int16_T Bias_Bias_g;                 /* Computed Parameter: Bias_Bias_g
                                        * Referenced by: '<S13>/Bias'
                                        */
  int16_T Bias_Bias_c;                 /* Computed Parameter: Bias_Bias_c
                                        * Referenced by: '<S14>/Bias'
                                        */
  uint16_T PhaseCurrentADCGain_Gain;
                                 /* Computed Parameter: PhaseCurrentADCGain_Gain
                                  * Referenced by: '<S3>/Phase Current ADC Gain'
                                  */
  uint16_T DCBusVoltageADCGain_Gain;
                                 /* Computed Parameter: DCBusVoltageADCGain_Gain
                                  * Referenced by: '<S3>/DC Bus Voltage ADC Gain'
                                  */
  uint16_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S25>/Constant'
                                        */
  uint16_T End_Value;                  /* Computed Parameter: End_Value
                                        * Referenced by: '<S23>/End'
                                        */
  uint16_T Start_Value;                /* Computed Parameter: Start_Value
                                        * Referenced by: '<S23>/Start'
                                        */
  uint16_T Bias_Bias_cx;               /* Computed Parameter: Bias_Bias_cx
                                        * Referenced by: '<S23>/Bias'
                                        */
  uint16_T Start_Value_i;              /* Computed Parameter: Start_Value_i
                                        * Referenced by: '<S21>/Start'
                                        */
  uint16_T Start1_Value;               /* Computed Parameter: Start1_Value
                                        * Referenced by: '<S21>/Start1'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S20>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S24>/FixPt Constant'
                                       */
  P_CoreSubsys_datalogger_targe_T CoreSubsys;/* '<S18>/For Each Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_datalogger_target_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_datalogger_target_T datalogger_target_P;

/* Block signals (default storage) */
extern B_datalogger_target_T datalogger_target_B;

/* Block states (default storage) */
extern DW_datalogger_target_T datalogger_target_DW;
extern const ConstB_datalogger_target_T datalogger_target_ConstB;/* constant block i/o */

/* External function called from main */
extern void datalogger_target_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void datalogger_target_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void datalogger_target_initialize(void);
extern void datalogger_target_step0(void);
extern void datalogger_target_step1(void);
extern void datalogger_target_terminate(void);
extern volatile boolean_T runModel;

/* Real-time Model object */
extern RT_MODEL_datalogger_target_T *const datalogger_target_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Voltage ADC Gain' : Unused code path elimination
 * Block '<S20>/Data Type Propagation' : Unused code path elimination
 * Block '<S24>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/DTC_output_1' : Eliminate redundant data type conversion
 * Block '<S15>/DTC_output_1' : Eliminate redundant data type conversion
 * Block '<S16>/DTC_output_1' : Eliminate redundant data type conversion
 * Block '<S17>/DTC_output_1' : Eliminate redundant data type conversion
 * Block '<S6>/DTC_input_1' : Eliminate redundant data type conversion
 * Block '<S37>/DTC_input_1' : Eliminate redundant data type conversion
 * Block '<S38>/DTC_input_1' : Eliminate redundant data type conversion
 * Block '<S39>/DTC_input_1' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'datalogger_target'
 * '<S1>'   : 'datalogger_target/ADC Interrupt Callback'
 * '<S2>'   : 'datalogger_target/SCI Receive Interrupt Callback'
 * '<S3>'   : 'datalogger_target/ADC Interrupt Callback/ADC'
 * '<S4>'   : 'datalogger_target/ADC Interrupt Callback/Data Logger'
 * '<S5>'   : 'datalogger_target/ADC Interrupt Callback/Inverter Driver'
 * '<S6>'   : 'datalogger_target/ADC Interrupt Callback/Inverter Enable'
 * '<S7>'   : 'datalogger_target/ADC Interrupt Callback/MPPT Algorithm'
 * '<S8>'   : 'datalogger_target/ADC Interrupt Callback/Timer'
 * '<S9>'   : 'datalogger_target/ADC Interrupt Callback/ADC/DC Bus ADC'
 * '<S10>'  : 'datalogger_target/ADC Interrupt Callback/ADC/Phase Current ADC'
 * '<S11>'  : 'datalogger_target/ADC Interrupt Callback/ADC/Phase Voltage ADC'
 * '<S12>'  : 'datalogger_target/ADC Interrupt Callback/ADC/Phase Current ADC/I_A'
 * '<S13>'  : 'datalogger_target/ADC Interrupt Callback/ADC/Phase Current ADC/I_B'
 * '<S14>'  : 'datalogger_target/ADC Interrupt Callback/ADC/Phase Current ADC/I_C'
 * '<S15>'  : 'datalogger_target/ADC Interrupt Callback/ADC/Phase Voltage ADC/V_A'
 * '<S16>'  : 'datalogger_target/ADC Interrupt Callback/ADC/Phase Voltage ADC/V_B'
 * '<S17>'  : 'datalogger_target/ADC Interrupt Callback/ADC/Phase Voltage ADC/V_C'
 * '<S18>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer'
 * '<S19>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Serial Transmit'
 * '<S20>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/Counter Limited'
 * '<S21>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/Data'
 * '<S22>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/For Each Subsystem'
 * '<S23>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/Start'
 * '<S24>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/Counter Limited/Increment Real World'
 * '<S25>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/Counter Limited/Wrap To Zero'
 * '<S26>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/For Each Subsystem/If Action Subsystem'
 * '<S27>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/For Each Subsystem/If Action Subsystem1'
 * '<S28>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/For Each Subsystem/If Action Subsystem2'
 * '<S29>'  : 'datalogger_target/ADC Interrupt Callback/Inverter Driver/PWM Gain and Offset'
 * '<S30>'  : 'datalogger_target/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation Algorithm'
 * '<S31>'  : 'datalogger_target/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation Algorithm/Compute Two Arm Modulation Offset'
 * '<S32>'  : 'datalogger_target/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation Algorithm/Zero Offset'
 * '<S33>'  : 'datalogger_target/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation Algorithm/Compute Two Arm Modulation Offset/If Lower Switch Always Conduct'
 * '<S34>'  : 'datalogger_target/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation Algorithm/Compute Two Arm Modulation Offset/If Upper Switch Always Conduct'
 * '<S35>'  : 'datalogger_target/ADC Interrupt Callback/MPPT Algorithm/Clarke Transform'
 * '<S36>'  : 'datalogger_target/ADC Interrupt Callback/MPPT Algorithm/Inverse Clarke Transform'
 * '<S37>'  : 'datalogger_target/ADC Interrupt Callback/Timer/ePWM'
 * '<S38>'  : 'datalogger_target/ADC Interrupt Callback/Timer/ePWM1'
 * '<S39>'  : 'datalogger_target/ADC Interrupt Callback/Timer/ePWM2'
 * '<S40>'  : 'datalogger_target/SCI Receive Interrupt Callback/SCI Receive'
 */
#endif                                 /* RTW_HEADER_datalogger_target_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
