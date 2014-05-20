#include <stan/math/error_handling/matrix/check_valid_column_index.hpp>
#include <gtest/gtest.h>
#include <stan/math/matrix/Eigen.hpp>

TEST(MathErrorHandlingMatrix, check_valid_column_index__size_t) {
  Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> y;
  size_t column;
  double result;
  
  y.resize(2,3);
  for (column = 1; column <= 3; column++) {
    EXPECT_TRUE(stan::math::check_valid_column_index("test(%1%)",
                                                     y, "matrix",
                                                     column,
                                                     &result));
  }
  
  column = 0;
  EXPECT_THROW(stan::math::check_valid_column_index("test(%1%)",
                                                    y, "matrix",
                                                    column,
                                                    &result),
               std::domain_error);
  
  column = 4;
  EXPECT_THROW(stan::math::check_valid_column_index("test(%1%)",
                                                    y, "matrix",
                                                    column,
                                                    &result),
               std::domain_error);
}


TEST(MathErrorHandlingMatrix, check_valid_column_index__int) {
  Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> y;
  int column;
  double result;
  
  y.resize(2,3);
  for (column = 1; column <= 3; column++) {
    EXPECT_TRUE(stan::math::check_valid_column_index("test(%1%)",
                                                     y, "matrix",
                                                     column,
                                                     &result));
  }
  
  column = 0;
  EXPECT_THROW(stan::math::check_valid_column_index("test(%1%)",
                                                    y, "matrix",
                                                    column,
                                                    &result),
               std::domain_error);
  
  column = 4;
  EXPECT_THROW(stan::math::check_valid_column_index("test(%1%)",
                                                    y, "matrix",
                                                    column,
                                                    &result),
               std::domain_error);
}


