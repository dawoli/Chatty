#include<bits\stdc++.h>
using namespace std;
int a1[100050],a2[100050],a3[100050];
int maxn,n;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int step,int sum1,int sum2,int tol1,int tol2){
	if(step==n+1)return ;
	if(tol1>n/2||tol2>n/2){
		if(sum1+sum2>maxn)maxn=sum1+sum2;
		return ;
	}
	dfs(step+1,sum1+a1[step],sum2,tol1+1,tol2);
	dfs(step+1,sum1,sum2+a2[step],tol1,tol2+1);
}
void dfs2(int step,int sum1,int sum2,int sum3,int tol1,int tol2,int tol3){
	if(step==n+1)return ;
	if(tol1>n/2||tol2>n/2||tol3>n/2){
		if(sum1+sum2+sum3>maxn)maxn=sum1+sum2+sum3;
		return ;
	}
	dfs2(step+1,sum1+a1[step],sum2,sum3,tol1+1,tol2,tol3);
	dfs2(step+1,sum1,sum2+a2[step],sum3,tol1,tol2+1,tol3);
	dfs2(step+1,sum1,sum2,sum3+a3[step],tol1,tol2,tol3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		maxn=0;
		bool flag=true,flag1=true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]!=0||a2[i]!=0)flag=false;
			if(a3[i]!=0)flag1=false;
		}
		if(flag){
			sort(a2+1,a2+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++)ans+=a2[i];
			cout<<ans;
			return 0;
		}
		if(n==2){
			cout<<max({a1[1]+a2[2],a1[1]+a3[2],a2[1]+a1[2],a2[1]+a3[2],a3[1]+a1[2],a3[1]+a2[2]});
			return 0;
		}
		if(flag1){
			dfs(1,0,0,0,0);
			cout<<maxn<<endl;
		}
		dfs2(1,0,0,0,0,0,0);
		cout<<maxn<<endl;
	}
	return 0; 	
}
