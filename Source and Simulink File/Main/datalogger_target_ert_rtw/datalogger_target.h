/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: datalogger_target.h
 *
 * Code generated for Simulink model 'datalogger_target'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Feb 13 14:56:57 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_datalogger_target_h_
#define RTW_HEADER_datalogger_target_h_
#include <stddef.h>
#ifndef datalogger_target_COMMON_INCLUDES_
#define datalogger_target_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "f28004x_device.h"
#include "DSP28xx_SciUtil.h"
#include "f28004x_examples.h"
#include "IQmathLib.h"
#include "f28004x_gpio.h"
#endif                                 /* datalogger_target_COMMON_INCLUDES_ */

#include "datalogger_target_types.h"
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
extern void config_ePWM_GPIO (void);
extern void config_ePWM_XBAR(void);
extern void configureIXbar(void);

/* Block signals (default storage) */
typedef struct {
  real32_T RateTransition[3];          /* '<Root>/Rate Transition' */
  real32_T SCIReceive[3];              /* '<S2>/SCI Receive' */
  uint16_T DCBusADC;                   /* '<S1>/DC Bus ADC' */
  uint16_T I_C;                        /* '<S8>/I_C' */
  uint16_T I_B;                        /* '<S8>/I_B' */
  uint16_T I_A;                        /* '<S8>/I_A' */
  uint16_T V_C;                        /* '<S9>/V_C' */
  uint16_T V_B;                        /* '<S9>/V_B' */
  uint16_T V_A;                        /* '<S9>/V_A' */
  uint16_T IndexVector;                /* '<S14>/Index Vector' */
  boolean_T NOT;                       /* '<S2>/NOT' */
} B_datalogger_target_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[2];          /* '<S22>/Unit Delay' */
  real_T UD_DSTATE[2];                 /* '<S5>/UD' */
  volatile real32_T RateTransition_Buffer[6];/* '<Root>/Rate Transition' */
  uint32_T ADCInterruptCallback_PREV_T;/* '<Root>/ADC Interrupt Callback' */
  uint16_T Output_DSTATE;              /* '<S24>/Output' */
  uint16_T Output_DSTATE_e;            /* '<S15>/Output' */
  volatile int16_T RateTransition_ActiveBufIdx;/* '<Root>/Rate Transition' */
  boolean_T ADCInterruptCallback_RESET_ELAP;/* '<Root>/ADC Interrupt Callback' */
} DW_datalogger_target_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T Width;                /* '<S13>/Width' */
} ConstB_datalogger_target_T;

