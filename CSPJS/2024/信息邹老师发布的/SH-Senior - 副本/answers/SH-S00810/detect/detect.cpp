#include<iostream>
#include<cmath>
const int N=100005;
const int M=100005;
using namespace std;
int shun(int v,int a,int s){
	if(s<0||v<0)return -1;
	float first=v*v+2*a*s;
	if(first<0)return -1;
	else return int(ceil(sqrt(first)));
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	bool deted[N][M];
	int n,m,l,v,ansfir,ansec,mdeted[M],maxplc,maxn=0,numfir;
	int d[N],v1[N],a[N];
	for(int time=0;time<T;time++){
		ansec=0;
		cin>>n>>m>>l>>v;
		for(int i=0;i<n;i++)cin>>d[i]>>v1[i]>>a[i];
		int p[M];
		for(int i=0;i<m;i++){
			cin>>p[i];
			mdeted[i]=0;
		}
		for(int i=0;i<n;i++){
			bool flag=false;
			for(int j=0;j<m;j++){
				deted[i][j]=false;
				if(shun(v1[i],a[i],p[j]-d[i])>v){
					flag=true;
					mdeted[j]++;
					deted[i][j]=true;
				}
			}
			if(flag)ansec++;
	 	}
	 	/*bool flagfin=false;
		while(flagfin){
			++numfir;
			maxn=0;
			for(int j=0;j<m;j++){
				if(maxn<mdeted[j]){
					maxn=mdeted[j];
					maxplc=j;
				}
			}
			if(maxn==0)flagfin=false;
			for(int i=0;i<n;i++){
				if(deted[i][maxplc]){
					for(int j=0;j<m;j++){
						if(deted[i][j]){
							deted[i][j]=false;
							mdeted[j]-=1;
						}
					}
				}
			}
		}*/
		cout<<ansec<<" "<<m-numfir-2<<endl;
	}
	return 0;
}
