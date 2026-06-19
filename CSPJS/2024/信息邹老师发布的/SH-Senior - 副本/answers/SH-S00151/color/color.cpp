#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++){
		int n,ans=0;
		cin>>n;
		int a[n+2]={};
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]==a[j]&&i!=j){
					ans+=a[i]; 
					a[i]=0;
					a[j]=0;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
