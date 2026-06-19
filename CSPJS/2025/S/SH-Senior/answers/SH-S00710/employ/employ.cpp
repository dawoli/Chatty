#include<bits/stdc++.h>
using namespace std;
int ans,a[505];
string x;
int n,m;
bool b[505];
 void dfs(int da,int r){
 	if(r==m ){
 		if(da==n){
 			ans+=1;
		 }
 		else{
 			int k=(n-da)*(n-da+1)/2;
 			if(k>998244353-ans){
 				k=k-998244353;
			 }
 			ans+=k;
		 }
 		ans=ans%; 
 		return;
	 }
	 if(da==n){
	 	return;
	 }
	 for(int i=1;i<=n;i++){
	 	if(!b[i]){
	 		if(x[da]=='1' and a[i]>da-1){
	 			b[i]=1;
				dfs(da+1,r+1);
				b[i]=0;
			 }
			 else{
			 	b[i]=1;
				dfs(da+1,r);
				b[i]=0;
			 }
		 }
	 }
 }
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
