#include<bits/stdc++.h>
using namespace std;
#define long long int
#define fin cin
#define fout cout
const int N=100005;
int main(){
	ifstream fin("duel.in");
	ofstream fout("duel.out");
	struct car{
		int d,v,a;
		bool cs;
	};
	car x[N];
	int n,m,length,vl,T,p[N],cnt=0,anss=0,ans=0;
	double v2;
	cin>>T;
	while(T>0){
		cin>>n>>m>>length>>vl;
		for(int i=1;i<=n;i++){
			cin>>x[i].d>>x[i].v>>x[i].a;
			x[i].cs=false;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(x[j].d>p[i]) break;
				else{
					v2=sqrt((x[j].v*x[j].v)+2*x[j].a*(x[j].d-p[i]));
					if(v2>vl){
						if(x[j].cs==false) cnt++;
						x[j].cs=true;
						
					}
				}
			}
			ans+=cnt;
			if(cnt==0) anss++;
		}
		cout<<ans<<" "<<anss--;
		ans=0;
		anss=0;
		T--;
	}
	fin.close();
	fout.close();
	return 0;
}
