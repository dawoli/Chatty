#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int qpow(int x,int y){
	int tot=1;
	while(y){
		if(y&1){
			tot*=x;
		}
		x*=x;
		y/=2;
		x%=mod; tot%=mod;
	}
	return tot;
}
int inv(int x){
	return qpow(x,mod-2);
}
int A(int x,int y){
	int tot=1;
	for(int i=y-x+1;i<=y;i++){
		tot*=i;
		tot%=mod;
	}
	return tot;
}
int C(int x,int y){
	int tot=A(x,y);
	tot*=inv(A(x,x));
	tot%=mod;
	return tot;
}
int n,m;
string s;
int c[505];
int ans;
int l[505];
int cnt[505];
int cnt2[505];
int id;
int p[12];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
//	if(n<=10){
//		for(int i=1;i<=n;i++){
//			p[i]=i;
//		}
//		do{
//			for(int i=1;i<=n;i++){
//				if()
//			}
//		}while(next_premutation(p+1,p+n+1));
//		cout<<ans<<endl;
//	}
	l[0]=1;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0') l[i]=l[i-1]+1;
		else l[i]=l[i-1];
	}
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0') l[i]=0;
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		cnt[c[i]]++;
		cnt2[l[i]]++;
	}
	ans=1;
	for(int i=0;i<=n;i++){
		cout<<i<<" "<<cnt[i]<<" "<<cnt2[i]<<endl;
		if(cnt2[i]>=cnt[i]){
			ans*=A(cnt[i],cnt2[i]);
			cnt2[i+1]+=cnt2[i]-cnt[i];
		}
		else if(cnt2[i]<cnt[i]){
			ans*=A(cnt2[i],cnt[i]);
			cnt2[n]-=(cnt[i]-cnt2[i]);
		}
		for(int i=n;i>=1;i--){
			if(cnt2[i]<0) cnt2[i-1]+=cnt2[i],cnt2[i]=0;
		}
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}

