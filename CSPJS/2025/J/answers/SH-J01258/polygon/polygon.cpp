#include<bits/stdc++.h>
using namespace std;

long long n,ans,a[5010];
string s;

void dfs(long long pos,long long l,long long sum,long long cnt,bool b){
	if(sum>2*l&&cnt>2&&b){
		ans=(ans+1)%998244353;
	}
	if(pos>n) return;
	dfs(pos+1,max(l,a[pos]),sum+a[pos],cnt+1,true);
	dfs(pos+1,l,sum,cnt,false);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0,true);
	cout<<ans;
}

