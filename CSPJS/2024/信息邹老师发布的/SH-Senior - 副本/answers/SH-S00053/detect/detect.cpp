#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5;
int T,n,m,L,V,p[M],dp[N];
long long cnt=0;
struct cheliang{
	int d,v,a,zhongdian;
}che[N];
bool check(int d){
	bool f=0;
	for(int i=d;i<=L;i++){
		if(p[i]) dp[i]++,f=1;
	}
	return f;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;//n是车辆数，m是检测仪数，L是道路长度，V是最快速度 
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>che[i].d>>che[i].v>>che[i].a;//d是开始位置，v是初始速度，a是加速度 
		}
		for(int i=1;i<=m;i++){
			int t;cin>>t;//检测仪的位置 
			p[t]=1;
		}//输入
		for(int i=1;i<=n;i++){
			if(che[i].v>V&&check(che[i].d)) cnt++;
		}
		cout<<cnt<<endl;
		cout<<n-1; 
	}
	return 0;
}
