#include<bits/stdc++.h>
using namespace std;

const int N=2e6+6;
typedef pair<int,int> pii;
int n,Max,ans,bit[2*N];
pii a[N],b[N];
multiset<pii> se;
vector< pair<int,int*> > v;

void compress(){
    for (int i=1; i<=n; ++i){
        v.push_back(make_pair(b[i].first,&b[i].first));
        v.push_back(make_pair(b[i].second,&b[i].second));
    }
    sort(v.begin(),v.end());
    Max=*(v[0].second)=1;
    for (int i=1; i<v.size(); ++i){
        if (v[i].first!=v[i-1].first) Max++;
        *(v[i].second)=Max;
    }
}

int main(){
    freopen("E.INP","r",stdin);
    freopen("E.OUT","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%d %d",&a[i].first,&a[i].second);
    sort(a+1,a+1+n);
    for (int i=1; i<=n; ++i)
        b[i]=pii(a[i].first-a[i].second,a[i].first+a[i].second);
    compress();
    int tmp;
    for (int i=1; i<=n; ++i){
        tmp=0;
        for (int x=b[i].first; x>0; x-=x&-x)
            tmp=max(tmp,bit[x]);
        tmp++;
        for (int x=b[i].second; x<Max; x+=x&-x)
            bit[x]=max(bit[x],tmp);
        ans=max(ans,tmp);
    }
    printf("%d",ans);
}