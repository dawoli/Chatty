#include <bits/stdc++.h>
using namespace std;
int t,n;
struct Club{
	long long a1,a2,a3;
}stu[100010];
int maxd1,maxd2,maxd3;
long long dp[100010][5],vis[100010][4][2][2][2];
/*dp[i][j]:the ith person is put to the no. j dept.
vis[i][j][m][n][p]: ith person with j dept. has all depts with m,n,p
personnel;
*/
int a2zero,a3zero;
bool cmpa1(const Club &a,const Club&b){
	if(a.a1<=b.a1) return false;
	return true;
}//a1 from big to small
bool cmpa2(const Club &a,const Club&b){
	if(a.a2<=b.a2) return false;
	return true;
}//a2 from big to small
bool cmpa3(const Club &a,const Club&b){
	if(a.a3<=b.a3) return false;
	return true;
}//a3 from big to small
struct Dept{
	long long a[5];
}dept[100010][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		a2zero=0,a3zero=0;
		maxd1=0,maxd2=0,maxd3=0;
		memset(dp,0,sizeof dp),memset(vis,0,sizeof vis);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&stu[i].a1,&stu[i].a2,&stu[i].a3);
			int tmp=max(stu[i].a1,max(stu[i].a2,stu[i].a3));
			if(tmp==stu[i].a1) maxd1+=1;
			else if(tmp==stu[i].a2) maxd2+=1;
			else maxd3+=1;
			if(stu[i].a2==0) a2zero+=1;
			if(stu[i].a3==0) a3zero+=1;
		}
