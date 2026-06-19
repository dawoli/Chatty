#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,a[10001],x[1001],y[1000],z[10001],ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	for(int j=0;j<a[i];j++){
	cin>>x[j]>>y[j]>>z[j];
	}
	cout<<max(max(max(x[0]+y[1],x[0]+z[1]),max(y[0]+x[1],y[0]+z[1])),max(z[0]+x[1],z[0]+y[1]))<<endl;
	}
	return 0;
}
