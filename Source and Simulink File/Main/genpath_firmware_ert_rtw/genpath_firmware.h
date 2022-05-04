/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: genpath_firmware.h
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

#ifndef RTW_HEADER_genpath_firmware_h_
#define RTW_HEADER_genpath_firmware_h_
#ifndef genpath_firmware_COMMON_INCLUDES_
#define genpath_firmware_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f28004x_includes.h"
#include "DSP28xx_SciUtil.h"
#include "IQmathLib.h"
#endif                                 /* genpath_firmware_COMMON_INCLUDES_ */

#include "genpath_firmware_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>
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

/* Block signals (default storage) */
typedef struct {
  real32_T RateTransitionSCIADC[3];    /* '<Root>/Rate Transition SCI-ADC' */
  real32_T SCIAReceive[3];             /* '<S2>/SCIA Receive' */
  real32_T DataTypeConversion[3];      /* '<S24>/Data Type Conversion' */
  uint16_T V_A;                        /* '<S13>/V_A' */
  uint16_T V_B;                        /* '<S13>/V_B' */
  uint16_T V_C;                        /* '<S13>/V_C' */
  uint16_T I_A;                        /* '<S11>/I_A' */
  uint16_T I_B;                        /* '<S11>/I_B' */
  uint16_T I_C;                        /* '<S11>/I_C' */
  uint16_T DCBusVoltageADC;            /* '<S3>/DC Bus Voltage ADC' */
  uint16_T BytePack[6];                /* '<S1>/Byte Pack' */
  uint16_T IndexVector;                /* '<S8>/Index Vector' */
  boolean_T Merge;                     /* '<S26>/Merge' */
  boolean_T NOT;                       /* '<S5>/NOT' */
} B_genpath_firmware_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE[3];        /* '<S20>/Unit Delay' */
  real32_T UnitDelay_DSTATE_g[3];      /* '<S38>/Unit Delay' */
  real32_T UnitDelay_DSTATE_m[3];      /* '<S42>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k;         /* '<S17>/Unit Delay' */
  volatile real32_T RateTransitionSCIADC_Buffer[6];/* '<Root>/Rate Transition SCI-ADC' */
  uint16_T Output_DSTATE;              /* '<S44>/Output' */
  uint16_T Output_DSTATE_d;            /* '<S31>/Output' */
  volatile int16_T RateTransitionSCIADC_ActiveBufI;/* '<Root>/Rate Transition SCI-ADC' */
  boolean_T Ifthecurrentispositive_Mode;/* '<S26>/If the current is positive ' */
  boolean_T Ifthecurrentisnegative_Mode;/* '<S26>/If the current is negative' */
} DW_genpath_firmware_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T Width;                /* '<S7>/Width' */
} ConstB_genpath_firmware_T;

/* Parameters for system: '<S26>/Upper Always On' */
struct P_UpperAlwaysOn_genpath_firmw_T_ {
  boolean_T Constant_Value;            /* Expression: true
                                        * Referenced by: '<S30>/Constant'
                                        */
};

/* Parameters for system: '<S43>/If Action Subsystem' */
struct P_IfActionSubsystem_genpath_f_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S47>/Constant'
                                        */
};

/* Parameters for system: '<S7>/Avoid Header and Terminator Collision' */
struct P_CoreSubsys_genpath_firmware_T_ {
  P_IfActionSubsystem_genpath_f_T IfActionSubsystem1;/* '<S43>/If Action Subsystem1' */
  P_IfActionSubsystem_genpath_f_T IfActionSubsystem;/* '<S43>/If Action Subsystem' */
};

