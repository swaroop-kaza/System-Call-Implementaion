
# What is it?
Implementation of new system calls in Linux.
  1) Hello world system call.
  2) System call to monitor all processes and their states.

1) Hello world system call
  Simple system call to print "hello world" to kernel log. In the user program, just call the system call with the corresponding new system call number. It goes to the system call definition and prints "hello world" to kernel log and return with a success/failure.
  
  
2) System call to monitor all processes and their states.
  It traverses through all processes and prints pid and corresponding state of all processes. In the end, it prints the total number of process, running process, sleeping process and terminated process to the kernel log. Call the system call in the user program and check the kernel log, you can see the current process running and sleeping process in your system. This is similar to "top" command in shell script. You can cross check the kernel log with "top" command to see the number of running and sleeping process.
  
You can check kernel log using the command "dmesg".

"dmesg" - shows the kernel log
"dmesg -c" - clears the kernel log. (It needs sudo access)

