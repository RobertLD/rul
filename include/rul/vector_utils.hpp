#pragma once
#include <cstddef>
#include <vector>

namespace rul::vector {
template<typename T>
class Matrix {
public:
    using index_type = std::ptrdiff_t;

    explicit constexpr Matrix(size_t rows, size_t cols)
        : m_rows(static_cast<index_type>(rows)),
          m_cols(static_cast<index_type>(cols)),
          m_data(rows * cols) {}

    constexpr Matrix(size_t rows, size_t cols, const T& value)
        : m_rows(static_cast<index_type>(rows)),
          m_cols(static_cast<index_type>(cols)),
          m_data(rows * cols, value) {}

    [[nodiscard]] constexpr size_t rows() const noexcept { return static_cast<size_t>(m_rows); }

    [[nodiscard]] constexpr size_t cols() const noexcept { return static_cast<size_t>(m_cols); }

    constexpr T& operator()(size_t row, size_t col) noexcept { return m_data[index(row, col)]; }

    constexpr const T& operator()(size_t row, size_t col) const noexcept {
        return m_data[index(row, col)];
    }

    static constexpr Matrix<T> identity(size_t size) {
        Matrix<T> mat(size, size);
        for (size_t i = 0; i < size; ++i) {
            mat(i, i) = T(1);
        }
        return mat;
    }

    static constexpr Matrix<T> zero(size_t rows, size_t cols) { return Matrix<T>(rows, cols); }

private:
    [[nodiscard]] constexpr index_type index(size_t row, size_t col) const noexcept {
        return static_cast<index_type>(row) * m_cols + static_cast<index_type>(col);
    }

    index_type m_rows;
    index_type m_cols;
    std::vector<T> m_data;
};
} // namespace rul::vector
