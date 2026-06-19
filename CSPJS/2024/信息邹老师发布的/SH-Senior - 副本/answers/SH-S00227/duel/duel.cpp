#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define N 100009 
int n,x[N]; 
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>x[i];
	sort(x + 1,x + n + 1);
	int ans = n;
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i = 1;i <= n;i++){
		if(!q.empty() && q.top() < x[i]) q.pop();
		q.push(x[i]);
	}
	cout<<q.size()<<endl;
	return 0;
}

