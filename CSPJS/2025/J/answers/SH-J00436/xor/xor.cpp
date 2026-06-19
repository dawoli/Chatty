#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[500005],rst[500005][2];
int f(int x,int y){
	int t=0,s=0,fl=0;
	memset(ans,0,sizeof(ans));
	if(x==1)ans[++t]=1;
	while(x>1){
		while(x%2==1&&x>1){
			x=(x-1)/2;
			ans[++t]=1;
		}
		while(x%2==0&&x>1){
			x/=2;
			ans[++t]=0;
		}
		if(x==1){
			ans[++t]=1;
			break;
		}
	}
	for(int i=1;i<=t;i++)rst[i][1]=ans[i];
	memset(ans,0,sizeof(ans));
	if(y==1)ans[++s]=1;
	while(y>1){
		while(y%2==1&&y>1){
			y=(y-1)/2;
			ans[++s]=1;
		}
		while(y%2==0&&y>1){
			y/=2;
			ans[++s]=0;
		}
		if(y==1){
			ans[++s]=1;
			break;
		}
	}
	for(int i=1;i<=s;i++)rst[i][2]=ans[i];
	for(int i=1;i<=max(s,t);i++){
		if((rst[i][1]==1&&rst[i][2]==0)||(rst[i][1]==0&&rst[i][2]==1)){
			int b=1;
			for(int j=1;j<=i-1;j++)b*=2;
			fl+=b;
		}
	}
	return fl;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,xb=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int sl=a[l];
			for(int i=l+1;i<=r;i++){
				sl=f(sl,a[i]);
			}
			if(sl==k){
				xb++;
			}
		}
	}
	cout<<xb;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
