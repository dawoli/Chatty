#include<bits/stdc++.h>
using namespace std;
//nan zuo bei you ,nan da bei xiao
double det[100010],l[100010],r[10010],d[10010],a[10010],v[10010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T,m,n,L,V;
	cin>>T;
	int i,j;
	while(T>0){
		cin>>n>>m>>L>>V;
		int sum1=0,sum2=0;
		bool flag1=0,flag2=0,flag3=0;
		for(i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]<0){
				flag1=1;
				flag2=1;
			}
			if(a[i>0]){
				flag1=1;
				flag3=1;
			}
			if(a[i]>0){
				r[i]=L;
				if(v[i]>V){
					l[i]=d[i];
				}
				else if(v[i]==V){
					l[i]=d[i]+0.00000001;
				}
				else{
					l[i]=d[i]+(V-v[i])*v[i]/a[i]+(V-v[i])*(V-v[i])/(2*a[i]);
				}
			}
			else if(a[i]==0){
				if(v[i]>V){
					l[i]=d[i];
					r[i]=L;
				}
				else{
					l[i]=0;
					r[i]=-1.0;
				}
			}
			else{
				if(v[i]<=V){
					l[i]=0;
					r[i]=-1.0;
				}
				else{
					l[i]=d[i];
					r[i]=d[i]+(V-v[i])*v[i]/a[i]+(V-v[i])*(V-v[i])/(2*a[i]);
				}
			}
		}
		for(i=0;i<m;i++){
			cin>>det[i];
		}
		if(flag1==0){
			for(i=0;i<n;i++){
				if(d[i]<=det[m-1]&&v[i]>V){
					sum1++;
				}
			}
			sum2=1;
		}
		if(flag2==0&&flag1!=0){
			for(i=0;i<n;i++){
				if(l[i]<=det[m-1]){
					sum1++;
				}
			}
			sum2=1;
		}
		cout<<sum1<<' '<<sum2<<endl;
		T--;
	}
}
