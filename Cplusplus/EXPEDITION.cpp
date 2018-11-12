#include<bits/stdc++.h>
using namespace std;

const int N=3e5+5;
typedef pair<int,int> pii;

int n,a[N];
int Time[N],trace[N],Last[N];
deque<pii> dq;

void print_trace(int i, int counts){
    if (i==0) {
        printf("%d\n",counts);
        return;
    }
    print_trace(trace[i],counts+1);
    printf("%d ",i);
}

int main(){
    freopen("EXPEDITION.INP","r",stdin);
    freopen("EXPEDITION.OUT","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        Last[a[i]]=i;
    }
    Time[a[1]]=1;
    dq.push_back(pii(1,1));
    for (int i=2; i<n; ++i){
        if (Last[a[i]]==i) {
            Time[a[i]]=0;
            continue;
        }
        while(Time[a[dq.front().first]]!=dq.front().second) dq.pop_front();
        trace[i]=dq.front().first;
        Time[a[i]]=i;
        dq.push_back(pii(i,i));
    }
    while(!dq.empty() && a[dq.back().first]!=a[n]) dq.pop_back();
    if (dq.empty())
        printf("0");
    else
        print_trace(dq.back().second,0);
}