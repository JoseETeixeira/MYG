#include <iostream>
#include <iomanip>

#include "color/color.hpp"

using namespace std;



#define print(c) cout << c[0] << ", " << c[1] << ", " << c[2] << endl;

int main( int argc, char *argv[] )
 {
  ::color::hsl<uint8_t     >  c1( ::color::constant::aqua_t{} );
  ::color::hsl<uint16_t    >  c2( ::color::constant::aqua_t{} );
  ::color::hsl<uint32_t    >  c3( ::color::constant::aqua_t{} );
  ::color::hsl<uint64_t    >  c4( ::color::constant::aqua_t{} );
  ::color::hsl<float       >  c5( ::color::constant::aqua_t{} );
  ::color::hsl<double      >  c6( ::color::constant::aqua_t{} );
  ::color::hsl<long double >  c7( ::color::constant::aqua_t{} );

  print(c1)
  print(c2)
  print(c3)
  print(c4)
  print(c5)
  print(c6)
  print(c7)

  return EXIT_SUCCESS;
 }
