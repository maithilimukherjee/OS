# OS — Operating Systems Examples

This repository is a collection of small programs and scripts demonstrating common operating-systems concepts used in introductory OS / systems programming labs: process creation and control (zombies, orphans, exec), signal handling, and simple shell-like / utility shell scripts.

Repository structure
- ZombiesAndOrphans/ — examples that demonstrate zombie and orphan processes and how to avoid zombies.
- exec/ — small C programs illustrating usage of the exec family (replacing a process image).
- shell/ — a set of small shell scripts implementing common programming exercises (sorting, numeric checks, string operations).
- signals/ — C programs that demonstrate signal handling and process control (SIGINT, stop/continue, sending signals, etc).

Below is a guided overview of every folder and file with compile/run instructions and short descriptions.

---

## ZombiesAndOrphans

Files:
- nozombiespls.c — https://github.com/maithilimukherjee/OS/blob/main/ZombiesAndOrphans/nozombiespls.c  
  Likely demonstrates how to prevent zombie processes (e.g., using wait/waitpid or signal handlers to reap children). Compile: `gcc -Wall -o nozombiespls ZombiesAndOrphans/nozombiespls.c` Run: `./nozombiespls`
- orphan.c — https://github.com/maithilimukherjee/OS/blob/main/ZombiesAndOrphans/orphan.c  
  Demonstrates creating a child process that becomes an orphan and gets adopted by init (or systemd) when the parent exits. Compile: `gcc -Wall -o orphan ZombiesAndOrphans/orphan.c` Run: `./orphan`
- zombie.c — https://github.com/maithilimukherjee/OS/blob/main/ZombiesAndOrphans/zombie.c  
  Demonstrates creation of a zombie process (child exits while parent does not wait). Compile: `gcc -Wall -o zombie ZombiesAndOrphans/zombie.c` Run: `./zombie` — observe `ps` or `top` to see the zombie entry.

Common tips:
- Use `ps -l` or `ps aux | grep <program>` to observe states (Z = zombie).
- If a program demonstrates zombies, you can observe parent PID and child PID, and see the child with a "Z" state until parent reaps it.

---

## exec

Files:
- ex1.c — https://github.com/maithilimukherjee/OS/blob/main/exec/ex1.c  
- ex2.c — https://github.com/maithilimukherjee/OS/blob/main/exec/ex2.c  
- ex3.c — https://github.com/maithilimukherjee/OS/blob/main/exec/ex3.c  
- ex4.c — https://github.com/maithilimukherjee/OS/blob/main/exec/ex4.c  
- ex5.c — https://github.com/maithilimukherjee/OS/blob/main/exec/ex5.c  
- ex6.c — https://github.com/maithilimukherjee/OS/blob/main/exec/ex6.c  

Purpose:
These examples illustrate use of the exec family of functions (execl, execlp, execv, execvp, execle, execve) to replace the current process image with a new program. Each example typically demonstrates a different exec variant or a different way to set arguments/environment.

Compile & run:
- Compile each example: `gcc -Wall -o ex1 exec/ex1.c` (replace ex1/ex1.c accordingly)
- Run: `./ex1` (some examples expect command-line args; see source or experiment)

Notes:
- If any example forks before exec, you'll see parent/child behavior; otherwise exec replaces the process so subsequent code in that process won't run.
- Use `strace ./exN` to inspect the system calls (useful to see execve system call).

---

## shell

Small shell scripts (bash) that implement various typical programming tasks. Make executable and run:

General usage:
- `chmod +x shell/<script>.sh`
- `./shell/<script>.sh` (or run with `bash shell/<script>.sh`)

Files:
- armstrong.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/armstrong.sh  
  Check whether a number is an Armstrong (narcissistic) number.
- bubblesort.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/bubblesort.sh  
  Implements bubble sort on a list of numbers (interactive or via arguments).
- countchar.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/countchar.sh  
  Counts occurrences of a character in an input string or file.
- delpos.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/delpos.sh  
  Deletes an element at a specified position from a list or array.
- descending.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/descending.sh  
  Sorts numbers in descending order (likely simple sort using loops).
- factorial.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/factorial.sh  
  Computes factorial of a number (iterative or recursive).
- fib.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/fib.sh  
  Prints Fibonacci sequence or the nth Fibonacci number.
- gcd.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/gcd.sh  
  Computes the greatest common divisor of two integers (Euclidean algorithm).
- isprime.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/isprime.sh  
  Tests if a given number is prime.
- minmax.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/minmax.sh  
  Finds minimum and maximum in a list of numbers.
- processinf.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/processinf.sh  
  Prints process-related info (PID, PPID, maybe process status) or system process info.
- substr.sh — https://github.com/maithilimukherjee/OS/blob/main/shell/substr.sh  
  Extracts substring from a string (using shell parameter expansion or cut).

These scripts are useful as quick demos of shell programming and basic algorithm implementations.

---

## signals

Files:
- ctrlc.c — https://github.com/maithilimukherjee/OS/blob/main/signals/ctrlc.c  
  Demonstrates handling SIGINT (Ctrl-C). Likely installs a signal handler to intercept SIGINT and perform a custom action (e.g., cleanup or toggling behavior).
  Compile: `gcc -Wall -o ctrlc signals/ctrlc.c`
