import sys
input = sys.stdin.readline  


def binary_search(left, right, tar):
    
    while left <= right:
        mid = (left + right) // 2
        
        if A[mid] > tar:
            right = mid - 1
        elif A[mid] < tar:
            left = mid + 1
        else:
            return 1
        
    return 0

N = int(input())
A = list(map(int, input().split()))
M = int(input())
tar = list(map(int, input().split()))

A.sort()

for i in tar:
    print(binary_search(0, len(A) - 1, i))


