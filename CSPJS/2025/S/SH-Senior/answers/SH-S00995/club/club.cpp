#include<bits/stdc++.h>
using namespace std;
int T,n,s[210000],ans;
struct stu{
	int b[5],f1,f2,f3;
}a[210000]; 
void dfs(int pos,int n1,int n2,int n3,int dp){
	if(n1>n/2||n2>n/2||n3>n/2||s[pos]+dp<=ans)return;
	if(pos==n+1){
		ans=max(ans,dp);
		return;
	}
	if(f1==1&&f2==2&&f3==3){
		dfs(pos+1,n1+1,n2,n3,dp+a[pos].b[1]);
		dfs(pos+1,n1,n2+1,n3,dp+a[pos].b[2]);
		dfs(pos+1,n1,n2,n3+1,dp+a[pos].b[3]);
	}
	if(f1==1&&f2==3&&f3==2){
		dfs(pos+1,n1+1,n2,n3,dp+a[pos].b[1]);
		dfs(pos+1,n1,n2,n3+1,dp+a[pos].b[3]);
		dfs(pos+1,n1,n2+1,n3,dp+a[pos].b[2]);
	}
	if(f1==2&&f2==1&&f3==3){
		dfs(pos+1,n1,n2+1,n3,dp+a[pos].b[2]);
		dfs(pos+1,n1+1,n2,n3,dp+a[pos].b[1]);
		dfs(pos+1,n1,n2,n3+1,dp+a[pos].b[3]);
	}
	if(f1==2&&f2==3&&f3==1){
		dfs(pos+1,n1,n2+1,n3,dp+a[pos].b[2]);
		dfs(pos+1,n1,n2,n3+1,dp+a[pos].b[3]);
		dfs(pos+1,n1+1,n2,n3,dp+a[pos].b[1]);
	}
	if(f1==3&&f2==1&&f3==2){
		dfs(pos+1,n1,n2,n3+1,dp+a[pos].b[3]);
		dfs(pos+1,n1+1,n2,n3,dp+a[pos].b[1]);
		dfs(pos+1,n1,n2+1,n3,dp+a[pos].b[2]);
	}
	if(f1==3&&f2==2&&f3==1){
		dfs(pos+1,n1,n2,n3+1,dp+a[pos].b[3]);
		dfs(pos+1,n1,n2+1,n3,dp+a[pos].b[2]);
		dfs(pos+1,n1+1,n2,n3,dp+a[pos].b[1]);
	}
}
bool cmp(stu a,stu b){
	if(a.b[1]==b.b[1]){
		if(a.b[2]==b.b[2]){
			return a.b[3]>=b.b[3];
		}
		return a.b[2]>=b.b[2];
	}
	return a.b[1]>=b.b[1];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=-1;
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i].b[j];
		for(int i=1;i<=n;i++){
			if(a[i].b[1]>=a[i].b[3]&&a[i].b[1]>=a[i].b[3]){
				a[i].f1=1;
				if(a[i].b[2]>=a[i].b[3]){
					a[i].f2=2;
					a[i].f3=3;
				}
				else{
					a[i].f2=3;
					a[i].f3=2;
				}
			}
			else if(a[i].b[2]>=a[i].b[1]&&a[i].b[2]>=a[i].b[3]){
				a[i].f1=2;
				if(a[i].b[1]>=a[i].b[3]){
					a[i].f2=1;
					a[i].f3=3;
				}
				else{
					a[i].f2=3;
					a[i].f3=1;
				}
			}
			else{
				a[i].f1=3;
				if(a[i].b[1]>=a[i].b[2]){
					a[i].f2=1;
					a[i].f3=2;
				}
				else{
					a[i].f2=2;
					a[i].f3=1;
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=n;i>=1;i--)s[i]=s[i+1]+max(a[i].b[1],max(a[i].b[2],a[i].b[3]));
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
