import copy

n = int(input())
color = input()
adjTab = [[] for i in range(n + 1)]
for i in range(n - 1):
    fo, to = map(int, input().strip().split())
    adjTab[fo].append(to)
    adjTab[to].append(fo)

vaildPath = set()

def dfs(fo, cur, s, step, path):
    s.add(color[cur - 1])
    path.append(str(cur))
    if step == 0:
        if len(s) == 3:
            path.sort()
            vaildPath.add(''.join(path))

    for to in adjTab[cur]:
        if to == fo:
            continue
        dfs(cur, to, copy.deepcopy(s), step - 1, copy.deepcopy(path)) 
    
for i in range(1, n + 1):
    dfs(0, i, set(), 3, [])
print(len(vaildPath))


