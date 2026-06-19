#include<bits/stdc++.h>
using namespace std;
struct car{
	int d;
	int a;
	double v;
};
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int qwe=0;qwe<T;qwe++){
		int n,m,l,V,o1=0,o2=0,demaxi;
		cin>>n>>m>>l>>V;
		car ca[n];
		for(int i=0;i<n;i++){
			cin>>ca[i].d>>ca[i].v>>ca[i].a;
		}
		int det[m];
		int de[m]={0};
		int demax=0;
		for(int i=0;i<m;i++){
			cin>>det[i];
			if(demax<det[i]){
			demax=det[i];
			demaxi=i;
			}
		}
		for(int i=0;i<n;i++){
					int detj=l+1;
					int detjj;
			if(ca[i].a<0){
				o1+=(ca[i].v>V);
				for(int j=0;j<m;j++){
					if(det[j]>detj&&det[j]>ca[i].d){
						detjj=j;
					}
				}
				de[detjj]=1;
			}else{
				if((ca[i].a^2+2*ca[i].a*(l-ca[i].d))>V){
					o1+=1;
					de[demaxi]=1;
				}
			}
		}
		for(int i=0;i<m;i++){
			o2+=de[i];
		}
	cout<<o1<<" "<<m-o2;
	}
	return 0;
}
