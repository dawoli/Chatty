#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int t;
int n,m,L,V;
int d[100005],v[100005],a[100005]; 
int p[1000005];
struct cc{
	int d,v,a;
	bool iff;
	double ftime;
	double fs;
	int firstp;
	int ltime;
}car[100005];
bool cmp(cc A,cc B){
	return A.d<B.d;
}
double po(double a){
	return a*a;
}
double tt(double a,double v){
	return (V-v)/a;
}
double ss(double tt,double a,double v){
	return v*tt+0.5*a*po(tt);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			car[i].iff=false;
			car[i].firstp=-1;
			cin>>car[i].d>>car[i].v>>car[i].a;
			car[i].ftime=tt(car[i].a,car[i].v);
			car[i].fs=ss(car[i].ftime,car[i].a,car[i].v);
			if(car[i].fs<=(double)(L-car[i].d))
				car[i].iff=true;
		}
		bool ff=true;
		int cntt=0;
		for(int i=0;i<n;i++)
			if(car[i].a!=0){
				ff=false;
				if(car[i].v>V)
					cntt++;
			}
		if(ff){
			sort(car,car+n,cmp);
			for(int i=0;i<m;i++){
				cin>>p[i];
			}
			cout<<cntt<<" "<<1<<endl;
		}else{
			int ans1=0,ans2=0;
			for(int i=0;i<m;i++){
				cin>>p[i];
				bool flag=false;
				for(int i=0;i<n;i++){
					if(car[i].firstp==-1){
						flag=true;
						if(car[i].fs+car[i].d>=(double)p[i]){
							ans1++;
							car[i].firstp=i;
						}else
							flag=false;
					}
				}
				if(!flag)
					ans2++;
			}
			ans2--;
			cout<<ans1<<" "<<ans2<<endl;			
		}

	}
	return 0;
}