- killProcess.c — https://github.com/maithilimukherjee/OS/blob/main/signals/killProcess.c  
  Demonstrates sending signals to a process programmatically (using kill()) or how to receive/handle signals.
  Compile: `gcc -Wall -o killProcess signals/killProcess.c`
- orphans.c — https://github.com/maithilimukherjee/OS/blob/main/signals/orphans.c  
  Another program demonstrating orphan processes and possibly signal behavior when parent exits.
  Compile: `gcc -Wall -o orphans signals/orphans.c`
- pcTango.c — https://github.com/maithilimukherjee/OS/blob/main/signals/pcTango.c  
  Likely demonstrates coordination (a “tango”) between parent and child using signals (e.g., parent and child sending signals back-and-forth).
  Compile: `gcc -Wall -o pcTango signals/pcTango.c`
- resumeProcess.c — https://github.com/maithilimukherjee/OS/blob/main/signals/resumeProcess.c  
  Demonstrates stopping and resuming processes (SIGSTOP / SIGCONT) or handling signals that pause/resume program execution.
  Compile: `gcc -Wall -o resumeProcess signals/resumeProcess.c`

How to test signal programs:
- Run the program in one terminal, then send signals from another: `kill -SIGINT <pid>` or `kill -SIGSTOP <pid>` / `kill -SIGCONT <pid>`.
- Use Ctrl-C to send SIGINT if the program catches and handles it.
- Use `ps` to determine PIDs.

---

## Build & Run (summary)

1. Build all C programs (simple loop):
   - Example (Linux/macOS):
     - cd to repo root
     - For a specific file: `gcc -Wall -o bin/zombie ZombiesAndOrphans/zombie.c`
     - Or build many: `gcc -Wall -o bin/ctrlc signals/ctrlc.c && gcc -Wall -o bin/zombie ZombiesAndOrphans/zombie.c` etc.
2. Run:
   - C programs: `./bin/<program>`
   - Shell scripts: `bash shell/<script>.sh` or `chmod +x shell/<script>.sh && ./shell/<script>.sh`
3. Inspect processes:
   - Use `ps`, `top`, `pgrep`, `pstree` to observe child/parent relationships, zombie state, and signals.

---

## Notes & recommendations

- This repository contains small learning examples. The exact behavior (arguments, interactive prompts) is defined in each source file. Read the code for precise usage.
- Consider adding:
  - A top-level Makefile to build all C programs and place binaries in a `bin/` folder.
  - A LICENSE file if you want to specify reuse terms.
  - A CONTRIBUTING.md with guidelines if you expect collaborators.

---

## Quick links to files

ZombiesAndOrphans
- https://github.com/maithilimukherjee/OS/blob/main/ZombiesAndOrphans/nozombiespls.c
- https://github.com/maithilimukherjee/OS/blob/main/ZombiesAndOrphans/orphan.c
- https://github.com/maithilimukherjee/OS/blob/main/ZombiesAndOrphans/zombie.c

exec
- https://github.com/maithilimukherjee/OS/blob/main/exec/ex1.c
- https://github.com/maithilimukherjee/OS/blob/main/exec/ex2.c
- https://github.com/maithilimukherjee/OS/blob/main/exec/ex3.c
- https://github.com/maithilimukherjee/OS/blob/main/exec/ex4.c
- https://github.com/maithilimukherjee/OS/blob/main/exec/ex5.c
- https://github.com/maithilimukherjee/OS/blob/main/exec/ex6.c

shell
- https://github.com/maithilimukherjee/OS/blob/main/shell/armstrong.sh
- https://github.com/maithilimukherjee/OS/blob/main/shell/bubblesort.sh
- https://github.com/maithilimukherjee/OS/blob/main/shell/countchar.sh
- https://github.com/maithilimukherjee/OS/blob/main/shell/delpos.sh
- https://github.com/maithilimukherjee/OS/blob/main/shell/descending.sh
- https://github.com/maithilimukherjee/OS/blob/main/shell/factorial.sh
- https://github.com/maithilimukherjee/OS/blob/main/shell/fib.sh
- https://github.com/maithilimukherjee/OS/blob/main/shell/gcd.sh
- https://github.com/maithilimukherjee/OS/blob/main/shell/isprime.sh
- https://github.com/maithilimukherjee/OS/blob/main/shell/minmax.sh
- https://github.com/maithilimukherjee/OS/blob/main/shell/processinf.sh
- https://github.com/maithilimukherjee/OS/blob/main/shell/substr.sh

signals
- https://github.com/maithilimukherjee/OS/blob/main/signals/ctrlc.c
- https://github.com/maithilimukherjee/OS/blob/main/signals/killProcess.c
- https://github.com/maithilimukherjee/OS/blob/main/signals/orphans.c
- https://github.com/maithilimukherjee/OS/blob/main/signals/pcTango.c
- https://github.com/maithilimukherjee/OS/blob/main/signals/resumeProcess.c

---

