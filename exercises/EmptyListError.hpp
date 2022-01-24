#include <stdexcept>
#include <string>

class EmptyListError : public std::runtime_error {
public:
    EmptyListError(const std::string& message = "")
        : std::runtime_error(message) {}
};
