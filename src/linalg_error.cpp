#include "linalg_error.hpp"

namespace linalg
{

LinalgError::LinalgError(const std::string& message)
    : _message(message)
{}

LinalgError::~LinalgError() = default;

const char *LinalgError::what() const noexcept {
    return _message.c_str();
}

} // namespace linalg