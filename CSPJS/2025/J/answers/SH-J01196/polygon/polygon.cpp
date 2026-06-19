#include<bits/stdc++.h> 
using namespace std;
long long cnt,n,a[5009],cnt2;
bool b;
void dfs(int idx,int sum,int qwe,int lmn){
	if(idx>n){
		if(a[lmn]*2<sum&&qwe>=3){
			cnt++;
			cnt%=998244353;	
		}
		return;
	}
	dfs(idx+1,sum+a[idx],qwe+1,idx);
	dfs(idx+1,sum,qwe,lmn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)b=1;
	}
	if(b==0){
		for(int i=3;i<=n;i++){
			cnt2=1;
			for(int j=0;j<i;j++){
				cnt2*=(n-j);
				cnt2%=998244353;
			}
			for(int j=2;j<=i;j++){
				cnt2/=j;
			}
			cnt+=cnt2;
		}
		cout<<cnt;
		return 0;
	}
	cnt=0;
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<cnt;
	return 0;
} 
