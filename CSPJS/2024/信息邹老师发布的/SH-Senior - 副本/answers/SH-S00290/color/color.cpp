#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,m,ans,cnt[1000005],a;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=1;j<=m;j++){
			cnt[j]=0;
		}
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>a;
			cnt[a]++;
		}
		for(int j=1;j<=m;j++){
			if(cnt[j]>=2){
				ans=ans+(cnt[j]-1)*j;
			}
		}
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}
