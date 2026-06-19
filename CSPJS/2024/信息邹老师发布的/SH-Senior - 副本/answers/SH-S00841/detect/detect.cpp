#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
int n,m,L,V;
struct car{
	int d,v,a;
}object[100010];
int p[100010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i = 0;i < n;i++) cin>>object[i].d>>object[i].v>>object[i].a;
		for(int i = 0;i < m;i++) cin>>p[i];
		int cnt = 0;
		for(int i = 0;i < n;i++){
			double vv=sqrt(object[i].v * object[i].v + 2 * object[i].a * (p[m-1] - object[i].d));
			if(object[i].d <= p[m - 1] && vv > V) cnt++;
		}
		cout<<cnt<<' '<<((cnt>0)?(m-1):m)<<endl;
	}
	return 0;
}

