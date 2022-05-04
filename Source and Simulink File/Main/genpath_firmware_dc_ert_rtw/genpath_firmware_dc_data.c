/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: genpath_firmware_dc_data.c
 *
 * Code generated for Simulink model 'genpath_firmware_dc'.
 *
 * Model version                  : 3.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr 21 10:46:13 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#include "genpath_firmware_dc.h"

/* Invariant block signals (default storage) */
const ConstB_genpath_firmware_dc_T genpath_firmware_dc_ConstB = {
  4U                                   /* '<S7>/Width' */
};

/* Block parameters (default storage) */
P_genpath_firmware_dc_T genpath_firmware_dc_P = {
  /* Variable: HW_LS
   * Referenced by: '<S6>/Gain2'
   */
  0.0196F,

  /* Mask Parameter: CounterLimited_uplimit
   * Referenced by: '<S38>/FixPt Switch'
   */
  999U,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: Filter_Constant_Value
   * Referenced by: '<S17>/Filter_Constant'
   */
  0.02F,

  /* Computed Parameter: One_Value
   * Referenced by: '<S17>/One'
   */
  0.98F,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S17>/Unit Delay'
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

  /* Computed Parameter: Filter_Constant_Value_d
   * Referenced by: '<S20>/Filter_Constant'
   */
  0.02F,

  /* Computed Parameter: One_Value_e
   * Referenced by: '<S20>/One'
   */
  0.98F,

  /* Computed Parameter: UnitDelay_InitialCondition_c
   * Referenced by: '<S20>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S6>/Gain1'
   */
  -30.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_j
   * Referenced by: '<S25>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S25>/Gain'
   */
  0.0001F,

  /* Computed Parameter: Filter_Constant_Value_c
   * Referenced by: '<S29>/Filter_Constant'
   */
  0.1F,

  /* Computed Parameter: One_Value_f
   * Referenced by: '<S29>/One'
   */
  0.9F,

  /* Computed Parameter: UnitDelay_InitialCondition_i
   * Referenced by: '<S29>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<S24>/Gain'
   */
  0.5F,

  /* Computed Parameter: PreventDivisionByZero_UpperSat
   * Referenced by: '<S24>/Prevent Division By Zero'
   */
  81.5F,

  /* Computed Parameter: PreventDivisionByZero_LowerSat
   * Referenced by: '<S24>/Prevent Division By Zero'
   */
  0.1F,

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

  /* Computed Parameter: DCBusVoltageADCGain_Gain
   * Referenced by: '<S3>/DC Bus Voltage ADC Gain'
   */
  41733U,

  /* Computed Parameter: PhaseCurrentADCGain_Gain
   * Referenced by: '<S3>/Phase Current ADC Gain'
   */
  54067U,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S38>/Constant'
   */
  0U,

  /* Computed Parameter: End_Value
   * Referenced by: '<S33>/End'
   */
  65535U,

  /* Computed Parameter: Start_Value
   * Referenced by: '<S33>/Start'
   */
  61166U,

  /* Computed Parameter: Bias_Bias_c
   * Referenced by: '<S33>/Bias'
   */
  2U,

  /* Computed Parameter: Start_Value_i
   * Referenced by: '<S32>/Start'
   */
  0U,

  /* Computed Parameter: Start1_Value
   * Referenced by: '<S32>/Start1'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S31>/Output'
   */
  0U,

  /* Computed Parameter: Bias_Bias_p
   * Referenced by: '<S11>/Bias'
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

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S37>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: CommandedSignal_Y0
   * Referenced by: '<S2>/Commanded Signal'
   */
  0U,

  /* Computed Parameter: RateTransitionSCIADC_InitialCon
   * Referenced by: '<Root>/Rate Transition SCI-ADC'
   */
  0U,

  /* Start of '<S30>/CoreSubsys' */
  {
    /* Start of '<S30>/If Action Subsystem1' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S35>/Constant'
       */
      515U
    }
    ,

    /* End of '<S30>/If Action Subsystem1' */

    /* Start of '<S30>/If Action Subsystem' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S34>/Constant'
       */
      258U
    }
    /* End of '<S30>/If Action Subsystem' */
  }
  /* End of '<S30>/CoreSubsys' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
