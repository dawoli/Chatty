#include<bits/stdc++.h>
using namespace std;
struct car{
	int d,v,a;
};
int T;
int n,m,L,V,ans1=0,ans2=0;
vector<car> l;
vector<int> v;
vector<bool> b;
bool check(int d,int v1,int a){
	for(int i=0;i<m;i++){
		bool flag=false;
		if(d<=v[i]){
			if(a==0 && v1>V){
				flag=true;
			}
			int ys=sqrt(v1*v1+2*a*(v[i]-d));
			if(ys>V){
				flag=true;
			}
		}
		if(flag==true){
			ans1++;
			bool flaag=true;
			for(int j=i;j<m;j++){
					if(b[j]==true){
						flaag=false;
					}
				}
				if(flaag==true){
					b[i]=true;
				}
				return a<v[i];
		}
	}
}

int main()
{
	freopen("detect.in.","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
			cin>>n>>m>>L>>V;
			for(int j=0;j<n;j++){
				int D,V,A;
				cin>>D>>V>>A;
				l[i].d=D;
				l[i].v=V;
				l[i].a=A;
			}
			for(int k=0;k<m;k++){
				int f;
				cin>>f;
				v.push_back(f);
				b.push_back(false);
			}
			for(int q=0;q<n;q++){
				check(l[q].d,l[q].v,l[q].a);
			}
			for(int z=0;z<m;z++){
				if(b[z]==true){
					ans2++;
				}
			}
			cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
