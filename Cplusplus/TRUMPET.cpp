#include<bits/stdc++.h>
using namespace std;

int n,d,ans;

int main(){
    freopen("TRUMPET.INP","r",stdin);
    freopen("TRUMPET.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n>>d;
    int p=1, status;
    for (int i=1; i<=n; ++i){
        cin>>status;
        if (status){
                p=i;
                continue;
        };
        if (i-p>=d) ans++,p=i;
    }
    cout<<ans;
}
