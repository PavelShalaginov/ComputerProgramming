#include<bits/stdc++.h>
using namespace std;

string s,ss;
int f[1000006],ans=0;

void manaker(){
	int l=0,r=-1;
	int d=0;
	for (int i=0; i<s.length(); ++i){
		if (i<=r)
			d=min(f[l+r-i],r-i);
		else 
			d=0;
		while (i+d+1<s.length() && i-d-1>=0 && s[i+d+1]==s[i-d-1]) d++;
		f[i]=d;
		if (i+d>r) r=i+d,l=i-d;
		if (s[i]==' ') ans+=d;
		else ans+=d/2;
	}
}

int main(){
	freopen("ALL_PAL.INP","r",stdin);
	freopen("ALL_PAL.OUT","w",stdout);
	ios_base::sync_with_stdio();
	cin>>ss;
	for (int i=0; i<ss.length(); ++i) s=s+ss[i]+' ';
	s.erase(s.length()-1,0);
	ans=ss.length();
	manaker();
	cout<<ans;
}