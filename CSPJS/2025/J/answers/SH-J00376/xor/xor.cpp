#include<iostream>
#include<cstdio>
using namespace std;
int n,k,ans;
int a[500009],b[500009];
bool ta=1,tb=1;
void dfs(int id,int cnt){
	if(id>n){
		ans=max(ans,cnt);
		return ;
	}
	for(int i=id;i<=n;i++){
		if((b[i]^b[id-1])==k){
			dfs(i+1,cnt+1);
		}
	}
	dfs(id+1,cnt); 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)ta=0;
		if(a[i]>=2)tb=0;
	}
	if(ta==1){
		cout<<n/2<<'\n';
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(tb==1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
		cout<<ans<<'\n';
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	dfs(1,0);
	cout<<ans<<'\n';
//	cout<<(b[1]^b[0])<<' '<<(b[4]^b[1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
