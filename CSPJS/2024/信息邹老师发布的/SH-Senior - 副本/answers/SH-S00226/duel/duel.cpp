#include<bits/stdc++.h>
using namespace std;
int n,ans,tmp,a[100005],ok[100005],ans[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	int ans=0,sum=0;
	for(int i=1;i<=100000;i++){
		int r=min(sum,cnt[i]);
		ans=r;
		sum+=cnt[i]-r;
	}
	cout<<ans<<endl;
	return 0;
} 
