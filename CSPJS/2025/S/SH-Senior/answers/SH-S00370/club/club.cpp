#include<bits/stdc++.h>
using namespace std;
int abc[100005][3];
int dp[3][100010];
int people[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n=0;
	cin>>T;
	while(T--){
			people[0]=people[1]=people[2]=0;
			for(int i=0;i<=2;i++)
				for(int j=1;j<=n;j++)
					dp[i][j]=0;
			for(int i=1;i<=n;i++)
				for(int j=0;j<=2;j++)
					abc[i][j]=0;
			cin>>n;
			if(n!=2){
				int lim=n/2;
				for(int i=1;i<=n;i++){
					cin>>abc[i][0]>>abc[i][1]>>abc[i][2];
				}
				for(int i=0;i<=2;i++){
					int i1=i,cnt=0;
					for(int j=1;j<=n;j++){
						dp[i][j]+=dp[i][j-1]+abc[j][i1];
						people[i1]++;
						if(people[i1]>=lim) i1++,cnt++;
						if(i1>2) i1=0;
						if(cnt>2){
							dp[i][n]=dp[i][j];
							break;
						}
					}
					people[0]=people[1]=people[2]=0; 
				}
				for(int i=0;i<=2;i++){
					for(int j=1;j<=n;j++)
						cout<<dp[i][j]<<" ";
					cout<<endl;
				}
				cout<<max(dp[0][n],max(dp[1][n],dp[2][n]))<<endl;
			}else{
				int a1,a2,a3,b1,b2,b3;
				cin>>a1>>a2>>a3>>b1>>b2>>b3;
				int ans1=max(a1+b2,max(a1+b3));
				int ans2=max(a2+b1,max(a2+b3));
				int ans3=max(a3+b1,max(a3+b2));
				int ans4=max(b1+a2,max(b1+a3));
				int ans5=max(b2+a1,max(b2+a3));
				int ans6=max(b3+a1,max(b3+a2));
				int ans7=max(ans1,max(ans2,ans3));
				int ans8=max(ans4,max(ans5,ans6));
				cout<<max(ans7,ans8);
			}
	}
	return 0;
} 
