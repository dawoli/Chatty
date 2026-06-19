#include<bits/stdc++.h>
using namespace std;
const int x=100005;
int t,maxn,maxm;
int n,ans,sum;
int a[x],b[x],c[x],m[5];
void dfs(int s){
	int cnt=s;
	if(s==n+1) return;
	for(int l=1;l<=3;l++){
		if(m[l]<maxn){
			m[l]+=1;
			if(l==1){
				sum=sum+a[s];
				maxm=max(maxm,sum);
				dfs(cnt+1);
				sum=sum-a[cnt];
				m[1]-=1;
			}
			if(l==2){
				sum=sum+b[s];
				maxm=max(maxm,sum);
				dfs(cnt+1);
				sum=sum-b[cnt];
				m[2]-=1;
			}
			if(l==3){
				sum=sum+c[s];
				maxm=max(maxm,sum);
				dfs(cnt+1);
				sum=sum-c[cnt];
				m[3]-=1;
			}
		}
		else continue;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		sum=0;
		maxn=n/2;
		maxm=0;
		m[1]=0,m[2]=0,m[3]=0;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		dfs(1);
		cout<<maxm<<endl;
		for(int h=1;h<=n;h++){
			a[h]=0;
			b[h]=0;
			c[h]=0;
		}
	}
	return 0;
}
