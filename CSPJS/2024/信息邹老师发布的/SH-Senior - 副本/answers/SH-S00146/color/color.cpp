#include<bits/stdc++.h>
using namespace std;
int t,n,k[1000005],su[100005],x,a,b,ans;
map<int,int> mp;
void cl(int a,int b){
	for(int i=a;i<=b;i++){
		k[a]=0;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	cin>>t;
	while(t--){
		memset(k,0,sizeof(k));
		cin>>n;
		ans=0;
		a=b=-1;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(k[x]){
				ans+=x;
				cl(a,b);
				a=b;
				b=mp[x];
			}
			k[x]=1;
			mp[x]=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
