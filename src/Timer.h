#pragma once
#include <chrono>
#include <thread>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point _start;
    std::chrono::high_resolution_clock::time_point _mark;
    //std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::milliseconds> _start;
    //std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::milliseconds> _mark;
 // std::chrono::time_point<std::chrono::system_clock,std::chrono::nanoseconds> time_point;

public:
    // CONSTRUCTOR
    Timer();

    // MUTATORS
    void reset();
    void mark();

    // ACCESSORS
    float elapsed() const;
    void sleep(unsigned seconds) const;


};