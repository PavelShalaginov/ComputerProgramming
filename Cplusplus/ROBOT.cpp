#include<bits/stdc++.h>
using namespace std;

const int oo=1e9;
int m,n,p,k,f[44][44][222];
bool a[44][44];
char s[222];

int cal(int x, int y, int h){
    if (h>k) {
        if (x==m && y==n) return f[x][y][h]=0;
        else return f[x][y][h]=oo;
    }
    if (f[x][y][h]!=-1) return f[x][y][h];
    f[x][y][h]=cal(x,y,h+1)+1;
    int direct;
    if (s[h]=='U') {
        direct=(!a[x-1][y]);
        f[x][y][h]=min(f[x][y][h],cal(x-direct,y,h+1));
    }
    if (s[h]=='D') {
        direct=(!a[x+1][y]);
        f[x][y][h]=min(f[x][y][h],cal(x+direct,y,h+1));
    }
    if (s[h]=='L') {
        direct=(!a[x][y-1]);
        f[x][y][h]=min(f[x][y][h],cal(x,y-direct,h+1));
    }
    if (s[h]=='R') {
        direct=(!a[x][y+1]);
        f[x][y][h]=min(f[x][y][h],cal(x,y+direct,h+1));
    }
    return f[x][y][h];
}

int main(){
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    scanf("%d %d %d %d",&m,&n,&p,&k);
    for (int i=1; i<=k; ++i)
        do s[i]=getchar();
        while (!(s[i]=='U' || s[i]=='R' || s[i]=='D' || s[i]=='L'));
    for (int x,y; p--; ){
        scanf("%d %d",&x,&y);
        a[x][y]=1;
    }
    for (int i=0; i<=m+1; ++i)
        a[i][0]=a[i][n+1]=1;
    for (int i=0; i<=n+1; ++i)
        a[0][i]=a[m+1][i]=1;
    memset(f,-1,sizeof(f));
    int ans=cal(1,1,1);
    ans==oo ? printf("-1") : printf("%d",ans);
}
