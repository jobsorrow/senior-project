#include "MW_target_hardware_resources.h"
#include "MW_c28xGPIO.h"

void initializeOverrunService()
{

#ifdef CPU2

  Set_GPIOPin(34, GPIO_MUX_CPU2, 0, GPIO_OUTPUT, 0);

#else

  Set_GPIOPin(34, GPIO_MUX_CPU1, 0, GPIO_OUTPUT, 0);

#endif

  GPIO_WritePin(34, 0);
}

void executeOverrunService()
{
  GPIO_TogglePin(34);
}
