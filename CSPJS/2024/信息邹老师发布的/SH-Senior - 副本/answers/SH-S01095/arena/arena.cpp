#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
int T,ans,n,m,a[N],ab[N],c[N],x[9];
string s[19];
void ini_input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>ab[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	int k=ceil(log(n)/1.0*log(2));
	for(int i=0;i<k;i++) cin>>s[i];
	int T;
	cin>>T;
}
int solve(int peos){
	int sum=(peos+1)*peos/2;
	srand(time(0));
	return rand()%sum+1;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ini_input();
	cin>>T;
	for(int i=0;i<T;i++){
		for(int i=0;i<4;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			a[i]=ab[i]^x[(i%4)];
		}
		for(int i=1;i<=n;i++){
			int ap=solve(c[i]);
			ans^=(i*ap);
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}