//		cerr<<""<<maxd1<<" "<<maxd2<<" "<<maxd3<<endl;
		if(max(maxd1,max(maxd2,maxd3))==maxd1)
			/*cerr<<"sort1\n",*/sort(stu+1,stu+n+1,cmpa1);
		if(max(maxd1,max(maxd2,maxd3))==maxd2)
			/*cerr<<"sort2\n",*/sort(stu+1,stu+n+1,cmpa2);
		if(max(maxd1,max(maxd2,maxd3))==maxd3)
			/*cerr<<"sort3\n",*/sort(stu+1,stu+n+1,cmpa3);
		if(n==2){
			long long ans=stu[1].a1+stu[2].a2;
			ans=max(ans,stu[1].a1+stu[2].a3);
			ans=max(ans,stu[1].a2+stu[2].a1);
			ans=max(ans,stu[1].a2+stu[2].a3);
			ans=max(ans,stu[1].a3+stu[2].a1);
			ans=max(ans,stu[1].a3+stu[2].a2);
			printf("%lld\n",ans);
			continue;
		}
		else if(n==4){
			long long ans=stu[1].a1+stu[2].a1+stu[3].a2+stu[4].a2;
			ans=max(ans,stu[1].a1+stu[2].a1+stu[3].a2+stu[4].a3);
			ans=max(ans,stu[1].a1+stu[2].a1+stu[3].a3+stu[4].a2);
			ans=max(ans,stu[1].a1+stu[2].a1+stu[3].a3+stu[4].a3);
			
			ans=max(ans,stu[1].a1+stu[2].a2+stu[3].a1+stu[4].a2);
			ans=max(ans,stu[1].a1+stu[2].a2+stu[3].a1+stu[4].a3);
			ans=max(ans,stu[1].a1+stu[2].a2+stu[3].a2+stu[4].a1);
			ans=max(ans,stu[1].a1+stu[2].a2+stu[3].a2+stu[4].a3);
			ans=max(ans,stu[1].a1+stu[2].a2+stu[3].a3+stu[4].a1);
			ans=max(ans,stu[1].a1+stu[2].a2+stu[3].a3+stu[4].a2);
			ans=max(ans,stu[1].a1+stu[2].a2+stu[3].a3+stu[4].a3);
			
			ans=max(ans,stu[1].a1+stu[2].a3+stu[3].a1+stu[4].a2);
			ans=max(ans,stu[1].a1+stu[2].a3+stu[3].a1+stu[4].a3);
			ans=max(ans,stu[1].a1+stu[2].a3+stu[3].a2+stu[4].a1);
			ans=max(ans,stu[1].a1+stu[2].a3+stu[3].a2+stu[4].a2);
			ans=max(ans,stu[1].a1+stu[2].a3+stu[3].a2+stu[4].a3);
			ans=max(ans,stu[1].a1+stu[2].a3+stu[3].a3+stu[4].a1);
			ans=max(ans,stu[1].a1+stu[2].a3+stu[3].a3+stu[4].a2);
			//1
			ans=max(ans,stu[1].a2+stu[2].a1+stu[3].a1+stu[4].a2);
			ans=max(ans,stu[1].a2+stu[2].a1+stu[3].a1+stu[4].a3);
			ans=max(ans,stu[1].a2+stu[2].a1+stu[3].a2+stu[4].a1);
			ans=max(ans,stu[1].a2+stu[2].a1+stu[3].a2+stu[4].a3);
			ans=max(ans,stu[1].a2+stu[2].a1+stu[3].a3+stu[4].a1);
			ans=max(ans,stu[1].a2+stu[2].a1+stu[3].a3+stu[4].a2);
			ans=max(ans,stu[1].a2+stu[2].a1+stu[3].a3+stu[4].a3);
			
			ans=max(ans,stu[1].a2+stu[2].a2+stu[3].a1+stu[4].a1);
			ans=max(ans,stu[1].a2+stu[2].a2+stu[3].a1+stu[4].a3);
			ans=max(ans,stu[1].a2+stu[2].a2+stu[3].a3+stu[4].a1);
			ans=max(ans,stu[1].a2+stu[2].a2+stu[3].a3+stu[4].a3);
			
			ans=max(ans,stu[1].a2+stu[2].a3+stu[3].a1+stu[4].a1);
			ans=max(ans,stu[1].a2+stu[2].a3+stu[3].a1+stu[4].a2);
			ans=max(ans,stu[1].a2+stu[2].a3+stu[3].a1+stu[4].a3);
			ans=max(ans,stu[1].a2+stu[2].a3+stu[3].a2+stu[4].a1);
			ans=max(ans,stu[1].a2+stu[2].a3+stu[3].a2+stu[4].a3);
			ans=max(ans,stu[1].a2+stu[2].a3+stu[3].a3+stu[4].a1);
			ans=max(ans,stu[1].a2+stu[2].a3+stu[3].a3+stu[4].a2);
			//2

			ans=max(ans,stu[1].a3+stu[2].a1+stu[3].a1+stu[4].a2);
			ans=max(ans,stu[1].a3+stu[2].a1+stu[3].a1+stu[4].a3);
			ans=max(ans,stu[1].a3+stu[2].a1+stu[3].a2+stu[4].a1);
			ans=max(ans,stu[1].a3+stu[2].a1+stu[3].a2+stu[4].a2);
			ans=max(ans,stu[1].a3+stu[2].a1+stu[3].a2+stu[4].a3);
			ans=max(ans,stu[1].a3+stu[2].a1+stu[3].a3+stu[4].a1);
			ans=max(ans,stu[1].a3+stu[2].a1+stu[3].a3+stu[4].a2);
			
			ans=max(ans,stu[1].a3+stu[2].a3+stu[3].a1+stu[4].a1);
			ans=max(ans,stu[1].a3+stu[2].a3+stu[3].a1+stu[4].a2);
			ans=max(ans,stu[1].a3+stu[2].a3+stu[3].a2+stu[4].a1);
			ans=max(ans,stu[1].a3+stu[2].a3+stu[3].a2+stu[4].a2);
			
			ans=max(ans,stu[1].a3+stu[2].a3+stu[3].a1+stu[4].a1);
			ans=max(ans,stu[1].a3+stu[2].a3+stu[3].a1+stu[4].a2);
			ans=max(ans,stu[1].a3+stu[2].a3+stu[3].a1+stu[4].a3);
			ans=max(ans,stu[1].a3+stu[2].a3+stu[3].a2+stu[4].a1);
			ans=max(ans,stu[1].a3+stu[2].a3+stu[3].a2+stu[4].a3);
			ans=max(ans,stu[1].a3+stu[2].a3+stu[3].a3+stu[4].a1);
			ans=max(ans,stu[1].a3+stu[2].a3+stu[3].a3+stu[4].a2);
			//3
			printf("%lld\n",ans);
			continue;
		}
		if(a2zero==n&&a3zero==n){
			long long ans=0;
			sort(stu+1,stu+n+1,cmpa1);
			for(int i=1;i<=n/2;i++) ans+=stu[i].a1;
			printf("%lld\n",ans);
			continue;
		}//A
		dp[1][1]=stu[1].a1,dp[1][2]=stu[1].a2,dp[1][3]=stu[1].a3;
		dept[1][1].a[1]=1;
		dept[1][2].a[2]=1;
		dept[1][3].a[3]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(dept[i][j].a[j]+1<=n/2){//can be put in this dept
					int best=max(dp[i-1][3],max(dp[i-1][1],dp[i-1][2]));
					if(best==dp[i-1][1]){//dept1
						dp[i][j]=dp[i-1][1]+stu[i].a1;
						dept[i][j].a[1]+=1;
					}
					else if(best==dp[i-1][2]){//dept2
						dp[i][j]=dp[i-1][2]+stu[i].a2;
						dept[i][j].a[2]+=1;
					}
					else if(best==dp[i-1][3]){//dept3
						dp[i][j]=dp[i-1][3]+stu[i].a1;
						dept[i][j].a[3]+=1;
					}
				}
			}
		}
		long long final=max(dp[n][1],max(dp[n][2],dp[n][3]));
		printf("%lld\n",final);
	}
	
	return 0;
}
