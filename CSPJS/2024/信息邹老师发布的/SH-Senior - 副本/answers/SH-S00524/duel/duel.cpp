#include<bits/stdc++.h>
using namespace std;
const int N=100002;
int a[N];
queue<int> q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(!q.empty() && q.front()<a[i]) q.pop();
		q.push(a[i]);
	}
	cout<<q.size();
	return 0;
}
