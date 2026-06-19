#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],f[200005],anss,t;
void dfs(int pos){
	if(pos>n){
		long long ans=0;
		int prer=0,preb=0;
		for(int i=1;i<=n;i++){
			if(f[i]==1){
				if(prer==0){
					prer=i;
				}
				else{
					if(a[prer]==a[i]){
						ans+=a[prer];
					}
					prer=i;
				}
			}
			if(f[i]==2){
				if(preb==0){
					preb=i;
				}
				else{
					if(a[preb]==a[i]){
						ans+=a[preb];
					}
					preb=i;
				}
			}
		}
		anss=max(anss,ans);
		return;
	}
	for(int i=1;i<=2;i++){
		f[pos]=i;
		dfs(pos+1);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		anss=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs(1);
		cout<<anss<<endl;
	}
	
}

