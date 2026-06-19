#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int a[5005];
int mp[5005][5005];
int dfs(int num,int l,int r,int cnt){
	long long res=0;
	if(num>2*a[r]&&cnt>=3){
		res++;
	}
	for(int i=l;i<r;i++){
		res+=dfs(num+a[i],i+1,r,cnt+1);
		res%=Mod;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]==1&&a[n]==1){
		mp[1][1]=1;
		for(int i=2;i<=n+1;i++){
			for(int j=1;j<=i;j++){
				mp[i][j]=mp[i-1][j]+mp[i-1][j-1];
			}
		}
		long long res=0;
		for(int i=4;i<=n+1;i++){
			res+=mp[n+1][i];
			res%=Mod;
		}
		cout<<res;
	}
	else{
		for(int i=3;i<=n;i++){
			cnt+=dfs(a[i],1,i,1);
			cnt%=Mod;
		}
		cout<<cnt;
	}
	
	return 0;
} 
