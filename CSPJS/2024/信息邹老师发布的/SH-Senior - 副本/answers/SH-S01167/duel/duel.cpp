#include<bits/stdc++.h>
using namespace std;
int n,r[100005],ans,rct,cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>r[i];
	sort(r+1,r+1+n);
	rct=r[1];
	for(int i=1;i<=n;i++){
		if(r[i]!=rct)ans=max(ans,cnt),rct=r[i],cnt=1;
		else cnt++;
	}
	cout<<max(ans,cnt)<<endl;
	return 0;
} 
