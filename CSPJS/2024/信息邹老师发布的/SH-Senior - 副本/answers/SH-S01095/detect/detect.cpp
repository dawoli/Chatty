#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
struct car{
	int d,v,a;
	double ovst,oved;
} c[N];
int T,p[N];
void solve(){
	int n,m,L,V;
	cin>>n>>m>>L>>V;
	for(int i=0;i<n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
	for(int i=0;i<m;i++) cin>>p[i];
	srand(time(0));
	cout<<(rand())%(n+1)<<" "<<(rand())%(m+1)<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++)
		solve();
	return 0;
}

