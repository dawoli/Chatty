#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,r[MAXN],ans;
queue<int> q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+1+n);
	for(int i=1;i<=n;i++){
		q.push(r[i]);
		if(q.front()<r[i]) q.pop();
		
	}
	for(int i=1;i<=n;i++){
		if(q.empty()!=1) ans++;
		else break;
		q.pop(); 
	}
	cout<<ans<<endl;
	return 0;
}
