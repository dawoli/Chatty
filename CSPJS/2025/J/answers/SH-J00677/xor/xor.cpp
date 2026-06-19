#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k;
int a[MAXN],dp[MAXN];
/*string transform(int n){
	string s;
	while(n>=1){
		s+=n%2;
		n/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	int ans=0;
	for(int i=n;i>=1;i--){
		dp[i]=dp[i+1];
		int num=0;
		for(int j=i;j<=n;j++){
			if(i<=n-2&&j!=i&&dp[j+1]!=dp[j]){
				//cout<<j<<endl;
			    break;
			}
			num^=a[j];
			if(num==k){
			    dp[i]=dp[j+1]+1;
			    //cout<<dp[i]<<endl;
			    break;
			}
		}
	}
	//for(int i=1;i<=n;i++)
	    //cout<<dp[i]<<" ";
	cout<<dp[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
