---
typora-root-url: ../../../Hexo-blog/source
---

# 1 Lecture 1 -- Computer System & OS Overview

Based on Chapter 1 and 2 in textbook.

## 1.1 Basic Elements

The basic elements are processor, main memory, I/O modules and system bus.

### 1.1.1 Processor

- Referred to as the Central Processing Unit (CPU).
- Two internal components:
  - Control Unit
  - Arithmetic & Logic Unit (ALU)
- Controls operation and performs data processing
- Works repeatedly and continuounsly in cycles to execute instructions![machine-cycle](/images/3103img/machine-cycle.png)



### 1.1.2 Main Memory

- Referred to as primary memory or simply RAM.
- Consists of a set of locations defined by sequentially numbered addresses
- Stores data and programs
- Volatile
  - Contents of the memory is lost when the computer is shut down



### 1.1.3 I/O Modules

- **Moves data** between the computer and the external environment such as:
  - Storage (e.g. hard drive)
  - Communication equipment
  - Terminals



### 1.1.4 System Bus

- Provides for communications among processors, main memory and I/O modules

![top-level-view](/images/3103img/top-level-view.png)



## 1.2 Instruction Execution

- A program consists of a set of instructions stored in main memory.

- 4 steps in a machine cycle

  - Processor reads (fetches) an instruction from memory
  - Processor interprets (decodes) the current instruction
  - Processor executes the instruction
  - Processor stores the result back to memory

- Registers: special memory locations inside the processor that can be accessed very fast

  - Program Counter (PC) holds address of the instruction to be fetched next. PC is incremented after each fetch.
  - Fetched instruction loaded into Instruction Register (IR).
  - Execution result stored in Accumulator (AC) temporarily.
  - Program Status Word (PSW) contains execution status information. (Flags in Assembly Language)

- Each instruction contains bits (opcode) specifying whtat action the CPU needs to take

  - Processor-memory
  - processor-IO
  - data processing
  - Contol

  ![eg-program-execution](/images/3103img/eg-program-execution.png)



Consider the example above, the first digit in an instruction is the opcode (4 bits, 16 operations).

- 0001: Load AC from memory
- 0010: Store AC to memory
- 0101: Add memory to AC



## 1.3 Interrupts

An interrupt means other modules could interrupt the normal sequencing of the processor.

![interrupt-class](/images/3103img/interrupt-class.png)

Interrupts are provided to improve processor utilization. Since most peripheral modules are slower than the processor, if the processor pauses to wait for device, there will be a wasteful use of it.

Consider the following example showing the difference between no interruption, short I/O wait and long I/O wait.

![interrupt-comparison](/images/3103img/interrupt-comparison.png)

Case 1: No interrupts. When the technique is not used, the processor has to wait for the whole I/O operation to be completed. As the I/O operation takes time longer than the processor in million times order, it wastes the use of the processor a lot.

Case 2: Interrupts with shor I/O wait. The processor will proceed to the next operation while letting the I/O module execute the order itself. In this case, the I/O command will finish before the processor completes the next instruction. Therefore, it issues an interruption to let processor deal with the I/O operations, which takes only a short period of time.

Case 3: As in case 2, the processor lets the I/O module execute the I/O command. However, after it completes the next instruction, it may needs to wait for the I/O module to finish the command.

![intstruction-cycle-with-interrupts](/images/3103img/intstruction-cycle-with-interrupts.png)

To process the interrupt, the processor needs to find the way to store the current processing states (PC, PSW, and values in other registers). Program stack is used.

![simple-interrupt-processing](/images/3103img/simple-interrupt-processing.png)

![interrupt-memory-register-change](/images/3103img/interrupt-memory-register-change.png)



## 1.4 Uniprogramming and Multiprogramming

- Uniprogramming: only one program is running at a given time.

  The processor spends a certain amount of time executing. until it reaches an I/O instruction. It must then wait until that I/O instruction conclues before proceeding.

- Multiprogramming: processor has more than one program to execute.

  When one job needs to wait for I/O, the processor can switch to the other job.

(More notes about how it is different from multiprocessing will be added later on)

![multiprogramming-example](/images/3103img/multiprogramming-example.png)

With uniprogramming, there is gross underutilisation of all resources. The improvement of average resource utilisation, throughput and response times is evident if multiprogramming is used.



### 1.4.1 Difference Between Terminologies

