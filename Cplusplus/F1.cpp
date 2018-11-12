#include<bits/stdc++.h>
using namespace std;

const int N=2e2+2;

int m,n,a[3*N][3*N],ans;
string s;

void counts(int m, int n, int p, int q, bool &ok, int &cnt){
    ok=1;
    cnt=0;
    if (m==p){
        for (int i=0; i<=q-n; ++i){
            if (a[m][n+i]==-1) ok=0;
            if (a[m][n+i]== 1) cnt++;
        }
        return;
    }
    if (n==q){
        for (int i=0; i<=p-m; ++i){
            if (a[m+i][n]==-1) ok=0;
            if (a[m+i][n]== 1) cnt++;
        }
        return;
    }
    if (m<n){
        for (int i=0; i<=)
    }
}

int main(){
    freopen("F1.INP","r",stdin);
    freopen("F1.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>m>>n;
    for (int i=1; i<=m; ++i){
        cin>>s;
        for (int i=1; i<=n; ++i)
            if (s[i-1]=='x') a[i][j]=1;
            else if (s[i-1]=='0') a[i][j]=-1;
    }
    for (int i=-1; i<=m+2; ++i)
        for (int j=-1; j<=n+2; ++j)
            ans+=check(i,j);
    cout<<ans;
}