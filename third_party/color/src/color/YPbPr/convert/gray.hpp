#ifndef color_YPbPr_convert_gray
#define color_YPbPr_convert_gray

#include "../../_internal/convert.hpp"
#include "../../gray/gray.hpp"

#include "../../_internal/normalize.hpp"
#include "../../_internal/diverse.hpp"

namespace color
 {
  namespace _internal
   {

    template
     <
       typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
      ,typename gray_tag_name
     >
     struct convert
      <
        ::color::category::YPbPr<   YPbPr_tag_name, YPbPr_reference_number >
       ,::color::category::gray< gray_tag_name >
      >
      {
       public:
         typedef ::color::category::YPbPr<   YPbPr_tag_name, YPbPr_reference_number > category_left_type;
         typedef ::color::category::gray< gray_tag_name > category_right_type;
         typedef typename ::color::trait::scalar<category_left_type>::instance_type  scalar_type;

         typedef ::color::trait::bound<category_left_type>         bound_left_trait_type;
         typedef ::color::trait::container<category_left_type>     container_left_trait_type;
         typedef ::color::trait::container<category_right_type>    container_right_trait_type;

         typedef typename container_left_trait_type::input_type         container_left_input_type;
         typedef typename container_right_trait_type::model_type  container_right_const_input_type;

         typedef ::color::_internal::diverse< category_left_type >    diverse_type;
         typedef ::color::_internal::normalize< category_right_type > normalize_type;

         static void process
          (
            container_left_input_type         left
           ,container_right_const_input_type  right
          )
          {
           scalar_type g = normalize_type::template process<0>( container_right_trait_type::template get<0>( right ) );

                  auto        Y  = diverse_type::template process<0>( g );
           static auto const  Pb = diverse_type::template process<1>( 0.5 );
           static auto const  Pr = diverse_type::template process<2>( 0.5 );

           container_left_trait_type::template set<0>( left, Y );
           container_left_trait_type::template set<1>( left, Pb );
           container_left_trait_type::template set<2>( left, Pr );
          }
      };

   }
 }

#endif
