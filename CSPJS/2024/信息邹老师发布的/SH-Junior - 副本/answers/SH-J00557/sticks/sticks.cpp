#include<bits/stdc++.h>
using namespace std;
long long T,n;
long long a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	 cin>>T;
	 while(T--){
	 	string dp[101010];
	 	cin>>n;
	 	dp[0]="-1",dp[1]="-1",dp[2]="1",dp[3]="7",dp[4]="4",dp[5]="2",dp[6]="6",dp[7]="8";
	 	for(long long i=8;i<=n;i++){
	 		for(long long j=0;j<10;j++){
	 			if(i-a[j]<=1) continue;
	 			string s=dp[i-a[j]]+(char)(j+'0');
	 			if(j==0) dp[i]=s;
	 			else{
	 				if(dp[i].size()>s.size()) dp[i]=s;
	 				else if(dp[i].size()==s.size()) dp[i]=min(dp[i],s);
				}
			}
		}
		cout<<dp[n]<<endl;
	}
	//50»è 
	
	return 0;
} 
