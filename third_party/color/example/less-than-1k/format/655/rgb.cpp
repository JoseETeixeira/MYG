#include <iostream>
#include <iomanip>

#include "color/color.hpp"


int main( int argc, char *argv[] )
 {
  ::color::rgb< ::color::type::split655_t > r;

  r = ::color::constant::orange_t{}; //!< Fill with some useful information


  std::cout<< (unsigned)r[0] << "," << (unsigned)r[1] << "," << (unsigned)r[2] << "," << (unsigned)r[3];

  std::cout<< std::endl;

  return EXIT_SUCCESS;
 } 