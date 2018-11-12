#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<char,ll> pcl;

void task1(){
    string x,y;
    stringstream s1,s2;
    vector<pcl> X,Y;
    X.clear();Y.clear();

    cin>>x>>y;

    char ch;
    ll num;

    s1<<x;
    while (s1>>ch>>num) X.push_back(pcl(ch,num));

    s2<<y;
    while (s2>>ch>>num) Y.push_back(pcl(ch,num));

    if ((X.back()).first==(Y.front()).first){
        (Y.front()).second+=(X.back()).second;
        X.pop_back();
    }

    for (int i=0; i<X.size(); ++i) cout<<X[i].first<<X[i].second;
    for (int i=0; i<Y.size(); ++i) cout<<Y[i].first<<Y[i].second;
    cout<<'\n';
}

void task2(){
    string s;
    ll p,c;
    stringstream ss;
    vector<pcl> S;
    S.clear();

    cin>>s;
    cin>>p>>c;

    char ch;
    ll num;

    ss<<s;
    while (ss>>ch>>num) S.push_back(pcl(ch,num));

    vector<ll> a;
    for (int i=0; i<S.size(); ++i)
        a.push_back(S[i].second);
    for (int i=1; i<a.size(); ++i)
        a[i]+=a[i-1];
    int it=lower_bound(a.begin(),a.end(),p)-a.begin();
    ll tmp;

    for (int i=it; i<S.size(); ++i){
        tmp=min(c,S[i].second-p+1);
        S[i].second-=tmp;
        c-=tmp;
        p=1;
        if (c==0) break;
    }

    for (int i=0; i<S.size(); ++i)
        if (S[i].second) cout<<S[i].first<<S[i].second;
    cout<<'\n';
}

void task3(){
    string s;
    ll p,c;
    stringstream ss;
    vector<pcl> S;
    S.clear();

    cin>>s;
    cin>>p>>c;

    char ch;
    ll num;

    ss<<s;
    while (ss>>ch>>num) S.push_back(pcl(ch,num));

    vector<ll> a;
    for (int i=0; i<S.size(); ++i)
        a.push_back(S[i].second);
    for (int i=1; i<a.size(); ++i)
        a[i]+=a[i-1];
    int it=lower_bound(a.begin(),a.end(),p)-a.begin();
    ll tmp;

    for (int i=it; i<S.size(); ++i){
        tmp=min(c,S[i].second-p+1);
        cout<<S[i].first<<tmp;
        S[i].second-=tmp;
        c-=tmp;
        p=1;
        if (c==0) break;
    }
    cout<<'\n';
}

void task4(){
    string x,y;
    ll p;
    stringstream s1,s2;
    vector<pcl> X,Y;
    X.clear();Y.clear();

    cin>>x>>y;
    cin>>p;

    char ch;
    ll num;

    s1<<x;
    while (s1>>ch>>num) X.push_back(pcl(ch,num));

    s2<<y;
    while (s2>>ch>>num) Y.push_back(pcl(ch,num));

    vector<ll> a;
    for (int i=0; i<X.size(); ++i)
        a.push_back(X[i].second);
    for (int i=1; i<a.size(); ++i)
        a[i]+=a[i-1];
    int it=lower_bound(a.begin(),a.end(),p)-a.begin();
    if (it>0) p-=a[it-1];

    X.insert(X.begin()+it+1,pcl(X[it].first,X[it].second-p+1));
    X[it].second=p-1;
    if (X[it].first==(Y.front()).first){
        (Y.front()).second+=X[it].second;
        X[it].second=0;
    }
    if (X[it+1].first==(Y.back()).first){
        (Y.back()).second+=X[it+1].second;
        X[it+1].second=0;
    }

    for (int i=0; i<=it; ++i)
        if (X[i].second) cout<<X[i].first<<X[i].second;
    for (int i=0; i<Y.size(); ++i)
        if (Y[i].second) cout<<Y[i].first<<Y[i].second;
    for (int i=it+1; i<=X.size(); ++i)
        if (X[i].second) cout<<X[i].first<<X[i].second;
    cout<<'\n';
}

int main(){
    freopen("test.INP","r",stdin);
    freopen("test.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    string s;
    while (cin>>s){
        cout<<s<<": ";
        if (s[1]=='1') task1();
        if (s[1]=='2') task2();
        if (s[1]=='3') task3();
        if (s[1]=='4') task4();
    }
}

/*
@1: a1b13c9
@2: a1b19
@3: a9b1
@4: a10d1b22
@1: a1b3
*/