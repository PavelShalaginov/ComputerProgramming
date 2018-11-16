#include<bits/stdc++.h>
using namespace std;

const int N=1e2+4;
int m,n,k,q;
int a[N][N];


int main(){
    freopen("COVERAGE.INP","r",stdin);
    freopen("COVERAGE.OUT","w",stdout);
    cin>>m>>n>>k;
    for (int i=1,x,y; i<=k; ++i){
        cin>>x>>y;
        a[x][y]=-1;
    }
    cin>>q;
    for (int i=1,x,y; i<=q; ++i){
        cin>>x>>y;
        a[x][y]=i;
    }
    for (int i=1; i<=m; ++i){
        for (int j=1; j<=n; ++j)
            cout<<setw(2)<<a[i][j]<<' ';
        cout<<endl;
    }
}