#include <bits/stdc++.h>
using namespace std;
int T,n,m,L,V,cnt;
struct Car{
	int d,v,a;
}cars[100001];
int detectors[100001];

int main(){
	freopen("detect.in","r",stdin);
	freoepn("detect.out","w",stdout);

	cin>>T;
	for(int _=0;_<T;++_){
		cin>>n>>m>>L>>V;
		cnt=0;
		for(int i=0;i<n;i++){
			Car c;
			cin>>c.d>>c.v>>c.a;
			cars[i]=c;
		} 
		for(int i=0;i<m;i++){
			cin>>detectors[i];
		}
		for(int i=0;i<n;i++){
			Car c=cars[i];
			if(c.v>V && c.d<=detectors[m-1]){
				cnt++;
			}
		}
		cout<<cnt<<' '<<int(bool(cnt));
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
