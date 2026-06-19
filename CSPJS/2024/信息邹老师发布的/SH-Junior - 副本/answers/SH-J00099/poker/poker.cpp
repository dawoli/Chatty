#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[10][100],ans;
map<char,ll>m1,m2;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	m1['A']=1;
	for(ll i=2;i<=9;i++)m1[i+'0']=i;
	m1['T']=10,m1['J']=11,m1['Q']=12,m1['K']=13;
	m2['D']=1,m2['C']=2,m2['H']=3,m2['S']=4;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s;
		a[m2[s[0]]][m1[s[1]]]=1;
	}
	for(ll i=1;i<=4;i++)for(ll j=1;j<=13;j++)if(!a[i][j])ans++;
	cout<<ans;
	return 0;
} 
