import sys
input = sys.stdin.readline

num = [0] * 11
n = int(input())

def func(cnt, next):
    if cnt == n:
        for i in range(n):
            print(num[i], end = " ")
        print()
    
    else:
        for i in range(1, n + 1):
            rep = True
            num[cnt] = i
            for j in range(cnt):
                if num[j] == num[cnt]:
                    rep = False

            if rep:
                if num[cnt - 1] < num[cnt] and num[cnt] < next:
                    break

            if rep:
                if next <= num[cnt]:
                    func(cnt + 1, num[cnt] + 1)
                else:
                    func(cnt + 1, next)


func(0, 0)