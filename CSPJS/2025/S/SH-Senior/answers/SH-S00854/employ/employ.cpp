#include<bits/stdc++.h>
using namespace std;
long long int m,n,x,c[500005];//a[i]为第i天之前有多少人未通过（i从0开始
long long int res;
bool flag,b[100005];
string s;
long long f(long long n){
	long long res1=1;
	for(long long int i=2;i<=n;i++){
		res1*=i;
		res1%=998244353;
	}
	return res1;
}
void dfs(int x,int mn,int ou){
	if(mn>=m){
		res+=f(n-x-1);
		res%=998244353;
		return ;
	}
	if(x==n){
		return ;
	}
	if(mn+n-x-1<m) return ;
	for(int i=0;i<n;i++){
		if(b[i]==0){
			b[i]=1;
			if(ou>=c[i] || s[x+1]=='0') dfs(x+1,mn,ou+1);
			else dfs(x+1,mn+1,ou);
			b[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;//前来应聘的人数和希望录用的人数
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(s[i]=='0') flag=1;
	}
	if(flag==0){
		long long res1=1;
		for(int i=2;i<=n;i++){
			res1*=i;
			res1%=998244353;
		}
		cout<<res1;
		return 0;
	}
	dfs(-1,0,0);
	cout<<res%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
