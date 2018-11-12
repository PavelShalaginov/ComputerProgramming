#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=3e5+5;
const ll mod=1e9+7;

int n;
string s;

ll HashL[N],HashR[N],Pow[N];

inline ll Get_HashL(int l, int r){
    return HashL[r]-HashL[l-1]*Pow[r-l+1];
}
inline ll Get_HashR(int l, int r){
    return HashR[l]-HashR[r+1]*Pow[r-l+1];
}

void process(int &ans1, int &ans2, ll base){
    Pow[0]=1;
    for (int i=1; i<=n; ++i)
        Pow[i]=Pow[i-1]*base%mod;
    for (int i=1; i<=n; ++i)
        HashL[i]=(HashL[i-1]*base+s[i]-'a')%mod;
    for (int i=n; i>=1; --i)
        HashR[i]=(HashR[i+1]*base+s[i]-'a')%mod;

    for (int i=2; i<=n; ++i)
        if ((Get_HashL(1,i/2)+mod*mod)%mod==(Get_HashR(i-i/2+1,i)+mod*mod)%mod) ans1=i;
    for (int i=n-1; i>0; --i)
        if ((Get_HashL(i,i+(n-i+1)/2-1)+mod*mod)%mod==(Get_HashR(n-(n-i+1)/2+1,n)+mod*mod)%mod) ans2=i;
}

int main(){
    freopen("PAROLE.INP","r",stdin);
    freopen("PAROLE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>s;
    n=s.length();
    s="0"+s+"0";

    int ans1=1;
    int ans2=n;
    process(ans1,ans2,26);

    if (ans1>=n-ans2+1){
        for (int i=n; i>ans1; --i)
            cout<<s[i];
        cout<<s.substr(1,n);
    }
    else {
        cout<<s.substr(1,n);
        for (int i=ans2-1; i>0; --i)
            cout<<s[i];
    }
}