# 큰 수의 법칙
# N, M, K를 공백으로 구분하여 입력받기
n, m, k = map(int, input().split())
# N개의 수를 공백으로 구분하여 입력받기
data = list(map(int, input().split()))

data.sort()

first = data[n-1]
second = data[n-2]

result = 0
count = 0
for i in range(m):
  if count != k:
    result += data[n-1]
    count += 0
  else:
    result += data[n-2]
    i += 1
    count = 0

print(result)

# -------------------------------------------------------
# 가장 큰 수가 더해지는 횟수 계산
max_repeat_count = int(m/(k+1)) * k
max_repeat_count += m % (k+1) # 안 나눠 떨어지는 경우

result = 0
result += max_repeat_count * first # 가장 큰 수 더하기
result += (m - max_repeat_count) * second # 두 번째로 큰 수 더하기