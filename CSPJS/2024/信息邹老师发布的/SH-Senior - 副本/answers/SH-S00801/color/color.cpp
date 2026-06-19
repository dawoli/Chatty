#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9,A=1e6+9;
int t,n,a[N];
bool b[N];
int lst[2];
ll ans,f[N][2];
void BF(){
	ans=0;
	for(int S=0;S<1<<(n-1);S++){
		//cout<<"S="<<S<<endl;
		ll now=0;
		for(int i=1;i<=n;i++)
			if(S&(1<<(i-1))) b[i]=1;
			else b[i]=0;
		int lst[2];lst[0]=lst[1]=0;
		//for(int i=1;i<=n;i++) cout<<b[i];
		//cout<<"S="<<S<<endl;
		for(int i=1;i<=n;i++){
			if(lst[b[i]]>0&&a[lst[b[i]]]==a[i]) now+=a[i];
			lst[b[i]]=i;
		}
		for(int i=1;i<=n;i++) cout<<b[i];
		cout<<" ->"<<now<<endl;
		ans=max(ans,now);
	}
}
void solve1(){
	memset(f,0,sizeof(f));
	f[1][0]=a[1];
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(a[j]==a[i]){
				f[i][0]=max(f[i][0],f[j][0]+a[i]);
				f[i][1]=max(f[i][1],f[j][1]+a[i]);
			}
			else{
				f[i][0]=max(f[i][0],max(f[j][0],f[j][1]));
				f[i][1]=max(f[i][1],max(f[j][0],f[j][1]));
			}
	//for(int i=1;i<=n;i++) cout<<f[i][0]<<" ";
	//cout<<endl;
	//for(int i=1;i<=n;i++) cout<<f[i][1]<<" ";
	//cout<<endl;
	ans=f[n][0];
}
int main(){
	ios::sync_with_stdio(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=15) BF();
		else solve1();
		cout<<ans<<endl;
	}
	return 0;
}
