//100pts
#include <bits/stdc++.h>
using namespace std;
int cnt[100009];
int f[100009];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>f[i];
	}
	sort(f,f+n+1);
	cnt[1]++;
	int key=1;
	int bef=0;
	bool flag=0;
	for(int i=2;i<=n;i++) {
//		cout<<cnt[1]<<" ";
		if(f[i]>f[i-1]) {
			flag=1;
			key++;
			cnt[key]++;
			if(cnt[bef]<=0) bef++;
			if(key>bef)cnt[bef]--;
		}
		while(flag&&cnt[bef]<=0)bef++;
		if(f[i]==f[i-1]){
			cnt[key]++;
			if(key>bef)cnt[bef]--;
		}
		
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=cnt[i];
//		cout<<cnt[i]<<endl;
	}
	cout<<ans<<endl;
	return 0;
} 

