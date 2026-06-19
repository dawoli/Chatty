#include<bits/stdc++.h>
using namespace std;
int t,n,res,num1[100002],num2[100002],num3[100002],dp[205][205][205];
int peo[4],ans[4];
struct Stu{
	int a,clu,id;
}stu[300002];
bool vis[100002];
bool cmp(Stu a,Stu b){
	return a.a>b.a;
}
void solve2(){
	int cincnt=1;
	for(int i=1,cina,cinb,cinc;i<=n;i++){
		vis[i]=0;
		for(int j=1,x;j<=3;j++){
			cin>>x;
			stu[cincnt++]={x,j,i};
		}
	}
	sort(stu+1,stu+cincnt,cmp);
	for(int i=1;i<=cincnt;i++){
		if(!vis[stu[i].id]&&peo[stu[i].clu]<n/2){
			vis[stu[i].id]=1;
			peo[stu[i].clu]++;
			ans[stu[i].clu]+=stu[i].a;
		}
	}
	cout<<ans[1]+ans[2]+ans[3]<<endl;
	for(int i=1;i<=3;i++){
		peo[i]=ans[i]=0;
	}
}
void solve(){
	memset(dp,0,sizeof dp);
	int ans=0;
	cin>>n;
	if(n>200){
		solve2();
		return;
	}
	for(int i=1;i<=n;i++){
		cin>>num1[i]>>num2[i]>>num3[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,n/2);j++){//第一组人数 
			for(int k=0;k<=min(i,n/2);k++){//第二组人数 
				int l=i-j-k;
				if(l<0)continue;
				if(j>0&&j<=n/2){//加入第一组 
					dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+num1[i]);
				}
				if(k>0&&k<=n/2){
					dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+num2[i]);
				}
				if(l>0&&l<=n/2){
					dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+num3[i]);
				}
			}
		}
	}
	for(int i=0;i<=n/2;i++){
		for(int j=n/2-i;j<=n/2;j++){
			int k=n-i-j;
			ans=max(ans,dp[i][j][k]);
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
