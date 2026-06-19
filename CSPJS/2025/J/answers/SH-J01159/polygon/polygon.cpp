#include<bits/stdc++.h>
using namespace std;
int f[5009];
unsigned long long num[25000009];
unsigned long long ans[5009];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f+1,f+1+n);
	num[0]++;
	num[f[1]]++;
	num[f[2]]++;
	num[f[1]+f[2]]++;
	int m_a_x=f[1]+f[2];
	for(int i=3;i<=n;i++){
		ans[i]=ans[i-1];
		for(int j=f[i]+1;j<=m_a_x;j++){
			ans[i]+=num[j]%998244353;
			ans[i]%=998244353;
		}
		for(int j=m_a_x;j>=0;j--) num[j+f[i]]+=num[j]%998244353;
		m_a_x+=f[i];
	}
	cout<<ans[n]%998244353<<endl;
	return 0;
}
