#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll base=1e9+7,N=1e6+6;
ll n,s,g[1000006],tmp;

ll Pow(ll a, ll n){
    int tmp=1;
    while (n>0){
        if (n&1) tmp=tmp*a%base;
        a=a*a%base;
        n>>=1;
    }
    return tmp;
}

int main(){
    freopen("D.INP","r",stdin);
    freopen("D.OUT","w",stdout);
    g[0]=1;
    for (int i=1; i<N; ++i)
        g[i]=g[i-1]*i%base;
    scanf("%lld",&n);
    for (int i=1; i<=n; ++i){
        scanf("%lld",&tmp);
        s+=tmp;
    }
    printf("%lld",g[s]*Pow(g[n]*g[s-n]%base,base-2)%base);
}