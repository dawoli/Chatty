#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,ans;
string s;
int level[N],c[N];
int x_1,x__0;
bool cmp_1(int x,int y){
	return x>y;
}
bool vis[N];
void dfs(int pos,int step,int failure,int aim){
	if(pos>n||step>=aim){
		if(step==aim){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			if(failure<c[i]){
				vis[i]=1;
				int fail=failure,ssp=step;
				if(level[pos]==0){
					fail++;
				}else{
					ssp++;
				}
				dfs(pos+1,ssp,fail,aim);
				vis[i]=0;
			}else{
				vis[i]=1;
				dfs(pos+1,step,failure+1,aim);
				vis[i]=0;
			}
		}
	}
	return;
}
int main(){
//	//取消注释!!!!!!!!
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	//取消注释!!!!!!!!
	cin>>n;
	cin>>s;
	for(int i=0;i<s.size();i++){
		level[i+1]=int(s[i]-'0');
		if(level[i+1]==1){
			x_1++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			x__0++;
		}
	}
	//A
	if(x_1==n){
		for(int i=m;i<=n-x__0;i++){
			long long hhh=1;
			for(int j=1;j<=i;j++){
				hhh=hhh*(i-j+1)/j%mod;
			}
			ans=(ans+hhh)%mod;
		}
		cout<<ans;
		return 0;
	}
	//B
	for(int i=m;i<=n;i++){
		dfs(1,0,0,i);
	}
	cout<<ans;
	return 0;
}
//3 2
//101
//1 1 2
//
//10 5
//1101111011
//6 0 4 2 1 2 5 4 3 3
