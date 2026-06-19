#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9,A=1e5+9;
int n,r[N];
int cnt[A],mx,sum,ans;
int main(){
	ios::sync_with_stdio(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	for(int i=1;i<=n;i++) cnt[r[i]]++,mx=max(mx,r[i]);
	for(int i=1;i<=mx;i++){//统计退出了的 
		if(cnt[i]){
			if(sum>cnt[i]){
				ans+=cnt[i];
				cnt[i]=0;
			}
			else{
				ans+=sum;
				sum=cnt[i];
			}
		}
	}
	ans=n-ans;
	cout<<ans; 
	return 0;
}
