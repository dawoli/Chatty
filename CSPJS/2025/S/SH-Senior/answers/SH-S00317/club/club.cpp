#include<bits/stdc++.h>
using namespace std;
int n,ans,ct[4];
struct node{
	int a[4],p;
}m[100005];
void solve(){
	ans=0;
	memset(ct,0,sizeof(ct));
	memset(m,0,sizeof(m));
	cin>>n;
	for(int i=1;i<=n;i++){
		int mx=1;
		for(int j=1;j<=3;j++){
			cin>>m[i].a[j];
			if(m[i].a[j]>m[i].a[mx])mx=j;
		}
		m[i].p=mx;
		ans+=m[i].a[mx];
		ct[mx]++;
	}
	for(int j=1;j<=3;j++){
		if(ct[j]>n/2){
			int j1,j2;
			if(j==1){j1=2;j2=3;}
			if(j==2){j1=1;j2=3;}
			if(j==3){j1=2;j2=1;}
			priority_queue<int> q;
			for(int i=1;i<=n;i++){
				if(m[i].p==j){
					int tmp=max(m[i].a[j1],m[i].a[j2])-m[i].a[j];
					q.push(tmp);
				}
			}
			while(ct[j]>n/2){
				ct[j]--;
				ans+=q.top();
				q.pop();
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
