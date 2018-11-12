#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m;
int height[N],parent[N][20];
vector<int> a[N];

void dfs(int u){
    for (int i=0; i<a[u].size(); ++i)
    if (parent[u][0]!=a[u][i]){
        parent[a[u][i]][0]=u;
        height[a[u][i]]=height[u]+1;
        dfs(a[u][i]);
    }
}

int LCA(int u, int v){
    if (height[u]<height[v]) swap(u,v);
    int tmp=height[u]-height[v];
    for (int i=19; i>=0; --i)
        if ((tmp>>i)&1)
            u=parent[u][i];
    if (u==v) return u;
    for (int i=19; i>=0; --i)
        if (parent[u][i]!=parent[v][i]){
            u=parent[u][i];
            v=parent[v][i];
        }
    return parent[u][0];
}

int child(int u, int v){
    if (height[u]<height[v]) swap(u,v);
    int tmp=height[u]-height[v]-1;
    for (int i=19; i>=0; --i)
        if ((tmp>>i)&1)
            u=parent[u][i];
    return u;
}

main(){
    freopen("VT33p_GUIDE.INP","r",stdin);
    freopen("VT33p_GUIDE.OUT","w",stdout);
    scanf("%d",&n);
    for (int i=1,u,v; i<n; ++i){
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    for (int i=1; i<20; ++i)
        for (int u=1; u<=n; ++u)
            parent[u][i]=parent[parent[u][i-1]][i-1];
    int u,v,t;
    scanf("%d",&m);
    while (m--){
        scanf("%d %d",&u,&v);
        t=LCA(u,v);
        if (t==u) printf("%d\n",child(u,v));
        else if (t==v) printf("%d\n",parent[u][0]);
        else printf("%d\n",parent[u][0]);
    }
}