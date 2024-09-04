import sys
input = sys.stdin.readline

N = int(input())
stack = []

for _ in range(N):
    com = list(map(str, input().split()))
    if com[0] == "push":
        stack.append(com[1])

    elif com[0] == "pop":
        if len(stack) != 0:
            print(stack.pop())
        else:
            print(-1)
        
    elif com[0] == "size":
        print(len(stack))

    elif com[0] == "empty":
        if len(stack) == 0:
            print(1)
        else:
            print(0)

    else:
        if len(stack) != 0:
            print(stack[-1])
        else:
            print(-1)