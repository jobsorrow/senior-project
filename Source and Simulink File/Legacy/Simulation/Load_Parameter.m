
%-------------Mechanical parameter----------------------------

l  = 0.015;      %pitch m/rev
JG = 8.675e-7;  %kg*m^2
Jl = 2.5536e-6; %kg*m^2
m  = 2.16;      %kg
nthre = 0.8;
nthru = 1.2;
a = l/(2*pi)/nthre/nthru;
Jeq = m*l/(2*pi)+(JG+Jl)/a;
k = 40000;  %N/m
d = 13600;    %N*Sec/m

%--------------Electrical parameter----------------------------
RL = 32.23;    %ohm
RG = 32.23;    %ohm
Ls = 11.3e-3;   %H
Lq = 16e-3;    %H
Ld = 16e-3;    %H

Polepairs = 6;
PermanentMagnetFlux = 0.009;

fh = 100; %derivartive cutoff
w_h = 2*pi*fh;
Th = 1/w_h;

damp_coeff = (a*d*l)/(2*pi);
pwm_sampling_freq = 16e3;

%-------------------Discretized-------------------
Ts = 1/pwm_sampling_freq;
A = -(RG*Ts)/(RG*Th-Ls);
B = -Ts/Th;


