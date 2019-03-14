#include <iostream>
#include <chrono>
#include <vector>

#include "stopwatch.h"

using namespace std::chrono;
using namespace elma;
using namespace stopwatch;

StopWatch&OnState:: stopwatch() { return (StopWatch&) state_machine(); }

void OnState::exit(const Event& e) {
    if ( e.name() == "start/stop" ) {
        // User stopped the stopwatch
        stopwatch().stop();
    } else if ( e.name() == "lap" ) {
        // User adds a lap to the stopwatch lap list
        stopwatch().lap();
    }
}
