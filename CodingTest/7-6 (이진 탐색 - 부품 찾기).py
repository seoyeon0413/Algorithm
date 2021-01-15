# 내가 푼거
n = int(input())
arr = list(map(int, input().split()))
m = int(input())
x = list(map(int, input().split()))

count_list = [0] * (max(arr)+1)

for i in range(len(arr)):
  count_list[arr[i]] = 1

print(count_list)

for i in range(m):
  if count_list[x[i]] > 0:
    print("yes", end =' ')
  else:
    print("no", end=' ')

# ------------------------------------------------------- 
# 답지
n = int(input())
arr = [0] * 1000001

for i in input().split():
  arr[int(i)] = 1

m = int(input())
x = list(map(int, input().split()))

for i in x:
  if arr[i] == 1:
    print('yes', end=' ')
  else:
    print('no', end=' ')
