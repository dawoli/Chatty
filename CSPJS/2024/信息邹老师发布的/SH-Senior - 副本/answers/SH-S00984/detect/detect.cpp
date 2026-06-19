#include<bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005];//中第 i 辆车从主干道上距离最南端 di 的位置驶入，以 vi 的初速度和 ai 的加速度做匀加速运动向北行驶
int jk[100005];//表示监控 
int cs[100005];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,m,l,xv;//车辆数量、测速仪数量、主干道长度和道路限速
		cin>>n>>m>>l>>xv;
		for(int j=1;j<=n;j++){
			cin>>d[j]>>v[j]>>a[j];
		}
		for(int j=1;j<=m;j++){
			cin>>jk[j];
		}
		int sc=0;
		for(int j=1;j<=n;j++){
			bool flag=0;
			if(d[j]<=jk[m]&&v[j]*v[j]+(2*a[j]*(jk[m]-d[j]))>xv*xv){
				sc++;
			}
		}
		cout<<sc<<" ";
		if(sc==0){
			cout<<m<<endl;
		}
		else{
			cout<<m-1<<endl;
		}
	}
}
