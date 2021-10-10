%This file contains configuration parameters for the genpath model

%% Simulation Related

% Fundamental sample time
SIM_TS = 1e-6;

%% PWM Related

% PWM switching frequency in Hz
PWM_FS = 20e3;
% PWM switching period in s.
PWM_PRD = 1/PWM_FS;
% CPU clock speed in Hz, use to compute time base period
PWM_CPU_CLK = 100e6;
% Time base period in cpu clock cycle
PWM_TIM_BASE_PRD = PWM_CPU_CLK/PWM_FS;

%% Hardware Related

% Battery voltage in V
HW_VBATT = 12;
% hardware sampling time
HW_TS = PWM_PRD;
% adc resolution in bits
HW_ADC_RES = 12;
% adc analog reference in V
HW_ADC_AREF = 3.3;
% BLDC stator resistance in ohm
HW_BLDC_RS = 32.23;
% BLDC direct axis inductance in H
HW_BLDC_LD = 16e-3;
% BLDC quadrature axis inductance in H
HW_BLDC_LQ = 16e-3;
% BLDC Stator inductance
HW_BLDC_LS = 11.3e-3;
% BLDC Pole pairs
HW_BLDC_PP = 6;
% BLDC flux linkage in Wb
HW_BLDC_PHI = 0.009;
% Damping coefficient in N/(m/s)
HW_MECH_B = 13600;
% Hard stop constraint in m
HW_MECH_HS = -0.015;
% Spring coefficient in N/m
HW_MECH_KS = 40e3;
% Pitch of Lead Screw in m
HW_MECH_PITCH = 8e-3;
%% HIL Related

HIL_ENABLE = Simulink.Parameter(0);


%% Development Related

% voltage source inverter command voltage amplitude in V
VSI_AMP = 6;
% voltage source inverter command frequency in Hz
VSI_FREQ = 50;