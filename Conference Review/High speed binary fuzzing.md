# High speed binary fuzzing
https://github.com/HexHive/retrowrite
https://media.ccc.de/v/36c3-10880-no_source_no_problem_high_speed_binary_fuzzing
http://nebelwelt.net/publications/files/19CCC-presentation.pdf
## Effective fuzzing 101
* Test cases must trigger bugs
    * Coverage-guided fuzzing
* The fuzzer must detect bugs
    * Sanitization
* Speed is key (zero sum game)

## Fuzzing with source code
* Add instrumentation at compile time
    * Short snippets of code for coverage tracking, sanitization, ...
Source code -> Compiler(Coverage tracking, sanitization, ...) -> Instrumented binary

## Rewriting binaries
* Approach 0: black box fuzzing
* Approach 1: rewrite dynamically
    * Translate target at runtime
    * Terrible performance (10-100x slower)
* Approach 2: rewrite statically
    * More complex analysis
    * ...but much better performance!

## Position-independent code
* Code that can be loaded at any address
* Required for: ASLR, shared libraries
* Cannot use hardcoded static addresses
    * Must use relative addressing instead
* On x86_64, PIC leverages RIP-relative addressing
    * lea rax, [rip + 0x1234]
* Distinguish references from constants in PIE binaries
    * RIP-relative = reference, everything else = constant

## Address Sanitizer (ASan)
* Instrumentation catches memory corruption at runtime
    * Arguably most dangerous class of bugs
* Very popular sanitizer
    * Thousands of bugs in Chrome and Linux
* About 2x slowdown

## Kernel vs. userspace fuzzing
|   | Crash handling | Tooling | Determinism |
| -------- | -------- | -------- | -------- |
| Userspace| OS handles crashes gracefully| Easy to use and widely available | Single-threaded code usually deterministic|
| Kernel | Need VM to keep the system stable | More complex setup, fewer tools | Interrupts, many concurrent threads|

## Kernel binary fuzzing
* Approach 0: black box fuzzing
* Approach 1: dynamic translation
    * Slow! (10x +)
    * No sanitization like ASan
* Approach 2: Intel Processor Trace (or similar)
    * Requires hardware support
    * Still no sanitization
* Approach 3: static rewriting

## kRetroWrite
* Kernel modules are always position-independent
* Linux modules are ELF files
    * Reuse RetroWrite’s symbolizer
* Implemented code coverage and binary ASan

## kRetroWrite coverage
* Idea: use kCov infrastructure
    * Can interoperate with source-based kCov
* Call coverage collector at the start of each basic block
* Integrates with, e.g., syzkaller, or debugfs