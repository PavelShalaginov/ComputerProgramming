#include<bits/stdc++.h>
using namespace std;

int n,k;
long long ans;
vector<int> a,b;

int main(){
	freopen("DRILL.INP","r",stdin);
	freopen("DRILL.OUT","w",stdout);
	ios_base::sync_with_stdio();
	cin>>n>>k;
	for (int i=0,tmp; i<n; ++i){
		cin>>tmp;
		a.push_back(tmp);
	}
	ans=1e18;
	for (int st=0; st<=1; ++st){
		b=a;
		for (int i=st; i<n; i+=2) b[i]-=k;
		nth_element(b.begin(),b.begin()+b.size()/2,b.end());
		long long tmp=0;
		for (int i=0; i<n; ++i)
			tmp+=abs(b[i]-b[b.size()/2]);
		ans=min(ans,tmp);
	}
	cout<<ans;
}