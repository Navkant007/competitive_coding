"""
In a network of computers (nodes), an infected node (computer having a malware) can transmit the malware to other nodes and infect them.
Given a list of network traces, find out the nodes who have started the malware transmission.
The network traces are given in the form of pair [a,b] which means node 'a' transmited malware to node 'b'.
Example:
Input:
[[1, 2 ], [1, 3], [2, 4], [2, 5], [6, 4]]
Output:
[1, 6]


1: 2, 3, 4
2: 4, 5
6: 4
"""

def main():
    data = list(map(int, input().split()))
    print(data)

if __name__ == "__main__":
    main()