import sys
input = sys.stdin.readline

n = int(input())
arr = []

for i in range(n):
    age, name = map(str, input().split())
    arr.append((age, name))
    
arr.sort(key = lambda x: int(x[0]))


for i in range(n):
    print(arr[i][0], arr[i][1])