/* Parameters (default storage) */
struct P_genpath_firmware_T_ {
  real32_T HW_BLDC_LQ;                 /* Variable: HW_BLDC_LQ
                                        * Referenced by: '<S6>/Gain2'
                                        */
  uint16_T CounterLimited_uplimit;     /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S33>/FixPt Switch'
                                        */
  uint16_T CounterLimited_uplimit_k; /* Mask Parameter: CounterLimited_uplimit_k
                                      * Referenced by: '<S51>/FixPt Switch'
                                      */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S37>/Gain'
                                        */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S36>/Gain'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S35>/Constant'
                                        */
  real32_T Bias_Bias;                  /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S3>/Bias'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real32_T Filter_Constant_Value;   /* Computed Parameter: Filter_Constant_Value
                                     * Referenced by: '<S20>/Filter_Constant'
                                     */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S20>/One'
                                        */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S20>/Unit Delay'
                                */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real32_T UnitDelay_InitialCondition_j;
                             /* Computed Parameter: UnitDelay_InitialCondition_j
                              * Referenced by: '<S38>/Unit Delay'
                              */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S38>/Gain'
                                        */
  real32_T Filter_Constant_Value_c;
                                  /* Computed Parameter: Filter_Constant_Value_c
                                   * Referenced by: '<S42>/Filter_Constant'
                                   */
  real32_T One_Value_f;                /* Computed Parameter: One_Value_f
                                        * Referenced by: '<S42>/One'
                                        */
  real32_T UnitDelay_InitialCondition_i;
                             /* Computed Parameter: UnitDelay_InitialCondition_i
                              * Referenced by: '<S42>/Unit Delay'
                              */
  real32_T Filter_Constant_Value_m;
                                  /* Computed Parameter: Filter_Constant_Value_m
                                   * Referenced by: '<S17>/Filter_Constant'
                                   */
  real32_T One_Value_o;                /* Computed Parameter: One_Value_o
                                        * Referenced by: '<S17>/One'
                                        */
  real32_T UnitDelay_InitialCondition_b;
                             /* Computed Parameter: UnitDelay_InitialCondition_b
                              * Referenced by: '<S17>/Unit Delay'
                              */
  real32_T Ifthecurrentispositive_OnVal;
                             /* Computed Parameter: Ifthecurrentispositive_OnVal
                              * Referenced by: '<S26>/If the current is positive '
                              */
  real32_T Ifthecurrentispositive_OffVal;
                            /* Computed Parameter: Ifthecurrentispositive_OffVal
                             * Referenced by: '<S26>/If the current is positive '
                             */
  real32_T Ifthecurrentisnegative_OnVal;
                             /* Computed Parameter: Ifthecurrentisnegative_OnVal
                              * Referenced by: '<S26>/If the current is negative'
                              */
  real32_T Ifthecurrentisnegative_OffVal;
                            /* Computed Parameter: Ifthecurrentisnegative_OffVal
                             * Referenced by: '<S26>/If the current is negative'
                             */
  real32_T PreventDivisionByZero_UpperSat;
                           /* Computed Parameter: PreventDivisionByZero_UpperSat
                            * Referenced by: '<S24>/Prevent Division By Zero'
                            */
  real32_T PreventDivisionByZero_LowerSat;
                           /* Computed Parameter: PreventDivisionByZero_LowerSat
                            * Referenced by: '<S24>/Prevent Division By Zero'
                            */
  real32_T Bias_Bias_a;                /* Computed Parameter: Bias_Bias_a
                                        * Referenced by: '<S24>/Bias'
                                        */
  real32_T PreventOvermodulation_UpperSat;
                           /* Computed Parameter: PreventOvermodulation_UpperSat
                            * Referenced by: '<S24>/Prevent Overmodulation'
                            */
  real32_T PreventOvermodulation_LowerSat;
                           /* Computed Parameter: PreventOvermodulation_LowerSat
                            * Referenced by: '<S24>/Prevent Overmodulation'
                            */
  real32_T TimeBasePeriod_Gain;       /* Computed Parameter: TimeBasePeriod_Gain
                                       * Referenced by: '<S24>/Time Base Period'
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
  uint16_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S33>/Constant'
                                        */
  uint16_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S28>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S31>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S32>/FixPt Constant'
                                       */
  uint16_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S51>/Constant'
                                        */
  uint16_T End_Value;                  /* Computed Parameter: End_Value
                                        * Referenced by: '<S46>/End'
                                        */
  uint16_T Start_Value;                /* Computed Parameter: Start_Value
                                        * Referenced by: '<S46>/Start'
                                        */
  uint16_T Bias_Bias_c;                /* Computed Parameter: Bias_Bias_c
                                        * Referenced by: '<S46>/Bias'
                                        */
  uint16_T Start_Value_i;              /* Computed Parameter: Start_Value_i
                                        * Referenced by: '<S45>/Start'
                                        */
  uint16_T Start1_Value;               /* Computed Parameter: Start1_Value
                                        * Referenced by: '<S45>/Start1'
                                        */
  uint16_T Output_InitialCondition_a;
                                /* Computed Parameter: Output_InitialCondition_a
                                 * Referenced by: '<S44>/Output'
                                 */
  uint16_T Bias_Bias_p;                /* Computed Parameter: Bias_Bias_p
                                        * Referenced by: '<S11>/Bias'
                                        */
  uint16_T Bias1_Bias;                 /* Computed Parameter: Bias1_Bias
                                        * Referenced by: '<S11>/Bias1'
                                        */
  uint16_T Bias2_Bias;                 /* Computed Parameter: Bias2_Bias
                                        * Referenced by: '<S11>/Bias2'
                                        */
  uint16_T PreventPWMCounterOverrun_UpperS;
                          /* Computed Parameter: PreventPWMCounterOverrun_UpperS
                           * Referenced by: '<S24>/Prevent PWM Counter Overrun'
                           */
  uint16_T PreventPWMCounterOverrun_LowerS;
                          /* Computed Parameter: PreventPWMCounterOverrun_LowerS
                           * Referenced by: '<S24>/Prevent PWM Counter Overrun'
                           */
  uint16_T FixPtConstant_Value_j;   /* Computed Parameter: FixPtConstant_Value_j
                                     * Referenced by: '<S50>/FixPt Constant'
                                     */
  boolean_T Ifthecurrentispositive_YOn;/* Expression: true
                                        * Referenced by: '<S26>/If the current is positive '
                                        */
  boolean_T Ifthecurrentispositive_YOff;/* Expression: false
                                         * Referenced by: '<S26>/If the current is positive '
                                         */
  boolean_T Ifthecurrentisnegative_YOn;/* Expression: false
                                        * Referenced by: '<S26>/If the current is negative'
                                        */
  boolean_T Ifthecurrentisnegative_YOff;/* Expression: true
                                         * Referenced by: '<S26>/If the current is negative'
                                         */
  boolean_T Merge_InitialOutput;      /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S26>/Merge'
                                       */
  P_CoreSubsys_genpath_firmware_T CoreSubsys;
                              /* '<S7>/Avoid Header and Terminator Collision' */
  P_UpperAlwaysOn_genpath_firmw_T LowerAlwaysOn;/* '<S26>/Lower Always On' */
  P_UpperAlwaysOn_genpath_firmw_T UpperAlwaysOn;/* '<S26>/Upper Always On' */
};

