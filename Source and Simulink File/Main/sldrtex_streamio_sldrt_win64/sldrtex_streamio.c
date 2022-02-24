/*
 * sldrtex_streamio.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sldrtex_streamio".
 *
 * Model version              : 2.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Thu Feb 24 15:21:22 2022
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sldrtex_streamio.h"
#include "sldrtex_streamio_private.h"
#include "sldrtex_streamio_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  1.0,
  36864.0,
  108.0,
  111.0,
  99.0,
  97.0,
  108.0,
  104.0,
  111.0,
  115.0,
  116.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* options for Simulink Desktop Real-Time board 1 */
static double SLDRTBoardOptions1[] = {
  0.0,
  36880.0,
  108.0,
  111.0,
  99.0,
  97.0,
  108.0,
  104.0,
  111.0,
  115.0,
  116.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 2;
SLDRTBOARD SLDRTBoards[2] = {
  { "Standard_Devices/TCP_Protocol", 36880U, 256, SLDRTBoardOptions0 },

  { "Standard_Devices/TCP_Protocol", 36864U, 256, SLDRTBoardOptions1 },
};

/* Block signals (default storage) */
B_sldrtex_streamio_T sldrtex_streamio_B;

/* Block states (default storage) */
DW_sldrtex_streamio_T sldrtex_streamio_DW;

/* Real-time model */
static RT_MODEL_sldrtex_streamio_T sldrtex_streamio_M_;
RT_MODEL_sldrtex_streamio_T *const sldrtex_streamio_M = &sldrtex_streamio_M_;

/* Model output function */
void sldrtex_streamio_output(void)
{
  real_T SineWavedouble_tmp;
  real_T SineWavedouble_tmp_0;
  int32_T i;

  /* S-Function (sldrtsi): '<Root>/Stream Input' */
  /* S-Function Block: <Root>/Stream Input */
  {
    char indata[1388U];
    int status;
    const char* terminators = "\r\0\n\0";
    memset(indata, 0, sizeof(indata));
    status = RTBIO_DriverIO(0, STREAMINPUT, IOREADWITHRESET, 1387U, NULL,
      (double*) indata, terminators);
    if (status & 0x1) {
      real32_T var0;
      real32_T var1;
      real32_T var2;
      real32_T var3;
      int32_T var4;
      int32_T var5;
      int32_T var6;
      int32_T var7;
      int32_T var8;
      int32_T var9;
      int32_T var10;
      int32_T var11;
      int nscan = sscanf(indata, "%f %f %f %f %d %d %d %d %d %d %d %d", &var0,
                         &var1, &var2, &var3, &var4, &var5, &var6, &var7, &var8,
                         &var9, &var10, &var11);
      if (nscan > 0)
        sldrtex_streamio_B.StreamInput_o1[0] = (real_T) var0;
      if (nscan > 1)
        sldrtex_streamio_B.StreamInput_o1[1] = (real_T) var1;
      if (nscan > 2)
        sldrtex_streamio_B.StreamInput_o1[2] = (real_T) var2;
      if (nscan > 3)
        sldrtex_streamio_B.StreamInput_o1[3] = (real_T) var3;
      if (nscan > 4)
        sldrtex_streamio_B.StreamInput_o2[0] = (int8_T) var4;
      if (nscan > 5)
        sldrtex_streamio_B.StreamInput_o2[1] = (int8_T) var5;
      if (nscan > 6)
        sldrtex_streamio_B.StreamInput_o2[2] = (int8_T) var6;
      if (nscan > 7)
        sldrtex_streamio_B.StreamInput_o2[3] = (int8_T) var7;
      if (nscan > 8)
        sldrtex_streamio_B.StreamInput_o2[4] = (int8_T) var8;
      if (nscan > 9)
        sldrtex_streamio_B.StreamInput_o2[5] = (int8_T) var9;
      if (nscan > 10)
        sldrtex_streamio_B.StreamInput_o2[6] = (int8_T) var10;
      if (nscan > 11)
        sldrtex_streamio_B.StreamInput_o2[7] = (int8_T) var11;
    }
  }

  /* S-Function (sldrtso): '<Root>/Stream Output' */
  /* S-Function Block: <Root>/Stream Output */

  /* no code required */

  /* Sin: '<Root>/Sine Wave (double)' incorporates:
   *  Sin: '<Root>/Sine Wave (int8)'
   */
  SineWavedouble_tmp = sldrtex_streamio_M->Timing.t[0];
  SineWavedouble_tmp_0 = sin(sldrtex_streamio_P.SineWavedouble_Freq *
    SineWavedouble_tmp + sldrtex_streamio_P.SineWavedouble_Phase);

  /* Sin: '<Root>/Sine Wave (double)' */
  sldrtex_streamio_B.SineWavedouble[0] = SineWavedouble_tmp_0 *
    sldrtex_streamio_P.SineWavedouble_Amp[0] +
    sldrtex_streamio_P.SineWavedouble_Bias;
  sldrtex_streamio_B.SineWavedouble[1] = SineWavedouble_tmp_0 *
    sldrtex_streamio_P.SineWavedouble_Amp[1] +
    sldrtex_streamio_P.SineWavedouble_Bias;
  sldrtex_streamio_B.SineWavedouble[2] = SineWavedouble_tmp_0 *
    sldrtex_streamio_P.SineWavedouble_Amp[2] +
    sldrtex_streamio_P.SineWavedouble_Bias;
  sldrtex_streamio_B.SineWavedouble[3] = SineWavedouble_tmp_0 *
    sldrtex_streamio_P.SineWavedouble_Amp[3] +
    sldrtex_streamio_P.SineWavedouble_Bias;
  for (i = 0; i < 8; i++) {
    /* Sin: '<Root>/Sine Wave (int8)' */
    sldrtex_streamio_B.SineWaveint8[i] = sin
      (sldrtex_streamio_P.SineWaveint8_Freq * SineWavedouble_tmp +
       sldrtex_streamio_P.SineWaveint8_Phase) *
      sldrtex_streamio_P.SineWaveint8_Amp[i] +
      sldrtex_streamio_P.SineWaveint8_Bias;
  }
}

/* Model update function */
void sldrtex_streamio_update(void)
{
  /* Update for S-Function (sldrtso): '<Root>/Stream Output' */

  /* S-Function Block: <Root>/Stream Output */
  {
    char_T outstring[1388U];
    int n = snprintf(outstring, 1388U, "%g %g %g %g %d %d %d %d %d %d %d %d\n",
                     (real_T) sldrtex_streamio_B.SineWavedouble[0], (real_T)
                     sldrtex_streamio_B.SineWavedouble[1], (real_T)
                     sldrtex_streamio_B.SineWavedouble[2], (real_T)
                     sldrtex_streamio_B.SineWavedouble[3], (int32_T)
                     sldrtex_streamio_B.SineWaveint8[0], (int32_T)
                     sldrtex_streamio_B.SineWaveint8[1], (int32_T)
                     sldrtex_streamio_B.SineWaveint8[2], (int32_T)
                     sldrtex_streamio_B.SineWaveint8[3], (int32_T)
                     sldrtex_streamio_B.SineWaveint8[4], (int32_T)
                     sldrtex_streamio_B.SineWaveint8[5], (int32_T)
                     sldrtex_streamio_B.SineWaveint8[6], (int32_T)
                     sldrtex_streamio_B.SineWaveint8[7]);
    RTBIO_DriverIO(1, STREAMOUTPUT, IOWRITE, n, NULL, (double*) outstring, NULL);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++sldrtex_streamio_M->Timing.clockTick0)) {
    ++sldrtex_streamio_M->Timing.clockTickH0;
  }

  sldrtex_streamio_M->Timing.t[0] = sldrtex_streamio_M->Timing.clockTick0 *
    sldrtex_streamio_M->Timing.stepSize0 +
    sldrtex_streamio_M->Timing.clockTickH0 *
    sldrtex_streamio_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++sldrtex_streamio_M->Timing.clockTick1)) {
      ++sldrtex_streamio_M->Timing.clockTickH1;
    }

    sldrtex_streamio_M->Timing.t[1] = sldrtex_streamio_M->Timing.clockTick1 *
      sldrtex_streamio_M->Timing.stepSize1 +
      sldrtex_streamio_M->Timing.clockTickH1 *
      sldrtex_streamio_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void sldrtex_streamio_initialize(void)
{
  /* Start for S-Function (sldrtso): '<Root>/Stream Output' */

  /* S-Function Block: <Root>/Stream Output */
  /* no initial value should be set */
}

