#include <bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int chao=0,guan=0;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		int d[n],v[n],a[n],p[m],pp[m];
		for(int i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=0;i<m;i++){
			cin>>p[i];
			pp[i]=0;
		}
		for(int i=0;i<n;i++){
			if(a[i]==0&&d[i]<=p[m-1]&&v[i]>V){
				chao+=1;
				guan=m-1;
			}
		}
		cout<<chao<<" "<<guan;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
