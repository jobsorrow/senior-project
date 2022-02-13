/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: datalogger_target.c
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

/* Block signals (default storage) */
B_datalogger_target_T datalogger_target_B;

/* Block states (default storage) */
DW_datalogger_target_T datalogger_target_DW;

/* Real-time model */
static RT_MODEL_datalogger_target_T datalogger_target_M_;
RT_MODEL_datalogger_target_T *const datalogger_target_M = &datalogger_target_M_;
static void rate_monotonic_scheduler(void);
uint16_T MW_adcAInitFlag = 0;
uint16_T MW_adcCInitFlag = 0;
uint16_T MW_adcBInitFlag = 0;

/* Hardware Interrupt Block: '<Root>/C28x Hardware Interrupt ' */
void isr_int1pie1_task_fcn(void)
{
  if (1 == runModel) {
    /* Call the system: <Root>/ADC Interrupt Callback */
    {
      int16_T tmp;

      /* RateTransition: '<Root>/Rate Transition' */
      tmp = datalogger_target_DW.RateTransition_ActiveBufIdx * 3;
      datalogger_target_B.RateTransition[0] =
        datalogger_target_DW.RateTransition_Buffer[tmp];
      datalogger_target_B.RateTransition[1] =
        datalogger_target_DW.RateTransition_Buffer[tmp + 1];
      datalogger_target_B.RateTransition[2] =
        datalogger_target_DW.RateTransition_Buffer[tmp + 2];

      /* S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt ' */

      /* Output and update for function-call system: '<Root>/ADC Interrupt Callback' */
      {
        real_T rtb_Gain3[3];
        real_T elapseTime;
        real_T rtb_Sum_idx_0;
        real_T rtb_TSamp_idx_0;
        real_T rtb_add_b;
        real_T rtb_add_c;
        real32_T rtb_AvoidDivisionByZero;
        uint32_T ADCInterruptCallback_ELAPS_T;
        int16_T s14_iter;
        uint16_T rtb_Merge_h[13];
        uint16_T rtb_Add;
        uint16_T rtb_Merge1;

        /* Asynchronous task reads absolute time. Data (absolute time)
           transfers from low priority task (base rate) to high priority
           task (asynchronous rate). Double buffers are used to ensure
           data integrity.
           -- rtmL2HLastBufWr is the buffer index that is written last.
         */
        datalogger_target_M->Timing.clockTick2 =
          datalogger_target_M->Timing.rtmL2HDbBufClockTick
          [datalogger_target_M->Timing.rtmL2HLastBufWr];
        if (datalogger_target_DW.ADCInterruptCallback_RESET_ELAP) {
          ADCInterruptCallback_ELAPS_T = 0UL;
        } else {
          ADCInterruptCallback_ELAPS_T = datalogger_target_M->Timing.clockTick2
            - datalogger_target_DW.ADCInterruptCallback_PREV_T;
        }

        datalogger_target_DW.ADCInterruptCallback_PREV_T =
          datalogger_target_M->Timing.clockTick2;
        datalogger_target_DW.ADCInterruptCallback_RESET_ELAP = false;

        /* Sum: '<S35>/FixPt Sum1' incorporates:
         *  Constant: '<S35>/FixPt Constant'
         *  UnitDelay: '<S24>/Output'
         */
        datalogger_target_DW.Output_DSTATE +=
          datalogger_target_P.FixPtConstant_Value;

        /* S-Function (c2802xadc): '<S1>/DC Bus ADC' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          datalogger_target_B.DCBusADC = (AdcaResultRegs.ADCRESULT6);
        }

        /* S-Function (c2802xadc): '<S8>/I_C' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          datalogger_target_B.I_C = (AdcaResultRegs.ADCRESULT5);
        }

        /* S-Function (c2802xadc): '<S8>/I_B' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          datalogger_target_B.I_B = (AdccResultRegs.ADCRESULT4);
        }

        /* S-Function (c2802xadc): '<S8>/I_A' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          datalogger_target_B.I_A = (AdccResultRegs.ADCRESULT3);
        }

        /* S-Function (c2802xadc): '<S9>/V_C' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          datalogger_target_B.V_C = (AdccResultRegs.ADCRESULT2);
        }

        /* S-Function (c2802xadc): '<S9>/V_B' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          datalogger_target_B.V_B = (AdccResultRegs.ADCRESULT1);
        }

        /* S-Function (c2802xadc): '<S9>/V_A' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          datalogger_target_B.V_A = (AdcbResultRegs.ADCRESULT0);
        }

        /* If: '<S13>/If' incorporates:
         *  Inport: '<S16>/Data_width'
         *  UnitDelay: '<S15>/Output'
         */
        if (datalogger_target_DW.Output_DSTATE_e == 0U) {
          /* Outputs for IfAction SubSystem: '<S13>/Start' incorporates:
           *  ActionPort: '<S17>/Action Port'
           */
          /* SignalConversion generated from: '<S17>/Data_out' incorporates:
           *  Constant: '<S17>/End'
           *  Constant: '<S17>/Start'
           *  Inport: '<S17>/Data'
           */
          rtb_Merge_h[0] = datalogger_target_P.End_Value;
          rtb_Merge_h[1] = datalogger_target_P.Start_Value;
          rtb_Merge_h[2] = datalogger_target_B.V_A;
          rtb_Merge_h[3] = datalogger_target_B.V_B;
          rtb_Merge_h[4] = datalogger_target_B.V_C;
          rtb_Merge_h[5] = datalogger_target_B.I_A;
          rtb_Merge_h[6] = datalogger_target_B.I_B;
          rtb_Merge_h[7] = datalogger_target_B.I_C;
          rtb_Merge_h[8] = datalogger_target_B.DCBusADC;
          rtb_Merge_h[9] = 0U;
          rtb_Merge_h[10] = 0U;
          rtb_Merge_h[11] = 0U;
          rtb_Merge_h[12] = 0U;

          /* Bias: '<S17>/Bias' */
          rtb_Merge1 = datalogger_target_ConstB.Width +
            datalogger_target_P.Bias_Bias_c;

          /* End of Outputs for SubSystem: '<S13>/Start' */
        } else {
          /* Outputs for IfAction SubSystem: '<S13>/Data' incorporates:
           *  ActionPort: '<S16>/Action Port'
           */
          /* SignalConversion generated from: '<S16>/Data_out' incorporates:
           *  Constant: '<S16>/Start'
           *  Constant: '<S16>/Start1'
           *  Inport: '<S16>/Data'
           */
          rtb_Merge_h[0] = datalogger_target_B.V_A;
          rtb_Merge_h[1] = datalogger_target_B.V_B;
          rtb_Merge_h[2] = datalogger_target_B.V_C;
          rtb_Merge_h[3] = datalogger_target_B.I_A;
          rtb_Merge_h[4] = datalogger_target_B.I_B;
          rtb_Merge_h[5] = datalogger_target_B.I_C;
          rtb_Merge_h[6] = datalogger_target_B.DCBusADC;
          rtb_Merge_h[7] = 0U;
          rtb_Merge_h[8] = 0U;
          rtb_Merge_h[9] = 0U;
          rtb_Merge_h[10] = 0U;
          rtb_Merge_h[11] = datalogger_target_P.Start_Value_i;
          rtb_Merge_h[12] = datalogger_target_P.Start1_Value;
          rtb_Merge1 = datalogger_target_ConstB.Width;

          /* End of Outputs for SubSystem: '<S13>/Data' */
        }

        /* End of If: '<S13>/If' */

        /* Outputs for Iterator SubSystem: '<S4>/Serial Transmit' incorporates:
         *  WhileIterator: '<S14>/While Data Available'
         */
        /* MultiPortSwitch: '<S14>/Index Vector' */
        s14_iter = 0;
        do {
          datalogger_target_B.IndexVector = rtb_Merge_h[s14_iter];

          {
            scia_xmit((char*)&datalogger_target_B.IndexVector, 2, 2);
          }

          rtb_Add = (rtb_Merge1 - s14_iter) - 1U;
          s14_iter++;
        } while (rtb_Add != 0U);

        /* End of Outputs for SubSystem: '<S4>/Serial Transmit' */

        /* Sum: '<S18>/FixPt Sum1' incorporates:
         *  Constant: '<S18>/FixPt Constant'
         *  UnitDelay: '<S15>/Output'
         */
        datalogger_target_DW.Output_DSTATE_e +=
          datalogger_target_P.FixPtConstant_Value_j;

        /* Gain: '<S1>/Gain2' */
        rtb_TSamp_idx_0 = (real_T)datalogger_target_P.Gain2_Gain_o *
          1.4901161193847656E-8;

        /* Gain: '<S1>/Gain3' incorporates:
         *  Bias: '<S1>/Bias'
         *  Gain: '<S1>/Gain2'
         *  SignalConversion generated from: '<S1>/Gain2'
         */
        rtb_Gain3[0] = (rtb_TSamp_idx_0 * (real_T)datalogger_target_B.I_A +
                        datalogger_target_P.Bias_Bias) *
          datalogger_target_P.Gain3_Gain;
        rtb_Gain3[1] = (rtb_TSamp_idx_0 * (real_T)datalogger_target_B.I_B +
                        datalogger_target_P.Bias_Bias) *
          datalogger_target_P.Gain3_Gain;

        /* Outputs for Atomic SubSystem: '<S1>/Clarke Transform' */
        /* Gain: '<S3>/one_by_sqrt3' incorporates:
         *  Sum: '<S3>/a_plus_2b'
         */
        rtb_add_b = ((rtb_Gain3[0] + rtb_Gain3[1]) + rtb_Gain3[1]) *
          datalogger_target_P.one_by_sqrt3_Gain;

        /* End of Outputs for SubSystem: '<S1>/Clarke Transform' */

        /* SampleTimeMath: '<S5>/TSamp'
         *
         * About '<S5>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        elapseTime = (real_T)ADCInterruptCallback_ELAPS_T * 5.0E-5 *
          datalogger_target_P.TSamp_WtEt;

        /* Outputs for Atomic SubSystem: '<S1>/Clarke Transform' */
        /* Sum: '<S22>/Add1' incorporates:
         *  AlgorithmDescriptorDelegate generated from: '<S3>/a16'
         *  Constant: '<S22>/Filter_Constant'
         *  Constant: '<S22>/One'
         *  Product: '<S22>/Product'
         *  Product: '<S22>/Product1'
         *  UnitDelay: '<S22>/Unit Delay'
         */
        datalogger_target_DW.UnitDelay_DSTATE[0] = rtb_Gain3[0] *
          datalogger_target_P.Filter_Constant_Value +
          datalogger_target_P.One_Value * datalogger_target_DW.UnitDelay_DSTATE
          [0];

        /* End of Outputs for SubSystem: '<S1>/Clarke Transform' */

        /* SampleTimeMath: '<S5>/TSamp'
         *
         * About '<S5>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp_idx_0 = datalogger_target_DW.UnitDelay_DSTATE[0] / elapseTime;

        /* Outputs for Atomic SubSystem: '<S1>/Clarke Transform' */
        /* Sum: '<S22>/Add1' incorporates:
         *  AlgorithmDescriptorDelegate generated from: '<S3>/a16'
         *  Constant: '<S22>/Filter_Constant'
         *  Constant: '<S22>/One'
         *  Product: '<S22>/Product'
         *  Product: '<S22>/Product1'
         *  UnitDelay: '<S22>/Unit Delay'
         */
        datalogger_target_DW.UnitDelay_DSTATE[1] = rtb_add_b *
          datalogger_target_P.Filter_Constant_Value +
          datalogger_target_P.One_Value * datalogger_target_DW.UnitDelay_DSTATE
          [1];

        /* End of Outputs for SubSystem: '<S1>/Clarke Transform' */

        /* SampleTimeMath: '<S5>/TSamp'
         *
         * About '<S5>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        elapseTime = datalogger_target_DW.UnitDelay_DSTATE[1] / elapseTime;

        /* Outputs for Atomic SubSystem: '<S1>/Clarke Transform' */
        /* Sum: '<S1>/Sum' incorporates:
         *  AlgorithmDescriptorDelegate generated from: '<S3>/a16'
         *  Gain: '<S1>/Gain1'
         *  Sum: '<S5>/Diff'
         *  UnitDelay: '<S5>/UD'
         *
         * Block description for '<S5>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S5>/UD':
         *
         *  Store in Global RAM
         */
        rtb_Sum_idx_0 = -datalogger_target_P.HW_BLDC_RS * rtb_Gain3[0] +
          (rtb_TSamp_idx_0 - datalogger_target_DW.UD_DSTATE[0]);

        /* End of Outputs for SubSystem: '<S1>/Clarke Transform' */

        /* Gain: '<S7>/one_by_two' */
        rtb_add_c = datalogger_target_P.one_by_two_Gain * rtb_Sum_idx_0;

        /* Outputs for Atomic SubSystem: '<S1>/Clarke Transform' */
        /* Gain: '<S7>/sqrt3_by_two' incorporates:
         *  AlgorithmDescriptorDelegate generated from: '<S3>/a16'
         *  Gain: '<S1>/Gain1'
         *  Sum: '<S1>/Sum'
         *  Sum: '<S5>/Diff'
         *  UnitDelay: '<S5>/UD'
         *
         * Block description for '<S5>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S5>/UD':
         *
         *  Store in Global RAM
         */
        rtb_add_b = (-datalogger_target_P.HW_BLDC_RS * rtb_add_b + (elapseTime -
          datalogger_target_DW.UD_DSTATE[1])) *
          datalogger_target_P.sqrt3_by_two_Gain;

        /* End of Outputs for SubSystem: '<S1>/Clarke Transform' */

        /* Gain: '<S1>/DC Bus Voltage Conditioning' */
        rtb_AvoidDivisionByZero = (real32_T)
          datalogger_target_P.DCBusVoltageConditioning_Gain * 4.76837158E-7F *
          (real32_T)datalogger_target_B.DCBusADC;

        /* Saturate: '<S12>/Avoid Division By Zero' */
        if (rtb_AvoidDivisionByZero >
            datalogger_target_P.AvoidDivisionByZero_UpperSat) {
          rtb_AvoidDivisionByZero =
            datalogger_target_P.AvoidDivisionByZero_UpperSat;
        } else if (rtb_AvoidDivisionByZero <
                   datalogger_target_P.AvoidDivisionByZero_LowerSat) {
          rtb_AvoidDivisionByZero =
            datalogger_target_P.AvoidDivisionByZero_LowerSat;
        }

        /* End of Saturate: '<S12>/Avoid Division By Zero' */

        /* Product: '<S12>/Divide' incorporates:
         *  Sum: '<S7>/add_b'
         *  Sum: '<S7>/add_c'
         */
        rtb_Gain3[0] = rtb_Sum_idx_0 / rtb_AvoidDivisionByZero;
        rtb_Gain3[1] = (rtb_add_b - rtb_add_c) / rtb_AvoidDivisionByZero;
        rtb_Gain3[2] = ((0.0 - rtb_add_c) - rtb_add_b) / rtb_AvoidDivisionByZero;

        /* Gain: '<S12>/Gain2' incorporates:
         *  Bias: '<S12>/Bias'
         */
        rtb_Gain3[0] = (rtb_Gain3[0] + datalogger_target_P.Bias_Bias_a) *
          datalogger_target_P.Gain2_Gain;
        rtb_Gain3[1] = (rtb_Gain3[1] + datalogger_target_P.Bias_Bias_a) *
          datalogger_target_P.Gain2_Gain;
        rtb_Gain3[2] = (rtb_Gain3[2] + datalogger_target_P.Bias_Bias_a) *
          datalogger_target_P.Gain2_Gain;

        /* S-Function (c2802xpwm): '<S10>/ePWM' */

        /*-- Update CMPA value for ePWM1 --*/
        {
          EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Gain3[0]);
        }

        /* S-Function (c2802xpwm): '<S10>/ePWM1' */

        /*-- Update CMPA value for ePWM4 --*/
        {
          EPwm4Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Gain3[1]);
        }

        /* S-Function (c2802xpwm): '<S10>/ePWM2' */

        /*-- Update CMPA value for ePWM2 --*/
        {
          EPwm2Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Gain3[2]);
        }

        /* Switch: '<S36>/FixPt Switch' */
        if (datalogger_target_DW.Output_DSTATE >
            datalogger_target_P.CounterLimited_uplimit) {
          /* Sum: '<S35>/FixPt Sum1' incorporates:
           *  Constant: '<S36>/Constant'
           *  UnitDelay: '<S24>/Output'
           */
          datalogger_target_DW.Output_DSTATE =
            datalogger_target_P.Constant_Value_k;
        }

        /* End of Switch: '<S36>/FixPt Switch' */

        /* Switch: '<S19>/FixPt Switch' */
        if (datalogger_target_DW.Output_DSTATE_e >
            datalogger_target_P.CounterLimited_uplimit_k) {
          /* Sum: '<S18>/FixPt Sum1' incorporates:
           *  Constant: '<S19>/Constant'
           *  UnitDelay: '<S15>/Output'
           */
          datalogger_target_DW.Output_DSTATE_e =
            datalogger_target_P.Constant_Value_m;
        }

        /* End of Switch: '<S19>/FixPt Switch' */

        /* Update for UnitDelay: '<S5>/UD'
         *
         * Block description for '<S5>/UD':
         *
         *  Store in Global RAM
         */
        datalogger_target_DW.UD_DSTATE[0] = rtb_TSamp_idx_0;
        datalogger_target_DW.UD_DSTATE[1] = elapseTime;
      }

      /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt ' */
    }
  }
}

