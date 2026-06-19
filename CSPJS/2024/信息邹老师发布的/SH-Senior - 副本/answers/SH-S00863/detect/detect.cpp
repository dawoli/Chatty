#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m,l,v,p[100009];
bool isA0;
struct Car{
	int d,v,a;
}car[100009];
namespace A0{
	void solve(){
		
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		isA0=1;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>car[i].d>>car[i].v>>car[i].a;
			if(car[i].a) isA0=0;
		} 
		for(int i=1;i<=m;i++) cin>>p[i];
		sort(p+1,p+m+1);
		if(isA0) A0::solve();
	}
	return 0;
}

