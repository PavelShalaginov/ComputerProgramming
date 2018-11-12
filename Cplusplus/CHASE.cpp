#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pll;

int n,k;
ll v1,v2,s;
pll a[N];

ld t;
ll delay;

int it[N<<2];

void build(int k, int l, int r){
    if (l==r){
        it[k]=l;
        return ;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    if (a[it[k<<1]].second>a[it[k<<1|1]].second)
        it[k]=it[k<<1];
    else
        it[k]=it[k<<1|1];
}
void update(int k, int l, int r,const int &idx){
    if (r<idx || l>idx) return;
    if (l==r) {
        it[k]=0;
        return ;
    }
    int mid=(l+r)>>1;
    update(k<<1,l,mid,idx);
    update(k<<1|1,mid+1,r,idx);
    if (a[it[k<<1]].second>a[it[k<<1|1]].second)
        it[k]=it[k<<1];
    else
        it[k]=it[k<<1|1];
}
int get(int k, int l, int r,const int &ll,const int &rr){
    if (l>rr || r<ll) return 0;
    if (ll<=l && r<=rr) return it[k];
    int mid=(l+r)>>1;
    int tmp1=get(k<<1,l,mid,ll,rr);
    int tmp2=get(k<<1|1,mid+1,r,ll,rr);
    if (a[tmp1].second>a[tmp2].second)
        return tmp1;
    else
        return tmp2;
}

int main(){
    freopen("CHASE.INP","r",stdin);
    freopen("CHASE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    cin>>v1>>v2;
    cin>>s;
    for (int i=1; i<=n; ++i)
        cin>>a[i].first>>a[i].second;
    build(1,1,n);
    if (s==0 || v1>=v2){
        if (s==0)  cout<<0;
        else cout<<"inf";
        return 0;
    }
    int st=lower_bound(a+1,a+1+n,pll(s,0))-a;
    int fw;
    int tmp;
    while(k>0){
        t=(ld)(s+v2*delay)/(v2-v1);
        fw=upper_bound(a+1,a+1+n,pll(s+(ll)ceil(v1*t),0))-a-1;
        if (fw<st) break;
        tmp=get(1,1,n,st,fw);
        delay+=a[tmp].second;
        k--;
        update(1,1,n,tmp);
    }
    t=(ld)(s+v2*delay)/(v2-v1);
    cout<<fixed<<setprecision(10)<<t;
}