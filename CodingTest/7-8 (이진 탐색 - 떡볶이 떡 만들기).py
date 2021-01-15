# 전형적인 이진 탐색 문제, 파라메트릭 서치 유형의 문제
# 파라메트릭 서치 = 최적화 문제를 결정 문제로 바꾸어 해결하는 기법
# 파라메트릭 서치 -> 원하는 조건을 만족하는 가장 알맞은 값을 찾는 문제
# ex. 범위 내에서 조건을 만족하는 가장 큰 값을 찾으라는 최적화 문제 -> 이진 탐색으로 결정 문제를 해결하면서 범위 좁히기 가능


n, m = map(int, input().split())
arr = list(map(int, input().split()))

start = 0
end = max(arr)

result = 0
while start <= end:
  total = 0
  mid = (start+end) // 2

  for x in arr:
    if x > mid: # 잘랐을 때의 떡의 양 계산
      total += x-mid

    
  if total < m: # 떡의 양이 부족한 경우 더 많이 자르기 (왼쪽 부분 탐색)
    end = mid-1
  else: # 떡의 양이 충분한 경우 덜 자르기 (오른쪽 부분 탐색)
    result = mid # 최대한 덜 잘랐을 때가 정답이므로, 여기서 result에 기록
    start = mid+1

print(result)
