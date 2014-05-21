#ifndef __STAN__MATH__MATRIX__TAIL_HPP__
#define __STAN__MATH__MATRIX__TAIL_HPP__

#include <vector>
#include <stan/math/matrix/Eigen.hpp>
#include <stan/math/error_handling/matrix/check_valid_column_index.hpp>
#include <stan/math/error_handling/matrix/check_valid_row_index.hpp>
#include <stan/math/matrix/validate_std_vector_index.hpp>

namespace stan {
  namespace math {

    /**
     * Return the specified number of elements as a vector
     * from the back of the specified vector.
     */
    template <typename T>
    inline
    Eigen::Matrix<T,Eigen::Dynamic,1>
    tail(const Eigen::Matrix<T,Eigen::Dynamic,1>& v,
         size_t n) {
      if (n != 0)
        check_valid_row_index("tail(%1%)", v, "v", v.size() - n + 1);
      return v.tail(n);
    }


    /**
     * Return the specified number of elements as a row vector
     * from the back of the specified row vector.
     */
    template <typename T>
    inline
    Eigen::Matrix<T,1,Eigen::Dynamic>
    tail(const Eigen::Matrix<T,1,Eigen::Dynamic>& rv,
         size_t n) {
      if (n != 0)
        check_valid_column_index("tail(%1%)", rv, "rv", rv.size() - n + 1);
      return rv.tail(n);
    }

    template <typename T>
    std::vector<T> tail(const std::vector<T>& sv,
                        size_t n) {
      if (n != 0)
        validate_std_vector_index(sv, sv.size() - n + 1, "tail");
      std::vector<T> s;
      for (typename std::vector<T>::size_type i = sv.size() - n; i < sv.size(); ++i)
        s.push_back(sv[i]);
      return s;
    }


  }
}

#endif
