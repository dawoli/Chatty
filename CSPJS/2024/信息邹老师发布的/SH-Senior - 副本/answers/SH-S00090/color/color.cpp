	//freopen不要注释 
	//freopen不要注释 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int q;
int a[N]; 
bool k[N];//表示红蓝，红为0，蓝为1；
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>q;
	for(int i=1;i<=q;i++){
		int n;
		cin>>n;
		int c[N];
		int f[N];
		for(int j=1;j<=n;j++){
			cin>>a[j];
			c[j]=0;
		}
		
		for(int j=1;j<=n;j++){
			for(int k=1;k<j;k++){
				for(int m=0;m<=1;m++){
					f[j]=m;
					for(int n=0;n<=1;n++){
						f[k]=n;
						if((a[k]==a[j])&&f[k]==f[j]){
							c[j]=a[j];
						}
						c[1]=0;
					}		
				}
			}	
		}
		int ans=0;
		for(int l=1;l<=n;l++){
			ans+=c[l];
		}
		cout<<ans<<'\n';
	}
	//输出用\n 
	//记得写freopen，并且不要注释掉！！！！！
	//freopen不要注释
	//写return 0 
	return 0;
} 
