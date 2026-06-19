#include<iostream> 
#include<cstdio>
#include<vector>
using namespace std;
long long n;
int a[5005];
int ans;
void dfs(int d,int sidenum,int largeside,int sum){
	if(d==n+1){
		return;
	}
	//cout<<d<<" "<<sidenum<<" "<<largeside<<" "<<sum<<endl;
	{
		dfs(d+1,sidenum,largeside,sum);
	}
	{
		sidenum++;
		sum+=a[d];
		largeside=max(largeside,a[d]);
		if(sidenum>=3&&(sum>2*largeside)){
			ans=(ans+1)%998244353;
			//cout<<ans<<" "<<d<<" "<<sidenum<<" "<<largeside<<" "<<sum<<endl;
		}
		dfs(d+1,sidenum,largeside,sum);
	}
}
long long f(int n){
	unsigned long long ret=1;
	for(int i=1;i<=n;i++){
		ret=ret*i;
	}
	return ret;
}
long long c(int m,int n){
	return ((f(m))/(f(n)*f(m-n)));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	int key=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		key=max(key,a[i]);
	}
	if(key==1){
		int num=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				num++;
			}
		}
		for(int i=3;i<=num;i++){
			ans+=c(num,i);
			ans%=998244353;
		}
		cout<<ans;
	}else if(key==0){
		cout<<0;
	}else{
		dfs(1,0,0,0);
		cout<<ans;
	}
	return 0;
}
