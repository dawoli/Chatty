#include<bits/stdc++.h>
using namespace std;
bool a[10][18];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		string x;
		cin>>x;
		int y,z;
		if(x[0]=='D'){
			y=1;
		}else if(x[0]=='C'){
			y=2;
		}else if(x[0]=='H'){
			y=3;
		}else if(x[0]=='S'){
			y=4;
		}
		if(x[1]=='A'){
			z=1;
		}else if(x[1]=='2'){
			z=2;
		}else if(x[1]=='3'){
			z=3;
		}else if(x[1]=='4'){
			z=4;
		}else if(x[1]=='5'){
			z=5;
		}else if(x[1]=='6'){
			z=6;
		}else if(x[1]=='7'){
			z=7;
		}else if(x[1]=='8'){
			z=8;
		}else if(x[1]=='9'){
			z=9;
		}else if(x[1]=='T'){
			z=10;
		}else if(x[1]=='J'){
			z=11;
		}else if(x[1]=='Q'){
			z=12;
		}else if(x[1]=='K'){
			z=13;
		}
		if(a[y][z]==0){
		a[y][z]=1;
		cnt++;
		}
	}
	cout<<52-cnt;
	return 0;
}
