#pragma once
#include <chrono>
#include <thread>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point _start;
    std::chrono::high_resolution_clock::time_point _mark;

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