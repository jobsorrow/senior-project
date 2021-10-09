/*
 * File: control_algorithm_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef CONTROL_ALGORITHM_CA_H
#define CONTROL_ALGORITHM_CA_H

/* preprocessor validation checks */
#include "control_algorithm_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_control_algorithm_HWRes;
extern CA_PWS_TestResults CA_control_algorithm_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_control_algorithm_ExpHW;
extern CA_HWImpl CA_control_algorithm_ActHW;

/* entry point function to run tests */
void control_algorithm_caRunTests(void);

#endif                                 /* CONTROL_ALGORITHM_CA_H */
