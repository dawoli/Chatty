#include<bits/stdc++.h>
using namespace std;
struct car{
	int d,v,a;
	bool cs[100005];
}c[100005];
int csy[100005],ccs[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		int cnt=0,minus=0;
		for(int i=1;i<=n;i++)
			cin>>c[i].d>>c[i].v>>c[i].a;
		for(int i=1;i<=m;i++)
			cin>>csy[i];
		for(int i=1;i<=n;i++){
			int temp=cnt;
			if(c[i].d<=csy[i]&&c[i].v>V){
				c[i].cs=1;
				cnt++;
			}
			if(c[i].d>csy[i]&&c[i].v>V) cnt--;
			ccs[i]=(cnt-temp);
			if(ccs[i]==0||(i+1)!=m) minus++;
		}
		cout<<cnt<<" "<<minus<<endl;
	}
	return 0;
}
