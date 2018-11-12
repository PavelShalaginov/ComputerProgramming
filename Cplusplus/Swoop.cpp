#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,st[N];
long long x[N],y[N],f[N];

bool cross(int i, int j,int t){
    return (x[j]-x[i])*(y[t]-y[j])-(x[t]-x[j])*(y[j]-y[i])>=0;
}
long long distance(int i, int j){
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

int main(){
    freopen("Swoop.INP","r",stdin);
    freopen("Swoop.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>x[i]>>y[i];
    long double goc;
    int j=1;
    st[j]=1;
    for (int i=2; i<=n; ++i){
        f[i]=2e18;
        while(j>0 && y[i]>=y[st[j]]){
            f[i]=min(f[i],max(f[st[j]],distance(i,st[j])));
            j--;
        }
        if (j>0) f[i]=min(f[i],max(f[st[j]],distance(i,st[j])));
        st[++j]=i;
    }
    cout<<setprecision(10)<<fixed<<sqrt(f[n]);
}