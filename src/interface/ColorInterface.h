#pragma once
#include <string>


struct ColorInterface {
    // FORMATTING HELPRS
    std::string red(const std::string& ) const;
    std::string red(int message) const;
    std::string red(float message) const;
    std::string red_underline(const std::string& ) const;

    std::string white(const std::string& ) const;
    std::string cyan(const std::string& ) const;
    std::string blue(const std::string& ) const;
    std::string magenta(const std::string& ) const;
    std::string green(int ) const;
};
