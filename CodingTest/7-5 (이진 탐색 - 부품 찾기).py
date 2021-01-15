# 시간 복잡도: O((M + N) * logN)
# 정렬: O(NlogN)
# 이진 탐색: O(MlogN)
def binary_search(arr, target, start, end):
  if start > end:
    return None

  mid = (start + end) // 2

  if arr[mid] == target:
    return True
  elif arr[mid] > target:
    return binary_search(arr, target, start, mid-1)
  else:
    return binary_search(arr, target, mid+1, end)


n = int(input())
arr = list(map(int, input().split()))
m = int(input())
x = list(map(int, input().split()))

arr.sort()

for i in range(m):
  result = binary_search(arr, x[i], 0, n-1)
  if result != None:
    print("yes", end=' ')
  else:
    print("no", end=' ')
