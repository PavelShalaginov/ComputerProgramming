#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+5;
const int base=1e9+7;

int n,q;
string s;

int it[N<<2];
int Pow[N];
int Sum[N];

int build(int k, int l, int r){
    if (l==r) return it[k]=(s[l-1]=='1');
    int mid=(l+r)>>1;
    return it[k]=build(k<<1,l,mid)+build(k<<1|1,mid+1,r);
}
int get(int k, int l, int r, const int &ll, const int &rr){
    if (l>rr || r<ll) return 0;
    if (ll<=l && r<=rr) return it[k];
    int mid=(l+r)>>1;
    return it[k]=get(k<<1,l,mid,ll,rr)+get(k<<1|1,mid+1,r,ll,rr);
}

main(){
    freopen("520C.INP","r",stdin);
    freopen("520C.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n>>q;
    cin>>s;
    Pow[0]=Sum[0]=1;
    for (int i=1; i<=n; ++i){
        Pow[i]=Pow[i-1]*2%base;
        Sum[i]=(Sum[i-1]+Pow[i])%base;
    }
    build(1,1,n);
    int l, r, cnt;
    while(q--){
        cin>>l>>r;
        cnt=get(1,1,n,l,r);
        if (r-l+1!=cnt) cout<<(Sum[r-l]-Sum[r-l-cnt]+base)%base<<'\n';
        else cout<<Sum[r-l]<<'\n';
    }
}