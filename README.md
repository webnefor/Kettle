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

    cmake CMakeLists.txt && make


Example:

    ./kettle -v google.com -p 80 -t 25 

    
<img width="505" alt="Screenshot 2024-02-26 at 19 28 32" src="https://github.com/seout/Kettle/assets/113185077/f555192a-0378-4ace-84c0-9515ba09e7c5">