- A multiprogramming system runs more than one program "simultaneously" on one processor. The system attempts to keep several **programs** resident in main memory and **switches the processor rapidly between them**. Multiprogramming was developed to improve processor I/O and resource utilization.
- A multiprocessor is a computer system with **more than one processor**. Multiprocessing was developed in an effort to increase processing speeds by allowing truly parallel computation.



## 1.5 The Memory Hierarchy

The memory hierarchy is designed to meet the constraints on a computer's memory. That is, how much?, how fast?, ane how expensive?

Going from top to down along the hierarchy, we shall observe

- Decreasing cost per bit
- Increasing capcity
- Increasing access time 
- Decreasing frequency of access to the memory by the processor

![memory-hierarhy](/images/3103img/memory-hierarhy.png)

### 1.5.1 Cache Memory

We know that the processor must access memory at least once per instruction cycle. Thus processor execution is limited by memory cycle time. buy processor speed is much faster than memory access speed.

The solution to this performance gap could be copying information in use from slower to faster (but smaller) storage temporarily. The storage is exactly cache.

Cache is checked first to determine if information is there.

- If it is, information is used directly from the cache.
- If not, data is copied to cache and used there.

Note that if the *hit ratio* is low, the time penalty for an idle cache access will make this design even more inefficient than the design without cache memory.

![hit-ratio-effect](/images/3103img/hit-ratio-effect.png)

By analysing a simple two-level memory, we shall find that the relationship is linear.

#### 1.5.1.1 Principle of Locality

Data which is required soon is often close to the current data. If data is accessed, then it's neighbors might also be accessed in the near future.

**Spatial locality** refers to the tendency of execution to involve a number of memory locations that are clustered while **temporal locality** refers to the tendency for a processor to access memory locations that have been used recently.



### 1.5.2 Secondary Memory

Secondary Memories are also known as storage devices

- Extension of main meory that provides large non-volatile storage capacity
- Used to store program and data files
- Most commonly used: magnetic disks
  - Disk surface is logically divided into tracks, which are subdivided into sectors
  - The disk controller determines the logical interaction between the device and the computer



## 1.6 I/O Communication Techniques

When the processor encounters an instruction related to I/O, it executes that instruction by using a command to the appropriate I/O module. There are three techniques possible for I/O operations:

- Programmed I/O
- Interrupt-driven I/O
- Direct memory access (DMA)

### 1.6.1 Programmed I/O

- CPU issues a read command to I/O module to read a word of data from an external device into memory.
- I/O module performs the requested action
  - then sets the appropriate bits in the I/O status register (but takes no further action to alert CPU)
- CPU periodically checks the status of I/O module until it determines the instruction is completed.
- The performance is poor.

<img src="/images/3103img/programmed-IO.png" style="zoom:50%" />



### 1.6.2 Interrupt-Driven I/O

- CPU issues a read command to I/O module and then goes on to do some other useful work
- I/O module will then interrupt CPU to request service when it is ready to exchange data with CPU.
- CPU executes the data transfer and then resumes its former processing
- More efficient than programmed I/O because there is no needless waiting. However, interrupt-driven I/O requires active intervention of CPU to perform data transfer

<img src="/images/3103img/interrupt-driven-IO.png" style="zoom:50%" />



### 1.6.3 Direct Memory Access

- Performed by a seperate module.
- When CPU wishes to read/write, it issues a command to DMA module containing
  - Whether a read or write is requested
  - The address of the I/O device involved
  - The starting location in memory to read/write
  - The number of words to be read/written
- DMA module transfers the entire block of data directly to and from memory without going through CPU.
- More efficient than interrupt-driven I/O

<img src="/images/3103img/direct-memory-access.png" style="zoom:50%" />



## 1.7 Operating System Objectives & Functions

OS is a program that controls the execution of application programs. It acts as an interface between applications and hardware.

Main objectives:

- *Convenience*: making a computer more convenient to use
- *Efficiency*: allowing computer resources to be used efficiently
- *Ability to involve*: permitting effective development, testing and introduction of new system functions such as hardware upgrade, new hardware, new services, and fixes.



### 1.7.1 OS as a User/Computer Interface

- End user views a computer system in terms of a set of applications and is not concerned with the details of computer hardware.

- Programme makes use of a set of system programs (utilities) in developing an application and a running application invokes the utilities to perform certain functions
- The most important collection of system programs comprises the OS.



### 1.7.2 OS Services

- Program development

  OS provides a variety of facilities and services, such as editors and debuggers, to assist the programmer in creating programs.

- Program execution

  OS handles steps need to be performed to execute a program.

