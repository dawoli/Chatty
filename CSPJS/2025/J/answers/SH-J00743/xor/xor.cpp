#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n,k;
int a[500005];
int xo[500005];
int dp[500005];
int fd[500005];
map<int,vector<int> > mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		xo[i]=xo[i-1]^a[i];
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			for(int j=1;j<=i;j++){
				if((xo[i]^xo[j-1])==k){
					dp[i]=max(dp[i],dp[j-1]+1);
				}
			}
		}
		cout << dp[n] << endl;	
	}else{
		for(int i=0;i<=n;i++){
			if(k^xo[i]!=xo[i]) mp[k^xo[i]].push_back(i);
		}
		/*
		for(int i=1;i<=n;i++){
			cout << i << ':';
			cout << mp[xo[i]].size();
			for(int j=0;j<mp[xo[i]].size();j++){
				cout << mp[xo[i]][j] << ' ';
			}
			cout << endl;
		}
		*/
		for(int i=0;i<=n;i++) fd[i]=-1;
		for(int i=1;i<=n;i++){
			if(a[i]==k) fd[i]=i-1;
			else{
				int l=0,r=mp[xo[i]].size()-1;
				//cout << r << ' ';
				while(l<=r){
					int mid=(l+r)>>1;
					if(mp[xo[i]][mid]<=i){
						l=mid+1;
						fd[i]=mp[xo[i]][mid];
					}else{
						r=mid-1;
					}
				}
			}
			//cout << fd[i] << endl;
		}
		for(int i=1;i<=n;i++){
			if(fd[i]>=0)dp[i]=max(dp[i-1],dp[fd[i]]+1);
			else dp[i]=dp[i-1];
			//cout << dp[i] << ' ';
		}
		cout << dp[n] << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
