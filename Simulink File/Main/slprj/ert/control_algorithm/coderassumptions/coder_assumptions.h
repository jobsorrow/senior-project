/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "control_algorithm_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_control_algorithm_ExpHW
#define CA_Actual_HWImpl               CA_control_algorithm_ActHW
#define CA_HWImpl_Results              CA_control_algorithm_HWRes
#define CA_PortableWordSizes_Results   CA_control_algorithm_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   control_algorithm_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
