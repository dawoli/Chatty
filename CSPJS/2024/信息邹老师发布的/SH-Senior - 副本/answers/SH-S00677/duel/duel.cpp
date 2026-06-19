#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),endi=(b);i<=endi;++i)
#define foR(i,a,b) for(int i=(a),endi=(b);i>=endi;--i)
#define N 100009
#define ll long long
using namespace std;
int n;
int r[N];
int b[N];
int cnt=1;
int id;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	For(i,1,n) 
		cin>>r[i];
	sort(r+1,r+n+1);
	For(i,2,n+1)
		if(r[i]!=r[i-1]) {
			b[++id]=cnt;
			cnt=1;
		}else
			cnt++;
//	For(i,1,id)
//		cout<<b[i]<<' ';
	For(i,2,id)
		if(b[i]<=b[i-1])
			b[i]=b[i-1];
	cout<<b[id];
	return 0;
}

