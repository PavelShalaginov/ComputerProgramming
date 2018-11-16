#include<bits/stdc++.h>
using namespace std;

const int N=4e3+3;
typedef long long ll;
typedef pair<ll,ll> pll;

int n,q,nNode;
vector<pll> a[N];
vector<int> T[N];

inline pll operator - (const pll &a, const pll &b){
    return pll(a.first-b.first,a.second-b.second);
}
inline ll operator ^ (const pll &a, const pll &b){
    return a.first*b.second-b.first*a.second;
}
pll org;
inline bool less_angle(const pll &a, const pll &b){
    return (a-org).second*(b-org).first<(a-org).first*(b-org).second;
}
inline void fix(vector<pll> &a){
    sort(a.begin(),a.end());
    org=a[0];
    sort(a.begin()+1,a.end(),less_angle);
}
inline bool inCircle(const vector<pll> &a, const pll &x){
    if (x==a[0]) return 1;
    org=a[0];
    if (x.first<org.first) return 0;
    int idx=upper_bound(a.begin()+1,a.end(),x,less_angle)-a.begin();
    if (idx==1) return 0;
    if (idx==a.size() && !binary_search(a.begin()+1,a.end(),x,less_angle)) return 0;
    return ((x-a[idx-1])^(a[idx]-x))<=0LL;
}
inline bool Fuck_inCircle(const vector<pll> &a, const pll &x){
    if (x==a[0]) return 0;
    org=a[0];
    if (x.first<org.first) return 0;
    int idx=upper_bound(a.begin()+1,a.end(),x,less_angle)-a.begin();
    if (idx==a.size() || idx==1) return 0;
    if (idx==2 && binary_search(a.begin()+1,a.end(),x,less_angle)) return 0;
    return ((x-a[idx-1])^(a[idx]-x))<0LL;
}
int k,cnt;
inline void Insert(const int &idx){
    k=0;
    BEGIN:
    for (int i=1; i<T[k].size(); ++i){
        if (inCircle(a[T[T[k][i]][0]],a[idx][0])){
            k=T[k][i];
            goto BEGIN;
        }
    }
    T[++nNode].push_back(idx);
    for (int i=1; i<T[k].size(); ++i){
        if (inCircle(a[idx],a[T[T[k][i]][0]][0])){
            T[nNode].push_back(T[k][i]);
            T[k].erase(T[k].begin()+i);
            i--;
        }
    }
    T[k].push_back(nNode);
}
inline int check(const pll& x){
    k=cnt=0;
    BEGIN:
    for (int i=1; i<T[k].size(); ++i)
    if (cnt%2==0){
        if (inCircle(a[T[T[k][i]][0]],x)){
            k=T[k][i];
            cnt++;
            goto BEGIN;
        }
    }
    else{
        if (Fuck_inCircle(a[T[T[k][i]][0]],x)){
            k=T[k][i];
            cnt++;
            goto BEGIN;
        }
    }
    return cnt;
}

int main(){
    freopen("CMP.INP","r",stdin);
    freopen("CMP.OUT","w",stdout);
    scanf("%d %d",&n,&q);
    T[0].push_back(0);
    for (int i=1,m; i<=n; ++i){
        scanf("%d",&m);
        ll x,y;
        for (int j=1; j<=m; ++j){
            scanf("%lld %lld",&x,&y);
            a[i].push_back(pll(x,y));
        }
        fix(a[i]);
        Insert(i);
    }
    pll tmp;

    int tt=0;
        for (tmp.second=7; tmp.second>=-5; --tmp.second){
    for (tmp.first=4; tmp.first<=16; ++tmp.first)
            check(tmp)%2 ? putchar('Y'),tt++ : putchar('N');
        puts("");
        }
    cout<<tt<<endl;
    return 0;

    while (q--){
        scanf("%lld %lld",&tmp.first,&tmp.second);
        check(tmp)%2 ? puts("YES") : puts("NO");
    }
}