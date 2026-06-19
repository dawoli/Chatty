#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000005],x;
long long ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>x;
			if(a[x]) ans+=x;
			a[x]++;
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
