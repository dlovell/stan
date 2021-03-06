#ifndef __STAN__MATH__MATRIX__MDIVIDE_RIGHT_LDLT_HPP__
#define __STAN__MATH__MATRIX__MDIVIDE_RIGHT_LDLT_HPP__

#include <stan/math/matrix/Eigen.hpp>
#include <stan/math/matrix/LDLT_factor.hpp>
#include <stan/math/matrix/mdivide_left_ldlt.hpp>
#include <stan/math/matrix/transpose.hpp>
#include <stan/math/error_handling/matrix/check_multiplicable.hpp>
#include <boost/math/tools/promotion.hpp>

namespace stan {
  namespace math {

    /**
     * Returns the solution of the system xA=b given an LDLT_factor of A
     * @param A LDLT_factor
     * @param b Right hand side matrix or vector.
     * @return x = A^-1 b, solution of the linear system.
     * @throws std::domain_error if rows of b don't match the size of A.
     */

    template <typename T1, typename T2, int R1, int C1, int R2, int C2>
    inline 
    Eigen::Matrix<typename boost::math::tools::promote_args<T1,T2>::type,R1,C2>
    mdivide_right_ldlt(const Eigen::Matrix<T1,R1,C1> &b,
                       const stan::math::LDLT_factor<T2,R2,C2> &A) {
      using stan::math::transpose;
      stan::math::check_multiplicable("mdivide_right_ldlt(%1%)",b,"b",
                                      A,"A",(double*)0);

      return transpose(mdivide_left_ldlt(A,transpose(b)));
    }
    
    template <int R1, int C1, int R2, int C2>
    inline Eigen::Matrix<double,R1,C2>
    mdivide_right_ldlt(const Eigen::Matrix<double,R1,C1> &b,
                       const stan::math::LDLT_factor<double,R2,C2> &A) {
      stan::math::check_multiplicable("mdivide_right_ldlt(%1%)",b,"b",
                                      A,"A",(double*)0);
      return A.solveRight(b);
    }

  }
}
#endif
