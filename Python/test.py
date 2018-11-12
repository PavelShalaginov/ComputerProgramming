inp=input().split();
m = int(inp[0])
n = int(inp[1])
a = [['0' for i in range(0,m+1)] for j in range(0,n+1)]
f = [[ 0  for i in range(0,m+1)] for j in range(0,n+1)]
for i in range(1,m+1):
    inp=input()
    for j in range(1,n+1):
        a[i][j]=inp[j-1]
f[1][1]=int(a[1][1])
for i in range(1,m+1):
    for j in range(1,n+1):
        if i==1 and j==1:
            continue
        if (i+j)%2==0:
            if a[i-1][j]=='+':
                f[i][j]=max(f[i][j],f[i-1][j]+int(a[i][j]))
            if a[i-1][j]=='*':
                f[i][j]=max(f[i][j],f[i-1][j]*int(a[i][j]))
            if a[i][j-1]=='+':
                f[i][j]=max(f[i][j],f[i][j-1]+int(a[i][j]))
            if a[i][j-1]=='*':
                f[i][j]=max(f[i][j],f[i][j-1]*int(a[i][j]))
        else:
            f[i][j]=max(f[i-1][j],f[i][j-1])
print(f[m][n])
    