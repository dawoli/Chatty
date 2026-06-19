#include<bits/stdc++.h>
#define N 1000005
using namespace std;

struct Car{
	int dir,v,a;
	double overdir;
}car[N];

int dd[N];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,l,vmax,overcnt=0,abz=0,aez=0,asz=0;
		cin>>n>>m>>l>>vmax;
		for(int i=0;i<n;++i)
			cin>>car[i].dir>>car[i].v>>car[i].a;
		for(int i=0;i<m;++i)
			cin>>dd[i];
		double lastover=dd[m-1]*1.0,firstover=dd[0]*1.0;
		for(int i=0;i<n;++i){
			if(car[i].a==0){
				aez++;
				if(car[i].v>vmax){
					car[i].overdir=1.0*car[i].dir;
					if(car[i].overdir<=dd[m-1]){
						overcnt++;
						lastover=max(lastover,car[i].overdir);
					}
				}
			}
			else if(car[i].a>0){
				abz++;
				if(car[i].dir>dd[m-1])
					continue;
				car[i].overdir=1.0*car[i].dir+1.0*(vmax*vmax-car[i].v*car[i].v)/(2*car[i].a);
				if(car[i].overdir<=dd[m-1]){
					overcnt++;
					lastover=min(lastover,car[i].overdir);
				}
			}
			else{
				bool flag=false;
				asz++;
				car[i].overdir=1.0*car[i].dir+1.0*(vmax*vmax-car[i].v*car[i].v)/(2*car[i].a);
				if(!(car[i].overdir<=dd[0]||car[i].dir>dd[m-1])){
					for(int j=0;j<m;++j){
						if(car[i].dir>dd[j]&&car[i].overdir<=dd[j+1]){
							flag=true;
							break;
						}
					}
					if(!flag)
						overcnt++;
					firstover=min(firstover,car[i].overdir);
				}
			}
		}
		int deld;
		if((abz==0&&asz==0)||(abz==0&&aez==0)||(aez==0&&asz==0))
			deld=m-1;
		else deld=m-2;
		cout<<overcnt<<' '<<deld<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
