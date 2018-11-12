#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n, a[N], ans;

int main(){
	freopen("CASSIA.INP","r",stdin);
	freopen("CASSIA.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (int i=1; i<=n; ++i)
		cin>>a[i];
	ans=n;
	sort(a+1,a+1+n);
	for (int i=1,j=1; i<=n; ++i){
		while (a[i]-a[j]+1>n) ++j;
		ans=min(ans,n-(i-j+1));
	}
	cout<<ans;
}