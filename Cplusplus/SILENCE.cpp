#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[200005];
deque<int> dq;

int main(){
    freopen("SILENCE.INP","r",stdin);
    freopen("SILENCE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for (int i=1; i<=n; ++i) cin>>a[i];
    for (int i=1; i<=n; ++i){
        while(!dq.empty() && dq.front()<i-k+1) dq.pop_front();
        while(!dq.empty() && a[dq.back()]>=a[i]) dq.pop_back();
        dq.push_back(i);
        if (i>=k) cout<<a[dq.front()]<<' ';
    }
}
