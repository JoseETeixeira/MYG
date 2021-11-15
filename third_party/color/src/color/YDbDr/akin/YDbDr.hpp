#ifndef color_YDbDr_akin_YDbDr
#define color_YDbDr_akin_YDbDr

#include "../../generic/akin/YDbDr.hpp"
#include "../category.hpp"
#include "../../YDbDr/category.hpp"

namespace color
 {
  namespace akin
   {

    template< typename tag_name >
     struct YDbDr< ::color::category::YDbDr< tag_name >  >
      {
       public:
         typedef ::color::category::YDbDr< tag_name > akin_type;
      };

   }
 }

#endif
