#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
ld d,a1,a2,v,t,eps=1e-10;

int main(){
    freopen("VW04p_Checkout.INP","r",stdin);
    freopen("VW04p_Checkout.OUT","w",stdout);
    cin>>d>>a1>>a2>>v>>t;
    ld l,r,l1,r1;
    ld a=0.5*(1/a1+1/a2);
    l=eps;
    r=(-t+sqrt(t*t+4*a*d))/2/a;
    ld T1,T2;
    while (r-l>eps){
        l1=l+(r-l)/3;
        r1=r-(r-l)/3;
        T1=a*l1+d/l1;
        T2=a*r1+d/r1;
        if (T1>T2) l=l1;
        else r=r1;
    }
    cout<<fixed<<setprecision(8)<<T1;
}