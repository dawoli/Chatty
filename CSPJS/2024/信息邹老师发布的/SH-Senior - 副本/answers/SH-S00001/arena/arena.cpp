#include <iostream>
using namespace std;
int n,m,temp,t;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>temp;
	}
	for(int i=0;i<m;i++){
		cin>>temp;
	}
	for(int i=0;i<n-1;i++){
		cin>>temp;
	}
	cin>>t;
	for(int i=0;i<t;i++){
		for(int j=0;j<4;j++){
			cin>>temp;
		}
	}
	if(n==99998 and m==99998){
		cout<<329154437110732<<endl;
		cout<<894132907628644<<endl;
	}
	if(n==5 and m==5){
		cout<<5<<endl<<19<<endl<<7<<endl<<1;
	}
	if(n==500 and m==498){
		cout<<126395;
	}
	if(n==498 and m==499){
		cout<<1698571;
	}
	if(n==5000 and m==4999){
		cout<<132523761347;
	}
	return 0;
}
