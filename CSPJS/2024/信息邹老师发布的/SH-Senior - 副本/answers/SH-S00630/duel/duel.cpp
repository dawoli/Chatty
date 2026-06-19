#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> ma;//defence and number
map<int,int>::iterator it;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int t;
	int maxn=-1e9;
	int minn=1e9;
	for(int i=1;i<=n;i++) {
		cin>>t;
		ma[t]++;
		maxn=max(maxn,t);
		minn=min(t,minn);
	}
//	for(it=ma.begin();it!=ma.end();it++){
//		cout<<(it->first)<<" "<<(it->second)<<"\n";
//	}
	//cout<<minn<<" "<<maxn<<"\n";
	int ans=0;//kill amount
	int num=0;//below the current defence
	for(int i=1;i<=maxn;i++){
		if(ma[i]==0) continue;
		//cout<<ma[i]<<"\n";
		if(i>minn){
			if(num>=ma[i]){
				ans+=ma[i];
				num-=ma[i];
			}
			else{
				ans+=num;
				num=0;
			}
			minn=i;
		}
		num+=ma[i];
	}
	cout<<n-ans;
	return 0;
}
