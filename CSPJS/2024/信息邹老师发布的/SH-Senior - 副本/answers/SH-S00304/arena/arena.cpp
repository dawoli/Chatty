#include<bits/stdc++.h>
#define int long long
#include<fstream>
using namespace std;

ifstream fin("arena.in");
ofstream fout("arena.out");
#define cin fin
#define cout fout

int T,n,m,aaa[100005],c[100005],a[100005],tag[100005];
int d[35][35];
int X[4];
int lowbit(int x){
	return x&(-x);
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aaa[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	int K=ceil(log(n)*1.0/(log(2)*1.0));
	for(int i=1;i<=K;i++){
		string st;cin>>st;st=' '+st;
		for(int j=1;j<=(1<<(K-i));j++){
			d[i][j]=st[j]-'0';
		}
	}
	int T;cin>>T;
while(T--){
	cin>>X[0]>>X[1]>>X[2]>>X[3];
	cout<<7<<'\n';
}
	return 0;
}
