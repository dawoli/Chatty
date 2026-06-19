#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,a[N],f[N][N],g[N][N],T;//f[i][j]前i个数 蓝色在i 红色在j的最大值 g[i][j]前i个数 红色在i 蓝色在j的最大值 
int main(){
	freopen("color.in","r",stdin),freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				f[i][j]=g[i][j]=-1;
			}
		}
		f[1][0]=0,g[1][0]=0;
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
			    //f[i][j] 蓝色在i 红色在j
				//我们考虑给i+1上红色 则蓝色在i 红色在i+1
				int tmp=f[i][j];
				if(j&&a[i+1]==a[j]){
					tmp+=a[j];
				}
				g[i+1][i]=max(g[i+1][i],tmp); 
				//我们考虑给i+1上蓝色 则蓝色在i+1 红色在j
				tmp=f[i][j];
				if(a[i]==a[i+1]){
					tmp+=a[i];
				}
				f[i+1][j]=max(f[i+1][j],tmp); 
				//g[i][j]红色在i 蓝色在j
				//我们考虑给i+1上红色 则蓝色在j 红色在i+1
				tmp=g[i][j];
				if(a[i]==a[i+1]){
					tmp+=a[i];
				} 
				g[i+1][j]=max(g[i+1][j],tmp);
				//我们考虑给i+1上蓝色 则红色在i 蓝色在i+1
				tmp=g[i][j];
				if(j&&a[j]==a[i+1]){
					tmp+=a[j];
				} 
				f[i+1][i]=max(f[i+1][i],tmp);
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,f[n][i]),ans=max(ans,g[n][i]);
		}
		cout<<ans<<'\n';
	}
} 
