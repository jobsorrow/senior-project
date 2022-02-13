#include "c2000BoardSupport.h"
#include "f28004x_device.h"
#include "f28004x_examples.h"
#include "f28004x_globalprototypes.h"
#include "rtwtypes.h"
#include "datalogger_target.h"
#include "datalogger_target_private.h"

void enableExtInterrupt (void);
void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

interrupt void ADCA1_INT_isr(void)
{
  isr_int1pie1_task_fcn();
  EALLOW;
  AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;
  EDIS;
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
                                     /* Acknowledge to receive more interrupts*/
}

interrupt void SCIA_RX_INT_isr(void)
{
  isr_int9pie1_task_fcn();
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFINTCLR = 1;
  EDIS;
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
                                     /* Acknowledge to receive more interrupts*/
}

void enable_interrupts()
{
  EALLOW;
  PieVectTable.ADCA1_INT = &ADCA1_INT_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER1.bit.INTx1 = 1;   /* Enable interrupt ADCA1_INT*/
  IER |= M_INT1;
  EALLOW;
  PieVectTable.SCIA_RX_INT = &SCIA_RX_INT_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER9.bit.INTx1 = 1;   /* Enable interrupt SCIA_RX_INT*/
  IER |= M_INT9;

  /* Enable global Interrupts and higher priority real-time debug events:*/
  EINT;                                /* Enable Global interrupt INTM*/
  ERTM;                               /* Enable Global realtime interrupt DBGM*/
}

void init_SCI(void)
{                                      /* initialize SCI & FIFO registers */
  EALLOW;

  /*
   * Initialize SCI_A with following parameters:
   *    BaudRate              : 6250000
   *    CharacterLengthBits   : 8
   *    EnableLoopBack        : 0
   *    NumberOfStopBits      : 1
   *    ParityMode            : None
   *    SuspensionMode        : Free_run
   *    CommMode              : Raw_data
   */
  CpuSysRegs.PCLKCR7.bit.SCI_A = 1;
  asm(" NOP");
  SciaRegs.SCICCR.bit.STOPBITS = 0;
                    /*Number of stop bits. (0: One stop bit, 1: Two stop bits)*/
  SciaRegs.SCICCR.bit.PARITY = 0;/*Parity mode (0: Odd parity, 1: Even parity)*/
  SciaRegs.SCICCR.bit.PARITYENA = 0;   /*Enable Pary Mode */
  SciaRegs.SCICCR.bit.LOOPBKENA = 0;   /*Loop Back enable*/
  SciaRegs.SCICCR.bit.ADDRIDLE_MODE = 0;/*ADDR/IDLE Mode control*/
  SciaRegs.SCICCR.bit.SCICHAR = 7;     /*Character length*/
  SciaRegs.SCICTL1.bit.RXERRINTENA = 0;/*Disable receive error interrupt*/
  SciaRegs.SCICTL1.bit.SWRESET = 1;    /*Software reset*/
  SciaRegs.SCICTL1.bit.TXENA = 1;      /* SCI transmitter enable*/
  SciaRegs.SCICTL1.bit.RXENA = 1;      /* SCI receiver enable*/
  SciaRegs.SCIHBAUD.bit.BAUD = 0U;
  SciaRegs.SCILBAUD.bit.BAUD = 1U;

  /*Free run, continue SCI operation regardless of suspend*/
  SciaRegs.SCIPRI.bit.FREESOFT = 3;
  SciaRegs.SCIFFCT.bit.ABDCLR = 0;
  SciaRegs.SCIFFCT.bit.CDC = 0;
  SciaRegs.SCIFFTX.bit.SCIRST = 1;     /* SCI reset rx/tx channels*/
  SciaRegs.SCIFFTX.bit.SCIFFENA = 1;   /* SCI FIFO enhancements are enabled.*/
  SciaRegs.SCIFFTX.bit.TXFIFORESET = 1;/* Re-enable transmit FIFO operation.*/
  SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;/* Re-enable receive FIFO operation.*/
  SciaRegs.SCIFFRX.bit.RXFFIENA = 1;
  SciaRegs.SCIFFRX.bit.RXFFIL = 6;
  SciaRegs.SCICTL1.bit.RXERRINTENA = 1;
  /*Enable receive error interrupt by default if receive FIFO interrupt is enabled*/
  EDIS;
}

void init_SCI_GPIO(void)
{
  EALLOW;
  GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;/*Asynch input GPIO28 SCIRXDA*/
  GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;  /*Enable pull-up for GPIO28*/
  GpioCtrlRegs.GPAGMUX2.bit.GPIO28 = 0;
  GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1; /*Configure GPIO28 as SCIRXDA*/
  GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;  /*Enable pull-up for GPIO29*/
  GpioCtrlRegs.GPAGMUX2.bit.GPIO29 = 0;
  GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1; /*Configure GPIO29 as SCITXDA*/
  EDIS;
}
