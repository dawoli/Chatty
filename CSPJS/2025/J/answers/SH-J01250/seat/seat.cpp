#include <iostream>
#include <algorithm>
using namespace std;


int n,m,xm,a[100],xl;

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			xm=a[i];
		}
	}
	
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xm){
			xl=i;
			break;
		}
	}
	int x=ceil((double)xl/m);
	cout<<x<<" ";
	if(x%2==0){
		cout<<m-xl%m+1;
	} else {
		cout<<xl%m;
	}
	return 0;
}
