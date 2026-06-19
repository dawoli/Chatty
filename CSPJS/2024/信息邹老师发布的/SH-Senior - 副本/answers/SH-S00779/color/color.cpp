#include<iostream>
#include<stdio.h>
using namespace std;
const int N=2e5+9;
int a[N];
bool b[N];
int T;
int n;
int cnt;
int ans=-1;
void Count(){
	cnt=0;
	int R=0,B=0;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			if(a[i]==a[R]){
				cnt+=a[i];
			}
			R=i;
		}
		else{
			if(a[i]==a[B]){
				cnt+=a[i];
			}
			B=i;
		}
	}
}
void dfs(int x){
	if(x==n+1){
		Count();
		ans=max(ans,cnt);
		return;
	}
	b[x]=0;
	dfs(x+1);
	b[x]=1;
	dfs(x+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		ans=-1;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
