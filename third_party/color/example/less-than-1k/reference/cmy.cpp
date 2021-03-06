#include <iostream>
#include <iomanip>

#include "color/color.hpp"

using namespace std;



#define print(c) cout << c[0] << ", " << c[1] << ", " << c[2] << endl;

int main( int argc, char *argv[] )
 {
  ::color::cmy<uint8_t     >  c1( ::color::constant::aqua_t{} );
  ::color::cmy<uint16_t    >  c2( ::color::constant::aqua_t{} );
  ::color::cmy<uint32_t    >  c3( ::color::constant::aqua_t{} );
  ::color::cmy<uint64_t    >  c4( ::color::constant::aqua_t{} );
  ::color::cmy<float       >  c5( ::color::constant::aqua_t{} );
  ::color::cmy<double      >  c6( ::color::constant::aqua_t{} );
  ::color::cmy<long double >  c7( ::color::constant::aqua_t{} );

  print(c1)
  print(c2)
  print(c3)
  print(c4)
  print(c5)
  print(c6)
  print(c7)

  return EXIT_SUCCESS;
 }