/* Parameters (default storage) */
struct P_datalogger_target_T_ {
  real_T HW_BLDC_RS;                   /* Variable: HW_BLDC_RS
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S5>/UD'
                               */
  uint16_T CounterLimited_uplimit;     /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S36>/FixPt Switch'
                                        */
  uint16_T CounterLimited_uplimit_k; /* Mask Parameter: CounterLimited_uplimit_k
                                      * Referenced by: '<S19>/FixPt Switch'
                                      */
  real_T one_by_sqrt3_Gain;            /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S3>/one_by_sqrt3'
                                        */
  real_T Bias_Bias;                    /* Expression: -1.65
                                        * Referenced by: '<S1>/Bias'
                                        */
  real_T Gain3_Gain;                   /* Expression: -10
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Filter_Constant_Value;        /* Expression: Filter_constant
                                        * Referenced by: '<S22>/Filter_Constant'
                                        */
  real_T One_Value;                    /* Expression: 1 - Filter_constant
                                        * Referenced by: '<S22>/One'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S22>/Unit Delay'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S5>/TSamp'
                                        */
  real_T one_by_two_Gain;              /* Expression: 1/2
                                        * Referenced by: '<S7>/one_by_two'
                                        */
  real_T sqrt3_by_two_Gain;            /* Expression: sqrt(3)/2
                                        * Referenced by: '<S7>/sqrt3_by_two'
                                        */
  real_T Bias_Bias_a;                  /* Expression: 0.5
                                        * Referenced by: '<S12>/Bias'
                                        */
  real_T Gain2_Gain;                   /* Expression: 5000
                                        * Referenced by: '<S12>/Gain2'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S25>/Out1'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S32>/Constant'
                                        */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S31>/convert_pu'
                                        */
  real32_T AvoidDivisionByZero_UpperSat;
                             /* Computed Parameter: AvoidDivisionByZero_UpperSat
                              * Referenced by: '<S12>/Avoid Division By Zero'
                              */
  real32_T AvoidDivisionByZero_LowerSat;
                             /* Computed Parameter: AvoidDivisionByZero_LowerSat
                              * Referenced by: '<S12>/Avoid Division By Zero'
                              */
  real32_T CommandedValue_Y0;          /* Computed Parameter: CommandedValue_Y0
                                        * Referenced by: '<S2>/Commanded Value'
                                        */
  real32_T RateTransition_InitialCondition;
                          /* Computed Parameter: RateTransition_InitialCondition
                           * Referenced by: '<Root>/Rate Transition'
                           */
  uint16_T DCBusVoltageConditioning_Gain;
                            /* Computed Parameter: DCBusVoltageConditioning_Gain
                             * Referenced by: '<S1>/DC Bus Voltage Conditioning'
                             */
  uint16_T Gain2_Gain_o;               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S1>/Gain2'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S11>/Gain'
                                        */
  uint16_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S19>/Constant'
                                        */
  uint16_T End_Value;                  /* Computed Parameter: End_Value
                                        * Referenced by: '<S17>/End'
                                        */
  uint16_T Start_Value;                /* Computed Parameter: Start_Value
                                        * Referenced by: '<S17>/Start'
                                        */
  uint16_T Bias_Bias_c;                /* Computed Parameter: Bias_Bias_c
                                        * Referenced by: '<S17>/Bias'
                                        */
  uint16_T Start_Value_i;              /* Computed Parameter: Start_Value_i
                                        * Referenced by: '<S16>/Start'
                                        */
  uint16_T Start1_Value;               /* Computed Parameter: Start1_Value
                                        * Referenced by: '<S16>/Start1'
                                        */
  uint16_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S36>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S24>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S35>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition_a;
                                /* Computed Parameter: Output_InitialCondition_a
                                 * Referenced by: '<S15>/Output'
                                 */
  uint16_T FixPtConstant_Value_j;   /* Computed Parameter: FixPtConstant_Value_j
                                     * Referenced by: '<S18>/FixPt Constant'
                                     */
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
    uint32_T clockTick0;
    uint8_T rtmL2HLastBufWr;
    uint32_T rtmL2HDbBufClockTick[2];
    uint32_T clockTick2;
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
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Propagation' : Unused code path elimination
 * Block '<S18>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Constant' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/add_b' : Unused code path elimination
 * Block '<S26>/add_c' : Unused code path elimination
 * Block '<S26>/one_by_two' : Unused code path elimination
 * Block '<S26>/sqrt3_by_two' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Offset' : Unused code path elimination
 * Block '<S29>/Switch' : Unused code path elimination
 * Block '<S29>/Unary_Minus' : Unused code path elimination
 * Block '<S27>/dcos' : Unused code path elimination
 * Block '<S27>/dsin' : Unused code path elimination
 * Block '<S27>/qcos' : Unused code path elimination
 * Block '<S27>/qsin' : Unused code path elimination
 * Block '<S27>/sum_alpha' : Unused code path elimination
 * Block '<S27>/sum_beta' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/Data Type Conversion1' : Unused code path elimination
 * Block '<S28>/Get_FractionVal' : Unused code path elimination
 * Block '<S28>/Get_Integer' : Unused code path elimination
 * Block '<S30>/Product' : Unused code path elimination
 * Block '<S30>/Product1' : Unused code path elimination
 * Block '<S30>/Sum3' : Unused code path elimination
 * Block '<S30>/Sum4' : Unused code path elimination
 * Block '<S30>/Sum5' : Unused code path elimination
 * Block '<S30>/Sum6' : Unused code path elimination
 * Block '<S28>/Lookup' : Unused code path elimination
 * Block '<S28>/Sum' : Unused code path elimination
 * Block '<S28>/Sum2' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S34>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/indexing' : Unused code path elimination
 * Block '<S28>/offset' : Unused code path elimination
 * Block '<S28>/sine_table_values' : Unused code path elimination
 * Block '<S23>/Unary Minus' : Unused code path elimination
 * Block '<S24>/Data Type Propagation' : Unused code path elimination
 * Block '<S35>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Voltage ADC Gain' : Unused code path elimination
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
 * '<S3>'   : 'datalogger_target/ADC Interrupt Callback/Clarke Transform'
 * '<S4>'   : 'datalogger_target/ADC Interrupt Callback/Data Logger'
 * '<S5>'   : 'datalogger_target/ADC Interrupt Callback/Discrete Derivative'
 * '<S6>'   : 'datalogger_target/ADC Interrupt Callback/IIR Filter'
 * '<S7>'   : 'datalogger_target/ADC Interrupt Callback/Inverse Clarke Transform'
 * '<S8>'   : 'datalogger_target/ADC Interrupt Callback/Line Current ADC'
 * '<S9>'   : 'datalogger_target/ADC Interrupt Callback/Line Voltage ADC'
 * '<S10>'  : 'datalogger_target/ADC Interrupt Callback/PWM Output'
 * '<S11>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator'
 * '<S12>'  : 'datalogger_target/ADC Interrupt Callback/To Compare Value'
 * '<S13>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer'
 * '<S14>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Serial Transmit'
 * '<S15>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/Counter Limited'
 * '<S16>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/Data'
 * '<S17>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/Start'
 * '<S18>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/Counter Limited/Increment Real World'
 * '<S19>'  : 'datalogger_target/ADC Interrupt Callback/Data Logger/Packet Serializer/Counter Limited/Wrap To Zero'
 * '<S20>'  : 'datalogger_target/ADC Interrupt Callback/IIR Filter/IIR Filter'
 * '<S21>'  : 'datalogger_target/ADC Interrupt Callback/IIR Filter/IIR Filter/Low-pass'
 * '<S22>'  : 'datalogger_target/ADC Interrupt Callback/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S23>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/3-Phase Sine Voltage Generator'
 * '<S24>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/Counter Limited'
 * '<S25>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/If Action Subsystem'
 * '<S26>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/3-Phase Sine Voltage Generator/Inverse Clarke Transform'
 * '<S27>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/3-Phase Sine Voltage Generator/Inverse Park Transform'
 * '<S28>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/3-Phase Sine Voltage Generator/Sine-Cosine Lookup'
 * '<S29>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/3-Phase Sine Voltage Generator/Inverse Park Transform/Switch_Axis'
 * '<S30>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Interpolation'
 * '<S31>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp'
 * '<S32>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S33>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S34>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S35>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/Counter Limited/Increment Real World'
 * '<S36>'  : 'datalogger_target/ADC Interrupt Callback/Sine Generator/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_datalogger_target_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
