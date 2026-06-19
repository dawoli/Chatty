#include<bits/stdc++.h>
using namespace std;
bool a[1000010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t; cin>>t;
	while(t>0){
		long long ans=0;
		memset(a,0,sizeof(a));
		int n; cin>>n;
		for(int i=1;i<=n;i++){
			int x; cin>>x;
			if(a[x]) ans+=x;
			a[x]=1;
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}

