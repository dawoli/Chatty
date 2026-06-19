#include<iostream>
using namespace std;

int dmax=0;
int car=0,detect=0;
int t,n,m,l,vmax,a,p;
int d[1000010],v[1000010];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>l>>vmax;
		if(m==0){
			cout<<0<<0;
			return 0;
		}
		for(int j=1;j<=n;j++){
			cin>>d[j]>>v[j]>>a;
	    }
	    for(int j=1;j<=m;j++){
	    	cin>>p;
	    	if(p>dmax&&p<=l){
	    		dmax=p;
			}
		}
		for(int j=1;j<=n;j++){
			if(d[j]<=dmax&&v[j]>vmax){
				car++;
			}
		}
		if(car==0){
			detect=m;
		}else{
			detect=m-1;
		}
		cout<<car<<" "<<detect<<endl;
	}
	return 0;
}
