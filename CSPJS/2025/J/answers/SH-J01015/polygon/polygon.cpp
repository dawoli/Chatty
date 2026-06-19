#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	//解注释！！！！！！！ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//cout<<(1<<21);
	int n;
	cin>>n;
	int a[5005],maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	} 
	ll ans=0;
	if(maxn==1){
		for(int i=3;i<=n;i++){
			ll chu=1,beichu=1;
			for(int j=1;j<=i;j++){
				beichu*=j;
				chu*=(n-j+1);
			}
			//printf("%d %d\n",chu,beichu);
			ans+=chu/beichu;
			ans%=998244353;
		} 
		cout<<(ans%998244353);
		return 0;
	}
	if(n<=20){ 
		for(int i=0;i<(1<<n);i++){
	    	int b[25]={},isone=0,sum=0,ma=0;
			for(int j=1;j<=n;j++){
				b[j]=(i>>(j-1))&1;
				if(b[j]==1){
					isone++;
					sum+=a[j];
					ma=max(ma,a[j]);
				} 
			}
			if(sum>ma*2&&isone>=3) ans++;
		}
		cout<<(ans%998244353);
		return 0;
	}
	//记得取余！！！！！！ 
	return 0;
}
