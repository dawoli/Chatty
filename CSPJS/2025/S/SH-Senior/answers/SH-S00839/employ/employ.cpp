#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,op=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			op=-1;
		}
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*op;
}
const int MOD=998244353;
int n,m,d[509],c[509],cnt;
void solveA(){
	int ans=1;
	for(int i=n;i>m;i--){
		ans+=c[i];
	}
	if(ans-1<m){
		cout<<0<<endl;
		return ;
	}
	cout<<ans<<endl;
}
/*
15 

c[n-m+1],
n-m
0 

all-c[],<=n-m

all-c[]+c[0]<=n-m




n-m-c[0]
c[1]





*/
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		d[i]=ch-'0';
		cnt+=d[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	if(cnt==n){
		solveA();
	}
	return 0;
}
/*



3 2
101
1 1 2


2














*/
