#include<iostream>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(d-c*3-b*5-a*2>0){
		cout<<"Yes"<<endl<<d-c*3-b*5-a*2;
	}
	else cout<<"No"<<endl<<(d-c*3-b*5-a*2)-2*(d-c*3-b*5-a*2);
	return 0;
}
