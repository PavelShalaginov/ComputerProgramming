#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> black;
vector<int> white;

int main(){
    freopen("NECKLACE.INP","r",stdin);
    freopen("NECKLACE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>s;
    for (int i=0; i<s.length(); ++i)
    if (s[i]=='0'){
        if (black.empty() || s[black.back()]=='1')
            black.push_back(i);
        else
            white.push_back(i);
    }
    else {
        if (black.empty() || s[black.back()]=='1'){
            cout<<-1;
            return 0;
        }
        else black.push_back(i);
    }
    if (!black.empty() && s[black.back()]=='1'){
        cout<<-1;
        return 0;
    }
    cout<<(!black.empty())+white.size()<<'\n';
    if (!black.empty()){
        cout<<black.size()<<' ';
        for (int i=0; i<black.size(); ++i) cout<<black[i]+1<<' ';
        cout<<'\n';
    }
    if (!white.empty()){
        for (int i=0; i<white.size(); ++i) cout<<1<<' '<<white[i]+1<<'\n';
    }
}