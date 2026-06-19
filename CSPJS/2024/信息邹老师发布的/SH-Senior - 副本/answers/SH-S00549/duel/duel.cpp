#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,r[N],maxx,cnt[N],def=0,att=0,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		cnt[r[i]]++;
		maxx=max(maxx,r[i]);
	}
	for(int i=1;i<=maxx;i++){
		att=cnt[i];
		if(def<=att){
			ans+=def;
			att-=def;
			def=0;
		}
		else{
			ans+=att;
			def-=att;
			att=0;
		}
		def+=cnt[i];
	}
	cout<<n-ans<<endl;
	return 0;
}
