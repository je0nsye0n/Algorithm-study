from collections import deque
import sys
input = sys.stdin.readline


n = int(input())
que = deque()
max, max_num = 0, 0
tmp = 0
result = []

for _ in range(n):
    info = list(map(int, input().split()))

    if info[0] == 1:
        que.append(info[1])
    else:
        que.popleft()

    tmp = len(que)
    if max <= tmp and tmp > 0:
        if max == tmp:
            if max_num > que[-1]:
                max_num = que[-1]
        else:
            max = tmp
            max_num = que[-1]

        


print(max, max_num)