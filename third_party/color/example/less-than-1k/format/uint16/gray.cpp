#include <iostream>
#include <iomanip>

#include "color/color.hpp"


int main( int argc, char *argv[] )
 {
  ::color::gray< std::uint16_t > g;

  g = ::color::constant::orange_t{}; //!< Fill with some useful information

  std::cout<< "Orange in color::cmy<std::uint16_t> = { ";
  std::cout<< std::setw(12) << std::right << (unsigned)g[0];
  std::cout<< " };";
  std::cout<< std::endl;
  return EXIT_SUCCESS;
 }
