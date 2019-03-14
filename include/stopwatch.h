#ifndef _ELMA_STOP_WATCH_H
#define _ELMA_STOP_WATCH_H

#include "elma/elma.h" // Note installation directory for elma

#include "on.h"
#include "off.h"
#include "user_interface.h"

namespace stopwatch {

    using namespace std::chrono;
    using namespace elma;    

    //! A stop watch class, that inherits from StateMachine
    class StopWatch : public StateMachine {

        public:
        //! Make a new stopwatch
        StopWatch();

        //! Start the stopwatch
        void begin();

        //! Reset the stopwatch to zero and erase laps
        void reset();

        //! Stop the stopwatch
        void stop();

        //! Add a lap time to the list of lap times.
        void lap();

        //! Get the time stored by the stopwatch
        high_resolution_clock::duration value();

        //! Get a list of lap times
        const vector<high_resolution_clock::duration>& laps() { return _laps; }

        private:

        // When overriding the StateMachine class, put state declarations here.
        OnState on;
        OffState off;

        // Other private variables
        bool _running;
        high_resolution_clock::time_point _start_time;
        high_resolution_clock::duration _elapsed;
        vector<high_resolution_clock::duration> _laps;

    };

}

#endif