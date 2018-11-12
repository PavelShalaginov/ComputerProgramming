#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5,base=1e9+7;
vector< vector<int> > couple={{3},{3,2},{3,1},{3,2,1,0}};
int n,k,stt[N],f[N][4];

bool checked(int x, int y){
    if (x/2==1 && y/2!=1) return 0;
    if (x%2==1 && y%2!=1) return 0;
    return 1;
}

int main(){
    freopen("TILING.INP","r",stdin);
    freopen("TILING.OUT","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i=1,x,y; i<=k; ++i){
        scanf("%d %d",&x,&y);
        stt[x]|=(1<<(y-1));
    }
    f[0][3]=1;
    for (int i=1; i<=n; ++i)
        for (int x=0; x<4; ++x)
        if (checked(stt[i],x)){
            for (int j=0; j<couple[x].size(); ++j)
                if (checked(stt[i],couple[x][j]))
                    f[i][x]=(f[i][x]+f[i-1][couple[x][j]])%base;
            if (x==3 && stt[i]==0) f[i][x]=(f[i][x]+f[i-1][x])%base;
        }
    printf("%d",f[n][3]);
}