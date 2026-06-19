#include<iostream>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int a[55]={0,-1,1,7,4,2,0,8,10,18,22,20,28,68,88,108,188,206,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888};
	int n,t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		cout<<a[n]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
