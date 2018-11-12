#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

///WA

ll a1,b1,a2,b2,a,b,c;
pll ans;

pll ex_gcd(ll a, ll b){
    if (b==0) return pll(1,0);
    pll tmp=ex_gcd(b,a%b);
    return pll(tmp.second,tmp.first-tmp.second*(a/b));
}

void solve(){
    a=abs(a);
    b=abs(b);
    ll d=__gcd(a,b);
    ll t=ceil(max(-(long double)ans.first/b,-(long double)ans.second/a));
    cout<<ans.first+t*b/d<<' '<<ans.second+t*a/d;
}

int main(){
    freopen("INTEGER7.INP","r",stdin);
    freopen("INTEGER7.OUT","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    a=a1;
    b=-a2;
    c=b2-b1;
    if (a==0 || b==0){
        if (a==0) cout<<c/b;
        else cout<<c/a;
        return 0;
    }
    ll d=__gcd(a,b);
    ans=ex_gcd(a/d,b/d);
    ans.first*=c/d;
    ans.second*=c/d;
    solve();
}