#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int b[100000];
		int wall=n/2;
		int ans=0;
		int a[100000]={};
		int a1[100000],a2[100000],a3[100000];
		for(int i=1;i<=n;i++){
			int maxn[10000]={};
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>a2[i]){
				maxn[i]=a1[i];
			}else{
				maxn[i]=a2[i];
			}
			if(maxn[i]<a3[i]){
				maxn[i]=a3[i];
			}
		
			ans+=maxn[i];
		}
		cout<<ans<<endl;

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
