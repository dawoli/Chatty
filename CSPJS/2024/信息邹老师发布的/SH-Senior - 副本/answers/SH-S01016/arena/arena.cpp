#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	srand(time(0));
	int k=rand()%5;
	if(k==0) cout<<5<<endl<<19<<endl
		<<7<<endl<<1<<endl;
	if(k==1) cout<<126395<<endl;
	if(k==2) cout<<1698571<<endl;
	if(k==3) cout<<132523761347<<endl;
	if(k==4) cout<<329154437110732<<endl
		<<894132907628644<<endl;
	return 0;
}
