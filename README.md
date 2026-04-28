*This project has been created as part of the 42 curriculum by josepedr.*
# Philosophers


## Description


## Incstructions

#### Compilation:


`make`


This will automatically compile the program with the appropriate pthread flag, alongside the common flags used in every 42 C project (-Wall -Werror -Wextra).


#### Usage:
`./philo num_of_philosophers time_to_die time_to_eat time_to_sleep [num_of_meals_each_philosopher_must_eat]`


| Argument | Description |
| --- | --- |
| `num_of_philosophers` | number of philosophers sitting around the table during the simulation |
| `time_to_die` | time it takes (in milliseconds) for a philosopher to die if no meal has been eaten since (min. 60ms) |
| `time_to_eat` | time it takes (in milliseconds) for a philosopher to eat (min. 60ms) |
| `time_to_sleep` | time it takes (in milliseconds) for a philosopher to sleep (min. 60ms) |
| `num_of_meals_each_philosopher_must_eat` | optional argument, simulation ends after this ammount of means has been eaten (min. 1)|


## Resources


### References
* [Oceano's video on the philosopher's project](https://youtu.be/zOpzGHwJ3MU?si=Yj_X0piF8gMYQeGQ) — a really in depth video that helped me get an idea of the project's structure and how to start it.
* [Portfolio Resources's video on mutexes](https://youtu.be/raLCgPK-Igc?si=8RUq5eNMpPerW14G) — a really thorough and straight to the point video that goes over the basic concepts of mutual exclusion and shared resources between multiple threads.
* [Linux Manual](https://www.man7.org) — for POSIX compliant thread creation, mutex handling and understanding/usage of corresponding funcitons.
* [w3schools.com](https://www.w3schools.com/) — great for 'explain me like im five' explainations when examples for all the core concepts when the Linux Manual gets a bit too hard to read.
* [Sourceware's entry on Debugging Programs with Multiple Threads](https://sourceware.org/gdb/current/onlinedocs/gdb.html/Threads.html) — really helpful and detailed instrucitions on how to better use GDB when debugging programs with multiple threads.
* [Dina ELgammal's Medium article about the project](https://medium.com/@denaelgammal/dining-philosophers-problem-42-project-guide-mandatory-part-a20fb8dc530e) — helpful guide overall and where I learned about the (lifesaving) -fsanitize flag to detect thrading problems while the program runs.
* [nafuka11](https://github.com/nafuka11/philosophers-visualizer)'s [visualizer](https://nafuka11.github.io/philosophers-visualizer/) — really great tool to visualize and detect problems in a simpler way, using a GUI instead of the logs the program outputs.


### AI Usage
Used copilot to understand the project's core concepts such as:
- Array of structs;
- Mutexes;
As well as help with pthread functions (how to use them, what arguments they expect and values they return)
