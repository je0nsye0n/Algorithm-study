from heapq import heappush, heappop, heapify
import sys
input = sys.stdin.readline

heap = []
N = int(input())

for _ in range(N):
    num = int(input())

    if num == 0:
        if len(heap) == 0:
            print(0)
        else:
            print(heappop(heap))
    
    else:
        heappush(heap, num)

    