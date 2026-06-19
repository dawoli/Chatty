#include<bits/stdc++.h>
using namespace std;
long long t,a[200005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long maxn=-1;
		for(long long c=0;c<=(1<<n)-1;c++){
			long long ans=0,pre1=-1,pre2=-1;
			for(int i=1;i<=n;i++){
				long long mask=(1<<(i-1));
				if((c^mask)!=0){
					if(pre1==-1){
						pre1=i;
						continue;
					}
					if(a[i]==a[pre1]){
						ans+=a[pre1];
					}
					pre1=i;
				}
				else{
					if(pre2==-1){
						pre2=i;
						continue;
					}
					if(a[i]==a[pre2]){
						ans+=a[pre2];
					}
					pre2=i;
				}
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn<<endl;
	}
	return 0;
}
