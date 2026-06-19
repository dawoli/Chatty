#include<bits/stdc++.h>
using namespace std;
#define N 200007
int a[N];
int c[N];
pair<int,int> last[N];
int n,T;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		int ans=0;
		for(int i=0;i<(1<<n);++i){
			for(int j=0;j<n;++j){
				if(i>>j&1){
					c[j]=1;
				}
				else{
					c[j]=0;
				}
			}
			int ll[]={2e9,2e9};
			int ct=0;
			for(int j=0;j<n;++j){
				if(ll[c[j]]!=2e9){
					if(a[ll[c[j]]]==a[j]) ct+=a[j];
				}
				ll[c[j]]=j;
			}
			ans=max(ans,ct);
		}
		cout<<ans<<'\n';
	}
	return 0;
}



/*
csp-s2024游记
T1贼简单，2min秒了

T2哈哈哈 不会
拿到了20pts a[i]=0的部分分

17:22 又打了个暴力，这题应该是30-40pts不等 

T3暴力

T4不会

预计140pts 这够干啥的？蓝勾都不够 
 
*/
