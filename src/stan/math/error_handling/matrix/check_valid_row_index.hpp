#ifndef __STAN__MATH__ERROR_HANDLING__MATRIX__CHECK_VALID_ROW_INDEX_HPP__
#define __STAN__MATH__ERROR_HANDLING__MATRIX__CHECK_VALID_ROW_INDEX_HPP__

#include <sstream>
#include <boost/type_traits/common_type.hpp>
#include <stan/math/error_handling/dom_err.hpp>
#include <stan/math/matrix/Eigen.hpp>

namespace stan {
  namespace math {

    template <class T_y, int R, int C, class T_size, class T_result>
    inline bool check_valid_row_index(const char* function,
                                      const Eigen::Matrix<T_y,R,C>& y,
                                      const char* name_y,
                                      const T_size row_index,
                                      T_result* result) {
      if (!(row_index >= 1 && row_index <= y.rows())) {
        std::ostringstream msg;
        msg << ": expecting row index to be between 1 and " 
            << y.rows() << ", but found row index = %1%";
        std::string tmp(msg.str());
        return dom_err(function,row_index,name_y,
                       tmp.c_str(),"",
                       result);
      }
      return true;
    }

    template <class T_y, int R, int C, class T_size>
    inline
    bool check_valid_row_index(const char* function,
                                  const Eigen::Matrix<T_y,R,C>& y,
                                  const char* name_y,
                                  const T_size row_index,
                                  T_size* result = 0) {
      return check_valid_row_index<T_y,R,C,T_size,T_size>(function,
                                                          y, name_y, row_index,
                                                          result);
    }

  }
}
#endif
