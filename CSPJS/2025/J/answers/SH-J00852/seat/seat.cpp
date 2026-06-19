#include <bits/stdc++.h>
using namespace std;
const int N=19;
int n,m,a[N*N],cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]){
			cnt++;
		}
	}
	int nowx=1,nowy=1,uod=1;
	for(int i=1;i<cnt;i++){
		if(uod==1){
			nowy++;
			if(nowy>n){
				nowy=n;
				nowx++;
				uod=0;
			}
		}else{
			nowy--;
			if(nowy<1){
				nowy=1;
				nowx++;
				uod=1;
			}
		}
	}
	cout<<nowx<<' '<<nowy<<endl;
	return 0;
}
