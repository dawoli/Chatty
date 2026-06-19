#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[1000005]={0};
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0,maxn=0;
		bool flag=0;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			a[k]++;
			maxn=max(maxn,k);
		}
		for(int i=1;i<=maxn;i++){
			if(a[i]){
				ans+=(a[i]-1)*i;
				a[i]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
