#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=505;
const int MOD=998244353;
int m,n;
char a[MAXN];
int s[MAXN];
int p[MAXN];
int c[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool flag_A=1;    
	int cnt_c=0;
	int sum_m=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		s[i]=a[i]-'0';
		if(s[i]==0)flag_A=0;
		sum_m+=s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt_c++;
	}
	if(sum_m<m){
		cout<<0<<endl;
		return 0;
	}
	if(n-cnt_c<m){
		cout<<0<<endl;
		return 0;
	}
	if(flag_A){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=MOD;
		} 
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)p[i]=i;
	int sum=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++)if(cnt>=c[p[i]]||s[i]==0)cnt++;
		if(n-cnt>=m)sum++;
	}while(next_permutation(p+1,p+n+1)); 
	cout<<sum<<endl;
	return 0;
}
