#include<bits/stdc++.h>
#define long long ll
#define unsigned long long ull
using namespace std;
struct node{
	int d,v,a;
};
int op[1000005];
int opp[1000005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int cv=1;cv<=t;cv++){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		int cnt=0;
		node car[100005];
		for(int i=1;i<=n;i++){
			cin>>car[i].d>>car[i].v>>car[i].a;
		}
//		for(int i=1;i<=n;i++){
//			cout<<car[i].ax<<" ";
//		}
		for(int i=1;i<=m;i++){
			int qwer;
			cin>>qwer;
			op[qwer]=1;
		}
		int tp=0;
		int oppi=0;
		for(int i=1;i<=n;i++){
			int f=0;
			if(car[i].a==0){
				if(car[i].v>V){
					for(int j=L;j>=car[i].d;j--){
						if(op[j]){
							cnt++;
							f=1;
							tp=1;
							break;
						}
					}
				}
				else{
					continue;
				}
			}
			else if(car[i].a<0&&car[i].v<=V){
				continue;
			}
			else{
				if(car[i].a>0){
					for(int j=L;j>=car[i].d;j--){
						if(op[j]){
							double su=sqrt(car[i].v*car[i].v+2*car[i].a*(j-car[i].d));
							if(su>V){
								cnt++;
								f=1;
							}
							break;
						}
					}
				}
				else{
					double hsw=(0-car[i].v*car[i].v)/2*car[i].a;
					for(int j=car[i].d;j<=L&&j<=car[i].d+hsw;j++){
						if(op[j]){
							double su=sqrt(car[i].v*car[i].v+2*car[i].a*(j-car[i].d));
							if(su>V){
								cnt++;
								f=1;
							}
							break;
						}
					}
				}
			}
			if(f==0){
				continue;
			}
			
			
			
			
			
			
			
			
			
			
			
			double ax=(V*V-car[i].v*car[i].v)/2*car[i].a;
			int fl=0;
			int ne=-1;
			if(car[i].a>0){
				for(int j=L;j>=ax+car[i].d;j--){
					if(opp[j]){
						fl=1;
						break;
					}
					if(op[j]&&ne==-1){
						ne=j;
					}
				}
				if(fl==0){
					opp[ne]=1;
					oppi++;
				}
			}
			else if(car[i].a<0){
//				double hsw=(0-car[i].v*car[i].v)/2*car[i].a;
				for(int j=ax+car[i].d;j>=car[i].d;j--){
					if(opp[j]){
						fl=1;
						break;
					}
					if(op[j]&&ne==-1){
						ne=j;
					}
				}
				if(fl==0){
					opp[ne]=1;
					oppi++;
				}
			}
			else{
				for(int j=L;j>=car[i].d;j--){
					if(opp[j]){
						fl=1;
						break;
					}
					if(op[j]){
						ne=j;
					}
				}
				if(fl==0){
					opp[ne]=1;
					oppi++;
				}
			}
		}
		cout<<cnt<<" ";
		if(oppi==0&&tp==1){
			cout<<m-1<<endl;
		}
		else{
			cout<<m-oppi<<endl;
		}
//		for(int k=0;k<=L;k++){
//			if(opp[k]){
//				cout<<k<<" ";
//			}
//		}
//		cout<<endl;
		memset(op,0,sizeof(op));
		memset(opp,0,sizeof(opp));
	}
	return 0;
}
