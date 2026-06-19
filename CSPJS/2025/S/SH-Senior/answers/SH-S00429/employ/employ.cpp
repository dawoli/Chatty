#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m,a[505],k,sum;
long long ans;
string s;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==0)	sum++;
	}
	if(m!=1){
		cout<<sum<<endl;
		ans=1;
		if(sum>n-m){
			cout<<"0";
			return 0;
		}
		for(int i=n-sum;i>=n-m-sum+1;--i){
			ans*=i;
			ans%=mod;
		}	
		//cout<<ans<<endl;
		for(int i=1;i<=n-m;++i){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}else{
		sort(a+1,a+1+n,cmp);
		int l=0;
		while(l<s.size()&&s[l]=='0')	l++;
		//cout<<l<<" ";
		k=-1;
		for(int i=sum+1;i<=n;++i){
			if(a[i]>l){
				k=n-i+1;	
				break;
			}
		}
		if(k==-1){
			cout<<"0";
			return 0;
		}
		ans=1;
		for(int i=1;i<=n-1;++i){
			ans*=i;
			ans%=mod;
		}
		ans*=k;
		ans%=mod;
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
