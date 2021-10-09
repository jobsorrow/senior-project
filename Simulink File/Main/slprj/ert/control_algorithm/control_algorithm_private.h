/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_algorithm_private.h
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

#ifndef RTW_HEADER_control_algorithm_private_h_
#define RTW_HEADER_control_algorithm_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtm)->timingBridge->taskCounter[(rtm)->Timing.mdlref_GlobalTID[sti]] == 0)
#endif

/* Macros for accessing real-time model data structure */
#ifndef rtmGetClockTick0
#define rtmGetClockTick0(rtm)          ( *(((rtm)->timingBridge->clockTick[(rtm)->Timing.mdlref_GlobalTID[0]])) )
#endif

#ifndef rtmGetClockTickH0
#define rtmGetClockTickH0(rtm)         ( *((rtm)->timingBridge->clockTickH[(rtm)->Timing.mdlref_GlobalTID[0]]) )
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (*((rtm)->timingBridge->taskTime[0]))
#endif

extern P_control_algorithm_T control_algorithm_P;

#endif                             /* RTW_HEADER_control_algorithm_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
