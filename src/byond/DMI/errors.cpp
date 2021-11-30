#include "errors.h"

#include <sstream>

ReasonError::ReasonError(const char *reason) : reason(reason) {}

std::string ReasonError::describe() { return reason; }

VersionError::VersionError(float got, float expected)
    : got(got), expected(expected) {}

std::string VersionError::describe() {
    std::stringstream s;
    s << "Expected DMI version " << expected << ", got " << got;
    return s.str();
}
