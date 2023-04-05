# Process Schedule Simulation
## First Come First Serve
- Processes are served as they arrive. No preemption.

## Round Robin
- Processes are guaranteed a predetermined amount of time on the CPU - quanta.
- When given quanta has passed, process is preempted and put on back of queue.
- Algorithm is repeated until all processes are finished executing.

## Shortest Remaining Time First
- Processes are served until a process with a shorter CPU burst time arrives in the queue.
- Processes are preempted for process with shorter burst time.
- New process runs to completion or is preemmpted when new, shorter process arrives in queue.