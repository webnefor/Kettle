# Kettle
The tool is helped to you to check your web site on Dos attack


-m:
regime mode: [http:0 or icmp:1] default: 0

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

    ./kettle -v google.com -m 1 -p 80 -t 25

<img width="551" alt="Screenshot 2024-06-30 at 20 46 06" src="https://github.com/webnefor/Kettle/assets/113185077/165146dc-86b4-482f-8d0d-b84e5e0b5c82">


