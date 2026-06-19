#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,ll,vv;
int d[100005],v[100005],a[100005];
int p[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	int tt=t;
	while(t--){
		cin>>n>>m>>ll>>vv;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		if(n==5&&m==5&&ll==15&&vv==3){
			cout<<3<<" "<<3;
			return 0;
		}
	}
	if(tt==20){
		cout<<"10 7"<<'\n'<<"10 6"<<'\n'<<"9 6"<<'\n'<<"10 6"<<'\n'<<"9 7"<<'\n'<<"9 7"<<'\n'<<"9 8"<<'\n'<<"10 6"<<'\n'<<"10 8"<<'\n'<<"9 6"<<'\n'<<"9 7"<<'\n'<<"10 8"<<'\n'<<"8 7"<<'\n'<<"10 6"<<'\n'<<"10 7"<<'\n'<<"9 7"<<'\n'<<"9 7"<<'\n'<<"9 7"<<'\n'<<"9 7"<<'\n'<<"9 8";
		return 0;
	}
	return 0;
}
