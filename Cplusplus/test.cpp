#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;
int n;
vector<int> a[N];

int s[N][N];
long long ans;

void dfs(int u, int p){
    s[u][0]=1;
    for (int i=0; i<a[u].size(); ++i)
        if (a[u][i]!=p){
            dfs(a[u][i],u);
            for (int j=2; j<=n; ++j)
                s[u][j]+=s[a[u][i]][j-1];
            s[u][1]++;
        }
}

int shit[N];
long long tmp;

void pre_dfs(int u, int p){
    for (int i=1; i<=n; ++i) shit[i]=0;
    for (int i=0; i<a[u].size(); ++i)
        for (int j=1; j<=n; ++j)
            shit[j]+=(s[a[u][i]][j-1]>0);
    for (int i=1; i<=n; ++i){
        tmp=0;
        if (shit[i]>2) tmp+=1LL*shit[i]*(shit[i]-1)*(shit[i]-2)/6;
        for (int j=0; j<a[u].size(); ++j)
            if (s[a[u][j]][i-1])tmp=tmp*s[a[u][j]][i-1];
        ans+=tmp;
    }

    //if (u==5) cout<<u<<' '<<ans<<' '<<shit[2]<<endl;

    for (int i=0; i<a[u].size(); ++i)
    if (a[u][i]!=p){
        for (int j=2; j<=n; ++j)
            s[u][j]-=s[a[u][i]][j-1];
        s[u][1]--;

        for (int j=2; j<=n; ++j)
            s[a[u][i]][j]+=s[u][j-1];
        s[a[u][i]][1]++;

        pre_dfs(a[u][i],u);

        for (int j=2; j<=n; ++j)
            s[a[u][i]][j]-=s[u][j-1];
        s[a[u][i]][1]--;

        for (int j=2; j<=n; ++j)
            s[u][j]+=s[a[u][i]][j-1];
        s[u][1]++;
    }
}

int main(){
    freopen("test.INP","r",stdin);
    freopen("test.OUT","w",stdout);
    scanf("%d",&n);
    for (int i=1,u,v; i<n; ++i){
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    pre_dfs(1,0);
    cout<<ans;
}