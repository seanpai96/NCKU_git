n,m,k = map(int,input().split())
ans = [i  for i in range(1,n+1)]

s = 0
s += m-1

while k != 0:
    ans.pop(s)
    s = s+m-1
    s %= len(ans)
    k -= 1

print(ans[s%len(ans)])
