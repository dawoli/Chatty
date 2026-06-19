#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cnt;
int c[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	int now=0,past=0,yushu=0;
	for(int i=1;i<=100004;i++){
		if(c[i]!=0){
			past=now;
			now=c[i];
			cnt+=min(now,past);
			yushu+=max(0,past-now);
		}
		if(now>past&&yushu>0&&c[i]!=0){
			cnt+=min(yushu,now-past);
			yushu=max(0,yushu-(now-past));
		}
	}
	int sum=n-cnt;
	cout<<sum;
	return 0;
}
