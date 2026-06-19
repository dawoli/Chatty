#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=25;
int T,n,a[N];
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		a[0]=0;
		int ans=0;
		for(int s=0;s<(1<<n);s++){
			int last0=0,last1=0,sum=0;
			for(int i=1;i<=n;i++){
				int col=(s>>(n-i)&1);
				if(col==0){
					if(a[last0]==a[i]){
						sum+=a[i];
					}
					last0=i;
				}
				else{
					if(a[last1]==a[i]){
						sum+=a[i];
					}
					last1=i;
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
}
