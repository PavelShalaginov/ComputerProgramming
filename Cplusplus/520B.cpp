#include<bits/stdc++.h>
using namespace std;

const int N=1e6+6;
int n,prime[N],ans,mx;
map<int,int> mp;

void init_prime(int n){
    for (int i=1; i<=n; ++i)
        prime[i]=i;
    for (int i=2; i<=n; ++i)
        if (prime[i]==i)
        for (int j=i+i; j<=n; j+=i)
            prime[j]=i;
}

int main(){
    freopen("520B.INP","r",stdin);
    freopen("520B.OUT","w",stdout);
    cin>>n;
    if (n==1){
        cout<<1<<' '<<0;
        return 0;
    }
    init_prime(n);
    while(n!=1){
        mp[prime[n]]++;
        n/=prime[n];
    }
    ans=1;
    for (map<int,int> ::iterator it=mp.begin(); it!=mp.end(); ++it){
        ans*=(*it).first;
        mx=max(mx,(*it).second);
    }
    cout<<ans<<' ';
    if ((mx-(mx&-mx))==0) ans=0;
    else ans=1;
    for (map<int,int> ::iterator it=mp.begin(); it!=mp.end(); ++it)
        if (mx!=(*it).second) ans=1;
    while(mx-(mx&-mx)) mx+=mx&-mx;
    while((mx&1)==0) ans++,mx>>=1;
    cout<<ans;
}