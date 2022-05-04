/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'genpath_firmware_ac'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr 28 12:44:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#include "genpath_firmware_ac.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    executeOverrunService();
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates that need to run this time step.
   * The return values are 1 and 0 for true and false, respectively.
   */
  genpath_firmware_ac_SetEventsForThisBaseStep(eventFlags);
  enableTimer0Interrupt();
  genpath_firmware_ac_step0();

  /* Get model outputs here */
  disableTimer0Interrupt();
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      executeOverrunService();
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    enableTimer0Interrupt();

    /* Step the model for subrate "1" */
    switch (1)
    {
     case 1 :
      genpath_firmware_ac_step1();

      /* Get model outputs here */
      break;

     default :
      break;
    }

    disableTimer0Interrupt();
    need2runFlags[1]--;
    isRateRunning[1]--;
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 5.0E-5;
  float systemClock = 100;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  c2000_flash_init();
  init_board();

#if defined(MW_EXEC_PROFILER_ON) || defined(MW_EXTMODE_RUNNING)

  hardwareTimer1Init();

#endif

  ;
  rtmSetErrorStatus(genpath_firmware_ac_M, 0);
  genpath_firmware_ac_initialize();
  initializeOverrunService();
  globalInterruptDisable();
  configureTimer0(modelBaseRate, systemClock);
  runModel = rtmGetErrorStatus(genpath_firmware_ac_M) == (NULL);
  enableTimer0Interrupt();
  enable_interrupts();
  globalInterruptEnable();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(genpath_firmware_ac_M) == (NULL));
  }

  /* Terminate model */
  genpath_firmware_ac_terminate();
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
