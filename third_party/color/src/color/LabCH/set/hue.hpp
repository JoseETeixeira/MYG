#ifndef color_LabCH_set_hue
#define color_LabCH_set_hue

// ::color::set::hue( c, val )

#include "../place/place.hpp"

 namespace color
  {
   namespace set
    {
     template< typename tag_name >
      inline
      void
      hue
       (
                  ::color::model< ::color::category::LabCH<tag_name> >                                   & color_parameter,
        typename  ::color::model< ::color::category::LabCH<tag_name> >::component_input_const_type         component_parameter
       )
       {
        typedef ::color::category::LabCH<tag_name>  category_type;
        enum
         {
           hue_p  = ::color::place::_internal::hue<category_type>::position_enum
         };

        color_parameter.template set<hue_p>( component_parameter );
       }

    }
  }

#endif
