#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+7;
string dp[N];
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	dp[2]="1";dp[3]="7";dp[4]="4";dp[5]="2";dp[6]="0";dp[7]="8";dp[8]="16";dp[9]="18";dp[10]="22";dp[11]="20";dp[12]="28";dp[13]="80";dp[14]="88";
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1){cout<<-1<<endl;continue;}
		if(n==6){cout<<6<<endl;continue;}
		if(n<=14){cout<<dp[n]<<endl;continue;}
		for(int i=15;i<=(n/7*7);i++){
			if(dp[i]!="") continue;
			string mini="0";
			for(int j=(i/7-1)*7+1;j<=i/7*7;j++){
				for(int k=2;k<=7;k++){
					if(j+k==i){
						int cg[N];
						int v=0;
						for(int u=0;u<dp[j].size();u++){cg[v]=dp[j][u]-'0';v++;}
						cg[v]=dp[k][0]-'0';
						sort(cg,cg+v);
						if(cg[0]==0){
							if(cg[1]>6) cg[0]=6;
							else cg[0]=cg[1],cg[1]=0;
						}
						string num;
						for(int i=0;i<=v;i++) num+=(cg[i]+'0');
						if(mini=="0") mini=num;
						else mini=min(num,mini);
					}
				}
			}
			dp[i]=mini;
		}
		string mini="0";
		for(int j=(n/7-1)*7+1;j<=n/7*7;j++){
				for(int k=2;k<=7;k++){
					if(j+k==n){
						int cg[N];
						int v=0;
						for(int u=0;u<dp[j].size();u++){cg[v]=dp[j][u]-'0';v++;}
						cg[v]=dp[k][0]-'0';
						sort(cg,cg+v);
						if(cg[0]==0){
							if(cg[1]>6) cg[0]=6;
							else cg[0]=cg[1],cg[1]=0;
						}
						string num;
						for(int i=0;i<=v;i++) num+=(cg[i]+'0');
						if(mini=="0") mini=num;
						else mini=min(num,mini);
					}
				}
		}
		dp[n]=mini;
		cout<<dp[n]<<endl;
	}
	return 0;
}
