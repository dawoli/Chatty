#include<bits/stdc++.h>
using namespace std;
int f[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f+1,f+1+n);
	if(f[n]==2){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(f[i]==1) cnt1++;
			else break;
		}
		cnt2=n-cnt1;
		cout<<max(cnt1,cnt2);
	}
	else{
		int mi=f[1],cnt=n;
		for(int i=2;i<=n;i++){
			if(f[i]==mi) continue;
			for(int j=i-1;j>=1;j--){
				if(f[j]<f[i]){
					f[j]=10000009;
					cnt--;
					break;
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}
