#include<bits/stdc++.h>
using namespace std;
void read(long long &x){
	x^=x;
	long long f=1;
	char a=getchar();
	while('0'>a||a>'9'){
		if(a=='-')f=-1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=f;
	return ;
}
typedef long long LL;
const LL MOD=998244353,SIZE=509,INF=1009;
LL n,m,ans,c[SIZE],rej,cnt;
string s;
bool modA=1;
int d[SIZE];
void check(){
	rej^=rej;
	cnt^=cnt;
	int i;
	for(i^=i;i<n;i++){
		if(s[i]=='0')rej++;
		else if(rej>=c[d[i]])rej++;
		else cnt++;
	}
	if(cnt>=m){
		ans++,ans%=MOD;
	}
	return ;
}
void dfs(int x){
	if(x==n+1){
		check();
		return ;
	}
	int i;
	for(i^=i;i<n;i++){
		if(d[i]==0){
			d[i]=x;
			dfs(x+1);
			d[i]^=d[i];
		}
	}
	return ;
}
void solveBF(){
	dfs(1);
	printf("%lld",ans);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);
	read(m);
	cin>>s;
	int i;
	for(i=0;i<s.size();i++)if(s[i]!=1)modA=0;
	for(i=1;i<=n;i++){
		read(c[i]);
	}
	solveBF();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
