#include <gtest/gtest.h>
#include <rul/matrix.hpp>

namespace rul::collections::matrix {

TEST(MatrixTest, ReportsDimensions) {
    Matrix<int> mat(2, 3);
    EXPECT_EQ(mat.rows(), 2u);
    EXPECT_EQ(mat.cols(), 3u);
}

TEST(MatrixTest, ElementsAreValueInitialized) {
    Matrix<int> mat(2, 2);
    for (size_t r = 0; r < mat.rows(); ++r) {
        for (size_t c = 0; c < mat.cols(); ++c) {
            EXPECT_EQ(mat(r, c), 0) << "at (" << r << ", " << c << ")";
        }
    }
}

TEST(MatrixTest, StoresElementsIndependently) {
    Matrix<int> mat(2, 3);
    mat(0, 0) = 1;
    mat(0, 2) = 2;
    mat(1, 1) = 3;

    EXPECT_EQ(mat(0, 0), 1);
    EXPECT_EQ(mat(0, 2), 2);
    EXPECT_EQ(mat(1, 1), 3);
    EXPECT_EQ(mat(1, 2), 0);
}

TEST(MatrixTest, ConstAccessReadsSameStorage) {
    Matrix<int> mat(1, 2);
    mat(0, 1) = 7;

    const Matrix<int>& ref = mat;
    EXPECT_EQ(ref(0, 1), 7);
}

TEST(MatrixTest, FillConstructorSetsEveryElement) {
    Matrix<int> mat(2, 2, 5);
    for (size_t r = 0; r < mat.rows(); ++r) {
        for (size_t c = 0; c < mat.cols(); ++c) {
            EXPECT_EQ(mat(r, c), 5) << "at (" << r << ", " << c << ")";
        }
    }
}

TEST(MatrixTest, IdentityHasOnesOnDiagonal) {
    const auto mat = Matrix<int>::identity(3);
    ASSERT_EQ(mat.rows(), 3u);
    ASSERT_EQ(mat.cols(), 3u);

    for (size_t r = 0; r < mat.rows(); ++r) {
        for (size_t c = 0; c < mat.cols(); ++c) {
            EXPECT_EQ(mat(r, c), r == c ? 1 : 0) << "at (" << r << ", " << c << ")";
        }
    }
}

TEST(MatrixTest, ZeroIsAllZeros) {
    const auto mat = Matrix<double>::zero(2, 4);
    ASSERT_EQ(mat.rows(), 2u);
    ASSERT_EQ(mat.cols(), 4u);

    for (size_t r = 0; r < mat.rows(); ++r) {
        for (size_t c = 0; c < mat.cols(); ++c) {
            EXPECT_DOUBLE_EQ(mat(r, c), 0.0) << "at (" << r << ", " << c << ")";
        }
    }
}

} // namespace rul::collections::matrix
