#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,t;
int c[4];//…ÁÕ≈ 
long long dp[4][50002];
int a[4][100002];
int b[100002];
int a12_0(){
	for(int i=1;i<=n;i++){
		if(a[2][i]!=0)return 0;
		if(a[3][i]!=0)return 0;
	}
	return 1;
}
int a3_0(){
	for(int i=1;i<=n;i++){
		if(a[3][i]!=0)return 0;
	}
	return 1;
}

int flag=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>n;
		c[1]=0;
		c[2]=0;
		c[3]=0;
		for(int q=1;q<=n;q++){
			cin>>a[1][q]>>a[2][q]>>a[3][q];
		}
		int max_a=0;
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j && a[i][1]+a[j][2]>max_a){
						max_a=a[i][1]+a[j][2];
					}
				}
			}
			cout<<max_a;
			flag=1;
		}
		if(flag==1)continue;
		
		if(a12_0()){
			for(int i=1;i<=n;i++)b[i]=a[1][i];
			sort(b+1,b+n+1);
			reverse(b+1,b+n+1);
			long long sum=0;
			for(int j=1;j<=n/2;j++){
				sum+=b[j];
			}
			cout<<sum;
			flag=1;
		}
		if(flag==1)continue;
		
		for(int i=1;i<=n;i++){
			for(int k=1;k<=3;k++){
				for(int j=n/2;j>=c[k];j--){
					if(dp[k][j-1]+a[k][i]>dp[k][j]){
						dp[k][j]=dp[k][j-1]+a[k][i];
						c[k]++;
					}
				}
			}
		}
		cout<<max(dp[1][n/2],max(dp[2][n/2],dp[3][n/2]));
		
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++)a[i][j]==0;
			for(int j=1;j<=n/2;j++)dp[i][j]==0;
		}
	}

	return 0;
}

//int maxa_pos(int i){
//	int ap=a[1][i];
//	int p=1;
//	if(a[2][i]>ap){
//		ap=a[2][i];
//		p=2;
//	}
//	if(a[3][i]>ap){
//		ap=a[3][i];
//		p=3;
//	}
//	return p;
//}
//int maxa(int i){
//	return max(a[1][i],max(a[2][i],a[3][i]));
//}
