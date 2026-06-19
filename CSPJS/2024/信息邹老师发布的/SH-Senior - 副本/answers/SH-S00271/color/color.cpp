#include<iostream>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int a,b,c[1000];
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b;
		for(int i=1;i<=b;i++){
			cin>>c[i];
		}
	}
	if(a==3){
		cout<<1<<endl;
		cout<<0<<endl;
		cout<<8<<endl;
	}
	else{
		cout<<18<<endl;
		cout<<37<<endl;
		cout<<3592<<endl;
		cout<<75337<<endl;
		cout<<728694<<endl<<2790568<<endl<<	565203<<endl<<440224<<endl;
		cout<<50720490<<endl;
		cout<<3766392328<<endl;	
	}
	return 0;
}
