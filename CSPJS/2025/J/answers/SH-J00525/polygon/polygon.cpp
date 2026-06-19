#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[10086];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				int sum=a[i]+a[j]+a[k];
				int biggest=max(a[i],max(a[j],a[k]));
				if(sum>2*biggest){
					ans=(ans+1)%MOD;
				}
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;//好吧主包承认只会枚举三元组了，希望有个20tps吧 ,拜拜喽，2025csp-j复赛，希望能考高分 
}
