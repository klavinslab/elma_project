#ifndef _ELMA_STOP_WATCH_ON_H
#define _ELMA_STOP_WATCH_ON_H

#include "stopwatch.h"

namespace stopwatch {

    using namespace std::chrono;
    using namespace elma;

    class StopWatch;  // Declare containing class so it can be refered to here
                      // before it is defined in stopwatch.h 

    //! The on state of the stopwatch
    class OnState : public State {        

        public:
        //! Build a new on state
        OnState() : State("on") {}
        void entry(const Event& e) {}
        void during() {}

        //! Perform actions required when switching from off to on
        //! \param e The event that triggered the transition        
        void exit(const Event&);

        StopWatch& stopwatch();        

    };

}

#endif