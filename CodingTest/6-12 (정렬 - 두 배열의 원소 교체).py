n, k = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort()

for i in range(k):
  if A[i] < B[n-i-1]:
    A[i] = B[n-i-1]
  else:
    break
