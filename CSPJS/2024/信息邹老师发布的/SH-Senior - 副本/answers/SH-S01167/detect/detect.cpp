#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,vlim,d[100005],v[100005],a[100005],p[100005],ans,cnt;
bool exc[100005],exc_new[100005],utl[25];
void input(){
	cin>>n>>m>>l>>vlim;
	for(int i=1;i<=n;i++)scanf("%d%d%d",&d[i],&v[i],&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&p[i]);
}
bool bf1(){
	if(n<=20&&m<=20)return 1;
	return 0;
}
bool bf2(){
	for(int i=1;i<=n;i++)
		if(a[i])return 0;
	return 1;
}
bool bf3(){
	for(int i=1;i<=n;i++)
		if(a[i]<=0)return 0;
	return 1;
}
bool bf4(){
	for(int i=1;i<=n;i++)
		if(a[i]>=0)return 0;
	return 1;
}
void dfs(int x,int num){
	if(x>m){
		for(int i=1;i<=n;i++)exc_new[i]=0;
		for(int i=1;i<=n;i++){
			if(v[i]<=vlim&&a[i]<=0)continue;
			for(int j=1;j<=m;j++){
				if(p[j]<d[i])continue;
				if(!utl[j])continue;
				if(v[i]*v[i]+2*a[i]*(p[j]-d[i])>vlim*vlim){
					exc_new[i]=1;
					break;
				}
			}
		}
		bool flag=1;
		for(int i=1;i<=n;i++)
			if(exc_new[i]!=exc[i]){
				flag=0;
				break;
			}
//		for(int i=1;i<=m;i++)cout<<utl[i]<<" ";
//		cout<<endl;
//		for(int i=1;i<=n;i++)cout<<exc[i]<<" "<<exc_new[i]<<endl;
//		cout<<flag<<endl<<num<<endl<<ans<<endl;
		if(flag)ans=max(ans,num);
		return;
	}
	utl[x]=0;
	dfs(x+1,num+1);
	utl[x]=1;
	dfs(x+1,num);
	return;
}
void solvebf1(){
	for(int i=1;i<=n;i++){
		if(v[i]<=vlim&&a[i]<=0)continue;
		for(int j=1;j<=m;j++){
			if(p[j]<d[i])continue;
			if(v[i]*v[i]+2*a[i]*(p[j]-d[i])>vlim*vlim){
				exc[i]=1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)if(exc[i])cnt++;
	cout<<cnt<<" ";
	dfs(1,0);
	cout<<ans<<endl;
	return;
}
void solvebf2(){
	for(int i=1;i<=n;i++){
		if(p[m]>=d[i]&&v[i]>vlim)cnt++;
	}
	cout<<cnt<<" "<<(cnt?m-1:m)<<endl;
	return;
}
void solvebf3(){
	for(int i=1;i<=n;i++){
		if(p[m]<d[i])continue;
		if(v[i]*v[i]+2*a[i]*(p[m]-d[i])>vlim*vlim)cnt++;
	}
	cout<<cnt<<" "<<(cnt?m-1:m)<<endl;
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		input();	
		cnt=0,ans=0;
		if(bf2())solvebf2();
		else if(bf1()){
			for(int i=1;i<=n;i++)exc[i]=0,exc_new[i]=0;
			solvebf1();
		}
		else if(bf3())solvebf3();
	}
	return 0; 
}
