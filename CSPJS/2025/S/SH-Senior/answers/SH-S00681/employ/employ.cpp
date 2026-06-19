#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define ___ __int128
using namespace std;
const int N=505,mod=998244353;

inline ll read() {
	ll x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int n,m,c[N],ans;
bool vis[N];
string s;
deque<int> q;

bool check() {
	int ct=0,ly=0;
	for(int i=1;i<=n;i++) {
		int u=q.front();
		q.push_back(u);
		q.pop_front();
		if(c[u]<=ct||s[i-1]=='0')ct++;
		else ly++;
	}
	if(ly>=m)return true;
	else return false;
}

void dfs(int step) {
	if(step==n) {
		if(check())ans++;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i])continue;
		q.push_back(i);
		vis[i]=1;
		dfs(step+1);
		q.pop_back();
		vis[i]=0;
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>s;
	for(int i=1;i<=n;i++) c[i]=read();
	if(n<=10) {
		dfs(0);
		cout<<ans;
	}
	return 0;
}