- Access I/O devices

  OS provides a uniform interface so that programmers can access I/O devices using simple reads and writes.

- Controlled access to files

  In the case of a system with multiple users, OS provides protection mechanisms to control access to the files

- System access

  For shared or public systems, OS controls access to the system as a whole and to specific system resources in order to provide protection of resources and data from unauthorized users and resolve conflicts for resource contention.

- Error detection and response

  A variety of errors can occur while a computer system is running. OS must provide a response that clears the error condition with the least impact on running applications.

- Accounting

  A good OS will collect usage statistics for various resources and monitor performance parameters such as response time.





### 1.7.3 OS as Resource Manager

<img src="/images/3103img/os-resource-management.png" style="zoom:50%" />

- A computer is a set of resources for the movement, storage, and processing of data
- The OS is responsible for managing these resources
  - determines how much processor time is to be devoted to the execution of a particular user program
  - controls the allocation of main memory
  - decides when an I/O device can be used by a program in execution
  - controls access to and use of files



# 2 Lecture 2 -- Process Desctiption and Control

## 2.1 How are processes represented and controlled by the OS?

### 2.1.1 The Concept of Process

All modern OS rely on a model in which the execution of an application corresponds to the existence of one or more processes.

Process:

- A program in execution
- An instance of a program running on a computer
- The entity that can be assigned to and executed on a processor
- A unit of activity characterised by the execution of a sequence of instructions, a current state, and an associated set of system resources

A process is comprised of:

- Program code
- Associated data needed by the program
- Execution context of the program. containing all information the OS needs to manage the process



### 2.1.2 Requirements of an OS

- Fundamental task: **process management**
- The operating system must:
  - Interleave the execution of multiple processes
  - Allocate resources to processes and protect the resources of each process from other processes
  - Enable processes to share and exchange information
  - Enable synchronisation among processes



Example: Interleaved Execution of Processes

Omitted. See lecture notes and the textbook.



## 2.2 Process States

### 2.2.1 Two-State Process Model

- OS creates a new process and enters it into the system
- Process may be in one of two states
  - Running
  - Not running



<img src="/images/3103img/two-state-process-model.png" style="zoom:50%" />

- Processes that are not running are kept in some sort of queue, waiting for their turn to execute. Processes moved by the dispatcher of the OS to the CPU then back to the queue until the task is completed.



### 2.2.2 Five-State Process Model

While some processes in the Not Running state are ready to execute, others may be blocked (e.g., waiting for an I/O operation to complete)

<img src="/images/3103img/five-state-process-model.png" style="zoom:50%" />

- Running: The process that is currently being executed.
- Ready: A process that is prepared to execute when given the opportunity
- New: A process that has just been created but has not yet been admitted to the pool of executable processes by the OS. Typically, a new process has not yet been loaded into main memory, although its process control block has been created.

- Blocked: A process that cannot execute until some event occurs, such as the completion of an I/O operation
- Exit: A process that has been released from the pool of executable processes by the OS, either because it halted or because it aborted for some reason.



We can either use two queues - one `READY_QUEUE` and another `BLOCKED QUEUE`, or use multiple blocked queues, which seperates the events of blocking.

### 2.2.3 Suspended Processes

- Processor is faster than I/O so all processes could be waiting for I/O. Therefore, processor could be idle most of the time.
- As a result, when none of the processes in the main memory is in the ready state, OS swaps one of the blocked processes out **on to disk** to free up more memory and use processor on othger processes.
- Blocked state becomes **suspend** state when swapped to disk.



<img src="/images/3103img/one-suspend-state.png" style="zoom:75%" />

However, it does no good to activate a suspended process in blocked state. For this reason, a model of two states `Blocked/Suspend` and `Ready/Suspend` is introduced.



<img src="/images/3103img/two-suspend-state.png" style="zoom:75%" />

Here, we summarize the reason for process suspension:

| Reason                   | Comment                                                      |
| ------------------------ | ------------------------------------------------------------ |
| Swapping                 | The OS needs to release sufficient main memory to bring in a process that is ready to execute |
| Other OS Reasons         | OS suspects process of causing a problem                     |
| Interactive User Request | User may wish to suspend execution of a program for purpose of debugging |
| Timing                   | A process may be executed periodically (e.g., an accounting or system monitoring process) and may be suspended while waiting for the next time |
| Parent Process Request   | A parent process may wish to suspend execution of a descendent to examine or modify the suspended process, or to coordinate the activity of various descendents. |



