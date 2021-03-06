#ifndef color_rgb_convert_YCgCo
#define color_rgb_convert_YCgCo

#include "../../_internal/convert.hpp"
#include "../../YCgCo/trait/container.hpp"
#include "../../YCgCo/category.hpp"
#include "../../YCgCo/constant.hpp"

#include "../../generic/operation/diverse.hpp"
#include "../../generic/operation/normalize.hpp"
#include "../../_internal/reformat.hpp"

#include "../place/red.hpp"
#include "../place/green.hpp"
#include "../place/blue.hpp"



namespace color
 {
  namespace _internal
   {

    template< typename rgb_tag_name, typename YCgCo_tag_name >
     struct convert
      <
        ::color::category::rgb< rgb_tag_name >
       ,::color::category::YCgCo< YCgCo_tag_name>
      >
      {
       public:
         typedef ::color::category::rgb< rgb_tag_name >  category_left_type;
         typedef ::color::category::YCgCo<YCgCo_tag_name>    category_right_type;

         typedef typename ::color::trait::scalar< category_left_type >::instance_type scalar_type;

         typedef ::color::trait::container<category_left_type>     container_left_trait_type;
         typedef ::color::trait::container<category_right_type>    container_right_trait_type;

         typedef typename container_left_trait_type::input_type         container_left_input_type;
         typedef typename container_right_trait_type::model_type  container_right_const_input_type;

         typedef ::color::constant::YCgCo< category_right_type > YCgCo_const_type;

         typedef ::color::_internal::diverse< category_left_type >    diverse_type;
         typedef ::color::_internal::normalize< category_right_type > normalize_type;

         enum
          {
            red_p   = ::color::place::_internal::red<category_left_type>::position_enum
           ,green_p = ::color::place::_internal::green<category_left_type>::position_enum
           ,blue_p  = ::color::place::_internal::blue<category_left_type>::position_enum
          };

         static void process
          (
            container_left_input_type         left
           ,container_right_const_input_type  right
          )
          {
           scalar_type Y  = normalize_type::template process<0>( container_right_trait_type::template get<0>( right ) );
           scalar_type Cg = normalize_type::template process<1>( container_right_trait_type::template get<1>( right ) );
           scalar_type Co = normalize_type::template process<2>( container_right_trait_type::template get<2>( right ) );

           Cg = YCgCo_const_type::Cg_diverse( Cg );
           Co = YCgCo_const_type::Co_diverse( Co );

           scalar_type r = Y - Cg + Co;
           scalar_type g = Y + Cg;
           scalar_type b = Y - Cg - Co;

           container_left_trait_type::template set<red_p  >( left, diverse_type::template process<red_p  >( r ) );
           container_left_trait_type::template set<green_p>( left, diverse_type::template process<green_p>( g ) );
           container_left_trait_type::template set<blue_p >( left, diverse_type::template process<blue_p >( b ) );
          }
      };

   }
 }

#endif