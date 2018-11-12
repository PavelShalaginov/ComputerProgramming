#include<bits/stdc++.h>
using namespace std;

const int N=1e6+6;
typedef pair<int,int> pii;
int n,ans,tmp;
pii a[N];

int main(){
    freopen("A.INP","r",stdin);
    freopen("A.OUT","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; ++i){
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    ans=-1e9;
    tmp=a[1].first+a[1].second;
    for (int i=2; i<=n; ++i){
        ans=max(ans,a[i].first+a[i].second-tmp);
        tmp=min(tmp,a[i].first+a[i].second);
    }
    tmp=-a[n].first+a[n].second;
    for (int i=n-1; i>0; --i){
        ans=max(ans,-a[i].first+a[i].second-tmp);
        tmp=min(tmp,-a[i].first+a[i].second);
    }
    printf("%d",ans);
}