#include<bits/stdc++.h>
using namespace std;
int co[10005],n;//true red false blue
int mxans=0;
int score(int* a,int* c,int* co){
	for(int i=1;i<=n;++i){
		for(int j=i;j>=1;--j){
			if(co[j]==co[i]){
				if(a[i]==a[j]){
					c[i]=a[i];
				}else{
					c[i]=0;
				}
			}else{
				c[i]=0;
			}
		}
	}
	int sc=0;
	for(int i=1;i<=n;++i){
		sc+=c[i];
	}
	return sc;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int a[10005],c[10005],t;
	cin>>t;
	for(int l=1;l<=t;++l){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for(int i=1;i<=n;++i){
			for(int j1=1;j1<=i;++j1){
				co[j1]=1;
			}
			for(int j2=1;j2<=n;++j2){
				co[j2-1]=0;
				co[j2]=1;
				int ans=score(a,c,co);
				if(ans>mxans){
					mxans=ans;
				}
			}
		}	cout<<mxans<<' ';
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