/* Model terminate function */
void sldrtex_streamio_terminate(void)
{
  /* Terminate for S-Function (sldrtso): '<Root>/Stream Output' */

  /* no final value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  sldrtex_streamio_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  sldrtex_streamio_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  sldrtex_streamio_initialize();
}

void MdlTerminate(void)
{
  sldrtex_streamio_terminate();
}

/* Registration function */
RT_MODEL_sldrtex_streamio_T *sldrtex_streamio(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  sldrtex_streamio_P.StreamInput_MaxMissedTicks = rtInf;
  sldrtex_streamio_P.StreamOutput_MaxMissedTicks = rtInf;

  /* initialize real-time model */
  (void) memset((void *)sldrtex_streamio_M, 0,
                sizeof(RT_MODEL_sldrtex_streamio_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sldrtex_streamio_M->solverInfo,
                          &sldrtex_streamio_M->Timing.simTimeStep);
    rtsiSetTPtr(&sldrtex_streamio_M->solverInfo, &rtmGetTPtr(sldrtex_streamio_M));
    rtsiSetStepSizePtr(&sldrtex_streamio_M->solverInfo,
                       &sldrtex_streamio_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&sldrtex_streamio_M->solverInfo, (&rtmGetErrorStatus
      (sldrtex_streamio_M)));
    rtsiSetRTModelPtr(&sldrtex_streamio_M->solverInfo, sldrtex_streamio_M);
  }

  rtsiSetSimTimeStep(&sldrtex_streamio_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&sldrtex_streamio_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = sldrtex_streamio_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    sldrtex_streamio_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    sldrtex_streamio_M->Timing.sampleTimes =
      (&sldrtex_streamio_M->Timing.sampleTimesArray[0]);
    sldrtex_streamio_M->Timing.offsetTimes =
      (&sldrtex_streamio_M->Timing.offsetTimesArray[0]);

    /* task periods */
    sldrtex_streamio_M->Timing.sampleTimes[0] = (0.0);
    sldrtex_streamio_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    sldrtex_streamio_M->Timing.offsetTimes[0] = (0.0);
    sldrtex_streamio_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(sldrtex_streamio_M, &sldrtex_streamio_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = sldrtex_streamio_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    sldrtex_streamio_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(sldrtex_streamio_M, 10.0);
  sldrtex_streamio_M->Timing.stepSize0 = 0.01;
  sldrtex_streamio_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  sldrtex_streamio_M->Sizes.checksums[0] = (2186423985U);
  sldrtex_streamio_M->Sizes.checksums[1] = (3877369020U);
  sldrtex_streamio_M->Sizes.checksums[2] = (684061439U);
  sldrtex_streamio_M->Sizes.checksums[3] = (3093044432U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    sldrtex_streamio_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(sldrtex_streamio_M->extModeInfo,
      &sldrtex_streamio_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sldrtex_streamio_M->extModeInfo,
                        sldrtex_streamio_M->Sizes.checksums);
    rteiSetTPtr(sldrtex_streamio_M->extModeInfo, rtmGetTPtr(sldrtex_streamio_M));
  }

  sldrtex_streamio_M->solverInfoPtr = (&sldrtex_streamio_M->solverInfo);
  sldrtex_streamio_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&sldrtex_streamio_M->solverInfo, 0.01);
  rtsiSetSolverMode(&sldrtex_streamio_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  sldrtex_streamio_M->blockIO = ((void *) &sldrtex_streamio_B);
  (void) memset(((void *) &sldrtex_streamio_B), 0,
                sizeof(B_sldrtex_streamio_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      sldrtex_streamio_B.SineWaveint8[i] = 0.0;
    }

    sldrtex_streamio_B.StreamInput_o1[0] = 0.0;
    sldrtex_streamio_B.StreamInput_o1[1] = 0.0;
    sldrtex_streamio_B.StreamInput_o1[2] = 0.0;
    sldrtex_streamio_B.StreamInput_o1[3] = 0.0;
    sldrtex_streamio_B.SineWavedouble[0] = 0.0;
    sldrtex_streamio_B.SineWavedouble[1] = 0.0;
    sldrtex_streamio_B.SineWavedouble[2] = 0.0;
    sldrtex_streamio_B.SineWavedouble[3] = 0.0;
  }

  /* parameters */
  sldrtex_streamio_M->defaultParam = ((real_T *)&sldrtex_streamio_P);

  /* states (dwork) */
  sldrtex_streamio_M->dwork = ((void *) &sldrtex_streamio_DW);
  (void) memset((void *)&sldrtex_streamio_DW, 0,
                sizeof(DW_sldrtex_streamio_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    sldrtex_streamio_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  sldrtex_streamio_M->Sizes.numContStates = (0);/* Number of continuous states */
  sldrtex_streamio_M->Sizes.numY = (0);/* Number of model outputs */
  sldrtex_streamio_M->Sizes.numU = (0);/* Number of model inputs */
  sldrtex_streamio_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  sldrtex_streamio_M->Sizes.numSampTimes = (2);/* Number of sample times */
  sldrtex_streamio_M->Sizes.numBlocks = (6);/* Number of blocks */
  sldrtex_streamio_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  sldrtex_streamio_M->Sizes.numBlockPrms = (22);/* Sum of parameter "widths" */
  return sldrtex_streamio_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
