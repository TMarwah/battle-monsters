#include "Timer.h"


Timer::Timer() {
    _start = std::chrono::high_resolution_clock::now();
    //_mark = 0;

}

void Timer::reset() {
    _start = std::chrono::high_resolution_clock::now();
    //_mark = 0;

}

void Timer::mark() {
    _mark = std::chrono::high_resolution_clock::now();

}


float Timer::elapsed() const {

    std::chrono::high_resolution_clock::time_point current;

    current = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = current - _start;

    return duration.count();


}

void Timer::sleep(unsigned seconds) const {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    
}