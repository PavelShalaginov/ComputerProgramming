#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int*> piit;
typedef pair<int,int> pii;
const int N=1e5+5;

int n;
pii a[N];

int it[4*N],lazy[4*N],MAX;
int ans[N];

vector<piit> v;
void compress(){
	for (int i=1; i<=n; ++i){
		v.push_back(piit(a[i].first,&a[i].first));
		v.push_back(piit(a[i].second,&a[i].second));
	}
	sort(v.begin(),v.end());
	(*v[0].second)=MAX=1;
	for (int i=1; i<v.size(); ++i){
		if (v[i].first!=v[i-1].first) MAX++;
		(*v[i].second)=MAX;
	}
}

void down(const int &k, const int &l, const int &r){
	int mid=(l+r)>>1;
	lazy[k<<1]+=lazy[k];
	it[k<<1]+=lazy[k]*(mid-l+1);
	lazy[k<<1|1]+=lazy[k];
	it[k<<1|1]+=lazy[k]*(r-mid);
	lazy[k]=0;
}

int get(int k, int l, int r, const int &ll, const int &rr){
	if (l>rr || r<ll) return 0;
	if (ll<=l && r<=rr) return it[k];
	int mid=(l+r)>>1;
	if (lazy[k]) down(k,l,r);
	return get(k<<1,l,mid,ll,rr)+get(k<<1|1,mid+1,r,ll,rr);
}
int update(int k, int l, int r, const int &ll, const int &rr){
	if (l>rr || r<ll) return 0;
	if (ll<=l && r<=rr){
		lazy[k]++;
		it[k]+=(r-l+1);
		return it[k];
	}
	int mid=(l+r)>>1;
	if (lazy[k]) down(k,l,r);
	return it[k]=update(k<<1,l,mid,ll,rr)+update(k<<1|1,mid+1,r,ll,rr);
}

int main(){
	freopen("PROGRAMS.INP","r",stdin);
	freopen("PROGRAMS.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (int i=1; i<=n; ++i)
			cin>>a[i].first>>a[i].second;
	compress();
	for (int i=n; i>=1; --i){
		if (get(1,1,n,a[i].first,a[i].second)==0) ans[++ans[0]]=i;
		update(1,1,n,a[i].first,a[i].second);
	}
	cout<<ans[0]<<'\n';
	for (int i=ans[0]; i>=1; --i) cout<<ans[i]<<' ';
}