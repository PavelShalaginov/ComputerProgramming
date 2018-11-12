#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+5;
int n,a[N];
ll Pow[N],Hash_L[N],Hash_R[N];
vector<int> ans;

int main(){
	freopen("IKEBANA.INP","r",stdin);
	freopen("IKEBANA.OUT","w",stdout);
	ios_base::sync_with_stdio();
	cin>>n;
	for (int i=1; i<=n; ++i) cin>>a[i];
	Pow[0]=1;
	for (int i=1; i<N; ++i) Pow[i]=Pow[i-1]*1000000007;
	for (int i=1; i<=n; ++i) Hash_L[i]=Hash_L[i-1]+a[i]*Pow[i];
	for (int i=n; i>=1; --i) Hash_R[i]=Hash_R[i+1]+a[i]*Pow[n-i+1];
	for (int i=0; i<=n/2; ++i)
		if (Hash_L[i]*Pow[n-2*i]==(Hash_R[i+1]-Hash_R[2*i+1]))
			ans.push_back(n-i);
	cout<<ans.size()<<'\n';
	for (int i=0; i<ans.size(); ++i) cout<<ans[i]<<' ';
}