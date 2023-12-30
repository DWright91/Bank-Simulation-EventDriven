// Dalton Wright
// CSCI 301 01
// Project #6
// PrecondViolatedExcep.h

#ifndef PRECOND_VIOLATED_EXCEP
#define PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
   PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep
#include "PrecondViolatedExcep.cpp"
#endif
