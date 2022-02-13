#include "c2000BoardSupport.h"
#include "f28004x_device.h"
#include "f28004x_examples.h"
#include "f28004x_globalprototypes.h"
#include "rtwtypes.h"
#include "datalogger_target.h"
#include "datalogger_target_private.h"
#include "MW_c28xGPIO.h"

void configureIXbar(void)
{
  /*--- Configuring GPIO set in Input Xbar---*/
  EALLOW;
  InputXbarRegs.INPUT7SELECT = 35;
  InputXbarRegs.INPUT8SELECT = 37;
  InputXbarRegs.INPUT9SELECT = 59;
  InputXbarRegs.INPUT10SELECT = 14;
  InputXbarRegs.INPUT11SELECT = 15;
  InputXbarRegs.INPUT12SELECT = 26;
  InputXbarRegs.INPUT13SELECT = 58;
  EDIS;
}
