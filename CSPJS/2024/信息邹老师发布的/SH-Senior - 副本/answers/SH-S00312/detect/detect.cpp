#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct car{
	int n,m,L,V;
	int d[N],v[N],a[N],p[N],sum;
	map<int,int>jud;
	int ansx,ansy,ansz[N];
};
car de[25];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>de[i].n>>de[i].m>>de[i].L>>de[i].V;
		for(int j=1;j<=de[i].n;j++){
			cin>>de[i].d[j]>>de[i].v[j]>>de[i].a[j];
			de[i].sum+=de[i].a[j];
		}
		for(int j=1;j<=de[i].m;j++){
			cin>>de[i].p[i];
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=de[i].n;j++){
			if(de[i].a[i]==0||de[i].sum==0){
				if(de[i].v[j]>de[i].V){
					de[i].ansx++;de[i].ansz[j]++;
					for(int k=1;k<=de[i].m;k++){
						if(de[i].p[k]>=de[i].d[j]){
							de[i].jud[de[i].p[k]]++;
						}						
					}
				}
			}
		}
		for(int k=1;k<=de[i].m;k++){
			if(de[i].jud[de[i].p[k]]==0){
				de[i].ansy++;
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<de[i].ansx<<" "<<de[i].ansy<<endl;
	}
	return 0;
}
