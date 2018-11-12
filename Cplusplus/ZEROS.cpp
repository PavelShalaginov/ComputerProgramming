#include<bits/stdc++.h>
using namespace std;

int n,b,ans;
int is_prime[1001];
map<int,int> mp;

void prime(){
    for (int i=2; i<=1000; ++i) is_prime[i]=i;
    for (int i=2; i<=1000; ++i)
        if (is_prime[i]==i)
        for (int j=i+i; j<=1000; j+=i)
            is_prime[j]=i;
}
void analyze(){
    while(is_prime[b]){
        mp[is_prime[b]]++;
        b/=is_prime[b];
    }
}
int counts(int x){
    int cnt=0;
    for (int i=x; i<=n; i*=x)
        cnt+=n/i;
    return cnt;
}

int main(){
    freopen("ZEROS.INP","r",stdin);
    freopen("ZEROS.OUT","w",stdout);
    cin>>n>>b;
    prime();
    analyze();
    ans=1e9;
    for (map<int,int>::iterator it=mp.begin();
    it!=mp.end(); ++it)
        ans=min(counts((*it).first)-(*it).second+1,ans);
    cout<<ans;
}