/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: genpath_firmware.h
 *
 * Code generated for Simulink model 'genpath_firmware'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Mar  2 20:58:00 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_genpath_firmware_h_
#define RTW_HEADER_genpath_firmware_h_
#include <math.h>
#include <stddef.h>
#ifndef genpath_firmware_COMMON_INCLUDES_
#define genpath_firmware_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "f28004x_device.h"
#include "DSP28xx_SciUtil.h"
#include "f28004x_examples.h"
#include "IQmathLib.h"
#include "f28004x_gpio.h"
#endif                                 /* genpath_firmware_COMMON_INCLUDES_ */

#include "genpath_firmware_types.h"
#include "MW_target_hardware_resources.h"

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
  real32_T RateTransitionSCIADC[3];    /* '<Root>/Rate Transition SCI-ADC' */
  real32_T SCIAReceive[3];             /* '<S2>/SCIA Receive' */
  uint16_T V_A;                        /* '<S11>/V_A' */
  uint16_T V_B;                        /* '<S11>/V_B' */
  uint16_T V_C;                        /* '<S11>/V_C' */
  uint16_T I_A;                        /* '<S9>/I_A' */
  uint16_T I_B;                        /* '<S9>/I_B' */
  uint16_T I_C;                        /* '<S9>/I_C' */
  uint16_T DCBusVoltageADC;            /* '<S3>/DC Bus Voltage ADC' */
  uint16_T IndexVector;                /* '<S23>/Index Vector' */
  boolean_T Merge;                     /* '<S36>/Merge' */
  boolean_T NOT;                       /* '<S6>/NOT' */
} B_genpath_firmware_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE[3];        /* '<S18>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k;         /* '<S15>/Unit Delay' */
  volatile real32_T RateTransitionSCIADC_Buffer[6];/* '<Root>/Rate Transition SCI-ADC' */
  uint16_T Output_DSTATE;              /* '<S25>/Output' */
  uint16_T Output_DSTATE_d;            /* '<S41>/Output' */
  volatile int16_T RateTransitionSCIADC_ActiveBufI;/* '<Root>/Rate Transition SCI-ADC' */
} DW_genpath_firmware_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T Width;                /* '<S22>/Width' */
} ConstB_genpath_firmware_T;

/* Parameters for system: '<S24>/If Action Subsystem' */
struct P_IfActionSubsystem_genpath_f_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S28>/Constant'
                                        */
};

/* Parameters for system: '<S22>/Avoid Header and Terminator Collision' */
struct P_CoreSubsys_genpath_firmware_T_ {
  P_IfActionSubsystem_genpath_f_T IfActionSubsystem1;/* '<S24>/If Action Subsystem1' */
  P_IfActionSubsystem_genpath_f_T IfActionSubsystem;/* '<S24>/If Action Subsystem' */
};

