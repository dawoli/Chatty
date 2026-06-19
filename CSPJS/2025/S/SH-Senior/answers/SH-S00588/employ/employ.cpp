#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int m,n,dp[510][510][510],dpxiao[1<<20][21],c[510],flagA=1;
string s;
int calc(int x){
	int cnt=0;
	while(x)
		x&=(x-1),cnt++;
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')
			flagA=0;
	for(int i=1;i<=n;i++)
		cin>>c[i],num0+=(int)(c[i]==0);
	if(m==n){
		if(num0||!flagA){
			cout<<0;
			return 0;
		}
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i,ans%=Mod;
		cout<<ans;
		return 0;
	}
	if((1<<n)*m*n<=10000000){
		dpxiao[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			int tmp=calc(i);
//			cout<<"!!!"<<i<<" "<<tmp<<"\n";
			for(int j=0;j<n;j++){
				if(i&(1<<j))
					continue;
				for(int k=0;k<=tmp;k++){
					if(k>=c[j+1]||s[tmp]=='0'){
//						cout<<<<j<<"\n";
						dpxiao[i|(1<<j)][k+1]+=dpxiao[i][k],dpxiao[i|(1<<j)][k+1]%=Mod;
					}
					else
						dpxiao[i|(1<<j)][k]+=dpxiao[i][k],dpxiao[i|(1<<j)][k]%=Mod;
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)
			ans+=dpxiao[(1<<n)-1][n-i],ans%=Mod;
		cout<<ans;
	}
	
}
