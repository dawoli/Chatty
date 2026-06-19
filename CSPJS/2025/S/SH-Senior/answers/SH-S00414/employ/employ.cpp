#include<bits/stdc++.h>
using namespace std;
int n,m,c[114514],dp[20][(1<<18)+1];char us[114514];
void popout(int x){
	stack<int> st;
	while(x>0){
		st.push(x%2);
		x/=2;
	}
	while(!st.empty()){
		cout<<st.top();st.pop();
	}
}
int main(){
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	cin>>us+1;
	for(int i=1;i<=n;i++)cin>>c[i];
	dp[0][0]=1;
	for(int l=0;l<=n;l++){
		for(int i=1;i<(1<<n);i++){
			int ppcnt=0;
			for(int j=1;j<(1<<n);j<<=1){
				if(i&j)ppcnt++;
			}
			if(l>ppcnt)continue;
			for(int j=1,k=1;k<=n;j<<=1,k++){
				if((i&j)){
					if(us[ppcnt]=='1'&&c[k]>(ppcnt-l-1)){
						if(l+1<=ppcnt){
							dp[l+1][i]=(dp[l+1][i]+dp[l][i^j])%998244353;
							//popout(i^j);cout<<"->";popout(i);cout<<"SUC\n";
						}
					}
					else{
						dp[l][i]=(dp[l][i]+dp[l][i^j])%998244353;
						//popout(i^j);cout<<"->";popout(i);cout<<"FAL "<<l<<" "<<k<<'\n';
					}
				}
			}
		}
	}long long ans=0;
	for(int i=m;i<=n;i++){
		ans=(ans+dp[i][(1<<n)-1])%998244353;
	}cout<<ans;
	return 0;
}
