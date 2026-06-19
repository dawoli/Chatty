#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[5005],cnt=0,c[5005],flag=1;
void dfs(int step,int bg,int l,int g,int flag){
	if(step==n+2) return;
	if(g>=3 && (l-bg>bg) && flag) cnt++;
	dfs(step+1,max(bg,a[step])%M,(l+a[step])%M,g+1,1);
	dfs(step+1,bg,l,g,0);
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//1 2 3 4 5
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(flag && a[i]>1) flag=0;
	}
	if(flag){
		cout<<(n-1)*(n-2)/2;
		return 0;
	}
	dfs(1,0,0,0,0);
	cout<<cnt;
	//#Shang4Shan3Ruo6Shui4
	return 0;
}
