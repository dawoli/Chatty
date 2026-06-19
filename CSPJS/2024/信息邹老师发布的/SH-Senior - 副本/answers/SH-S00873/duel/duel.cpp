#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,r[maxn],cnt[maxn],nxt[maxn];
int used[maxn];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	vector<int> a;
	map<int,bool> b;
	for(int i=0;i<n;i++){
		cin>>r[i];
		cnt[r[i]]++;
		if(!b[r[i]]){
			a.emplace_back(r[i]);
			b[r[i]]=1;
		}
	}
	sort(a.begin(),a.end());
	int x=-1;
	for(int i : a){
		if(x!=-1){
			nxt[x]=i;
		}
		x=i;
	}
	nxt[x]=maxn;
	int ans=n;
	for(int i=0;i<maxn;i++){
		if(cnt[i]<=0) continue;
		for(int j=nxt[i];j<maxn&&cnt[i]>0;j=nxt[j]){
			//cerr<<"i:"<<i<<" "<<cnt[i]<<" j:"<<j<<" "<<cnt[j]<<endl;
			if(cnt[i]<=0) break;
			if(cnt[j]-used[j]<=0) continue;
			if(cnt[j]-used[j]>=cnt[i]){
				used[j]+=cnt[i];
				ans-=cnt[i];
				cnt[i]=0;
			}else{
				cnt[i]-=cnt[j]-used[j];
				ans-=cnt[j]-used[j];
				used[j]=cnt[j];
			}
			//cerr<<"ans="<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}
/*
5
1 2 3 1 2

2

10
136 136 136 2417 136 136 2417 136 136 136

8
*/
