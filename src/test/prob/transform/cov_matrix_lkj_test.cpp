#include <vector>
#include <cmath>
#include <stdexcept>
#include <gtest/gtest.h>

#include <stan/agrad/agrad.hpp>
#include <stan/prob/transform/cov_matrix_lkj_constrain.hpp>
#include <stan/prob/transform/cov_matrix_lkj_free.hpp>
#include <stan/math/matrix/determinant.hpp>

using Eigen::Matrix;
using Eigen::Dynamic;

TEST(prob_transform,lkj_cov_matrix_rt) {
  unsigned int K = 4;
  unsigned int K_choose_2 = 6; 
  Matrix<double,Dynamic,1> x(K_choose_2 + K);
  x << -1.0, 2.0, 0.0, 1.0, 3.0, -1.5,
    1.0, 2.0, -1.5, 2.5;
  Matrix<double,Dynamic,Dynamic> y = stan::prob::cov_matrix_constrain_lkj(x,K);
  Matrix<double,Dynamic,1> xrt = stan::prob::cov_matrix_free_lkj(y);
  EXPECT_EQ(x.size(), xrt.size());
  for (Matrix<double,Dynamic,1>::size_type i = 0; i < x.size(); ++i) {
    EXPECT_FLOAT_EQ(x[i], xrt[i]);
  }
}
TEST(prob_transform,lkj_cov_matrix_free_exception) {
  Matrix<double,Dynamic,Dynamic> y(0,0);
  
  EXPECT_THROW(stan::prob::cov_matrix_free_lkj(y), std::domain_error);
  y.resize(0,10);
  EXPECT_THROW(stan::prob::cov_matrix_free_lkj(y), std::domain_error);
  y.resize(10,0);
  EXPECT_THROW(stan::prob::cov_matrix_free_lkj(y), std::domain_error);
  y.resize(1,2);
  EXPECT_THROW(stan::prob::cov_matrix_free_lkj(y), std::domain_error);

  y.resize(2,2);
  y << 0, 0, 0, 0;
  EXPECT_THROW(stan::prob::cov_matrix_free_lkj(y), std::runtime_error);
}