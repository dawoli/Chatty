#include<bits/stdc++.h>
using namespace std;
int a[5005],n,s=0,ans=0;
bool flag=true;
void dfs(int k,int m,int z){
	if(k==0){
		if(s>2*z){
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=m+1;i<=n;i++){
	    s+=a[i];
	    int tmp=z;
		dfs(k-1,i,max(tmp,a[i]));
		s-=a[i];
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) flag=false;
	}
	if(n<3){
	    printf("%d",0);	
	}
	else if(flag){
		for(int i=3;i<=n;i++){
			int t=1;
			for(int j=n;j>n-i;j--) t*=j;
			for(int j=i;j>1;j--) t/=j;
			ans+=t;
		}
		printf("%d",ans);	
	}
	else{
		for(int i=3;i<=n;i++)
	        dfs(i,0,0);
	    printf("%d",ans);	
	}
	
	return 0;
} 
