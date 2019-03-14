#ifndef _ELMA_STOP_WATCH_OFF_H
#define _ELMA_STOP_WATCH_OFF_H

#include "stopwatch.h"

namespace stopwatch {

    using namespace std::chrono;
    using namespace elma;

    class StopWatch; // Declare containing class so it can be refered to here
                     // before it is defined in stopwatch.h

    //! A State class to represen the state in which the stopwatch is off
    class OffState : public State {

        public:
        //! Construct a new off state
        OffState() : State("off") {}
        void entry(const Event& e) {}
        void during() {}

        //! Perform actions required when switching from off to on
        //! \param e The event that triggered the transition
        void exit(const Event& e);

        //! \return A reference to the containing finite state machine object
        StopWatch& stopwatch();

    };

}

#endif