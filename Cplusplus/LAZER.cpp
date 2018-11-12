#include <bits/stdc++.h>
using namespace std;

const int base=100000;

int n,t;
int e[4][4*base+4];

int main(){
	freopen("LAZER.INP","r",stdin);
	freopen("LAZER.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (int i=1; i<=n; ++i){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		e[1][base+x1]+=y2-y1;e[1][base+x2+1]-=y2-y1;
		e[2][base+x1+y1+1]++;e[2][base+x1+y2+1]--;
		e[2][base+x2+y1+1]--;e[2][base+x2+y2+1]++;
		e[3][base+x1-y2+1]++;e[3][base+x1-y1+1]--;
		e[3][base+x2-y2+1]--;e[3][base+x2-y1+1]++;
	}	
	for (int i=1; i<4*base+4; ++i) {
		e[1][i]+=e[1][i-1];
		e[2][i]+=e[2][i-1];
		e[3][i]+=e[3][i-1];
	}
	for (int i=1; i<4*base+4; ++i){
		e[2][i]+=e[2][i-1];
		e[3][i]+=e[3][i-1];
	}
	int x, d;
	cin>>t;
	while (t--){
		cin>>x>>d;
		if (d==1) cout<<1LL*e[d][base+x]*e[d][base+x]<<'\n';
		else cout<<2LL*e[d][base+x]*e[d][base+x]<<'\n';
	}
}	