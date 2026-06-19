#include<iostream>
#include<cstdio>
using namespace std;
int T,n,a[200005],g[200005],ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){//找到最近相同的编号 
			for(int j=i-1;j>=1;j--){
				if(a[i]==a[j]){
					ans+=a[i];
					g[j]=i;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
