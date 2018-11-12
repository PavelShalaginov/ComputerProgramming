import sys
inf = sys.stdin
x,y,n=inf.readline().split()
x = int(x)
y = int(y)
n = int(n)
a = []
for i in range(int(n)):
	a.append(inf.readline().split())
	a[i]=[int(x) for x in a[i]]
	if (a[i][0]>x) or (a[i][1]>y):
		a.pop()
		i-=1
		n-=1
a.append([x,y,0])
n+=1
a.sort()
def compress():
	MAX = 1
	b = []
	for i in range(n):
		b.append([a[i][1],i])
	b.sort()
	a[b[0][1]][1] = MAX
	for i in range(1,n):
		if (b[i][0]!=b[i-1][0]):
			MAX+=1
		a[b[i][1]][1]=MAX
	return MAX
MAX = compress()
bit = [0]*(MAX+1)
ans = 0
for i in range(n):
	tmp=0
	x = a[i][1]
	while (x>0):
		tmp=max(tmp,bit[x])
		x-=x&-x;
	tmp+=int(a[i][2])
	x = a[i][1]
	while (x<=MAX):
		bit[x]=max(bit[x],tmp);
		x+=x&-x
	ans=max(ans,tmp)
print(ans)
# qua thoi gian?