#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
struct s{
	int id,cha;
}c[100009];
int t,n;
int a[100009][6];
int b[100009];
bool ta=1,tb=1;
bool cmp1(int x,int y){
	return x>y;
}
bool cmp2(s x,s y){
	if(x.cha!=y.cha)return x.cha>y.cha;
	return x.id>y.id;
}
int abss(int x){
	if(x<0)return -x;
	return x;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0||a[i][3]!=0)ta=0;
		if(a[i][3]!=0)tb=0;
	}
	if(ta==1){
		for(int i=1;i<=n;i++)b[i]=a[i][1];
		sort(b+1,b+n+1,cmp1);
		long long ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=b[i];
		}
		cout<<ans<<'\n';
		return ;
	}
	if(tb==1){
		for(int i=1;i<=n;i++){
			c[i].cha=abss(a[i][1]-a[i][2]);
			c[i].id=i;
		}
		sort(c+1,c+n+1,cmp2);
		long long ans=0;
		int ac=0,bc=0;
		for(int j=1;j<=n;j++){
			int i=c[j].id;
			if(ac<n/2&&bc<n/2){
				if(a[i][1]>=a[i][2]){
					ans+=a[i][1];
					ac++;
				}
				else{
					ans+=a[i][2];
					bc++;
				}
			}
			else{
				if(ac>=n/2){
					ans+=a[i][2];
				}
				else{
					ans+=a[i][1];
				}
			}
		}
		cout<<ans<<'\n';
		return ;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=(a[i][1],max(a[i][2],a[i][3]));
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
