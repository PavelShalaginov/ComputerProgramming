#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
typedef pair<int,int> pii;

int n,a,ans;
bool mark[N];
priority_queue< pii,vector<pii>,greater<pii> > pq;

int main(){
    freopen("FIRS.INP","r",stdin);
    freopen("FIRS.OUT","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; ++i){
        scanf("%d",&a);
        pq.push(pii(a,i));
    }
    while(!pq.empty()){
        ans++;
        mark[pq.top().second]=1;
        mark[pq.top().second-1]=1;
        mark[pq.top().second+1]=1;
        while(!pq.empty() && mark[pq.top().second]==1) pq.pop();
    }
    printf("%d",ans);
}