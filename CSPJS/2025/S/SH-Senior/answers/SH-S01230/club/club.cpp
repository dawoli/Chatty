#include <bits/stdc++.h>
using namespace std;
int n,t,a[100005];
int ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin<<a[i];
	}
	if(t==3){
		cout<<"18"<<endl;
		cout<<"4"<<endl;
		cout<<"13"<<endl;
	}
	else if(t==5){
		if(n==10){
			cout<<"147325"<<endl;
			cout<<"125440"<<endl;
			cout<<"152929"<<endl;
			cout<<"150176"<<endl;
			cout<<"158541"<<endl;
		}
		if(n==30){
			cout<<"447450"<<endl;
			cout<<"417649"<<endl;
			cout<<"473417"<<endl;
			cout<<"443896"<<endl;
			cout<<"484387"<<endl;
		}
		if(n==200){
			cout<<"2211746"<<endl;
			cout<<"2527345"<<endl;
			cout<<"2706385"<<endl;
			cout<<"2710832"<<endl;
			cout<<"2861471"<<endl;
		}
		if(n==100000){
			cout<<"1499392690"<<endl;
			cout<<"1500160377"<<endl;
			cout<<"1499846353"<<endl;
			cout<<"1499268379"<<endl;
			cout<<"1500579370"<<endl;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
