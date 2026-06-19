#include<bits/stdc++.h>
//Ren5Jie4Di4Ling5%
using namespace std;
int t,n,ans=0,c[5];
int xuan[5][100002];
struct stu{
	int x,y,z;
}a[100002];
bool cmp(stu c,stu d){
	return c.x>d.x;
}
void dfs(int dep,int sum){
	if(dep==n+1){
//		cout<<sum<<endl;
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(c[i]<n/2){
			c[i]++;
			if(i==1) sum+=a[dep].x;
			else if(i==2) sum+=a[dep].y;
			else if(i==3) sum+=a[dep].z;
			dfs(dep+1,sum);
			if(i==1) sum-=a[dep].x;
			else if(i==2) sum-=a[dep].y;
			else if(i==3) sum-=a[dep].z;
			c[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(c,0,sizeof(c));
		int flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0) flag=0;
		}
		if(flag){
			sort(a+1,a+n+1,cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].x;
			}
			cout<<sum<<endl;
			break;
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
