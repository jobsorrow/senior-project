/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: datalogger_target_data.c
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

#include "datalogger_target.h"
#include "datalogger_target_private.h"

/* Invariant block signals (default storage) */
const ConstB_datalogger_target_T datalogger_target_ConstB = {
  7U                                   /* '<S18>/Width' */
};

/* Block parameters (default storage) */
P_datalogger_target_T datalogger_target_P = {
  /* Mask Parameter: CounterLimited_uplimit
   * Referenced by: '<S25>/FixPt Switch'
   */
  11999U,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S34>/Gain'
   */
  0.5F,

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S33>/Gain'
   */
  0.5F,

  /* Computed Parameter: one_by_sqrt3_Gain
   * Referenced by: '<S35>/one_by_sqrt3'
   */
  0.577350259F,

  /* Computed Parameter: Bias_Bias
   * Referenced by: '<S3>/Bias'
   */
  -1.65F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S3>/Gain3'
   */
  -10.0F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S7>/Gain1'
   */
  -0.28F,

  /* Computed Parameter: one_by_two_Gain
   * Referenced by: '<S36>/one_by_two'
   */
  0.5F,

  /* Computed Parameter: sqrt3_by_two_Gain
   * Referenced by: '<S36>/sqrt3_by_two'
   */
  0.866025388F,

  /* Computed Parameter: AvoidDivisionByZero_UpperSat
   * Referenced by: '<S29>/Avoid Division By Zero'
   */
  81.5F,

  /* Computed Parameter: AvoidDivisionByZero_LowerSat
   * Referenced by: '<S29>/Avoid Division By Zero'
   */
  0.1F,

  /* Computed Parameter: Bias_Bias_a
   * Referenced by: '<S29>/Bias'
   */
  0.5F,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S29>/Saturation'
   */
  1.0F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S29>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S29>/Gain2'
   */
  5000.0F,

  /* Computed Parameter: CommandedValue_Y0
   * Referenced by: '<S2>/Commanded Value'
   */
  0.0F,

  /* Computed Parameter: RateTransition_InitialCondition
   * Referenced by: '<Root>/Rate Transition'
   */
  0.0F,

  /* Computed Parameter: Bias_Bias_p
   * Referenced by: '<S12>/Bias'
   */
  5,

  /* Computed Parameter: Bias_Bias_g
   * Referenced by: '<S13>/Bias'
   */
  5,

  /* Computed Parameter: Bias_Bias_c
   * Referenced by: '<S14>/Bias'
   */
  5,

  /* Computed Parameter: PhaseCurrentADCGain_Gain
   * Referenced by: '<S3>/Phase Current ADC Gain'
   */
  13U,

  /* Computed Parameter: DCBusVoltageADCGain_Gain
   * Referenced by: '<S3>/DC Bus Voltage ADC Gain'
   */
  10U,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S25>/Constant'
   */
  0U,

  /* Computed Parameter: End_Value
   * Referenced by: '<S23>/End'
   */
  514U,

  /* Computed Parameter: Start_Value
   * Referenced by: '<S23>/Start'
   */
  257U,

  /* Computed Parameter: Bias_Bias_cx
   * Referenced by: '<S23>/Bias'
   */
  2U,

  /* Computed Parameter: Start_Value_i
   * Referenced by: '<S21>/Start'
   */
  0U,

  /* Computed Parameter: Start1_Value
   * Referenced by: '<S21>/Start1'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S20>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S24>/FixPt Constant'
   */
  1U,

  /* Start of '<S22>/CoreSubsys' */
  {
    /* Start of '<S22>/If Action Subsystem1' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S27>/Constant'
       */
      515U
    }
    ,

    /* End of '<S22>/If Action Subsystem1' */

    /* Start of '<S22>/If Action Subsystem' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S26>/Constant'
       */
      258U
    }
    /* End of '<S22>/If Action Subsystem' */
  }
  /* End of '<S22>/CoreSubsys' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
