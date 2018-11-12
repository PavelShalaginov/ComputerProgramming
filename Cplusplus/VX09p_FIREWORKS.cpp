#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n;
vector< vector<int> > a;
vector< vector<int> > ms;
long long ans,m;

void update(vector<int> &a,const int &val){
    if (a[0]<val){
        swap(a[0],a[1]);
        a[0]=val;
        return;
    }
    if (a[1]<val)
        a[1]=val;
}

void dfs(int u){
    ms[u].resize(2);
    ms[u][0]=1;
    for (int i=0; i<a[u].size(); ++i){
        dfs(a[u][i]);
        update(ms[u],ms[a[u][i]][0]+1);
    }
}

void pre_dfs(int u){
    ans=max(ans,2*ms[1][0]*(m-1)+ms[u][0]+ms[u][1]-1);
    for (int i=0; i<a[u].size(); ++i)
        pre_dfs(a[u][i]);
}

int main(){
    freopen("VX09p_FIREWORKS.INP","r",stdin);
    freopen("VX09p_FIREWORKS.OUT","w",stdout);
    scanf("%d %lld",&n,&m);
    a.resize(n+1);
    ms.resize(n+1);
    for (int i=2,u; i<=n; ++i){
        scanf("%d",&u);
        a[u].push_back(i);
    }
    dfs(1);
    pre_dfs(1);
    printf("%lld",ans);
}