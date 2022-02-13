/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: datalogger_target_data.c
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

#include "datalogger_target.h"
#include "datalogger_target_private.h"

/* Invariant block signals (default storage) */
const ConstB_datalogger_target_T datalogger_target_ConstB = {
  11U                                  /* '<S13>/Width' */
};

/* Block parameters (default storage) */
P_datalogger_target_T datalogger_target_P = {
  /* Variable: HW_BLDC_RS
   * Referenced by: '<S1>/Gain1'
   */
  0.28,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S5>/UD'
   */
  0.0,

  /* Mask Parameter: CounterLimited_uplimit
   * Referenced by: '<S36>/FixPt Switch'
   */
  19999U,

  /* Mask Parameter: CounterLimited_uplimit_k
   * Referenced by: '<S19>/FixPt Switch'
   */
  11999U,

  /* Expression: 1/sqrt(3)
   * Referenced by: '<S3>/one_by_sqrt3'
   */
  0.57735026918962584,

  /* Expression: -1.65
   * Referenced by: '<S1>/Bias'
   */
  -1.65,

  /* Expression: -10
   * Referenced by: '<S1>/Gain3'
   */
  -10.0,

  /* Expression: Filter_constant
   * Referenced by: '<S22>/Filter_Constant'
   */
  0.5,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S22>/One'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S22>/Unit Delay'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S5>/TSamp'
   */
  10101.010101010103,

  /* Expression: 1/2
   * Referenced by: '<S7>/one_by_two'
   */
  0.5,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S7>/sqrt3_by_two'
   */
  0.8660254037844386,

  /* Expression: 0.5
   * Referenced by: '<S12>/Bias'
   */
  0.5,

  /* Expression: 5000
   * Referenced by: '<S12>/Gain2'
   */
  5000.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S25>/Out1'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S32>/Constant'
   */
  0.0F,

  /* Computed Parameter: convert_pu_Gain
   * Referenced by: '<S31>/convert_pu'
   */
  1.0F,

  /* Computed Parameter: AvoidDivisionByZero_UpperSat
   * Referenced by: '<S12>/Avoid Division By Zero'
   */
  24.0F,

  /* Computed Parameter: AvoidDivisionByZero_LowerSat
   * Referenced by: '<S12>/Avoid Division By Zero'
   */
  0.1F,

  /* Computed Parameter: CommandedValue_Y0
   * Referenced by: '<S2>/Commanded Value'
   */
  0.0F,

  /* Computed Parameter: RateTransition_InitialCondition
   * Referenced by: '<Root>/Rate Transition'
   */
  0.0F,

  /* Computed Parameter: DCBusVoltageConditioning_Gain
   * Referenced by: '<S1>/DC Bus Voltage Conditioning'
   */
  41733U,

  /* Computed Parameter: Gain2_Gain_o
   * Referenced by: '<S1>/Gain2'
   */
  54067U,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S11>/Gain'
   */
  53687U,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S19>/Constant'
   */
  0U,

  /* Computed Parameter: End_Value
   * Referenced by: '<S17>/End'
   */
  65535U,

  /* Computed Parameter: Start_Value
   * Referenced by: '<S17>/Start'
   */
  65278U,

  /* Computed Parameter: Bias_Bias_c
   * Referenced by: '<S17>/Bias'
   */
  2U,

  /* Computed Parameter: Start_Value_i
   * Referenced by: '<S16>/Start'
   */
  0U,

  /* Computed Parameter: Start1_Value
   * Referenced by: '<S16>/Start1'
   */
  0U,

  /* Computed Parameter: Constant_Value_k
   * Referenced by: '<S36>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S24>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S35>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition_a
   * Referenced by: '<S15>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value_j
   * Referenced by: '<S18>/FixPt Constant'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
