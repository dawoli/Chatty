#include<bits/stdc++.h>
using namespace std;
int T,n,a[200009],ans=0;
void wrk(int num){
	int lst0=-1,lst1=-1,m=0;
	for(int i=1;i<=n;i++){
		int k=((num&(1<<(i-1)))?1:0);
		if(k==0){
			if(lst0!=-1){
				m+=(a[i]==a[lst0]?a[i]:0);
			}
			lst0=i;
		}else{
			if(lst1!=-1){
				m+=(a[i]==a[lst1]?a[i]:0);
			}
			lst1=i;
		}
	}
	ans=max(m,ans);
}
void dfs(int dep,int num){
	if(dep==0){
		wrk(num);
		return;
	}
	dfs(dep-1,num*2);
	dfs(dep-1,num*2+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
	    cin>>n;
	    ans=0;
	    for(int i=1;i<=n;i++){
	    	cin>>a[i];
	    }
	    dfs(n,0);
	    cout<<ans<<endl;
	}
	return 0;
}
