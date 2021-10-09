%This file contains configuration parameters for the genpath model

%% Simulation Related

%Fundamental sample time
SIM_TS = 1e-6;

%% PWM Related

%PWM switching frequency in Hz
PWM_FS = 20e3;
%PWM switching period
PWM_PRD = 1/PWM_FS;
%CPU clock speed in Hz, use to compute time base period.
PWM_CPU_CLK = 100e6;
%Time base period in cpu clock cycle
PWM_TIM_BASE_PRD = PWM_CPU_CLK/PWM_FS;

%% Hardware Related

% Battery voltage
HW_VBATT = 12;
HW_TS = PWM_PRD;
%% HIL Related

HIL_ENABLE = Simulink.Parameter(0);


%% Development Related

% voltage source inverter command voltage amplitude in V
VSI_AMP = 6;
% voltage source inverter command frequency in Hz
VSI_FREQ = 50;