/* Hardware Interrupt Block: '<Root>/C28x Hardware Interrupt ' */
void isr_int9pie1_task_fcn(void)
{
  if (1 == runModel) {
    /* Call the system: <Root>/SCI Receive Interrupt Callback */
    {
      /* S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt ' */

      /* Output and update for function-call system: '<Root>/SCI Receive Interrupt Callback' */

      /* S-Function (c28xsci_rx): '<S2>/SCI Receive' */
      {
        int i;
        int errFlg = NOERROR;
        unsigned int recbuff[6];
        for (i = 0; i < 6; i++)
          recbuff[i] = 0;

        /* Getting Data Head */
        {
          unsigned int recHead;
          int cnt = 0;
          int i = 0;
          char *expHead = "S";
          while (i < 1) {
            scia_rcv(&recHead, 1, SHORTLOOP, 1);
            if (recHead == expHead[i]) {
              i++;
            } else {
              i = 0;
            }

            if (cnt++ > 16) {
              errFlg = TIMEOUT;
              goto RXERRA;
            }
          }
        }

        /* End of Getting Data Head */

        /* Receiving data */
        errFlg = scia_rcv(recbuff, 12, LONGLOOP, 4);
        if (errFlg != NOERROR)
          goto RXERRA;

        /* Getting Data Tail */
        {
          int i;
          char *expTail = "E";
          unsigned int recTail[1];
          scia_rcv(recTail, 1, LONGLOOP, 1);
          for (i = 0; i< 1; i++) {
            if (expTail[i] != recTail[i]) {
              errFlg = DATAERR;
              goto RXERRA;
            }
          }
        }

        /* End of Getting Data Tail */
        memcpy( &datalogger_target_B.SCIReceive[0], recbuff, 6);
       RXERRA:
        asm(" NOP");
      }

      /* Logic: '<S2>/NOT' */
      datalogger_target_B.NOT = !(datalogger_target_B.SCIReceive[2] != 0.0F);

      /* S-Function (c280xgpio_do): '<S2>/Digital Output' */
      {
        if (datalogger_target_B.NOT)
          GpioDataRegs.GPBSET.bit.GPIO33 = 1;
        else
          GpioDataRegs.GPBCLEAR.bit.GPIO33 = 1;
      }

      /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt ' */

      /* RateTransition: '<Root>/Rate Transition' */
      datalogger_target_DW.RateTransition_Buffer
        [(datalogger_target_DW.RateTransition_ActiveBufIdx == 0) * 3] =
        datalogger_target_B.SCIReceive[0];
      datalogger_target_DW.RateTransition_Buffer[1 +
        (datalogger_target_DW.RateTransition_ActiveBufIdx == 0) * 3] =
        datalogger_target_B.SCIReceive[1];
      datalogger_target_DW.RateTransition_Buffer[2 +
        (datalogger_target_DW.RateTransition_ActiveBufIdx == 0) * 3] =
        datalogger_target_B.SCIReceive[2];
      datalogger_target_DW.RateTransition_ActiveBufIdx =
        (datalogger_target_DW.RateTransition_ActiveBufIdx == 0);
    }
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void datalogger_target_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(datalogger_target_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (datalogger_target_M->Timing.TaskCounters.TID[1])++;
  if ((datalogger_target_M->Timing.TaskCounters.TID[1]) > 19999) {/* Sample time: [1.0s, 0.0s] */
    datalogger_target_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void datalogger_target_step0(void)     /* Sample time: [5.0E-5s, 0.0s] */
{
  {                                    /* Sample time: [5.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 5.0E-5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  datalogger_target_M->Timing.clockTick0++;

  {
    /* Base rate updates double buffers of absolute time for
       asynchronous task. Double buffers are used to ensure
       data integrity when asynchronous task reads absolute
       time.
       -- rtmL2HLastBufWr is the buffer index that is written last.
     */
    boolean_T bufIdx = !datalogger_target_M->Timing.rtmL2HLastBufWr;
    datalogger_target_M->Timing.rtmL2HDbBufClockTick[bufIdx] =
      datalogger_target_M->Timing.clockTick0;
    datalogger_target_M->Timing.rtmL2HLastBufWr = bufIdx;
  }
}

/* Model step function for TID1 */
void datalogger_target_step1(void)     /* Sample time: [1.0s, 0.0s] */
{
  /* S-Function (c280xgpio_do): '<Root>/Red LED' incorporates:
   *  Constant: '<Root>/Constant'
   */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO23 = (datalogger_target_P.Constant_Value != 0);
  }
}

/* Model initialize function */
void datalogger_target_initialize(void)
{
  /* Start for S-Function (c280xgpio_do): '<Root>/Red LED' incorporates:
   *  Constant: '<Root>/Constant'
   */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFF3FFF;
  GpioCtrlRegs.GPADIR.all |= 0x800000;
  EDIS;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  datalogger_target_DW.RateTransition_Buffer[0] =
    datalogger_target_P.RateTransition_InitialCondition;
  datalogger_target_DW.RateTransition_Buffer[1] =
    datalogger_target_P.RateTransition_InitialCondition;
  datalogger_target_DW.RateTransition_Buffer[2] =
    datalogger_target_P.RateTransition_InitialCondition;

  /* SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt ' incorporates:
   *  SubSystem: '<Root>/ADC Interrupt Callback'
   */
  /* System initialize for function-call system: '<Root>/ADC Interrupt Callback' */

  /* Asynchronous task reads absolute time. Data (absolute time)
     transfers from low priority task (base rate) to high priority
     task (asynchronous rate). Double buffers are used to ensure
     data integrity.
     -- rtmL2HLastBufWr is the buffer index that is written last.
   */
  datalogger_target_M->Timing.clockTick2 =
    datalogger_target_M->Timing.rtmL2HDbBufClockTick
    [datalogger_target_M->Timing.rtmL2HLastBufWr];

  /* Start for S-Function (c2802xadc): '<S1>/DC Bus ADC' */
  if (MW_adcAInitFlag == 0) {
    InitAdcA();
    MW_adcAInitFlag = 1;
  }

  config_ADCA_SOC6 ();

  /* Start for S-Function (c2802xadc): '<S8>/I_C' */
  if (MW_adcAInitFlag == 0) {
    InitAdcA();
    MW_adcAInitFlag = 1;
  }

  config_ADCA_SOC5 ();

  /* Start for S-Function (c2802xadc): '<S8>/I_B' */
  if (MW_adcCInitFlag == 0) {
    InitAdcC();
    MW_adcCInitFlag = 1;
  }

  config_ADCC_SOC4 ();

  /* Start for S-Function (c2802xadc): '<S8>/I_A' */
  if (MW_adcCInitFlag == 0) {
    InitAdcC();
    MW_adcCInitFlag = 1;
  }

  config_ADCC_SOC3 ();

  /* Start for S-Function (c2802xadc): '<S9>/V_C' */
  if (MW_adcCInitFlag == 0) {
    InitAdcC();
    MW_adcCInitFlag = 1;
  }

  config_ADCC_SOC2 ();

  /* Start for S-Function (c2802xadc): '<S9>/V_B' */
  if (MW_adcCInitFlag == 0) {
    InitAdcC();
    MW_adcCInitFlag = 1;
  }

  config_ADCC_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S9>/V_A' */
  if (MW_adcBInitFlag == 0) {
    InitAdcB();
    MW_adcBInitFlag = 1;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c2802xpwm): '<S10>/ePWM' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select
       EPwm1Regs.TBCTL2.bit.SYNCOSELX           = 0;          // Sync Output Select - additional options

       EPwm1Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm1Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFF) | 0x32;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xF000) | 0x0;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 5000;            // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0;          // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5F) | 0x0;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0;          // Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0;          // Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5F) | 0x0;
    EPwm1Regs.CMPA.bit.CMPA = 0;       // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 32000;   // Counter Compare B Register
    EPwm1Regs.CMPC = 32000;            // Counter Compare C Register
    EPwm1Regs.CMPD = 32000;            // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 150;// Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 0;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0;          // DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0;          // DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFF) | 0x0;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1;
       EPwm1Regs.ETSEL.bit.INTEN                = 0;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7F) | 0x1A01;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30) | 0x30;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0F) | 0x101;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xF) | 0x1;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0;          // Digital Compare B Low COMP Input Select

     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x0;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm1Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 1;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0) | 0x20;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0;          // EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0;          //  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S10>/ePWM1' */

  /*** Initialize ePWM4 modules ***/
  {
    /*  // Time Base Control Register
       EPwm4Regs.TBCTL.bit.CTRMODE              = 2;          // Counter Mode
       EPwm4Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select
       EPwm4Regs.TBCTL2.bit.SYNCOSELX           = 0;          // Sync Output Select - additional options

       EPwm4Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select

       EPwm4Regs.TBCTL2.bit.PRDLDSYNC           = 0;          // Shadow select

       EPwm4Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm4Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm4Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm4Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm4Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm4Regs.TBCTL.all = (EPwm4Regs.TBCTL.all & ~0x3FFF) | 0x32;
    EPwm4Regs.TBCTL2.all = (EPwm4Regs.TBCTL2.all & ~0xF000) | 0x0;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm4Regs.TBPRD = 5000;            // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm4Regs.TBPHS.bit.TBPHS               = 0;          // Phase offset register
     */
    EPwm4Regs.TBPHS.all = (EPwm4Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm4Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm4Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm4Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm4Regs.CMPCTL.bit.SHDWAMODE           = 0;          // Compare A Register Block Operating Mode
       EPwm4Regs.CMPCTL.bit.SHDWBMODE           = 0;          // Compare B Register Block Operating Mode
     */
    EPwm4Regs.CMPCTL.all = (EPwm4Regs.CMPCTL.all & ~0x3C5F) | 0x0;

    /* EPwm4Regs.CMPCTL2.bit.SHDWCMODE           = 0;          // Compare C Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.SHDWDMODE           = 0;          // Compare D Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm4Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm4Regs.CMPCTL2.all = (EPwm4Regs.CMPCTL2.all & ~0x3C5F) | 0x0;
    EPwm4Regs.CMPA.bit.CMPA = 0;       // Counter Compare A Register
    EPwm4Regs.CMPB.bit.CMPB = 32000;   // Counter Compare B Register
    EPwm4Regs.CMPC = 32000;            // Counter Compare C Register
    EPwm4Regs.CMPD = 32000;            // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm4Regs.AQCTLA.all = 150;// Action Qualifier Control Register For Output A
    EPwm4Regs.AQCTLB.all = 2310;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm4Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm4Regs.AQSFRC.all = (EPwm4Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm4Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm4Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm4Regs.AQCSFRC.all = (EPwm4Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm4Regs.DBCTL.bit.OUT_MODE             = 0;          // Dead Band Output Mode Control
       EPwm4Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm4Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm4Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
       EPwm4Regs.DBCTL.bit.SHDWDBREDMODE        = 0;          // DBRED shadow mode
       EPwm4Regs.DBCTL.bit.SHDWDBFEDMODE        = 0;          // DBFED shadow mode
       EPwm4Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm4Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm4Regs.DBCTL.all = (EPwm4Regs.DBCTL.all & ~0x8FFF) | 0x0;
    EPwm4Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm4Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm4Regs.ETSEL.bit.SOCAEN               = 1;          // Start of Conversion A Enable
       EPwm4Regs.ETSEL.bit.SOCASELCMP           = 0;
       EPwm4Regs.ETSEL.bit.SOCASEL              = 2;          // Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM4SOC Period Select
       EPwm4Regs.ETSOCPS.bit.SOCAPRD2           = 1;
       EPwm4Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable
       EPwm4Regs.ETSEL.bit.SOCBSELCMP           = 0;
       EPwm4Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM4SOCB Period Select
       EPwm4Regs.ETSOCPS.bit.SOCBPRD2           = 1;
       EPwm4Regs.ETSEL.bit.INTEN                = 0;          // EPWM4INTn Enable
       EPwm4Regs.ETSEL.bit.INTSELCMP            = 0;
       EPwm4Regs.ETSEL.bit.INTSEL               = 1;          // Start of Conversion A Select
       EPwm4Regs.ETPS.bit.INTPSSEL              = 1;          // EPWM4INTn Period Select
       EPwm4Regs.ETINTPS.bit.INTPRD2            = 1;
     */
    EPwm4Regs.ETSEL.all = (EPwm4Regs.ETSEL.all & ~0xFF7F) | 0x1A01;
    EPwm4Regs.ETPS.all = (EPwm4Regs.ETPS.all & ~0x30) | 0x30;
    EPwm4Regs.ETSOCPS.all = (EPwm4Regs.ETSOCPS.all & ~0xF0F) | 0x101;
    EPwm4Regs.ETINTPS.all = (EPwm4Regs.ETINTPS.all & ~0xF) | 0x1;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm4Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm4Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm4Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm4Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm4Regs.PCCTL.all = (EPwm4Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm4Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm4Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM4A
       EPwm4Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM4B
       EPwm4Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM4A action on DCAEVT1
       EPwm4Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM4A action on DCAEVT2
       EPwm4Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM4B action on DCBEVT1
       EPwm4Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM4B action on DCBEVT2
     */
    EPwm4Regs.TZCTL.all = (EPwm4Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm4Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm4Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm4Regs.TZEINT.all = (EPwm4Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm4Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm4Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm4Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm4Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm4Regs.DCACTL.all = (EPwm4Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm4Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm4Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm4Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm4Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm4Regs.DCBCTL.all = (EPwm4Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm4Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm4Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0;          // Digital Compare A Low COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0;          // Digital Compare B Low COMP Input Select

     */
    EPwm4Regs.DCTRIPSEL.all = (EPwm4Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x0;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm4Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm4Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm4Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm4Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm4Regs.TZDCSEL.all = (EPwm4Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm4Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm4Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm4Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm4Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm4Regs.DCFCTL.all = (EPwm4Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm4Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm4Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm4Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm4Regs.DCCAPCTL.all = (EPwm4Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm4Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm4Regs.HRCNFG.bit.SELOUTB             = 1;          // EPWMB Output Selection Bit
     */
    EPwm4Regs.HRCNFG.all = (EPwm4Regs.HRCNFG.all & ~0xA0) | 0x20;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm4Regs.EPWMXLINK.bit.TBPRDLINK = 0;
    EPwm4Regs.EPWMXLINK.bit.CMPALINK = 3;
    EPwm4Regs.EPWMXLINK.bit.CMPBLINK = 3;
    EPwm4Regs.EPWMXLINK.bit.CMPCLINK = 3;
    EPwm4Regs.EPWMXLINK.bit.CMPDLINK = 3;

    /* SYNCPER - Peripheral synchronization output event
       EPwm4Regs.HRPCTL.bit.PWMSYNCSEL            = 0;          // EPWMSYNCPER selection
       EPwm4Regs.HRPCTL.bit.PWMSYNCSELX           = 0;          //  EPWMSYNCPER selection
     */
    EPwm4Regs.HRPCTL.all = (EPwm4Regs.HRPCTL.all & ~0x72) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S10>/ePWM2' */

  /*** Initialize ePWM2 modules ***/
  {
    /*  // Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select
       EPwm2Regs.TBCTL2.bit.SYNCOSELX           = 0;          // Sync Output Select - additional options

       EPwm2Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select

       EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0;          // Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm2Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFF) | 0x32;
    EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xF000) | 0x0;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 5000;            // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0;          // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0;          // Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0;          // Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5F) | 0x0;

    /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0;          // Compare C Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0;          // Compare D Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5F) | 0x0;
    EPwm2Regs.CMPA.bit.CMPA = 0;       // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 32000;   // Counter Compare B Register
    EPwm2Regs.CMPC = 32000;            // Counter Compare C Register
    EPwm2Regs.CMPD = 32000;            // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 150;// Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 2310;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 0;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
       EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0;          // DBRED shadow mode
       EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0;          // DBFED shadow mode
       EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFF) | 0x0;
    EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 1;          // Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0;
       EPwm2Regs.ETSEL.bit.SOCASEL              = 2;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM2SOC Period Select
       EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1;
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0;
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1;
       EPwm2Regs.ETSEL.bit.INTEN                = 0;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSELCMP            = 0;
       EPwm2Regs.ETSEL.bit.INTSEL               = 1;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.INTPSSEL              = 1;          // EPWM2INTn Period Select
       EPwm2Regs.ETINTPS.bit.INTPRD2            = 1;
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7F) | 0x1A01;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30) | 0x30;
    EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0F) | 0x101;
    EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xF) | 0x1;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0;          // Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0;          // Digital Compare B Low COMP Input Select

     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x0;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm2Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 1;          // EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0) | 0x20;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 0;
    EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1;
    EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1;
    EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1;
    EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1;

    /* SYNCPER - Peripheral synchronization output event
       EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0;          // EPWMSYNCPER selection
       EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0;          //  EPWMSYNCPER selection
     */
    EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72) | 0x0;
    EDIS;
    EALLOW;

    /* Enable TBCLK within the EPWM*/
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;
  }

  /* InitializeConditions for Sum: '<S35>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S24>/Output'
   */
  datalogger_target_DW.Output_DSTATE =
    datalogger_target_P.Output_InitialCondition;

  /* InitializeConditions for Sum: '<S18>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S15>/Output'
   */
  datalogger_target_DW.Output_DSTATE_e =
    datalogger_target_P.Output_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
  datalogger_target_DW.UnitDelay_DSTATE[0] =
    datalogger_target_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S5>/UD'
   *
   * Block description for '<S5>/UD':
   *
   *  Store in Global RAM
   */
  datalogger_target_DW.UD_DSTATE[0] =
    datalogger_target_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
  datalogger_target_DW.UnitDelay_DSTATE[1] =
    datalogger_target_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S5>/UD'
   *
   * Block description for '<S5>/UD':
   *
   *  Store in Global RAM
   */
  datalogger_target_DW.UD_DSTATE[1] =
    datalogger_target_P.DiscreteDerivative_ICPrevScaled;

  /* SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt ' incorporates:
   *  SubSystem: '<Root>/SCI Receive Interrupt Callback'
   */

  /* System initialize for function-call system: '<Root>/SCI Receive Interrupt Callback' */

  /* Start for S-Function (c28xsci_rx): '<S2>/SCI Receive' */

  /* Initialize datalogger_target_B.SCIReceive[0] */
  {
    datalogger_target_B.SCIReceive[0] = (real32_T)0.0;
    datalogger_target_B.SCIReceive[1] = (real32_T)0.0;
    datalogger_target_B.SCIReceive[2] = (real32_T)0.0;
  }

  /* Start for S-Function (c280xgpio_do): '<S2>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFF3;
  GpioCtrlRegs.GPBDIR.all |= 0x2;
  EDIS;

  /* SystemInitialize for S-Function (c28xsci_rx): '<S2>/SCI Receive' incorporates:
   *  Outport: '<S2>/Commanded Value'
   */
  datalogger_target_B.SCIReceive[0] = datalogger_target_P.CommandedValue_Y0;
  datalogger_target_B.SCIReceive[1] = datalogger_target_P.CommandedValue_Y0;
  datalogger_target_B.SCIReceive[2] = datalogger_target_P.CommandedValue_Y0;

  /* End of SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt ' */

  /* Enable for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt ' incorporates:
   *  SubSystem: '<Root>/ADC Interrupt Callback'
   */

  /* Enable for function-call system: '<Root>/ADC Interrupt Callback' */

  /* Asynchronous task reads absolute time. Data (absolute time)
     transfers from low priority task (base rate) to high priority
     task (asynchronous rate). Double buffers are used to ensure
     data integrity.
     -- rtmL2HLastBufWr is the buffer index that is written last.
   */
  datalogger_target_M->Timing.clockTick2 =
    datalogger_target_M->Timing.rtmL2HDbBufClockTick
    [datalogger_target_M->Timing.rtmL2HLastBufWr];
  datalogger_target_DW.ADCInterruptCallback_RESET_ELAP = true;

  /* End of Enable for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt ' */
}

/* Model terminate function */
void datalogger_target_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
