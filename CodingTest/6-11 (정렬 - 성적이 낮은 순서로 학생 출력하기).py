n = int(input())

arr = []
for i in range(n):
  input_data = input().split()
  arr.append(input_data[0], int(input_data[1]))
  
 arr = sorted(arr, key=lambda x:x[1])
 
 for student in arr:
  print(student[0], end=' ')