## 2.3 Data Structures Used to Manage Processes

OS manages the use of system resource by processes.

<img src="/images/3103img/process-and-resources.png" style="zoom:75%" />

In this snapshot, process $P_1$ is running and it has 2 I/O devices; $P_2$ is blocked waiting in memory for an I/O device allocated to $P_1$; $P_n$ has been swapped out and is suspended.



### 2.3.1 Operating System Control Structures

- For the OS to manage processes and resources, it must have information about the current status of each process and resource
- Tables are constructed for each entity the OS manages.

<img src="/images/3103img/os-control-tables.png" style="zoom:75%" />



### 2.3.2 Memory Tables

- Memory tables are used to keep track of both main (real) and secondary (virtual) memory.
- The following information must be included:
  - Allocation of main memory to processes
  - Allocation of secondary memory to processes
  - Protection attributes of blocks of main or virtual memory such as which processes may access certain shared memory regions
  - Information needed to manage virtual memory



### 2.3.3 I/O Tables

- Used by the OS to manage the I/O devices and channels of the computer
- At any given time, an I/O device may be available or assigned to a particular process
- If an I/O operation is in process, the OS needs to know:
  - The status of the I/O operation
  - The location in main memory being used as the source or the destination of the I/O transfer



### 2.3.4 File Tables

- These tables provide information about:
  - Existence of files
  - Location on secondary memory
  - Current status
  - Other attributes
- Sometimes this information is maintained by a file management system.



### 2.3.5 Process Table

- To manage and control a process, there is one entry for each process in the process table.
- Each entry points to a *process image* containing:
  - **User Data**: The modifiable part of the user space. May include program data, a user stack area, and programs that may be modified.
  - **User Program**: The program to be executed.
  - **Stack**: Each process has one or more LIFO stacks associated with it. A stack is used to store parameters and calling addresses for procedure and system calls.
  - **Process Control Block**: Data needed by the OS to control the process



#### 2.3.5.1 Process Control Block

- Each process has associated with it a number of attributes that are used by the OS for process control.
- The attributes are stored in a data structure called a process control block (PCB), created and managed by the OS.
- PCB contains sufficient information so that it is possible to interrupt a running process and later resume its execution.
- Information stored in PCB can grouped into three categories:
  - Process identification
  - Process state information
  - Process control information



##### 2.3.5.1.1 Process Identification

Each process is assigned a unique numeric identifier. Use:

- Many of the tables controlled by the OS may use process identifiers to cross-reference process tables.

  Example: Memory tables may be organized to provide a map of main memory of an indication of which process is assigned to which region.

- When processes communicate with one another, the process identifier informs the OS of the destination of a particular communication.

- When processes are allowed to create other processes, identifiers indicate the parent and descendents of each process.



##### 2.3.5.1.2 Process State Information

- Consists of processor registers' content
  - User-visible registers
  - Control and status registers
    - Program counter: address of next instruction
    - Program status word (PSW):
      - Condition codes: result of the most recent arithmetic or logical operation
      - Status information: e.g., interrupt enabled/disabled flags, execution mode
  - Stack pointers



##### 2.3.5.1.3 Process Control Information

- The additional information needed by the OS to control and coordinate the various active processes
  - Process state
  - Priority
  - Scheduling-related info
  - Waiting event
  - Data structuring
  - ... (See table 5, page 130 in textbook)



#### 2.3.5.2 Process List Structures

The queuing structure could be implemented as linked lists of PCBs in which pointers can be stored in the PCBs (structuring information).

<img src="/images/3103img/process-list-structures.png" style="zoom:50%" />



#### 2.3.5.3 Structure of Process Images in Virtual Memory

<img src="/images/3103img/process-images-virtual.png" style="zoom:75%" />



#### 2.3.5.4 Role of the Process Control Block

- PCB is the most important data structure in an OS
  - Contains all of the information about a process that is needed by the OS
  - Read and/or modified by virtually every module in the OS such as scheduling, resource allocation, interrupt processing and performance monitoring
  - Defines the state of the OS
- PCB requires protection, which is difficult
  - A faulty routine could damage PCBs, which could destroy the OS's ability to manage the affected processes.
  - Any design change to the PCB could affect many modules of the OS



## 2.4 Process Control

### 2.4.1 Modes of Execution

Most processors support at least two modes of execution to protect the OS and key OS tables from interference by user programs.

User mode:

- Less-privileged mode
- User programs typically execute in this mode

System mode (control mode or kernel mode):

