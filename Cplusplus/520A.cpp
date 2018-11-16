#include<bits/stdc++.h>
using namespace std;

const int N=111;
int n,a[N],ans;

int main(){
    freopen("520A.INP","r",stdin);
    freopen("520A.OUT","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    a[n+1]=1001;
    for (int i=0; i<=n+1; ++i)
        for (int j=i+2; j<=n+1; ++j)
            if (a[j]-a[i]==j-i)
                ans=max(ans,j-i-1);
    printf("%d",ans);
}