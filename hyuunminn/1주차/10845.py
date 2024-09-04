from collections import deque
import sys
input = sys.stdin.readline

deq = deque()

N = int(input())

for _ in range(N):
    com = list(map(str, input().split()))

    if com[0] == "push":
        deq.append(com[1])

    elif com[0] == "pop":
        if len(deq) != 0:
            print(deq.popleft())
        else:
            print(-1)
        
    elif com[0] == "size":
        print(len(deq))

    elif com[0] == "empty":
        if len(deq) == 0:
            print(1)
        else:
            print(0)

    elif com[0] == "front":
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[0])

    elif com[0] == "back":
        if len(deq) == 0:
            print(-1)

        else:
            print(deq[-1])
    