#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
int n,m,L,V,t,text;
int d[N],v[N],a[N],p[N];
bool cal(int i){
	int s=*lower_bound(p+1,p+1+m,d[i])-d[i];
	return sqrt(v[i]*v[i]+2*a[i]*s)<=V;
}
bool a0(){
	for(int i=1;i<=n;i++)if(a[i]!=0)return 0;
	return 1;
}
bool am(){
	for(int i=1;i<=n;i++)if(a[i]>=0)return 0;
	return 1;
}
bool ap(){
	for(int i=1;i<=n;i++)if(a[i]<=0)return 0;
	return 1;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
//		cout<<n<<" "<<m<<" "<<L<<" "<<V<<" "<<endl;
//		text++;
//		cout<<text<<endl;
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i];
		if(a0()){
//			cout<<666<<endl;
			int cnt=0;
			for(int i=1;i<=n;i++)if(v[i]>V&&d[i]<=p[m])cnt++;
			if(cnt==0)cout<<0<<" "<<m<<endl;
			else cout<<cnt<<" "<<m-1<<endl;
		}
		else if(am()){
//			cout<<"---"<<endl;
			int cnt=0;
			for(int i=1;i<=n;i++)if(v[i]>V&&cal(i))cnt++;
			cout<<cnt<<endl;
		}
	}
//	cout<<666<<endl;
//	cout<<text<<endl;
	return 0;
}

