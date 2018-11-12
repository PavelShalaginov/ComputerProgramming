#include<bits/stdc++.h>
using namespace std;

string s;
int q;
const long long base=5e5+3;
long long Hash[1000001],Pow[27];

int main(){
	freopen("TWOSTR.INP","r",stdin);
	freopen("TWOSTR.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>s;
	Pow[0]=1;
	for (int i=1; i<27; ++i) Pow[i]=Pow[i-1]*base;
	for (int i=1; i<=s.length(); ++i) Hash[i]=Hash[i-1]+Pow[s[i-1]-'a'];
	int a,b,c,d;
	cin>>q;
	while(q--){
		cin>>a>>b>>c>>d;
		(Hash[b]-Hash[a-1]==Hash[d]-Hash[c-1]) ? cout<<"YES"<<'\n' : cout<<"NO"<<'\n';
	}
}





/*
#include<bits/stdc++.h>
using namespace std;

string s;
int q,counts[1000001][26];

int main(){
	freopen("TWOSTR.INP","r",stdin);
	freopen("TWOSTR.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>s;
	for (int i=1; i<=s.length(); ++i)
		for (int c='a'; c<='z'; ++c)
			counts[i][c-'a']+=counts[i-1][c-'a']+(s[i-1]==c);
	int a,b,c,d;
	bool flag;
	cin>>q;
	while(q--){
		cin>>a>>b>>c>>d;
		flag=1;
		for (int i='a'; i<='z'; ++i)
			if (counts[b][i-'a']-counts[a-1][i-'a']!=counts[d][i-'a']-counts[c-1][i-'a'])
				flag=0;
		(flag==1) ? cout<<"YES"<<'\n' : cout<<"NO"<<'\n';
	}
}
*/