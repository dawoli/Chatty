#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*w;
}
const int MAXN=2e5+10;
int t,n,a[MAXN],dp[MAXN],ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t=read();
	ans=0;
	for(int i=1;i<=t;i++){
		n=read();
		for(int j=1;j<=n;j++){
			a[j]=read();	
		}
		sort(a,a+n+1);
		for(int k=1;k<=n;k++)cout<<a[k]<<" ";
		cout<<endl;
		ans=0;
			for(int j=1;j<=n;j++){
				if(a[j]==a[j-1]){
					ans+=a[j];
					a[j-1]=0;
					a[j]=0;
				}
				//if(a[k]==a[j]){
				//	if(dp[k]<dp[k]+k){
				//		dp[k]=dp[k]+k;
				//		a[k]=0;
				//		a[j]=0;	
			}
		
		cout<<ans<<endl;
		}
	
	
	return 0;
}