/* Real-time Model Data Structure */
struct tag_RTM_genpath_firmware_T {
  const char_T * volatile errorStatus;

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
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Phase Voltage ADC Gain' : Unused code path elimination
 * Block '<S23>/Add1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Filter_Constant' : Unused code path elimination
 * Block '<S23>/One' : Unused code path elimination
 * Block '<S23>/Product' : Unused code path elimination
 * Block '<S23>/Product1' : Unused code path elimination
 * Block '<S23>/Unit Delay' : Unused code path elimination
 * Block '<S31>/Data Type Propagation' : Unused code path elimination
 * Block '<S32>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Data Type Propagation' : Unused code path elimination
 * Block '<S50>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/FixPt Data Type Duplicate1' : Unused code path elimination
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
 * '<S5>'   : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver'
 * '<S6>'   : 'genpath_firmware/ADC Interrupt Callback/MPPT Algorithm'
 * '<S7>'   : 'genpath_firmware/ADC Interrupt Callback/Packet Serializer'
 * '<S8>'   : 'genpath_firmware/ADC Interrupt Callback/Serial Transmit'
 * '<S9>'   : 'genpath_firmware/ADC Interrupt Callback/Timer'
 * '<S10>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/DC Bus Voltage IIR Filter'
 * '<S11>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Current ADC'
 * '<S12>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Current IIR Filter'
 * '<S13>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Voltage ADC'
 * '<S14>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Voltage IIR Filter'
 * '<S15>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/DC Bus Voltage IIR Filter/IIR Filter'
 * '<S16>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/DC Bus Voltage IIR Filter/IIR Filter/Low-pass'
 * '<S17>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/DC Bus Voltage IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S18>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Current IIR Filter/IIR Filter'
 * '<S19>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Current IIR Filter/IIR Filter/Low-pass'
 * '<S20>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Current IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S21>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Voltage IIR Filter/IIR Filter'
 * '<S22>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Voltage IIR Filter/IIR Filter/Low-pass'
 * '<S23>'  : 'genpath_firmware/ADC Interrupt Callback/ADC/Phase Voltage IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S24>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/PWM Gain and Offset'
 * '<S25>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm'
 * '<S26>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm'
 * '<S27>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/Two Arm Modulation Algorithm'
 * '<S28>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Load Balancing'
 * '<S29>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Lower Always On'
 * '<S30>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Upper Always On'
 * '<S31>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Load Balancing/Counter Limited'
 * '<S32>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Load Balancing/Counter Limited/Increment Real World'
 * '<S33>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/First Quadrant Tracking Algorithm/Load Balancing/Counter Limited/Wrap To Zero'
 * '<S34>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/Two Arm Modulation Algorithm/Compute Two Arm Modulation Offset'
 * '<S35>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/Two Arm Modulation Algorithm/Zero Offset'
 * '<S36>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/Two Arm Modulation Algorithm/Compute Two Arm Modulation Offset/If Lower Switch Always Conduct'
 * '<S37>'  : 'genpath_firmware/ADC Interrupt Callback/Inverter Driver/Two Arm Modulation and First Quadrant Tracking Algorithm/Two Arm Modulation Algorithm/Compute Two Arm Modulation Offset/If Upper Switch Always Conduct'
 * '<S38>'  : 'genpath_firmware/ADC Interrupt Callback/MPPT Algorithm/Derivative'
 * '<S39>'  : 'genpath_firmware/ADC Interrupt Callback/MPPT Algorithm/IIR Filter'
 * '<S40>'  : 'genpath_firmware/ADC Interrupt Callback/MPPT Algorithm/IIR Filter/IIR Filter'
 * '<S41>'  : 'genpath_firmware/ADC Interrupt Callback/MPPT Algorithm/IIR Filter/IIR Filter/Low-pass'
 * '<S42>'  : 'genpath_firmware/ADC Interrupt Callback/MPPT Algorithm/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S43>'  : 'genpath_firmware/ADC Interrupt Callback/Packet Serializer/Avoid Header and Terminator Collision'
 * '<S44>'  : 'genpath_firmware/ADC Interrupt Callback/Packet Serializer/Counter Limited'
 * '<S45>'  : 'genpath_firmware/ADC Interrupt Callback/Packet Serializer/Data'
 * '<S46>'  : 'genpath_firmware/ADC Interrupt Callback/Packet Serializer/Start'
 * '<S47>'  : 'genpath_firmware/ADC Interrupt Callback/Packet Serializer/Avoid Header and Terminator Collision/If Action Subsystem'
 * '<S48>'  : 'genpath_firmware/ADC Interrupt Callback/Packet Serializer/Avoid Header and Terminator Collision/If Action Subsystem1'
 * '<S49>'  : 'genpath_firmware/ADC Interrupt Callback/Packet Serializer/Avoid Header and Terminator Collision/If Action Subsystem2'
 * '<S50>'  : 'genpath_firmware/ADC Interrupt Callback/Packet Serializer/Counter Limited/Increment Real World'
 * '<S51>'  : 'genpath_firmware/ADC Interrupt Callback/Packet Serializer/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_genpath_firmware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
