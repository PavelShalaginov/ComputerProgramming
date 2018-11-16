#include<bits/stdc++.h>
using namespace std;

const int N=6e5+5;
typedef long long ll;
typedef pair<int,ll> pil;

int n,m;
vector<int> a[N];
vector<pil> up[N];
ll bit[N],ans[N];

void dfs(int u,int p, int level){
    for (int i=0; i<up[u].size(); ++i){
        bit[level]+=up[u][i].second;
        bit[level+up[u][i].first+1]-=up[u][i].second;
    }
    ans[u]=bit[level];
    for (int i=0; i<a[u].size(); ++i)
        if (a[u][i]!=p){
            bit[level+1]+=bit[level];
            dfs(a[u][i],u,level+1);
            bit[level+1]-=bit[level];
        }
    for (int i=0; i<up[u].size(); ++i){
        bit[level]-=up[u][i].second;
        bit[level+up[u][i].first+1]+=up[u][i].second;
    }
}

int main(){
    freopen("54D.INP","r",stdin);
    freopen("54D.OUT","w",stdout);
    scanf("%d",&n);
    for (int i=1,u,v; i<n; ++i){
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    scanf("%d",&m);
    for (int i=1; i<=m; ++i){
        int d,v;
        ll x;
        scanf("%d %d %lld",&v,&d,&x);
        d=min(d,n);
        up[v].push_back(pil(d,x));
    }
    dfs(1,0,1);
    for (int i=1; i<=n; ++i)
        printf("%lld ",ans[i]);
}