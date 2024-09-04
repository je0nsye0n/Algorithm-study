# import sys
# input = sys.stdin.readline

T = input()

P = input()

def make_pi():
    pi = [0 for i in range(0, len(P))]

    j = 0
    for i in range(1, len(P)):
        while j > 0 and P[i] != P[j]:
            j = pi[j - 1]
        
        if P[i] == P[j]:
            j += 1
            pi[i] = j
    return pi

def solution(pi):
    result = []
    cnt = 0

    j = 0
    for i in range(0, len(T)):
        while j > 0 and T[i] != P[j]:
            j = pi[j - 1]

        if T[i] == P[j]:
            if j == (len(P) - 1):
                result.append(i - len(P) + 2)
                cnt += 1
                j = pi[j]
            else:
                j += 1
    
    print(cnt)
    for elem in result:
        print(elem)

solution(make_pi())
# def rabin_karp(pattern, text):
#     cnt = 0
#     pattern_len = len(pattern) - 1
#     text_len = len(text) - 1
#     pattern_hash, text_hash = 0, 0
#     power = 1

#     for i in range(text_len - pattern_len + 1):
#         if i == 0:
#             for j in range(pattern_len):
#                 text_hash += ord(text[text_len - j - 1]) * power
#                 pattern_hash += ord(pattern[pattern_len - j - 1]) * power

#                 if j < pattern_len - 1:
#                     power *= 2
#         else:
#             text_hash = 2 * (text_hash - ord(text[i - 1]) * power) + ord(text[pattern_len + i - 1])

#         if text_hash == text_hash:
#             found = True
#             for j in range(pattern_len):
#                 if text[i + j] != pattern[j]:
#                     found = False
#             if found:
#                 cnt += 1
#                 print(cnt)
#                 print(i + 1)

# rabin_karp(P, T)

