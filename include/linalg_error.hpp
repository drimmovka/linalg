#pragma once

#include <exception>
#include <string>

namespace linalg
{

class LinalgError : public std::exception {
public:
    explicit LinalgError(const std::string& message);
    
    ~LinalgError();

    const char *what() const noexcept override;
    
private:
    const std::string _message;
};

} // namespace linalg