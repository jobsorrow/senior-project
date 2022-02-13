#include "c2000BoardSupport.h"
#include "f28004x_device.h"
#include "f28004x_examples.h"
#include "f28004x_globalprototypes.h"
#include "rtwtypes.h"
#include "datalogger_target.h"
#include "datalogger_target_private.h"

void init_board ()
{
  DisableDog();
  EALLOW;
  CpuSysRegs.PCLKCR0.bit.DMA = 1;
  CpuSysRegs.PCLKCR6.bit.SD1 = 1;
  EDIS;

#ifdef CPU1

  EALLOW;
  EDIS;
  MW_InitSysPll(XTAL_OSC,10,0,0,1);

  //Turn on all peripherals
  //InitPeripheralClocks();
  EALLOW;
  CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1;
  CpuSysRegs.PCLKCR0.bit.CPUTIMER1 = 1;
  CpuSysRegs.PCLKCR0.bit.CPUTIMER2 = 1;
  CpuSysRegs.PCLKCR0.bit.HRPWM = 1;
  EDIS;

#endif

  EALLOW;

  /* Configure low speed peripheral clocks */
  ClkCfgRegs.LOSPCP.bit.LSPCLKDIV = 0U;
  EDIS;

  /* Disable and clear all CPU interrupts */
  DINT;
  IER = 0x0000;
  IFR = 0x0000;
  InitPieCtrl();
  InitPieVectTable();
  init_SCI();
  init_SCI_GPIO();
  InitCpuTimers();

  /* initial ePWM GPIO assignment... */
  config_ePWM_GPIO();
  EALLOW;

  /* Enable clock to ePWM */
  CpuSysRegs.PCLKCR2.bit.EPWM1 = 1;
  CpuSysRegs.PCLKCR2.bit.EPWM4 = 1;
  CpuSysRegs.PCLKCR2.bit.EPWM2 = 1;

  /* Disable TBCLK within ePWM before module configuration */
  CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
  EDIS;
  configureIXbar();

  /* initial GPIO qualification settings.... */
  EALLOW;
  GpioCtrlRegs.GPAQSEL1.all = 0x0;
  GpioCtrlRegs.GPAQSEL2.all = 0x0;
  GpioCtrlRegs.GPBQSEL1.all = 0x0;
  GpioCtrlRegs.GPBQSEL2.all = 0x0;

  // Set the pin to digital mode by default
  GpioCtrlRegs.GPAAMSEL.bit.GPIO22 = 0;
  GpioCtrlRegs.GPAAMSEL.bit.GPIO23 = 0;
  EDIS;
}