/* Parameters for system: '<S36>/Upper Always On' */
struct P_UpperAlwaysOn_genpath_firmw_T_ {
  boolean_T Constant_Value;            /* Expression: true
                                        * Referenced by: '<S40>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_genpath_firmware_T_ {
  uint16_T CounterLimited_uplimit;     /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S43>/FixPt Switch'
                                        */
  uint16_T CounterLimited_uplimit_k; /* Mask Parameter: CounterLimited_uplimit_k
                                      * Referenced by: '<S32>/FixPt Switch'
                                      */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S47>/Gain'
                                        */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S46>/Gain'
                                        */
  real32_T Bias_Bias;                  /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S3>/Bias'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real32_T Filter_Constant_Value;   /* Computed Parameter: Filter_Constant_Value
                                     * Referenced by: '<S18>/Filter_Constant'
                                     */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S18>/One'
                                        */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S18>/Unit Delay'
                                */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real32_T Filter_Constant_Value_m;
                                  /* Computed Parameter: Filter_Constant_Value_m
                                   * Referenced by: '<S15>/Filter_Constant'
                                   */
  real32_T One_Value_o;                /* Computed Parameter: One_Value_o
                                        * Referenced by: '<S15>/One'
                                        */
  real32_T UnitDelay_InitialCondition_b;
                             /* Computed Parameter: UnitDelay_InitialCondition_b
                              * Referenced by: '<S15>/Unit Delay'
                              */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real32_T PreventDivisionByZero_UpperSat;
                           /* Computed Parameter: PreventDivisionByZero_UpperSat
                            * Referenced by: '<S33>/Prevent Division By Zero'
                            */
  real32_T PreventDivisionByZero_LowerSat;
                           /* Computed Parameter: PreventDivisionByZero_LowerSat
                            * Referenced by: '<S33>/Prevent Division By Zero'
                            */
  real32_T Bias_Bias_a;                /* Computed Parameter: Bias_Bias_a
                                        * Referenced by: '<S33>/Bias'
                                        */
  real32_T PreventOvermodulation_UpperSat;
                           /* Computed Parameter: PreventOvermodulation_UpperSat
                            * Referenced by: '<S33>/Prevent Overmodulation'
                            */
  real32_T PreventOvermodulation_LowerSat;
                           /* Computed Parameter: PreventOvermodulation_LowerSat
                            * Referenced by: '<S33>/Prevent Overmodulation'
                            */
  real32_T TimeBasePeriod_Gain;       /* Computed Parameter: TimeBasePeriod_Gain
                                       * Referenced by: '<S33>/Time Base Period'
                                       */
  real32_T CommandedSignal_Y0;         /* Computed Parameter: CommandedSignal_Y0
                                        * Referenced by: '<S2>/Commanded Signal'
                                        */
  real32_T RateTransitionSCIADC_InitialCon;
                          /* Computed Parameter: RateTransitionSCIADC_InitialCon
                           * Referenced by: '<Root>/Rate Transition SCI-ADC'
                           */
  uint16_T DCBusVoltageADCGain_Gain;
                                 /* Computed Parameter: DCBusVoltageADCGain_Gain
                                  * Referenced by: '<S3>/DC Bus Voltage ADC Gain'
                                  */
  uint16_T PhaseCurrentADCGain_Gain;
                                 /* Computed Parameter: PhaseCurrentADCGain_Gain
                                  * Referenced by: '<S3>/Phase Current ADC Gain'
                                  */
  uint16_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S32>/Constant'
                                        */
  uint16_T End_Value;                  /* Computed Parameter: End_Value
                                        * Referenced by: '<S27>/End'
                                        */
  uint16_T Start_Value;                /* Computed Parameter: Start_Value
                                        * Referenced by: '<S27>/Start'
                                        */
  uint16_T Bias_Bias_c;                /* Computed Parameter: Bias_Bias_c
                                        * Referenced by: '<S27>/Bias'
                                        */
  uint16_T Start_Value_i;              /* Computed Parameter: Start_Value_i
                                        * Referenced by: '<S26>/Start'
                                        */
  uint16_T Start1_Value;               /* Computed Parameter: Start1_Value
                                        * Referenced by: '<S26>/Start1'
                                        */
  uint16_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S43>/Constant'
                                        */
  uint16_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S38>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S41>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S42>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition_a;
                                /* Computed Parameter: Output_InitialCondition_a
                                 * Referenced by: '<S25>/Output'
                                 */
  uint16_T Bias_Bias_p;                /* Computed Parameter: Bias_Bias_p
                                        * Referenced by: '<S9>/Bias'
                                        */
  uint16_T Bias1_Bias;                 /* Computed Parameter: Bias1_Bias
                                        * Referenced by: '<S9>/Bias1'
                                        */
  uint16_T Bias2_Bias;                 /* Computed Parameter: Bias2_Bias
                                        * Referenced by: '<S9>/Bias2'
                                        */
  uint16_T FixPtConstant_Value_j;   /* Computed Parameter: FixPtConstant_Value_j
                                     * Referenced by: '<S31>/FixPt Constant'
                                     */
  uint16_T PreventPWMCounterOverrun_UpperS;
                          /* Computed Parameter: PreventPWMCounterOverrun_UpperS
                           * Referenced by: '<S33>/Prevent PWM Counter Overrun'
                           */
  uint16_T PreventPWMCounterOverrun_LowerS;
                          /* Computed Parameter: PreventPWMCounterOverrun_LowerS
                           * Referenced by: '<S33>/Prevent PWM Counter Overrun'
                           */
  boolean_T Merge_InitialOutput;      /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S36>/Merge'
                                       */
  P_UpperAlwaysOn_genpath_firmw_T LowerAlwaysOn;/* '<S36>/Lower Always On' */
  P_UpperAlwaysOn_genpath_firmw_T UpperAlwaysOn;/* '<S36>/Upper Always On' */
  P_CoreSubsys_genpath_firmware_T CoreSubsys;
                             /* '<S22>/Avoid Header and Terminator Collision' */
};

