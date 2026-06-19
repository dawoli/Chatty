#include <bits/stdc++.h>
using namespace std;
int n,t,m,L,V;
bool f;
bool cmd(int x,int y){
	return x>y;
}
struct car{
	int d,v,a;
}c[1010];
int num[1010];
vector<int> b[1010];
int b1[1010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		int cnt=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>b1[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(c[i].v>V&&c[i].d<=b1[m]){
					cnt++;
					for(int k=j;k<=m;k++){
						b[j][i]=1;
					} 
					break;
				}
			}
		}
		cout<<cnt<<" "<<m/2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
