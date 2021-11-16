#ifndef color_hsl_convert_hsi
#define color_hsl_convert_hsi

#include "../category.hpp"

#include "../../_internal/convert.hpp"




#include "../../hsi/hsi.hpp"
#include "../../rgb/rgb.hpp"

namespace color
 {
  namespace _internal
   {

    template
     <
      typename hsl_tag_name
     ,typename hsi_tag_name
    >
     struct convert
      <
        ::color::category::hsl< hsl_tag_name >
       ,::color::category::hsi< hsi_tag_name >
      >
      {
       public:
         typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_left_type;
         typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_right_type;

         typedef typename ::color::trait::scalar< category_left_type >::instance_type scalar_type;

         typedef ::color::model< hsl_category_type >  hsl_model_type;
         typedef ::color::model< hsi_category_type >  hsi_model_type;

         typedef ::color::rgb< scalar_type >  rgb_model_type;

         typedef ::color::trait::container<category_left_type>     container_left_trait_type;
         typedef ::color::trait::container<category_right_type>    container_right_trait_type;

         typedef typename container_left_trait_type::input_type         container_left_input_type;
         typedef typename container_right_trait_type::model_type  container_right_const_input_type;

         static void process
          (
            container_left_input_type         left
           ,container_right_const_input_type  right
          )
          {
           left = hsl_model_type( rgb_model_type( hsi_model_type( right ) ) ).container();
          }
      };

   }
 }

#endif