#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,b[110][110];
struct node{
	int res,id;
}a[1010];

bool cmp(const node a,const node b){
	return a.res>b.res;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].res;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[(i-1)*m+j].id==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[(i-1)*m+(m-j+1)].id==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
