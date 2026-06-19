#include<bits/stdc++.h>
using namespace std;

int n,r[100010],num[100010],cnt[100010],last,ans,cur;
bool vis[100010];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		cnt[r[i]]++;
		if(!vis[r[i]])vis[r[i]]=true;
	}
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		if(vis[r[i]]){
			vis[r[i]]=false;
			num[++cur]=r[i];
		}
	}
	
/*	for(int i=1;i<=cur;i++){
		cout<<num[i]<<" "<<cnt[num[i]]<<endl;
	}*/
	
	for(int i=1;i<=cur;i++){
		int now=cnt[num[i]];
		ans+=min(last,now);
		last-=min(last,now);
		last+=cnt[num[i]];
	}
	
	cout<<n-ans<<endl;
	return 0;
}
 
