#include<bits/stdc++.h>
using namespace std;
#define N 100007
int a[N];
int n;
int sm;
priority_queue<int,vector<int>,greater<int> > pq;
priority_queue<int> q;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int nw=a[1];
	for(int i=1;i<=n;++i){
		pq.push(a[i]);
		if(!pq.empty()&&pq.top()<a[i]){
			pq.pop();
		}
	}
	cout<<pq.size();
} 
