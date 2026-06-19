#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout<<"ok"<<endl

int degree[100007][7];
int dp[100007];
//1 2 3 4=(1-2) 5=(1-3) 6=(2-3)

int main(){
	//n<=1e5 t<=5
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int T;
	cin>>T;
	while(T--){
		int n,c3=0,c2=0,c1=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>degree[i][j];
			}
			degree[i][4]=degree[i][1]-degree[i][2];
			degree[i][5]=degree[i][1]-degree[i][3];
			degree[i][6]=degree[i][2]-degree[i][3];
		}
		dp[0]=0;
		for(int i=1;i<=n;i++){
			int h=max(degree[i][1],max(degree[i][2],degree[i][3]));
			if(degree[i][1]==h){
				c1++;
				if(c1<=n/2){
					dp[i]=dp[i-1]+h;
				}else{
					if(c2==n/2){
						dp[i]=dp[i-1]+degree[i][3];
						c1--;
						c3++;
					}else if(c3==n/2){
						dp[i]=dp[i-1]+degree[i][2];
						c1--;
						c2++;
					}else{
						int minn=INT_MAX;
						for(int j=1;j<=i;j++){
							minn=min(minn,min(abs(degree[j][4]),abs(degree[j][5])));
						}
						for(int j=1;j<=i;j++){
							if(degree[j][4]==minn){
								c1--;
								c2++;
								dp[i]=dp[i-1]+degree[i][1]-abs(degree[j][4]);
								degree[j][4]=99999999;
							}else if(degree[j][5]==minn){
								c1--;
								c3++;
								dp[i]=dp[i-1]+degree[i][1]-abs(degree[j][5]);
								degree[j][5]=99999999;
							}
						}
					}
				}
			}else if(degree[i][2]==h){
				c2++;
				if(c2<=n/2){
					dp[i]=dp[i-1]+h;
				}else{
					if(c1==n/2){
						dp[i]=dp[i-1]+degree[i][3];
						c2--;
						c3++;
					}else if(c3==n/2){
						dp[i]=dp[i-1]+degree[i][1];
						c2--;
						c1++;
					}else{
						int minn=INT_MAX;
						for(int j=1;j<=i;j++){
							minn=min(minn,min(abs(degree[j][4]),abs(degree[j][6])));
						}
						for(int j=1;j<=i;j++){
							if(-degree[j][4]==minn){
								c2--;
								c1++;
								dp[i]=dp[i-1]+degree[i][2]-abs(degree[j][4]);
								degree[j][4]=-99999999;
							}else if(degree[j][6]==minn){
								c2--;
								c3++;
								dp[i]=dp[i-1]+degree[i][2]-abs(degree[j][6]);
								degree[j][6]=99999999;
							}
						}
					}
				}
			}else{
				c3++;
				if(c3<=n/2){
					dp[i]=dp[i-1]+h;
				}else{
					if(c1==n/2){
						dp[i]=dp[i-1]+degree[i][2];
						c3--;
						c2++;
					}else if(c2==n/2){
						dp[i]=dp[i-1]+degree[i][1];
						c3--;
						c1++;
					}else{
						int minn=INT_MAX;
						for(int j=1;j<=i;j++){
							minn=min(minn,min(abs(degree[j][5]),abs(degree[j][6])));
						}
						for(int j=1;j<=i;j++){
							if(-degree[j][5]==minn){
								c3--;
								c1++;
								dp[i]=dp[i-1]+degree[i][3]-abs(degree[j][5]);
								degree[j][5]=-99999999;
								
							}else if(-degree[j][6]==minn){
								c3--;
								c2++;
								dp[i]=dp[i-1]+degree[i][3]-abs(degree[j][6]);
								degree[j][6]=-99999999;
							}
						}
					}
				}
			}
		}
		/*
		for(int i=1;i<=n;i++){
			int h=max(degree[i][1],max(degree[i][2],degree[i][3]));
			if(degree[i][1]==h){
				c1++;
			}else if(degree[i][2]==h){
				c2++;
			}else{
				c3++;
			}
			ans+=h;
		}
		if(c1<=n/2 && c2<=n/2 && c3<=n/2){
			cout<<ans<<endl;
		}else{
			while(c1>n/2 || c2>n/2 || c3>n/2){
				int minn=INT_MAX;
				if(c1>n/2){
					while(c1>n/2){
						for(int i=1;i<=n;i++){
							minn=min(minn,min(degree[i][4],degree[i][5]));
						}
						for(int i=1;i<=n;i++){
							if(degree[i][4]==minn){
								c1--;
								c2++;
								ans-=degree[i][4];
							}else if(degree[i][5]==minn){
								c1--;
								c3++;
								ans-=degree[i][5];
							}
						}
					}
				}
				minn=INT_MAX;
				if(c2>n/2){
					while(c2>n/2){
						for(int i=1;i<=n;i++){
							minn=min(minn,min(-degree[i][4],degree[i][6]));
						}
						for(int i=1;i<=n;i++){
							if(-degree[i][4]==minn){
								c2--;
								c1++;
								ans+=degree[i][4];
							}else if(degree[i][6]==minn){
								c2--;
								c3++;
								ans-=degree[i][6];
							}
						}
					}
				}
				minn=INT_MAX;
				if(c3>n/2){
					while(c3>n/2){
						for(int i=1;i<=n;i++){
							minn=min(minn,min(-degree[i][5],-degree[i][6]));
						}
						for(int i=1;i<=n;i++){
							if(-degree[i][5]==minn){
								c3--;
								c1++;
								ans+=degree[i][5];
							}else if(-degree[i][6]==minn){
								c3--;
								c2++;
								ans+=degree[i][6];
							}
						}
					}
				}
			}
			cout<<ans<<endl;			
		}
		*/
		cout<<dp[n]<<endl;
	}
	return 0;
}


