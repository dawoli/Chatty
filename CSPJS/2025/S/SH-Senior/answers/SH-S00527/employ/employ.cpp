#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=505;
int n,mc,nm;
char s[N];
int c[N];
ll M=998244353;

int m[1<<18][19];
ll d(int l,int fs,int fc){
	if(l==n)return (fc<=nm?1:0);
	if(m[fs][fc])return (m[fs][fc]==-1?0:m[fs][fc]);
	ll res=0;
	for(int i=0;i<n;i++){
		int ms=1<<i;
		if(fs&ms)continue;
		if(s[l]=='0'||fc>=c[i])(res+=d(l+1,fs^ms,fc+1))%=M;
		else (res+=d(l+1,fs^ms,fc))%=M;
	}
	m[fs][fc]=(res?res:-1);
	return res;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	
	cin>>n>>mc;
	nm=n-mc;
	cin>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	cout<<d(0,0,0)<<endl;
	
	cout<<flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

