#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int m,n;
int p,q,x,y;
int row_min[N],row_max[N],row_sum[N],row;
int col_min[N],col_max[N],col_sum[N],col;

void set_row(){
    if (row_max[x]) row-=(row_max[x]-row_min[x]+1!=row_sum[x]);
    row_min[x]=min(row_min[x],y);
    row_max[x]=max(row_max[x],y);
    row_sum[x]++;
    row+=(row_max[x]-row_min[x]+1!=row_sum[x]);
}

void set_col(){
    if (col_max[y]) col-=(col_max[y]-col_min[y]+1!=col_sum[y]);
    col_min[y]=min(col_min[y],x);
    col_max[y]=max(col_max[y],x);
    col_sum[y]++;
    col+=(col_max[y]-col_min[y]+1!=col_sum[y]);
}

int main(){
    freopen("TURTLES.INP","r",stdin);
    freopen("TURTLES.OUT","w",stdout);
    scanf("%d %d",&m,&n);
    for (int i=1; i<=m; ++i)
        row_min[i]=n+1;
    for (int i=1; i<=n; ++i)
        col_min[i]=m+1;
    scanf("%d",&p);
    while(p--){
        scanf("%d %d",&x,&y);
        set_row();
        set_col();
    }
    row+col==0 ? puts("YES") : puts("NO");
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&x,&y);
        set_row();
        set_col();
        row+col==0 ? puts("YES") : puts("NO");
    }
}