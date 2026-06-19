#include<bits/stdc++.h>
using namespace std;
const int N=509;
const int M=998244353;
bool h[N];
int c[N];
bool f[N];
int n,m;
long long ans=0;
void pl(int t,int p){
	if(t==n){
		if(p>=m){
			ans++;
			ans=ans%M;
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(f[i]==0&&c[i]>=t){
			f[i]=1;
			pl(t+1,p+h[t]);
			f[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		h[i]=(int)s[i]-'0';
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	pl(0,0);
	cout<<ans<<endl;
	return 0;
}
