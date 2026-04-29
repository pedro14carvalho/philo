*This project has been created as part of the 42 curriculum by josepedr.*
# Philosophers


## Description
The Dining Philosophers problem is a classic synchronization and concurrency project from the 42 School curriculum. The objective is to learn the basics of creating a program with multiple threads and managing shared resources.

In this simulation, a group of philosophers sit at a round table. They can only do three things: **eat**, **sleep**, or **think**. To eat, a philosopher needs two forks. The challenge is to manage the shared resources (the forks) using **mutexes** to prevent data races, deadlocks, and ensure that no philosopher starves to death.

## Incstructions

#### Compilation:
```bash
make
```
This automatically compiles the program with the appropriate thread flag (`-pthread`), alongside the standard 42 School flags for C projects (`-Wall -Werror -Wextra`).


#### Usage:
Run the simulation using the following syntax:
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]
```

| Argument | Description |
| --- | --- |
| `num_of_philosophers` | number of philosophers sitting around the table |
| `time_to_die` | time (in milliseconds) a philosopher can survive without eating (min. 60ms). If a philosopher doesn't start eating withing this time frame, they die |
| `time_to_eat` | time (in milliseconds) it takes for a philosopher to eat (min. 60ms) |
| `time_to_sleep` | time (in milliseconds) a philosopher spends sleeping (min. 60ms) |
| `number_of_meals` | *(Optional)* ammount of meals **all** philosophers must eat to stop the simulation (min. 1)|


## Resources


### References
* [Oceano's video on the philosopher's project](https://youtu.be/zOpzGHwJ3MU?si=Yj_X0piF8gMYQeGQ) — a really in depth video that helped me get an idea of the project's structure and how to start it.
* [Portfolio Resources's video on mutexes](https://youtu.be/raLCgPK-Igc?si=8RUq5eNMpPerW14G) — a really thorough and straight to the point video that goes over the basic concepts of mutual exclusion and shared resources between multiple threads.
* [Linux Manual](https://www.man7.org) — for POSIX compliant thread creation, mutex handling and understanding/usage of corresponding funcitons.
* [w3schools.com](https://www.w3schools.com/) — great for "explain to me like im five" explainations with examples for all the core concepts when the Linux Manual gets a bit too difficult to understand.
* [Sourceware's entry on Debugging Programs with Multiple Threads](https://sourceware.org/gdb/current/onlinedocs/gdb.html/Threads.html) — really helpful and detailed instructions on how to better use `gdb` when debugging programs with multiple threads.
* [Dina ELgammal's Medium article about the project](https://medium.com/@denaelgammal/dining-philosophers-problem-42-project-guide-mandatory-part-a20fb8dc530e) — helpful guide overall and where I learned about the (lifesaving) -fsanitize flag to detect thrading problems while the program runs.
* [nafuka11](https://github.com/nafuka11/philosophers-visualizer)'s [visualizer](https://nafuka11.github.io/philosophers-visualizer/) — really great tool to visualize and detect problems in a simpler way, using a GUI instead of the logs the program outputs.


### AI Usage
Used copilot to understand the project's core concepts such as:
- Structuring array of structs;
- Concept and application of mutexes;
- Assistance with `pthread` functions (how to use them, what arguments they expect and the values they return);
- Help with debugging when 'gdb' was not enough (it's really hard to debug multiple threads!!!).
