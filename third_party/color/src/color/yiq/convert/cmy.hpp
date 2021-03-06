#ifndef color_yiq_convert_cmy
#define color_yiq_convert_cmy

#include "../../_internal/convert.hpp"
#include "../../cmy/trait/container.hpp"
#include "../../cmy/category.hpp"

#include "../../_internal/normalize.hpp"
#include "../../_internal/diverse.hpp"

namespace color
 {
  namespace _internal
   {

    template< typename yiq_tag_name, typename cmy_tag_name >
     struct convert
      <
        ::color::category::yiq<   yiq_tag_name >
       ,::color::category::cmy<   cmy_tag_name >
      >
      {
       public:
         typedef ::color::category::yiq<   yiq_tag_name > category_left_type;
         typedef ::color::category::cmy<   cmy_tag_name > category_right_type;
         typedef typename ::color::trait::scalar<category_left_type>::instance_type  scalar_type;

         typedef ::color::trait::container<category_left_type>     container_left_trait_type;
         typedef ::color::trait::container<category_right_type>    container_right_trait_type;

         typedef ::color::constant::yiq< category_left_type > yiq_const_type;

         typedef typename container_left_trait_type::input_type         container_left_input_type;
         typedef typename container_right_trait_type::model_type  container_right_const_input_type;

         typedef ::color::_internal::diverse< category_left_type >    diverse_type;
         typedef ::color::_internal::normalize< category_right_type > normalize_type;

         enum
          {
                  luma_p  = ::color::place::_internal::luma<category_left_type>::position_enum
           ,   inphase_p  = ::color::place::_internal::inphase<category_left_type>::position_enum
           ,quadrature_p  = ::color::place::_internal::quadrature<category_left_type>::position_enum
          };

         enum
          {
            cyan_p       = ::color::place::_internal::cyan<category_right_type>::position_enum
           ,magenta_p    = ::color::place::_internal::magenta<category_right_type>::position_enum
           ,yellow_p     = ::color::place::_internal::yellow<category_right_type>::position_enum
          };

         static void process
          (
            container_left_input_type         left
           ,container_right_const_input_type  right
          )
          {

           static scalar_type b11 = yiq_const_type::b11(), b12 = yiq_const_type::b12(), b13 = yiq_const_type::b13();
           static scalar_type b21 = yiq_const_type::b21(), b22 = yiq_const_type::b22(), b23 = yiq_const_type::b23();
           static scalar_type b31 = yiq_const_type::b31(), b32 = yiq_const_type::b32(), b33 = yiq_const_type::b33();

           static scalar_type const                              b32n = -b32;

           scalar_type r = scalar_type(1) - normalize_type::template process<cyan_p   >( container_right_trait_type::template get<cyan_p   >( right ) );
           scalar_type g = scalar_type(1) - normalize_type::template process<magenta_p>( container_right_trait_type::template get<magenta_p>( right ) );
           scalar_type b = scalar_type(1) - normalize_type::template process<yellow_p >( container_right_trait_type::template get<yellow_p >( right ) );

           scalar_type y = b11 * r + b12 * g + b13 * b;
           scalar_type i = b21 * r + b22 * g + b23 * b;
           scalar_type q = b31 * r + b32 * g + b33 * b;

           i = ( i / b21  + scalar_type(1) ) / scalar_type(2);
           q = ( q / b32n + scalar_type(1) ) / scalar_type(2);

           container_left_trait_type::template set<      luma_p>( left, diverse_type::template process<      luma_p>( y ) );
           container_left_trait_type::template set<   inphase_p>( left, diverse_type::template process<   inphase_p>( i ) );
           container_left_trait_type::template set<quadrature_p>( left, diverse_type::template process<quadrature_p>( q ) );
          }
      };

   }
 }

#endif
