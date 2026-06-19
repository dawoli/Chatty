#include<bits/stdc++.h>
using namespace std;
int t,m;
int n,a[100010][4],ans=0;
int dfs(int sum,int d,int x,int y,int z){
	if(d>n){
		if(x<=n/2 and y<=n/2 and z<=n/2){
			ans=max(ans,sum);
		}
		return 0;
	}
	for(int i=1;i<=3;i++){
		dfs(sum+a[d][i],d+1,x+(i==1),y+(i==2),z+(1==3));
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=m=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0 or a[i][3]!=0){
				m=1;
			}
		}
		if(m==0){
			int f[100010]={};
			for(int i=1;i<=n;i++){
				f[i]=a[i][1];
			}
			sort(f+1,f+n+1);
			for(int i=n;i>n/2;i--){
				ans+=f[i];
			}
		}else{
			dfs(0,1,0,0,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
