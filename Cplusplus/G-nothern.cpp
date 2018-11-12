#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;
const int oo=1e9;
const int xx[]={-1,-1,1,1};
const int yy[]={-1,1,1,-1};
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;

int n,m,xs,ys,xf,yf;
bool a[N][N];

int f1[N][N][4],f2[N][N][4];
priority_queue<ppp, vector<ppp> ,greater<ppp> > q1,q2;

void init(){
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j){
            a[i][j]=1;
            for (int k=0; k<4; ++k){
                f1[i][j][k]=oo;

                f2[i][j][k]=oo;
            }
        }
}

int dijkstra(){
    for (int i=0; i<4; ++i){
        f1[xs][ys][i]=0;
        q1.push(ppp(pii(0,i),pii(xs,ys)));

        f2[xf][yf][i]=0;
        q2.push(ppp(pii(0,i),pii(xf,yf)));
    }
    int x,y,z,t;
    while (!q1.empty() && !q2.empty()){
        z=q1.top().first.first;
        t=q1.top().first.second;
        x=q1.top().second.first;
        y=q1.top().second.second;
        q1.pop();
        if (x==xf && y==yf) return z;
        if (z!=f1[x][y][t]) continue;
        for (int i=0; i<4; ++i)
        if (a[x+xx[i]][y+yy[i]] && f1[x+xx[i]][y+yy[i]][i]>z+(t!=i)){
            f1[x+xx[i]][y+yy[i]][i]=z+(t!=i);
            q1.push(ppp(pii(z+(t!=i),i),pii(x+xx[i],y+yy[i])));
        }

        z=q2.top().first.first;
        t=q2.top().first.second;
        x=q2.top().second.first;
        y=q2.top().second.second;
        q2.pop();
        if (x==xs && y==ys) return z;
        if (z!=f2[x][y][t]) continue;
        for (int i=0; i<4; ++i)
        if (a[x+xx[i]][y+yy[i]] && f2[x+xx[i]][y+yy[i]][i]>z+(t!=i)){
            f2[x+xx[i]][y+yy[i]][i]=z+(t!=i);
            q2.push(ppp(pii(z+(t!=i),i),pii(x+xx[i],y+yy[i])));
        }
    }
    return -2;
}

int main(){
    freopen("test.INP","r",stdin);
    freopen("test.OUT","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%d %d %d %d",&xs,&ys,&xf,&yf);
    if ((xs+ys)%2 != (xf+yf)%2){
        cout<<-1;
        return 0;
    }
    init();
    for (int i=1,x,y; i<=m; ++i){
        scanf("%d %d",&x,&y);
        a[x][y]=0;
    }
    cout<<dijkstra()+1;
}