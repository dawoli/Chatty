#include<bits/stdc++.h>
#define int long long
const long long mod=998244353;
using namespace std;
int ans,an;
int n,a[5005],ma[5005][5005],maxa,l,r,mid;
bool u[5005];
//max，边数，和，now ，现遍数 
void dbx(int m,int nu,int su,int nw,int no){
	if(no==nu){
		if(su>m){
			ans++;
			ans=ans%mod;
			cout<<m<<' '<<nu<<' '<<su<<' '<<nw<<' '<<no<<endl; 
		}
		return;
	}
	int min=0;
	l=1;
	r=nw-1;
	while(r>l){
		mid=(r+l)/2;
		if(a[mid]+ma[mid-1][nu-no-1]>m){
			r=mid;
			min=mid;
		}
		else{
			l=mid+1;
		}
	}
	for(int i=min;i<nw;i++){
		dbx(m,nu,su+a[i],i,no+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a[0]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			ma[i][j]=ma[i][j-1]+a[i-j+1];
		}
	}
	if(n<=3){
		if(a[3]>=a[1]+a[2]){
			cout<<0;
			return 0;
		}
		cout<<1;
		return 0;
	}
	if(maxa==1){
		an=1;
		for(int m=1;m<=n;m++){
			an=an*(n-m+1)/m;
			if(m>=3){
				ans+=an;
				ans=ans%mod;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j>=3;j--){
			dbx(a[i],j,0,i,1);
		}
	}
	cout<<ans;
	return 0; 
}
