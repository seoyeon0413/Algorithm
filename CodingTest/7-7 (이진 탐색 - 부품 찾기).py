n = int(input())
set_arr = set(map(int, input().split()))
m = int(input())
x = list(map(int, input().split()))

for i in x:
  if i in set_arr:
    print("yes", end =' ')
  else:
    print("no", end=' ')
