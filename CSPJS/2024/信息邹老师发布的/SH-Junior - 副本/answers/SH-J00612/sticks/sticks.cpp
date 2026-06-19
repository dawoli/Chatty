#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,m,ans,a[8]={0,0,1,7,4,2,0,8};
void dfs(int tag,int t,int k) {
	if(t==0) {
		if(tag==n) {
			ans=min(ans,k);
			return;
		}
		return;
	}
	int l;
	for(int j=2;j<=7;j++) {
		tag+=j;
		if(t==m&&j==6)l=k*10+6;
		else l=k*10+a[j];
		t--;
		dfs(tag,t,l);
		tag-=j;
		t++;
	}
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		if(n<=14) {
			if(n%7==0)m=n/7;
			else m=n/7+1;
			ans=INT_MAX;
			dfs(0,m,0);
			if(ans==INT_MAX)cout<<-1<<endl;
			else cout<<ans<<endl;
			continue;
		}
		if(n%7==0) {
			m=n/7;
			for(int i=1;i<=m;i++) {
				cout<<8;
			}
			cout<<endl;
		}
		if(n%7==1) {
			m=n/7-1;
			cout<<"10";
			for(int i=1;i<=m;i++) {
				cout<<8;
			}
			cout<<endl;
		}
		if(n%7==2) {
			m=n/7;
			cout<<1;
			for(int i=1;i<=m;i++) {
				cout<<8;
			}
			cout<<endl;
		}
		if(n%7==3) {
			m=n/7-2;
			cout<<"200";
			for(int i=1;i<=m;i++) {
				cout<<8;
			}
			cout<<endl;
		}
		if(n%7==4) {
			m=n/7-1;
			cout<<"20";
			for(int i=1;i<=m;i++) {
				cout<<8;
			}
			cout<<endl;
		}
		if(n%7==5) {
			m=n/7;
			cout<<2;
			for(int i=1;i<=m;i++) {
				cout<<8;
			}
			cout<<endl;
		}
		if(n%7==6) {
			m=n/7;
			cout<<6;
			for(int i=1;i<=m;i++) {
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}
