#include<bits/stdc++.h>
using namespace std;

const int N=3e5+5;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

int n,m,k;
vector<pli> a[N];
pii e[N];
vector<int> b[N];

ll d[N];
int p[N];
priority_queue< pli,vector<pli>,greater<pli> > pq;

void dijkstra(){
    for (int i=2; i<=n; ++i)
        d[i]=1e18;
    pq.push(pli(0,1));
    while (!pq.empty()){
        int u=pq.top().second;
        ll du=pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        b[p[u]].push_back(u);
        for (int i=0; i<a[u].size(); ++i)
        if (d[a[u][i].second]>du+a[u][i].first){
            d[a[u][i].second]=du+a[u][i].first;
            p[a[u][i].second]=u;
            pq.push(pli(d[a[u][i].second],a[u][i].second));
        }
    }
}

int leaf[N];

int count_leaf(int u, int p){
    int tmp=1;
    for (int i=0; i<b[u].size(); ++i)
    if (b[u][i]!=p)
        tmp+=count_leaf(b[u][i],u);
    leaf[u]=tmp;
    return tmp;
}

int idx[N];
bool choose[N];
set<pii> se;

bool cmp(int i, int j){
    return leaf[i]<leaf[j];
}



void find_e(int u, int p){
    for (int i=0; i<b[u].size(); ++i)
    if (b[u][i]!=p && choose[b[u][i]]){
        se.insert(pii(u,b[u][i]));
        find_e(b[u][i],u);
    }
}

void Choose(){
    for (int i=1; i<=n; ++i)
        idx[i]=i,choose[i]=1;
    sort(idx+1,idx+1+n,cmp);
    int cant_choose=max(0,n-1-k);
    for (int i=1; i<=cant_choose; ++i)
        choose[idx[i]]=0;
    find_e(1,0);
}

void result(){
    int ex_choose=max(0,k-n+1);
    printf("%d\n",min(n-1,k));
    for (int i=1; i<=m; ++i)
    if (se.count(pii(e[i].second,e[i].first)) || se.count(pii(e[i].first,e[i].second)))
        printf("%d ",i);
}

int main(){
    freopen("54D.INP","r",stdin);
    freopen("54D.OUT","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1; i<=m; ++i){
        int u,v;
        ll w;
        scanf("%d %d %lld",&u,&v,&w);
        e[i]=pii(u,v);
        a[u].push_back(pli(w,v));
        a[v].push_back(pli(w,u));
    }
    dijkstra();
    count_leaf(1,0);
    Choose();
    result();
}