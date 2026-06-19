#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+1;
int a[4];
long long p[maxn][4];
int n;
long long dif[maxn];
void solve(){
	cin>>n;
	memset(p,0,sizeof(p));
	memset(dif,0,sizeof(dif));
	memset(a,0,sizeof(a));
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long mx=0;
		for(int j=1;j<=3;j++){
			cin>>p[i][j];
			mx=max(mx,p[i][j]);
		}
		ans+=mx;
		if(p[i][1]==mx){
			a[1]++;
		}else if(p[i][2]==mx){
			a[2]++;
		}else{
			a[3]++;
		}
	}
	if(a[1]>n/2){
		int lscan=0;
		for(int i=1;i<=n;i++){
			if(p[i][1]>p[i][2]&&p[i][1]>p[i][3]){
				long long mx2=max(p[i][2],p[i][3]);
				long long diff=p[i][1]-mx2;
				++lscan;
				dif[lscan]=diff;
			}
		}
		sort(dif+1,dif+lscan+1);
		for(int i=1;i<=a[1]-n/2;i++){
			ans-=dif[i];
		}
		cout<<ans;
	}else if(a[2]>n/2){
		int lscan=0;
		for(int i=1;i<=n;i++){
			if(p[i][2]>p[i][1]&&p[i][2]>p[i][3]){
				long long mx2=max(p[i][1],p[i][3]);
				long long diff=p[i][2]-mx2;
				++lscan;
				dif[lscan]=diff;
			}
		}
		sort(dif+1,dif+lscan+1);
		for(int i=1;i<=a[2]-n/2;i++){
			ans-=dif[i];
		}
		cout<<ans;
	}else if(a[3]>n/2){
		int lscan=0;
		for(int i=1;i<=n;i++){
			if(p[i][3]>p[i][2]&&p[i][3]>p[i][1]){
				long long mx2=max(p[i][1],p[i][2]);
				long long diff=p[i][3]-mx2;
				++lscan;
				dif[lscan]=diff;
			}
		}
		sort(dif+1,dif+lscan+1);
		for(int i=1;i<=a[3]-n/2;i++){
			ans-=dif[i];
		}
		cout<<ans;
	}else{
		cout<<ans;
	}
	cout<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
}
