#include<bits/stdc++.h>
using namespace std;
const int N = 200003;
typedef long long ll;
int T,n,a[N],maxa;
int lR,lB;
ll cnt,ans;
void solve15(int pos){
//	cout<<"DFS: "<<pos<<", lR = "<<lR<<", lB = "<<lB<<endl;
	if(pos==n+1){
//		cout<<"now ans = "<<ans<<", now cnt = "<<cnt<<endl;
		ans = max(ans,cnt);
		return;
	}
	
	int ansR = lR,ansB = lB;
	
	if(lR==a[pos]) cnt+=a[pos];
	lR = a[pos];
	solve15(pos+1);
	lR = ansR;
	if(lR==a[pos]) cnt-=a[pos];
	
	if(lB==a[pos]) cnt+=a[pos];
	lB = a[pos];
	solve15(pos+1);
	lB = ansB;
	if(lB==a[pos]) cnt-=a[pos];
}
void solve(){
	int f[203][203];
	memset(f,0xff,sizeof(f));
	f[0][0] = 0;
//	for(int i = 1;i<=maxa;i++) f[0][i] = f[i][0] = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=maxa;j++){
			if(f[a[i]][j]==-1) f[a[i]][j] = f[0][j];
			else{
				for(int k = 0;k<=maxa;k++){
					if(f[k][j]!=-1) f[a[i]][j] = max(f[a[i]][j],f[k][j]+(k==a[i]?a[i]:0));
				}
			}
		}
		for(int j = 0;j<=maxa;j++){
			if(f[a[i]][j]==-1) f[a[i]][j] = f[0][j];
			else{
				for(int k = 0;k<=maxa;k++){
					if(f[j][k]!=-1) f[j][a[i]] = max(f[j][a[i]],f[j][k]+(k==a[i]?a[i]:0));
				}
			}
		}
//		for(int j = 0;j<=maxa;j++)
//			for(int k = 0;k<=maxa;k++)
//				cout<<f[j][k]<<" \n"[k==maxa];
	}
	int ansmax = 0;
	for(int i = 0;i<=maxa;i++){
		for(int j = 0;j<=maxa;j++){
			if(f[i][j]!=-1)ansmax = max(ansmax,f[i][j]);
		}
	}
	cout<<ansmax<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		lR = lB = ans = cnt = maxa = 0; 
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
			maxa = max(maxa,a[i]);
		}
		if(n<=15){
			solve15(1);
			cout<<ans<<endl;
			continue;
		}
		solve();
	}
	return 0;
}
