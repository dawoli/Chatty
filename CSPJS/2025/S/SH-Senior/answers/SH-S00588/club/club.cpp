#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,ans,cnt[4],d[100010][5];
priority_queue<pair<int,int>>q;
void work(){
	int ans=0;
	while(!q.empty())
		q.pop();
	cnt[1]=cnt[2]=cnt[3]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int Max1=0,Max2=0,id1=0,id2=0;
		for(int j=1;j<=3;j++){
			cin>>d[i][j];
			if(Max1<d[i][j])
				Max2=Max1,id2=id1,Max1=d[i][j],id1=j;
			else if(Max2<d[i][j])
				Max2=d[i][j],id2=j;
		}
		ans+=Max1;
		cnt[id1]++;
		q.push({Max2-Max1,id1});
	}
	int id=0;
	for(int j=1;j<=3;j++)
		if(cnt[j]>n/2)
			id=j;
	if(!id){
		cout<<ans<<"\n";
		return ;
	}
	while(cnt[id]>n/2){
		pair<int,int>tmp=q.top();
		if(tmp.second==id)
			cnt[id]--,ans+=tmp.first;
		q.pop();
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
		work();
}
