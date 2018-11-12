#include<bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> tiii;
int a[8],DD,MM,YYYY;
int Days_of_months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string sa,sb,sc;
set<tiii> se;

bool check(const int &YYYY, const int &MM, const int &DD){
    if (!YYYY || !MM || !DD) return 0;
    if (MM>12) return 0;
    if (MM!=2) return DD<=Days_of_months[MM];
    int t=0;
    t = (YYYY%400==0 || (YYYY%100!=0 && YYYY%4==0));
    if (YYYY%3328==0) t=2;
    return DD<=Days_of_months[2]+t;
}

int main(){
	freopen("DATES.INP","r",stdin);
	freopen("DATES.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>sa>>sb>>sc;
	sa+=sb+sc;
	for (int i=0; i<sa.length(); ++i) a[i]=sa[i]-'0';
	sort(a,a+8);
	do {
		YYYY=a[0]*1000+a[1]*100+a[2]*10+a[3];
		MM=a[4]*10+a[5];
		DD=a[6]*10+a[7];
		if (check(YYYY,MM,DD)) se.insert(tiii(YYYY,MM,DD));
		//cout<<setw(4)<<setfill('0')<<YYYY<<' '<<setw(2)<<setfill('0')<<MM<<' '<<setw(2)<<setfill('0')<<DD<<'\n';
	} while(next_permutation(a,a+8));
	cout<<se.size()<<'\n';
	for (set<tiii>::iterator it=se.begin(); it!=se.end(); ++it)
        cout<<setw(4)<<setfill('0')<<get<0>(*it)<<' '<<setw(2)<<setfill('0')<<get<1>(*it)<<' '<<setw(2)<<setfill('0')<<get<2>(*it)<<'\n';
}
