#include<bits/stdc++.h>
using namespace std;

string s;
int ll,rr,l,r;
int c[256];

int main(){
    freopen("B.INP","r",stdin);
    freopen("B.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>s;
    c[s[0]]++;
    while (1){
        while (r+1<s.length() && c[s[r+1]]==0) c[s[r+1]]++,r++;
        if (r-l>rr-ll || (r-l==rr-ll && s.substr(l,r-l+1)<s.substr(ll,rr-ll+1))) ll=l,rr=r;
        if (r+1>=s.length()) break;
        r++;c[s[r]]++;
        while (c[s[r]]>1) c[s[l]]--,l++;
    }
    cout<<s.substr(ll,rr-ll+1);
}