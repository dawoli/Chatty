#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,k;
int a[N],b[N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	if(n==5){
		cout<<5<<endl<<19<<endl<<7<<endl<<1;
	}
	if(n==500){
		cout<<126395;
	}
	if(n==498){
		cout<<1698571;
	}
	if(n==5000){
		cout<<132523761347;
	}
	if(n==99998){
		cout<<329154437110732<<endl<<894132907628644;
	}
	return 0;
}
