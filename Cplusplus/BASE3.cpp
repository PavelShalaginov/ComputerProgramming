#include<bits/stdc++.h>
using namespace std;

long long x;
int a[1000],n,flag;

int main(){
    freopen("BASE3.INP","r",stdin);
    freopen("BASE3.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>x;
    flag=x/abs(x);
    x=abs(x);
    while (x){
        a[++n]=x%3;
        x/=3;
    }
    for (int i=n; i>=1; --i) cout<<a[i];
    cout<<'\n';
    for (int i=1; i<=n ; ++i)
        if (a[i]>=2) a[i]-=3,a[i+1]++;
    while (a[n+1]) n++;
    for (int i=n; i>=1; --i)
        a[i]*flag>=0 ? cout<<a[i]*flag : cout<<'a';
}
