#ifndef __STAN__MATH__FUNCTIONS__FDIM_HPP__
#define __STAN__MATH__FUNCTIONS__FDIM_HPP__

#include <boost/math/tools/promotion.hpp>

namespace stan {
  namespace math {
    /** 
     * The positive difference function (C99).  
     *
     * The function is defined by
     *
     * <code>fdim(a,b) = (a > b) ? (a - b) : 0.0</code>.
     *
     * @param a First value.
     * @param b Second value.
     * @return Returns min(a - b, 0.0).
     */
    template <typename T1, typename T2>
    inline typename boost::math::tools::promote_args<T1, T2>::type
    fdim(T1 a, T2 b) {
      return (a > b) ? (a - b) : 0.0;
    } 
  }
}

#endif
