#include<bits/stdc++.h>
using namespace std;
int T; 
int n[25], m[25], L[25], V[25], ans[25][5], num[25];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		int d[100005], v[100005], a[100005], p[100005], stop[100005]; 
		cin>>n[i]>>m[i]>>L[i]>>V[i];//n车辆数量、m测速仪数量、L主干道长度和V道路限速
		for(int j=0;j<n[i];j++) {
			cin>>d[j]>>v[j]>>a[j];//从距最南端d的位置驶入,v初速度和 a加速度
		}
		for(int j=0;j<m[i];j++) {cin>>p[j];num[i]++;//路上测速仪的位置
		}
		for(int j=0;j<n[i];j++){//第j辆车 
			if(v[j]>V[i])ans[i][1]++;
		}
	}

	for(int i=0;i<T;i++){
		cout<<ans[i][1]<<" "<<num[i]-1<<endl; 
	}
} 
