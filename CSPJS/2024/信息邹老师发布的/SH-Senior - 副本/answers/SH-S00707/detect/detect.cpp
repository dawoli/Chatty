#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9; 
int T;
int n,m,L,V;//车辆数量，测速仪数量，主干道长度，道路限速
int d[N];//i号车出没位置 
int v[N];//i号车初始移动速度
int a[N];//i号车加速度，可能为负数
int p[N];//i号监控出没位置；
int Ic[N];//此车辆是否被判定过 
int ans;//剩余必要摄像头
int cs;//超速车辆数量
int v1,s;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int z=0;z<T;z++){
		ans=0;
	cs=0;
	cin>>n>>m>>L>>V;
	for(int i=0;i<n;i++){
		cin>>d[i]>>v[i]>>a[i];
		Ic[i]=0;
	} 
	for(int i=0;i<m;i++){
		cin>>p[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(p[j]>=d[i]){
				s=p[j]-d[i];
				v1=max(0,v[i]*v[i]+2*a[i]*s);
				if(v1>V*V){
					if(Ic[i]==0){
						cs++;
						Ic[i]=1;
					}
					j=m;
				}
			}
		}
	}
	cout<<cs<<" ";
	cout<<m-1<<endl;
	}
	return 0;
}
