#ifndef color_gray_convert_YPbPr
#define color_gray_convert_YPbPr

#include "../../_internal/convert.hpp"
#include "../../YPbPr/place/place.hpp"

#include "../../_internal/reformat.hpp"

namespace color
 {
  namespace _internal
   {

    template
     <
       typename gray_tag_name
      ,typename YPbPr_tag_name,  ::color::constant::YPbPr::reference_enum YPbPr_reference_number
     >
     struct convert
      <
        ::color::category::gray< gray_tag_name >
       ,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
      >
      {
       public:
         typedef ::color::category::gray< gray_tag_name >                          category_left_type;
         typedef ::color::category::YPbPr<YPbPr_tag_name, YPbPr_reference_number> category_right_type;

         typedef ::color::trait::container<category_left_type>     container_left_trait_type;
         typedef ::color::trait::container<category_right_type>    container_right_trait_type;

         typedef ::color::_internal::reformat< category_left_type, category_right_type >    reformat_type;

         typedef typename container_left_trait_type::input_type         container_left_input_type;
         typedef typename container_right_trait_type::model_type  container_right_const_input_type;

         enum
          {
            luma_p = ::color::place::_internal::luma<category_right_type>::position_enum
          };

         static void process
          (
            container_left_input_type         left
           ,container_right_const_input_type  right
          )
          {
           container_left_trait_type::template set<0>( left, reformat_type::template process<0,luma_p>( container_right_trait_type::template get<luma_p>( right ) ) );
          }
      };

   }
 }

#endif
