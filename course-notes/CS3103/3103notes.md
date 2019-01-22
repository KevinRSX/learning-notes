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
- Works repeatedly and continuounsly in cycles to execute instructions

![machine-cycle](images/machine-cycle.png)



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

![top-level-view](images/top-level-view.png)



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

  ![eg-program-execution](images/eg-program-execution.png)



Consider the example above, the first digit in an instruction is the opcode (4 bits, 16 operations).

- 0001: Load AC from memory
- 0010: Store AC to memory
- 0101: Add memory to AC



## 1.3 Interrupts

An interrupt means other modules could interrupt the normal sequencing of the processor.

![interrupt-class](images/interrupt-class.png)

Interrupts are provided to improve processor utilization. Since most peripheral modules are slower than the processor, if the processor pauses to wait for device, there will be a wasteful use of it.

Consider the following example showing the difference between no interruption, short I/O wait and long I/O wait.

![interrupt-comparison](images/interrupt-comparison.png)

Case 1: No interrupts. When the technique is not used, the processor has to wait for the whole I/O operation to be completed. As the I/O operation takes time longer than the processor in million times order, it wastes the use of the processor a lot.

Case 2: Interrupts with shor I/O wait. The processor will proceed to the next operation while letting the I/O module execute the order itself. In this case, the I/O command will finish before the processor completes the next instruction. Therefore, it issues an interruption to let processor deal with the I/O operations, which takes only a short period of time.

Case 3: As in case 2, the processor lets the I/O module execute the I/O command. However, after it completes the next instruction, it may needs to wait for the I/O module to finish the command.

![intstruction-cycle-with-interrupts](images/intstruction-cycle-with-interrupts.png)

To process the interrupt, the processor needs to find the way to store the current processing states (PC, PSW, and values in other registers). Program stack is used.

![simple-interrupt-processing](images/simple-interrupt-processing.png)

![interrupt-memory-register-change](images/interrupt-memory-register-change.png)



## 1.4 Uniprogramming and Multiprogramming

- Uniprogramming: only one program is running at a given time.

  The processor spends a certain amount of time executing. until it reaches an I/O instruction. It must then wait until that I/O instruction conclues before proceeding.

- Multiprogramming: processor has more than one program to execute.

  When one job needs to wait for I/O, the processor can switch to the other job.

(More notes about how it is different from multiprocessing will be added later on)

![multiprogramming-example](images/multiprogramming-example.png)

With uniprogramming, there is gross underutilisation of all resources. The improvement of average resource utilisation, throughput and response times is evident if multiprogramming is used.



## 1.5 The Memory Hierarchy

The memory hierarchy is designed to meet the constraints on a computer's memory. That is, how much?, how fast?, ane how expensive?

Going from top to down along the hierarchy, we shall observe

- Decreasing cost per bit
- Increasing capcity
- Increasing access time
- Decreasing frequency of access to the memory by the processor

![memory-hierarhy](images/memory-hierarhy.png)

### 1.5.1 Cache Memory

We know that the processor must access memory at least once per instruction cycle. Thus processor execution is limited by memory cycle time. buy processor speed is much faster than memory access speed.

The solution to this performance gap could be copying information in use from slower to faster (but smaller) storage temporarily. The storage is exactly cache.

Cache is checked first to determine if information is there.

- If it is, information is used directly from the cache.
- If not, data is copied to cache and used there.

Note that if the *hit ratio* is low, the time penalty for an idle cache access will make this design even more inefficient than the design without cache memory.

![hit-ratio-effect](images/hit-ratio-effect.png)

By analysing a simple two-level memory, we shall find that the relationship is linear.

#### 1.5.1.1 Principle of Locality

Data which is required soon is often close to the current data. If data is accessed, then it's neighbors might also be accessed in the near future.

**Spatial locality** refers to the tendency of execution to involve a number of memory locations that are clustered while **temporal locality** refers to the tendency for a processor to access memory locations that have been used recently.



### 1.5.3 Secondary Memory

Secondary Memories are also known as storage devices

- Extension of main meory that provides large non-volatile storage capacity
- Used to store program and data files
- Most commonly used: magnetic disks
  - Disk surface is logically divided into tracks, which are subdivided into sectors
  - The disk controller determines the logical interaction between the device and the computer