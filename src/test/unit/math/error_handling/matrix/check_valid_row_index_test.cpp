#include <stan/math/error_handling/matrix/check_valid_row_index.hpp>
#include <gtest/gtest.h>
#include <stan/math/matrix/Eigen.hpp>

TEST(MathErrorHandlingMatrix, check_valid_row_index__size_t) {
  Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> y;
  size_t row;
  double result;
  
  y.resize(2,3);
  for (row = 1; row <= 2; row++) {
    EXPECT_TRUE(stan::math::check_valid_row_index("test(%1%)",
                                                  y, "matrix",
                                                  row,
                                                  &result));
  }
  
  row = 0;
  EXPECT_THROW(stan::math::check_valid_row_index("test(%1%)",
                                                 y, "matrix",
                                                 row,
                                                 &result),
               std::domain_error);
  
  row = 3;
  EXPECT_THROW(stan::math::check_valid_row_index("test(%1%)",
                                                 y, "matrix",
                                                 row,
                                                 &result),
               std::domain_error);
}


TEST(MathErrorHandlingMatrix, check_valid_row_index__int) {
  Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> y;
  int row;
  double result;
  
  y.resize(2,3);
  for (row = 1; row <= 2; row++) {
    EXPECT_TRUE(stan::math::check_valid_row_index("test(%1%)",
                                                  y, "matrix",
                                                  row,
                                                  &result));
  }
  
  row = 0;
  EXPECT_THROW(stan::math::check_valid_row_index("test(%1%)",
                                                 y, "matrix",
                                                 row,
                                                 &result),
               std::domain_error);
  
  row = 3;
  EXPECT_THROW(stan::math::check_valid_row_index("test(%1%)",
                                                 y, "matrix",
                                                 row,
                                                 &result),
               std::domain_error);
}


