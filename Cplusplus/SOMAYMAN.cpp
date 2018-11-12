#include <bits/stdc++.h>
using namespace std;

int f[20][2][1<<10];
string n;

int get_bit(int x, int i){
    return (x>>i)&1;
}
int on_bit(int x, int i){
    return x|(1<<i);
}
int count_bit(int x){
    int tmp=0;
    for (int i=0; i<10; ++i)
        tmp+=get_bit(x,i);
    return tmp;
}

int cal(int k,bool ok, int x){
    if (k>=10) return f[k][ok][x]=1;
    if (f[k][ok][x]!=-1) return f[k][ok][x];
    int tmp=0,xx;
    for (int i=0; i<10; ++i){
        xx=on_bit(x,i);
        if (x==0 && i==0) xx=0;
        if ((ok || i<=n[k]-'0') && count_bit(xx)<3 )
            tmp+=cal(k+1,ok || i<n[k]-'0',xx);
    }
    return f[k][ok][x]=tmp;
}

int main(){
    freopen("SOMAYMAN.INP","r",stdin);
    freopen("SOMAYMAN.OUT","w",stdout);
    cin>>n;
    while(n.length()<10) n="0"+n;
    memset(f,-1,sizeof(f));
    cout<<cal(0,0,0)-1;
}