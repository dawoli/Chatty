#include<bits/stdc++.h>
#define ld long double
using namespace std;
int t,n,a[200005],ans,vis[200005];
stack<int> o,p,op;
void dfs(int k,int l) {
	if(k==0) {
		for(int i=1;i<=n;i++) {
			if(!vis[i]) {
				p.push(i);
			}
		}
		int c=o.top(),d,sum=0;
		op.push(o.top());
		o.pop();
		while(!o.empty()) {
			if(a[c]==a[o.top()]){
				sum+=a[c];
			}
			c=o.top();
			op.push(o.top());
			o.pop();
		}
		if(!p.empty()) {
			d=p.top();
			p.pop();
		}
		while(!p.empty()) {
			if(a[d]==a[p.top()]){
				sum+=a[d];
			}
			d=p.top();
			p.pop();
		}
		ans=max(ans,sum);
		while(!op.empty()) {
			o.push(op.top());
			op.pop();
		}
		return;
	}
	if(l>n)return;
	for(int i=l;i<=n;i++) {
		o.push(i);
		vis[i]=1;
		dfs(k-1,i+1);
		o.pop();
		vis[i]=0;
	}
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		int i;
		if(n%2==0)i=n/2;
		else i=n/2+1;
		for(;i<=n;i++)dfs(i,1);
		cout<<ans<<endl;
	}
    return 0;
}
