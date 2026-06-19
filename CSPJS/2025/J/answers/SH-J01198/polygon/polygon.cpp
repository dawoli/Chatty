#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353,N=5005;
long long n,ans,x_1,x_12;
long long a[N];
void dfs(long long pos,long long step,long long target,long long sig,long long maxx){
	if(pos>n||step>=target){
		if(step==target&&sig>maxx*2){
			ans++;
			ans%=mod;
//			cout<<"man!!!  "<<pos<<" "<<step<<" "<<target<<" "<<sig<<" "<<maxx<<"\n";
		}
		return;
	}
	//get
	if(a[pos]!=0){
		dfs(pos+1,step+1,target,sig+a[pos],max(a[pos],maxx));
	}
	//not get
	dfs(pos+1,step,target,sig,maxx);
	return;
}
int main(){
	//取消注释!!!!!!!!!!!!!!!!!!!!
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//取消注释!!!!!!!!!!!!!!!!!!!!
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=1){
			x_12++;
			if(a[i]==1)x_1++;
		}
	}
	if(x_12==n){
		for(int i=3;i<=x_1;i++){
			long long h=1;
			for(int j=0;j<i;j++){
				h=h*(x_1-j)/(j+1);
				h%=mod;
			}
			ans+=h;
			
		}
		
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(1,0,i,0,-1);
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
