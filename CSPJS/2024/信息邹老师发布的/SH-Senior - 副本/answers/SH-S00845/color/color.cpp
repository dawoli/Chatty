#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[200005],maxn,cur[200005];
void dfs(int pos){
	if(pos>n){
		int tmp=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]==a[j]&&cur[i]==cur[j]){
					bool flag=true;
					for(int k=j+1;k<i;k++){
						if(cur[k]==cur[i]){
							flag=false;
							break;
						}
					}
					if(flag)tmp+=a[i];
				}
			}
		}
		maxn=max(maxn,tmp);
		return;
	}
	cur[pos]=0;
	dfs(pos+1);
	cur[pos]=1;
	dfs(pos+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
	    maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		dfs(1);
		cout<<maxn<<endl;
	}
	return 0;
}

