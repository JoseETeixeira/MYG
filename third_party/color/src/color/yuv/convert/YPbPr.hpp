#ifndef color_yuv_convert_YPbPr
#define color_yuv_convert_YPbPr

#include "../../_internal/convert.hpp"

#include "../category.hpp"


#include "../../YPbPr/YPbPr.hpp"
#include "../../rgb/rgb.hpp"

namespace color
 {
  namespace _internal
   {

    template
     <
       typename yuv_tag_name,    ::color::constant::yuv::reference_enum     yuv_reference_number
      ,typename YPbPr_tag_name,  ::color::constant::YPbPr::reference_enum YPbPr_reference_number
     >
     struct convert
      <
        ::color::category::yuv<      yuv_tag_name,   yuv_reference_number >
       ,::color::category::YPbPr<  YPbPr_tag_name, YPbPr_reference_number >
      >
      {
       public:
         typedef ::color::category::yuv<     yuv_tag_name,   yuv_reference_number >          yuv_category_type,  category_left_type;
         typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >        YPbPr_category_type, category_right_type;

         typedef typename ::color::trait::scalar< category_left_type >::instance_type scalar_type;


         typedef ::color::model< category_left_type  >    yuv_model_type,  left_model_type;
         typedef ::color::model< category_right_type >  YPbPr_model_type, right_model_type;

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
           left = yuv_model_type( rgb_model_type( YPbPr_model_type( right ) ) ).container();
          }
        };

   }
 }

#endif
