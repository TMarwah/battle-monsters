#include "ColorInterface.h"

// FORMATTING helpers

std::string ColorInterface::red(const std::string& message) const {
    std::string formattedMessage = "\033[1;31m" + message + "\033[0m";
    return formattedMessage;
}

std::string ColorInterface::red(int message) const {
    std::string formattedMessage = "\033[1;31m" + std::to_string(message) + "\033[0m";
    return formattedMessage;
}

std::string ColorInterface::red(float message) const {
    std::string formattedMessage = "\033[1;31m" + std::to_string(message) + "\033[0m";
    return formattedMessage;
}

std::string ColorInterface::white(const std::string& message) const {
    std::string formattedMessage = "\033[1;37m" + message + "\033[0m";
    return formattedMessage;
}

std::string ColorInterface::cyan(const std::string& message) const {
    std::string formattedMessage = "\033[1;36m" + message + "\033[0m";
    return formattedMessage;
}

std::string ColorInterface::blue(const std::string& message) const {
    std::string formattedMessage = "\033[1;34m" + message + "\033[0m";
    return formattedMessage;
}
std::string ColorInterface::magenta(const std::string& message) const {
    std::string formattedMessage = "\033[1;35m" + message + "\033[0m";
    return formattedMessage;
}

std::string ColorInterface::green(int message) const {
    std::string formattedMessage = "\033[1;32m" + std::to_string(message) + "\033[0m";
    return formattedMessage;
}

std::string ColorInterface::red_underline(const std::string& message) const {
    std::string formattedMessage = "\033[1;4;31m" + message + "\033[0m";
    return formattedMessage;
}
