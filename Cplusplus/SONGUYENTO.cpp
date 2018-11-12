#include<bits/stdc++.h>
using namespace std;

const int N=3e8+8;
int prime[N];
int a,b,k,ans;

void init_prime(int n){
    for (int i=2; i<=n; ++i) prime[i]=1;
    for (int i=2; i<=n; ++i)
        if (prime[i])
            for (int j=i+i; j<=n; j+=i)
                prime[j]=0;
    for (int i=2; i<=n; ++i)
        prime[i]+=prime[i-1];
}

int main(){
    freopen("SONGUYENTO.INP","r",stdin);
    freopen("SONGUYENTO.OUT","w",stdout);
    cin>>a>>b>>k;
    init_prime(b);
    k++;
    ans=-1;
    for (int i=a,j; i<=b;){
        i=upper_bound(prime,prime+b+1,prime[i]+1)-prime;
        if (i>b) break;
        j=lower_bound(prime,prime+b+1,prime[i]-k+1)-prime;
        if (j<a) continue;
        ans=max(ans,j-i+1);
    }
    cout<<ans;
}