s = input()
n = len(s)
s = "0"+s+"0"

pow = [26**i for i in range(n+1)]
 
HashL = [0]*(n+2)
for i in range(1,n+1):
    HashL[i]=HashL[i-1]*26+ord(s[i])-ord('a');
    
HashR = [0]*(n+2)
for i in range(n,0,-1):
    HashR[i]=HashR[i+1]*26+ord(s[i])-ord('a');
    
    
def Get_HashL(l,r):
    return HashL[r]-HashL[l-1]*pow[r-l+1]
def Get_HashR(l,r):
    return HashR[l]-HashR[r+1]*pow[r-l+1]
 
ans1 = 1
ans2 = n
 
for i in range(2,n+1):
    if Get_HashL(1,i//2)==Get_HashR(i-i//2+1,i):
        ans1=i 
for i in range(n-1,0,-1):
    if Get_HashL(i,i+(n-i+1)//2-1)==Get_HashR(n-(n-i+1)//2+1,n):
        ans2=i

if ans1>=n-ans2+1:
    for i in range(n,ans1,-1):
        print (s[i],end="")
    print (s[1:n+1])
else:
    print (s[1:n+1],end="")
    for i in range(ans2-1,0,-1):
        print (s[i],end="")
