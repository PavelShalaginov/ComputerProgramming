#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
typedef long long ll;
typedef pair<ll,ll> pll;

int n,q;
ll a[N];
pll it[N<<2];

pll build(int k, int l, int r){
    if (l==r) return it[k]=pll(a[l],0);
    int mid=(l+r)>>1;
    pll tmp1=build(k<<1,l,mid);
    pll tmp2=build(k<<1|1,mid+1,r);
    return it[k]=pll(max(tmp1.first,tmp2.first),max(tmp1.first+tmp2.first,max(tmp1.second,tmp2.second)));
}
pll update(int k, int l, int r,const int &idx, const ll &val){
    if (r<idx || l>idx) return it[k];
    if (l==r) return it[k]=pll(val,0);
    int mid=(l+r)>>1;
    pll tmp1=update(k<<1,l,mid,idx,val);
    pll tmp2=update(k<<1|1,mid+1,r,idx,val);
    return it[k]=pll(max(tmp1.first,tmp2.first),max(tmp1.first+tmp2.first,max(tmp1.second,tmp2.second)));
}
pll query(int k, int l, int r, const int &ll, const int &rr){
    if (l>rr || r<ll) return pll(0LL,0LL);
    if (l>=ll && r<=rr) return it[k];
    int mid=(l+r)>>1;
    pll tmp1=query(k<<1,l,mid,ll,rr);
    pll tmp2=query(k<<1|1,mid+1,r,ll,rr);
    return pll(max(tmp1.first,tmp2.first),max(tmp1.first+tmp2.first,max(tmp1.second,tmp2.second)));
}
int main(){
    freopen("KGSS.INP","r",stdin);
    freopen("KGSS.OUT","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%lld",&a[i]);
    build(1,1,n);
    scanf("%d\n",&q);
    char c;
    int ll, rr;
    while (q--){
        scanf("%c %d %d\n",&c,&ll,&rr);
        if (c=='Q')
            printf("%lld\n",query(1,1,n,ll,rr).second);
        else
            update(1,1,n,ll,rr);

    }
}