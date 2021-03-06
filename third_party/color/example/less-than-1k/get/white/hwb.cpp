#include <iostream>
#include <iomanip>
#include <cstdint>

#include "color/color.hpp"

int main( int argc, char *argv[] )
 {
  // Instead of float you may put std::uint8_t, ..., std::uint64_t, double, long double
  color::hwb<float> c;

  // initialize c before get.
  c = color::constant::turquoise_t{};

  // Here is how to get white component.
  auto f0 = color::get::white( c );

  // Now do whatever you wan to do
  std::cout << f0 << std::endl;

  return EXIT_SUCCESS;
 }
