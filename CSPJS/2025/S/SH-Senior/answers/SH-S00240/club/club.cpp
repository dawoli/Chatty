#include<bits/stdc++.h>
using namespace std;
int n;
int appli[100005][3];
int dp[205][205][205]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n;
		bool flag=true;
		vector<int> savestate;
		for(int i=1;i<=n;i++){
			cin>>appli[i][0]>>appli[i][1]>>appli[i][2];
			savestate.push_back(appli[i][0]);
			if(appli[i][2] || appli[i][1]) flag=false; 
		} 
		if(flag){
			int res=0; 
			sort(savestate.begin(),savestate.end());
			reverse(savestate.begin(),savestate.end()); 
			for(int i=0;i<n/2;i++){
				res+=savestate[i];
			} 
			cout<<res<<endl;
			continue;
		}
		int res=0;
		for(int i=1;i<=n;i++)
			for(int a=0;a<=min(i,n/2);a++)
				for(int b=0;b<=min(i-a,n/2);b++){
					int c=i-a-b;
					if(c>n/2) continue;
					int val1=0,val2=0,val3=0;
					if(a>=1) 
						val1=dp[a-1][b][c]+appli[i][0];
					if(b>=1) 
						val2=dp[a][b-1][c]+appli[i][1];
					if(c>=1)
						val3=dp[a][b][c-1]+appli[i][2]; 
					dp[a][b][c]=max(val1,max(val2,val3));
					if(i==n){
						res=max(dp[a][b][c],res);
					}
				}
//		for(int i=0;i<=n;i++){
//			for(int j=0;j<=n;j++){
//				for(int k=0;k<=n;k++){
//					cout<<dp[i][j][k]<<' ';
//				}cout<<endl;
//			}cout<<endl;
//		}
		cout<<res<<endl;
		memset(appli,0,sizeof(appli));
		memset(dp,0,sizeof(dp));
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
