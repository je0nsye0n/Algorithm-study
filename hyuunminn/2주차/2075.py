from queue import PriorityQueue
import sys

input = sys.stdin.readline

N = int(input())
que = PriorityQueue(maxsize=N + 1)
arr = []

for _ in range(N):
    arr = list(map(int, input().split()))

    for i in range(N):
        que.put(arr[i])
        if (que.full()) == True:
            que.get()

print(que.get())