/* Real-time Model Data Structure */
struct tag_RTM_genpath_firmware_T {
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
extern P_genpath_firmware_T genpath_firmware_P;

/* Block signals (default storage) */
extern B_genpath_firmware_T genpath_firmware_B;

/* Block states (default storage) */
extern DW_genpath_firmware_T genpath_firmware_DW;
extern const ConstB_genpath_firmware_T genpath_firmware_ConstB;/* constant block i/o */

/* External function called from main */
extern void genpath_firmware_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void genpath_firmware_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void genpath_firmware_initialize(void);
extern void genpath_firmware_step0(void);
extern void genpath_firmware_step1(void);
extern void genpath_firmware_terminate(void);
extern volatile boolean_T runModel;

/* Real-time Model object */
extern RT_MODEL_genpath_firmware_T *const genpath_firmware_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Phase Voltage ADC Gain' : Unused code path elimination
 * Block '<S21>/Add1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Filter_Constant' : Unused code path elimination
 * Block '<S21>/One' : Unused code path elimination
 * Block '<S21>/Product' : Unused code path elimination
 * Block '<S21>/Product1' : Unused code path elimination
 * Block '<S21>/Unit Delay' : Unused code path elimination
 * Block '<S25>/Data Type Propagation' : Unused code path elimination
 * Block '<S31>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S41>/Data Type Propagation' : Unused code path elimination
 * Block '<S42>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S7>/Sum' : Unused code path elimination
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
 * '<Root>' : 'genpath_firmware'
 * '<S1>'   : 'genpath_firmware/ADC Interrupt Callback'
 * '<S2>'   : 'genpath_firmware/SCI Receive Interrupt Callback'
 * '<S3>'   : 'genpath_firmware/ADC Interrupt Callback/ADC'
 * '<S4>'   : 'genpath_firmware/ADC Interrupt Callback/Command Data Parser'
 * '<S5>'   : 'genpath_firmware/ADC Interrupt Callback/Data Logger'
 * '<S6>'   : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver'
 * '<S7>'   : 'genpath_firmware/ADC Interrupt Callback/MPPT Algorithm'
 * '<S8>'   : 'genpath_firmware/ADC Interrupt Callback/ADC/DC Bus Voltage IIR Filter'
 * '<S9>'   : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Current ADC'
 * '<S10>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Current IIR Filter'
 * '<S11>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Voltage ADC'
 * '<S12>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Voltage IIR Filter'
 * '<S13>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/DC Bus Voltage IIR Filter/IIR Filter'
 * '<S14>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/DC Bus Voltage IIR Filter/IIR Filter/Low-pass'
 * '<S15>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/DC Bus Voltage IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S16>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Current IIR Filter/IIR Filter'
 * '<S17>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Current IIR Filter/IIR Filter/Low-pass'
 * '<S18>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Current IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S19>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Voltage IIR Filter/IIR Filter'
 * '<S20>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Voltage IIR Filter/IIR Filter/Low-pass'
 * '<S21>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Voltage IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S22>'  : 'genpath_firmware/ADC Interrupt Callback/Data Logger/Packet Serializer'
 * '<S23>'  : 'genpath_firmware/ADC Interrupt Callback/Data Logger/Serial Transmit'
 * '<S24>'  : 'genpath_firmware/ADC Interrupt Callback/Data Logger/Packet Serializer/Avoid Header and Terminator Collision'
 * '<S25>'  : 'genpath_firmware/ADC Interrupt Callback/Data Logger/Packet Serializer/Counter Limited'
 * '<S26>'  : 'genpath_firmware/ADC Interrupt Callback/Data Logger/Packet Serializer/Data'
 * '<S27>'  : 'genpath_firmware/ADC Interrupt Callback/Data Logger/Packet Serializer/Start'
 * '<S28>'  : 'genpath_firmware/ADC Interrupt Callback/Data Logger/Packet Serializer/Avoid Header and Terminator Collision/If Action Subsystem'
 * '<S29>'  : 'genpath_firmware/ADC Interrupt Callback/Data Logger/Packet Serializer/Avoid Header and Terminator Collision/If Action Subsystem1'
 * '<S30>'  : 'genpath_firmware/ADC Interrupt Callback/Data Logger/Packet Serializer/Avoid Header and Terminator Collision/If Action Subsystem2'
 * '<S31>'  : 'genpath_firmware/ADC Interrupt Callback/Data Logger/Packet Serializer/Counter Limited/Increment Real World'
 * '<S32>'  : 'genpath_firmware/ADC Interrupt Callback/Data Logger/Packet Serializer/Counter Limited/Wrap To Zero'
 * '<S33>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/PWM Gain and Offset'
 * '<S34>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Timer'
 * '<S35>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm'
 * '<S36>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm'
 * '<S37>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/Two Arm Modulation Algorithm'
 * '<S38>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Load Balancing'
 * '<S39>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Lower Always On'
 * '<S40>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Upper Always On'
 * '<S41>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Load Balancing/Counter Limited'
 * '<S42>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Load Balancing/Counter Limited/Increment Real World'
 * '<S43>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Load Balancing/Counter Limited/Wrap To Zero'
 * '<S44>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/Two Arm Modulation Algorithm/Compute Two Arm Modulation Offset'
 * '<S45>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/Two Arm Modulation Algorithm/Zero Offset'
 * '<S46>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/Two Arm Modulation Algorithm/Compute Two Arm Modulation Offset/If Lower Switch Always Conduct'
 * '<S47>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/Two Arm Modulation Algorithm/Compute Two Arm Modulation Offset/If Upper Switch Always Conduct'
 */
#endif                                 /* RTW_HEADER_genpath_firmware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
