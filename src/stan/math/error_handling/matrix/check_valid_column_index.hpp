#ifndef __STAN__MATH__ERROR_HANDLING__MATRIX__CHECK_VALID_COLUMN_INDEX_HPP__
#define __STAN__MATH__ERROR_HANDLING__MATRIX__CHECK_VALID_COLUMN_INDEX_HPP__

#include <sstream>
#include <boost/type_traits/common_type.hpp>
#include <stan/math/error_handling/dom_err.hpp>
#include <stan/math/matrix/Eigen.hpp>

namespace stan {
  namespace math {

    template <class T_y, int R, int C, class T_size, class T_result>
    inline bool check_valid_column_index(const char* function,
                                         const Eigen::Matrix<T_y,R,C>& y,
                                         const char* name_y,
                                         const T_size column_index,
                                         T_result* result) {
      if (!(column_index >= 1 && column_index <= y.cols())) {
        std::ostringstream msg;
        msg << ": expecting column index to be between 1 and " 
            << y.cols() << ", but found column index = %1%";
        std::string tmp(msg.str());
        return dom_err(function,column_index,name_y,
                       tmp.c_str(),"",
                       result);
      }
      return true;
    }

    template <class T_y, int R, int C, class T_size>
    inline
    bool check_valid_column_index(const char* function,
                                  const Eigen::Matrix<T_y,R,C>& y,
                                  const char* name_y,
                                  const T_size column_index,
                                  T_size* result = 0) {
      return check_valid_column_index<T_y,R,C,T_size,T_size>(function,
                                                             y, name_y, column_index,
                                                             result);
    }

  }
}
#endif
