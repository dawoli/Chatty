#include<bits/stdc++.h>
#define int long long
int n;
int a[100005][4],b[100005];
int cnt[4];
int check(int x){
	int res=0;
	for(int i=1;i<=3;i++){
		if(i==b[x]) continue;
		res=std::max(res,a[x][i]);
	}
	return res;
}
void solve(){
	std::cin>>n;
	cnt[1]=cnt[2]=cnt[3]=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		int now=-1,p=0;
		for(int j=1;j<=3;j++){
			std::cin>>a[i][j];
			if(a[i][j]>now){
				now=a[i][j];
				p=j;
			}
		}
		b[i]=p;
		cnt[p]++;
		ans+=now;
	} 
	bool flag=false;
	int zu=0,tot=0;
	for(int j=1;j<=3;j++){
		if(cnt[j]>n/2){
			flag=true;
			zu=j;
			tot=cnt[j];
			break;
		}
	}
	if(!flag){
		std::cout<<ans<<"\n";
		return;
	}
	std::priority_queue<int> q;
	for(int i=1;i<=n;i++){
		if(b[i]==zu){
			q.push(check(i)-a[i][zu]);
		}
	}
	while(tot>n/2){
		int num=q.top(); q.pop();
		ans+=num; tot--;
	}
	std::cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; std::cin>>t; while(t--) solve();
} 
