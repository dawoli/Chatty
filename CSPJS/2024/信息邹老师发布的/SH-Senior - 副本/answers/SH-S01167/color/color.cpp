#include<bits/stdc++.h>
using namespace std;
int t,n,a[105],ans;
void solvebf1(int pos,int b,int r,int tot){
	if(pos>n){
		ans=max(ans,tot);
		return;
	}
	solvebf1(pos+1,a[pos],r,tot+(a[pos]==b?b:0));
	solvebf1(pos+1,b,a[pos],tot+(a[pos]==r?r:0));
	return; 
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=15){
			solvebf1(1,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
