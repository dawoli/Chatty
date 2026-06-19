#include<bits/stdc++.h>
using namespace std;

const int maxn=2e6+5;
int ab(int x){
	if(x<0) x=-x;
	return x;
}
int t,n,tim[maxn],a[maxn],vis[maxn],f[maxn][2],col[2];


int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(tim,0,sizeof(tim));
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			tim[a[i]]++;
		}
			
		int ltb=1,ltr; //b:1 r:0
		
		for(int i=1;i<=n;i++){
			vis[a[i]]++;
			if(vis[a[i]]!=1){
				if(a[i]==a[ltb]){
					f[i][1]=f[ltb][1]+1;
					ltb=i;
				}
				if(a[i]==a[ltr]){
					f[i][0]=f[ltr][0]+1;
					ltr=i;
				}
			}
			else{
				if(vis[a[i]]==tim[a[i]]){
					for(int j=i;j>=1;j--){
						if(vis[a[j]]==tim[a[j]]) f[i][abs(a[j]+1)]=f[j][col[a[j]]];
					}
				}
			}
		}
		cout<<max(f[n][0],f[n][1]);
	}
}
