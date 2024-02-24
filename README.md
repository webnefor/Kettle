# Kettle
The tool is helped to you to check your web site on Dos attack


-m:
regime mode: [http or icmp] (default tcp)

-v:
entering target: (target.com)

-p:
entering target's port: (default 80)

-t:
indicated the number of thread: (default 2)

-i:
entering time: (default 1s)

-h:
HELP

How to compile:

    cmake CMakeLists.txt && make && make clean


Example:

    ./Kettle -v google.com -p 80 -t 25 
    
<img width="494" alt="Screenshot 2024-02-24 at 01 29 10" src="https://github.com/seout/Kettle/assets/113185077/f21d9af4-510d-49f6-82f4-f2f2d1f4acd5">
