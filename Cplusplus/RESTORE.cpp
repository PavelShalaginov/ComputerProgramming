#include<bits/stdc++.h>
using namespace std;

const int N=1e6+6;
int n,a[N],ans;

bool check(int idx){
    for (int i=idx; i<=n; ++i)
        if (abs(a[i]-(i-idx+1))>1) return 0;
    for (int i=1; i<idx; ++i)
        if (abs(a[i]-(n-idx+1+i))>1) return 0;
    return 1;
}

int main(){
    freopen("RESTORE.INP","r",stdin);
    freopen("RESTORE.OUT","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    if (n<=3000){
        for (int i=1; i<=n; ++i)
            if (check(i)) {
                ans=i;
                break;
            }
    }
    else {
        for (int i=1; i<=n; ++i)
        if (a[i]<=2){
            ans=i;
            break;
        }
    }
    (ans && check(ans)) ? printf("YES\n%d",ans) : puts("NO");
}