- More-privileged mode
- **Kernel** of the operating system (central module of an OS)
  - Loads first when the system starts
  - Resides in memory (in a protected area) all the time



### 2.4.2 Functions of an OS kernel

1. Process management
   - Process creation and termination
   - Process scheduling and dispatching
   - Process switching
   - Process sychronization and support for interprocess communication
   - Management of process control blocks
2. Memory management
   - Allocation of address space to processes
   - Swapping
   - Page and segment management
3. I/O management
   - Buffer management
   - Allocation of I/O channels and devices to processes
4. Support Functions
   - Interrupt handling
   - Accounting
   - Monitoring



### 2.4.3 Process Creation

Once the OS decides to create a new process, it

- Assigns a unique process identifier and adds a new entry to the process table
- Allocates space for the processes (process image)
- Initializes process control block
- Sets up appropriate linkages such as putting the new process in the Ready List
- Creates or expands other data structures such as an accounting file for performance assessment



### 2.4.4 Process Switching

A process switch may occur any time that the OS has gained control from the currently running process. When CPU switches to another process, the system must have the state of the old process and load the saved state for the new process (to be described).

Process-switch time is considered as overhead, so several issues are important

- What events triggers the switch?
- What must the OS do to the various data structures to achieve such a process switch?



Possible events giving OS control are:

| Mechanism                         | Cause                                                        | Use                                            |
| --------------------------------- | ------------------------------------------------------------ | ---------------------------------------------- |
| Interrupt                         | External to the execution of the current instruction. e.g., clock interrupt, I/O interrupt | Reaction to an asynchronus external event      |
| Trap                              | Associated with the execution of the current instruction, e.g., illegal file access | Handling of an error or an exception condition |
| System call (for supervisor call) | Explicit request, e.g., file open                            | Call to an operating system function           |



Steps:

1. Save the context of processor including program counter and other registers
2. Update the PCB of the process currently in the running state
3. Move the PCB of this process to appropriate queue - ready or blocked or ready/suspend
4. Select another process for execution
5. Update the PCB of the process selected
6. Update memory management data structures
7. Restore context of the processor to that which existed at the time the selected process was last switched out.



### 2.4.5 Mode Switching

- The occurrence of an interrupt does not necessarily mean a process switch
- It is possible that, after the processor switches from user mode to kernel mode in order to execute the interrupt handler (which may include privileged instructions), the currently running process will resume its execution.
- In such a mode switching case, only need to save and restore processor state information.



## 2.5 Process Management in UNIX

### 2.5.1 UNIX Overview

System process run in kernel mode

- executes operating system code to perform administrative and housekeeping functions

User processes

- operate in user mode to execute user programs and utilities
- operate in kernel mode to execute instructions that belong to the kernel
- enter kernel mode by issuing a system call, when an exception is generated or when an interrupt occurs



### 2.5.2 UNIX Process States

<img src="/images/3103img/unix-state-transition.png" style="zoom:75%" />

- **User running**: Executing in user mode
- **Kernel running**: Executing in kernel mode
- **Asleep in memory:** Unable to execute until an event occurs; process is in main memory (block state)
- **Ready to run in memory**: Ready to run as soon as the kernel schedules it
- **Ready to run, swapped**: Process is ready to run, but the swapper must swap the process into main memory before the kernel can schedule it to execute
- **Sleeping, swapped**: The process is awaiting an event and has been swapped to secondary storage
- **Preempted**: Process is returning from kernel to user mode, but the kernel preempts it and does a process switch to schedule another process (overhead)
- **Created**: Process is newly created and not yet ready to run
- **Zombie**: Process no longer exists, but it leaves a record for its parent process to collect



### 2.5.3 Case study: What happens when you call `fork()`?

This causes the OS, in kernel mode, to:

1. Allocate a slot in the process table for the new process.
2. Assign a unique process ID to the child process.
3. Make a copy of the process image of the parent, with the exception of any shared memory
4. Increment counters for any files owned by the parent, to reflect that an additional process now also owns these files
5. Assign the child process to the Ready to Run state
6. Return the ID number of the child to the parent process, and a 0 value to the child process



After creating the process, the kernel can do one of the following, as part of the dispatcher routine:

- Stay in the parent process
  - Control returns to user mode at the point of the fork call of the parent
- Transfer control to the child process
  - The child process begins executing at the same point in the code as the parent, namely at the return from the fork call
- Transfer control to another process
  - Both parent and child are left in the Ready to Run state