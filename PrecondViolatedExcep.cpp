// Dalton Wright
// CSCI 301 01
// Project #6
// PrecondViolatedExcep.cpp

#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message): logic_error("Precondition Violated Exception: " + message)
{
} // end constructor

// End of implementation file.
