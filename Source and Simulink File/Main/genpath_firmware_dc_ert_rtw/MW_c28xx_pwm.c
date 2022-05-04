#include "c2000BoardSupport.h"
#include "MW_f28004x_includes.h"
#include "rtwtypes.h"
#include "genpath_firmware_dc.h"
#include "genpath_firmware_dc_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;

  /*-- Configure pin assignments for ePWM1 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO0 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;  /* Configure GPIOGPIO0 as EPWM1A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO1 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;  /* Configure GPIOGPIO1 as EPWM1B*/

  /*-- Configure pin assignments for ePWM4 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO6 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;  /* Configure GPIOGPIO6 as EPWM4A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO7 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;  /* Configure GPIOGPIO7 as EPWM4B*/
  EDIS;
}
