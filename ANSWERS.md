**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

-   Created - This is when a process is first created. Typically not in this state very long.
-   Ready - The process has been loaded into the memory and waiting execution by the CPU.
-   Running - This is when the process has been moved to a CPU core and the instructions are being executed by the CPU.
-   Blocked - Process becomes blocked when it cannot carry out any further execution until and external change in state or event occurs. An example is when a program requires user input
-   Terminated - This is the state when the process has completed executing and before the parent process has cleaned it up. Also known as a zombie process at this point.

**2. What is a zombie process?**

-   A zombie process is the time when a process has ended and before it has been cleaned up by it's parent process

**3. How does a zombie process get created? How does one get destroyed?**

-   They get created when a child process exits and before the parent cleans it. The parent process is responsible for destorying it. If the process is orphaned the process with ID 1 is responsible for it.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

-   The speed at which the code exectures is faster since the compiled code works closer to the memory and hardware. More granular control over exacly what the program is doing and how many resources it does or does not take.
