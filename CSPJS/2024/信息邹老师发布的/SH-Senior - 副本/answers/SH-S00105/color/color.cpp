#include <bits/stdc++.h>
using namespace std;
int T,n;
long long a[200020],dp[2][200020],s[200020],sta[200020],ans;//dp表示最后一位颜色且长度为1~i
vector<int> pos[1000010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(pos,0,sizeof(pos));
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i]=s[i-1]+(a[i]==a[i-1])*a[i];
			pos[a[i]].push_back(i);
		}
		for(int i=0;i<(1<<(n-1));i++){
			long long tmp=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j))sta[j+1]=1;
				else sta[j+1]=0;
			}
			for(int k=2;k<=n;k++){
				int p=0;
				for(int l=k-1;l>=1;l--){
					if(sta[l]==sta[k]&&p==0){
						p++;
						if(a[l]==a[k])tmp+=a[k];
						continue;
					}
				}
			}
			ans=max(ans,tmp);
		}
		cout<<ans<<endl;
/*		dp[0][1]=0,dp[1][1]=0;
		for(int i=2;i<=n;i++){
			if(pos[a[i]].size()==0){
				dp[0][i]=dp[0][i-1];
				dp[1][i]=dp[1][i-1];
			}
			else{
				for(int j=0;j<pos[a[i]].size();j++){
					if(pos[a[i]][j]<i){
						dp[0][i]=max(dp[0][i],dp[0][pos[a[i]][j]]+s[i-1]-s[pos[a[i]][j]]+a[i]);
						dp[1][i]=max(dp[1][i],dp[1][pos[a[i]][j]]+s[i-1]-s[pos[a[i]][j]]+a[i]);	
					}
				}
			}
		}
		cout<<max(dp[0][n],dp[1][n])<<endl;*/
	}
	return 0;
}
