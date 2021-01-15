# 재귀 함수
def binary_search(arr, target, start, end):
  if start > end:
    return None
  mid = (start + end) // 2
  
  if arr[mid] == target:
    return mid
  elif arr[mid] > target:
    return binary_search(arr, target, start, mid-1)
  else:
    return binary_search(arr, target, mid+1, end)

# 반복문
def binary_search(arr, target, start, end):
  while start <= end:
    mid = (start + end) // 2

    if arr[mid] == target:
      return mid
    elif arr[mid] > target:
      end = mid-1
    else:
      start = mid+1
  
  return None


n, target = list(map(int, input().split()))
arr = list(map(int, input().split()))

result = binary_search(arr, target, 0, n-1)
if result == None:
  print("No 원소")
else:
  print(result + 1)
