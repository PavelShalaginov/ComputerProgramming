#include<bits/stdc++.h>
using namespace std;

int n,a[1000006],f[1000006],ans;

int main(){
    freopen("VT35p_SECRETKEY.INP","r",stdin);
    freopen("VT35p_SECRETKEY.OUT","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        a[i]+=i;
    }
    int j;
    for (int i=1; i<=n; ++i){
        j=lower_bound(f,f+1+ans,a[i])-f;
        f[j]=a[i];
        ans=max(ans,j);
    }
    printf("%d",ans);
}
