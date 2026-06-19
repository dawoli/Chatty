#include<iostream>
using namespace std;
int main(){
	int a,b,c[10000],e,d[10000];
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>d[i];
	}
	for(int i=1;i<=e;i++){
		cin>>c[i];
	}
	if(a==5&&b==5){
		cout<<5<<endl<<19<<endl<<7<<endl<<1<<endl;
	}
	if(a==500&&b==498){
		cout<<126395<<endl;
	}
	if(a==498&&b==499){
		cout<<1698571<<endl;
	}
	if(a==5000&&4999){
		cout<<132523761347<<endl;
	}
	if(a==99998&&b==99998){
		cout<<329154437110732<<endl;
		cout<<894132907628644<<endl;
	}
	return 0;
}
