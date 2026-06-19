#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int rd(){
	char c=getchar();int x=0;
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
long long jc(int p){
	long long x=1;
	for(int i=2;i<=p;i++)
	x=(x*(long long)i)%N;
	return x;
}
int n,m,c[505],cnt;
string s;
long long ans;
bool book[15];int a[15];
void dfs(int p){
	if(p==n+1){
		int x=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') x++;
			else if(x>=c[a[i]]) x++;
		}
		if(n-x>=m) ans=(ans+1)%N;
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			book[i]=1,a[p]=i;
			dfs(p+1);
			book[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++) cnt+=s[i]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(m==n){
		cout<<jc(n);
		return 0;
	}
	sort(c+1,c+1+n);
	if(m==1){
		long long asn=1;int tot=0,p=0;
		int d[505]={};
		for(int i=0;i<s.size();i++) d[i+1]=d[i]+(s[i]=='0');
		for(int i=n;i>=1;i--){
			p=n-c[i]+d[c[i]],tot++;
			if(tot>p){
				cout<<0;
				return 0;
			}
			asn=asn*(long long)(p-tot+1)%N;
		}
		cout<<(jc(n)-asn+N)%N;
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
	return 0;
}
