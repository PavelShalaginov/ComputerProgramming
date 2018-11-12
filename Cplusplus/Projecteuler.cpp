#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> ppi;

int MAX;
int x,y,n;
long long answer,bit[100005];
ppi a[100005];
vector<pii> v;

void compress(){
	for (int i=1; i<=n; ++i)
		v.push_back(pii(a[i].first.second,i));
	sort(v.begin(),v.end());
	MAX=1;
	a[v[0].second].first.second=MAX;
	for (int i=2; i<=n; ++i){
		if (v[i].first!=v[i-1].first) MAX++;
		a[v[i].second].first.second=MAX;
	}
}

int main(){
	freopen("MBUS.INP","r",stdin);
	freopen("MBUS.OUT","w",stdout);
	scanf("%d %d %d",&x,&y,&n);
	for (int i=1; i<=n; ++i){
		scanf("%d %d %d",&a[i].first.first,&a[i].first.second,&a[i].second);
		if (a[i].first.first>x || a[i].first.second>y){
			i--;n--;
		}
	}
	a[++n]=ppi(pii(x,y),0);
	sort(a+1,a+1+n);
	compress();
	long long tmp;
	for (int i=1; i<=n; ++i){
		tmp=0;
		for (int x=a[i].first.second; x>0; x-=x&-x)
			tmp=max(bit[x],tmp);
		tmp+=a[i].second;
		for (int x=a[i].first.second; x<=MAX; x+=x&-x)
			bit[x]=max(bit[x],tmp);
		answer=max(answer,tmp);
	}
	printf("%lld\n", answer);
}
			