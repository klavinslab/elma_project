Example Elma Project
===

[Elma](http://klavinslab.org/elma) is an event loop manager designed to teach embedded and reactive systems programming. This repository contains an example Elma project, showing how to use many Elma features, as well as illustrating how to arrange the files and directories in an Elma project.

The source code for this project is available [on github](https://github.com/klavinslab/elma_project).

Installation
---
```bash
git clone https://github.com/klavinslab/elma_project.git
cd elma_project
docker run -v $PWD:/source -it klavins/elma:latest bash
make
make docs
```

Execution
---
To run the stopwatch, type
```bash
bin/stopwatch
```
The stopwatch is controlled via the keyboard, via these keys:
- **s**: Start or stop
- **l**: Lap
- **r**: Reset
- **q**: Quit

Testing
---
To run tests, do
```bash
bin/test
```

Architecture
---
Describe how your project was designed, what choices you made, how things are organized, etc.

Results
---
Describe the results of testing and running your code. Include visuals when possible.

Acknowledgements
---
Mention anyone who helped you and how.

References
---
List all libraries, articles, stack overflow answers, etc. that you used to get your code working.
