#include<bits/stdc++.h>
using namespace std;
int a[200010],n;
bool tong1[1000010],tong2[1000010];
void solve(){
	int ans=0;
	memset(tong1,0,sizeof tong1);
	memset(tong2,0,sizeof tong2);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(tong1[a[i]]&&tong2[a[i]])ans+=a[i];
		else if(tong1[a[i]]&&!tong2[a[i]])ans+=a[i],tong2[a[i]]=1;
		else if(tong2[a[i]]&&!tong1[a[i]])ans+=a[i],tong1[a[i]]=1;	
		else tong1[a[i]]=1;	
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;cin>>t;
	while(t--)solve();
}
