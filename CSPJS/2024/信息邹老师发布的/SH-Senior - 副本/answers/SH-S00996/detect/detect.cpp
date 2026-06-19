#include<bits/stdc++.h>
using namespace std;
struct car{
	int d,v,a,yy;
	double k;
};
int Lv[1000001]={};
car a[100002]={};
int b[100002]={};
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n,m,V,L;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		//cin>>n>>m>>L>>V;
		memset(Lv,0,1000001);
		memset(b,0,100001);
		memset(a,0,100001);
		for(int j=0;j<n;j++){
			scanf("%d%d%d",&a[j].d,&a[j].v,&a[j].a);
			double aa=V;
			double bb=a[j].v;
			double cc=a[j].a;
			if(a[j].a!=0){
				a[j].k=(aa*aa-bb*bb)/(2*cc); 
				a[j].yy=a[j].k;
				if((V*V-a[j].v*a[j].v)%(2*a[j].a)==0){
					if(a[j].a>0){
						a[j].yy++;
					}
					else{
						a[j].yy--;
					}
				}
				a[j].yy+=a[j].d;
				//cout<<a[j].yy<<endl;
			}
		}
		for(int j=0;j<m;j++){
			cin>>b[j];
			Lv[b[j]]++;
		}
		int kk=0;
		for(int j=0;j<=L;j++){
			if(Lv[j]!=0){
				kk++;
			}
			Lv[j]=kk;
		}
		int sum1=0;
		for(int j=0;j<n;j++){
			if(a[j].a==0&&a[j].v>V&&a[j].d<=b[m-1]){
				sum1++;
			}
			else if(a[j].a>0){
				if(a[j].yy<a[j].d){
					a[j].yy=a[j].d;
				}
				if(a[j].yy>L){
					continue;
				}
				if(a[j].yy<=b[m-1]){
					sum1++; 
				}
			}
			else if(a[j].a<0){
				if(a[j].yy<a[j].d){
					continue;
				}
				if(a[j].yy>L){
					a[j].yy=L;
				}
				if(Lv[a[j].d-1]<Lv[a[j].yy]){
					sum1++; 
				}
			}
		}
		if(sum1==0){
			printf("%d %d\n",sum1,m);
		}
		else{
			printf("%d %d\n",sum1,m-1);
		}
		//cout<<sum1<<" "<<m-1<<endl;
	}
	return 0;
}
