# 숫자 카드 게임
n, m = map(int, input().split())

result = 0
for i in range(n):
  data = list(map(int, input().split()))
  # result = max(result, min_value)
  if result < min(data):
    result = min(data)

print(result)