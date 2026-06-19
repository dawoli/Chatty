#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
#define N 111111
int n,a[N],now,cnt[N],ans,used[N];
int main(){
	open("duel");
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],++cnt[a[i]];
	for(int i=1;i<=100000;i++){
		now=max(now,i+1);
		while(cnt[i]&&now<=100000){
//			cerr<<i<<' '<<cnt[i]<<' '<<now<<endl;
			if(cnt[i]>cnt[now]-used[now])cnt[i]-=cnt[now]-used[now],used[now]=cnt[now++];
			else used[now]+=cnt[i],cnt[i]=0;
		}
		ans+=cnt[i];
	}
	cout<<ans<<endl;
}
