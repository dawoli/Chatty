#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn];
priority_queue<int,vector<int>,greater<int> > Q;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		if(!Q.empty()) {
			int t=Q.top();
		    if(t<a[i])  Q.pop();
		}
		Q.push(a[i]);
	}
	cout<<Q.size();
	return 0;
}
