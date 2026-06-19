#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,d[100005],v[100005],a[100005],ans,sum,pt=1;
struct stu{
	int u=0,nu=0,nu2=1000005;
};

stu p[100005],o[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for (int z=1;z<=t;z++){
		sum=0;//超速的车 
		cin>>n>>m>>L>>V;//n车辆m测速仪L主干道V超速 
		ans=m;
		for (int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];//d初始位置v初速度a加速度 
			while(d[i]<L){
				if (v[i]<=0) break;
				if (v[i]>V && o[i].nu==0){
					o[i].nu=d[i];
				}
				v[i]+=a[i];
				d[i]+=v[i];
				if (v[i]<=V) {
				o[i].nu2=d[i];
				}
			}
		}//o【i】.nu表示第 i辆车在什么位置超速,0表示不超速 
		
		for (int i=1;i<=m;i++){
			cin>>p[i].nu;
		}
		for (int i=m;i>=1;i--){
			for (int j=1;j<=n;j++){
				if (o[j].nu<=p[i].nu && o[j].nu2>=p[i].nu && o[j].nu>0 && o[j].u==0){
					o[j].u=1;
					if (p[i].u==0) ans--;
					p[i].u=1;
					sum++;
				}
				
			}
		}
		cout<<sum<<" "<<ans<<endl;
		for (int i=1;i<=n;i++){
			d[i]=0;
			v[i]=0;
			a[i]=0;
			o[i].u=0;
			o[i].nu=0;
			o[i].nu2=1000005;
			p[i].nu=0;
			p[i].u=0;	}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;//大抵是T了
} 
