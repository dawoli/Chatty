#include<bits/stdc++.h>
#define N 100009
using namespace std;
priority_queue<int,vector<int>,greater<int> > da,beida;
int n,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;da.push(x);
	}
	while(!da.empty()){
		int u=da.top();da.pop();
		if(beida.size()){
			int v=beida.top();
			if(u>v){ans++;beida.pop();}
		}
		beida.push(u);
	}
	cout<<n-ans;
	return 0;
}
