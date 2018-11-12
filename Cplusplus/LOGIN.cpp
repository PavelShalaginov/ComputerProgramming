#include <bits/stdc++.h>
using namespace std;

const int N=2e4+4;
int n;
string s[N],str;
unordered_set<string> se;
map<string,int> mp;

int main(){
	freopen("LOGIN.INP","r",stdin);
	freopen("LOGIN.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (int t=1; t<=n; ++t){
		cin>>s[t];
		se.clear();
		for (int i=0; i<s[t].length(); ++i){
			str="";
			for (int j=i; j<s[t].length(); ++j){
				str+=s[t][j];
				if (!se.count(str)) {
					mp[str]++;
					se.insert(str);
				}
			}
		}
	}
	int ans=-n;
	for (int i=1; i<=n; ++i) ans+=mp[s[i]];
	cout<<ans;
}