#pragma once
#include <cassert>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <vector>

namespace rul::collections::matrix {
template<typename T>
class Matrix {
public:
    explicit constexpr Matrix(std::size_t rows, std::size_t cols)
        : m_rows(rows), m_cols(cols), m_data(checked_size(rows, cols)) {}

    explicit constexpr Matrix(std::size_t rows, std::size_t cols, const T& value)
        : m_rows(rows), m_cols(cols), m_data(checked_size(rows, cols), value) {}

    [[nodiscard]] constexpr std::size_t rows() const noexcept { return m_rows; }

    [[nodiscard]] constexpr std::size_t cols() const noexcept { return m_cols; }

    [[nodiscard]] constexpr T& operator()(std::size_t row, std::size_t col) noexcept {
        return m_data[index(row, col)];
    }

    [[nodiscard]] constexpr const T& operator()(std::size_t row, std::size_t col) const noexcept {
        return m_data[index(row, col)];
    }

    [[nodiscard]] constexpr T* data() noexcept { return m_data.data(); }

    [[nodiscard]] constexpr const T* data() const noexcept { return m_data.data(); }

    [[nodiscard]] constexpr auto begin() noexcept { return m_data.begin(); }

    [[nodiscard]] constexpr auto begin() const noexcept { return m_data.begin(); }

    [[nodiscard]] constexpr auto end() noexcept { return m_data.end(); }

    [[nodiscard]] constexpr auto end() const noexcept { return m_data.end(); }

    [[nodiscard]] constexpr bool operator==(const Matrix&) const = default;

    [[nodiscard]] static constexpr Matrix
    identity(std::size_t size, const T& zero = T(0), const T& one = T(1)) {
        Matrix mat(size, size, zero);
        for (std::size_t i = 0; i < size; ++i) {
            mat(i, i) = one;
        }
        return mat;
    }

    [[nodiscard]] static constexpr Matrix zero(std::size_t rows, std::size_t cols) {
        return Matrix(rows, cols, T(0));
    }

private:
    [[nodiscard]] static constexpr std::size_t checked_size(std::size_t rows, std::size_t cols) {
        if (cols != 0 && rows > std::numeric_limits<std::size_t>::max() / cols) {
            throw std::length_error(
                "rul::collections::matrix::Matrix: rows * cols overflows std::size_t");
        }
        return rows * cols;
    }

    [[nodiscard]] constexpr std::size_t index(std::size_t row, std::size_t col) const noexcept {
        assert(row < m_rows && col < m_cols);
        return row * m_cols + col;
    }

    std::size_t m_rows;
    std::size_t m_cols;
    std::vector<T> m_data;
};
} // namespace rul::collections::matrix
