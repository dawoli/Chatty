#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
int a[5005];
int n;
LL rp=0;
const LL bound=998244353;
void dfs(int x,int mx,int sum){
	if(x>n){
		if(sum>mx*2) rp++;
		rp%=bound;
		return ;
	}
	dfs(x+1,max(mx,a[x]),sum+a[x]);
	dfs(x+1,mx,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<rp<<endl;
	return 0;
}
//rp++!
