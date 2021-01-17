# 1. 특정한 지점의 주변 상,하,좌,우를 살펴본 뒤에 주변 지점 중에서 값이 '0'이면서 아직 방문하지 않은 지점이 있다면 해당 지점을 방문한다.
# 2. 방문한 지점에서 다시 상,하,좌,우를 살펴보면서 방문을 다시 진행하면, 연결된 모든 지점을 방문할 수 있다.
# 3. 1~2번 과정을 모든 노드에 반복하며 방문하지 않은 지점의 수를 센다.

n, m = map(int, input().split())

graph = []
for i in range(n):
  graph.append(list(map(int, input())))

# DFS로 특정한 노드를 방문한 뒤에 연결된 모든 노드들도 방문
def dfs(x, y):
  if x<= -1 or x >= n or y <= -1 or y >= m: # 주어진 범위를 벗어나는 경우 즉시 종료
    return False
  if graph[x][y] == 0: # 현재 노드를 아직 방문하지 않았다면
    graph[x][y] = 1 # 해당 노드 방문 처리
    dfs(x-1, y) # 이 네개는 방문처리를 하기 위한 목적으로만 수행됨. return X
    dfs(x, y-1)
    dfs(x+1, y)
    dfs(x, y+1)
    return True
  return False

result = 0
for i in range(n):
  for j in range(m):
    if dfs(i, j) == True: # 시작점의 return 값이 True라면 더하기
      result += 1

print(result)
