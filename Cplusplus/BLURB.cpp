#include<bits/stdc++.h>
using namespace std;

int n,a;
set<int> s;

int main(){
	freopen("BLURB.INP","r",stdin);
	freopen("BLURB.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (int i=1; i<=n; ++i){
		cin>>a;
		if (s.count(a))
			cout<<1<<' ';
		else {
			cout<<0<<' ';
			s.insert(a);
		}
	}
}