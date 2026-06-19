#include<bits/stdc++.h>
using namespace std;

int s[10010][5];
int t;
long long ans[10010][10010],a[10010];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int maxx=n/2;
		int sum[5]={maxx};
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>s[j][k];
			}
			a[j]=max(s[j][1],max(s[j][2],s[j][3]));
		}
		for(int j=1;j<=n;j++){
			for(int k=2;k<=n+1;k++){
				if(k-1>0){
					ans[j][k]=max(ans[j-1][k],ans[j-1][k-1]+a[j]);
				}
				else{
					ans[j][k]=max(ans[j-1][k],ans[j-1][k-1]);
				}
			}
		}
		cout<<ans[n][n+1]<<endl;
	}
	return 0;
}
