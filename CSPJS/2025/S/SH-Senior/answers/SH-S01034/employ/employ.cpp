#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+10;
const int MOD=998244353;

int n,m;
string str="";
int s[MAXN]={};
int c[MAXN]={};
int a[MAXN]={};
bool v[MAXN]={};

int dfs(int cnt,int x,int rf) {
	if(rf>n-m) return 0;
	if(cnt>=m) {
		int res=1;
		for(register int i=1;i<=n-x+1;i++) {
			res=res*i;
			res=res%MOD;
		}
		return res;
	}
	int res=0;
	for(register int i=1;i<=n;i++) {
		if(!v[i]) {
			v[i]=true;
			if(rf>=c[i] || s[i]==0) {
				res=res+dfs(cnt,x+1,rf+1);
				res=res%MOD;
			}
			else if(s[i]==1 && rf<c[i]) {
				res=res+dfs(cnt+1,x+1,rf);
				res=res%MOD;
			}
			v[i]=false;
		}
	}
	return res;
}

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str; int teg=0;
	for(register int i=1;i<=n;i++) {
		cin>>c[i];
		a[i]=i; s[i]=str[i-1]-'0';
		teg=teg+s[i];
	}
	if(n<=10) {
		int ans=0;
		do {
			int cnt=0;
			for(register int i=1;i<=n;i++) {
				if(cnt>=c[a[i]]) {
					cnt++;
				}
				else if(s[i]==0) {
					cnt++;
				}
			}
			if(n-cnt>=m) {
				ans++;
				ans=ans%MOD;
			}
		}while(next_permutation(a+1,a+n+1));
		cout<<ans<<endl;
		return 0;
	}
	else {
		cout<<dfs(0,1,0)<<endl;
		return 0;
	}
} 
