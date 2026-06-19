#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt=0;
void dfs(int b,int l,int m,int s){
	if(b>n)return;
	if(l>=3&&s>m*2) cnt++;
	dfs(b+1,l+1,max(m,a[b+1]),s+a[b+1]);
	dfs(b+2,l+1,max(m,a[b+2]),s+a[b+2]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i],a[i]);
	}
	
	cout<<cnt%998244353<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
