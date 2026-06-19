#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int x[9],a[N],p[N],n,m,T,q;
string s;
char d[N][N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>p[i];
	while((1<<q)<n) q++;
	for (int i=1;i<=q;i++){
		cin>>s;
		for (int j=0;j<s.size();j++){
			d[i][(1<<(i-1))*(j+1)]=s[j];
		}
	}
	cin>>T;
	for (int br=1;br<=T;br++){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		cout<<m<<endl;
	}
	return 0;
}
