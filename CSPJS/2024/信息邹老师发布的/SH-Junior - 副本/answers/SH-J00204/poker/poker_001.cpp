#include<bits/stdc++.h>
using namespace std;
#define N 5
#define M 15
int a[N][M];
string b;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int x,all=52;
	cin>>x;
	for(int i=1;i<=x;++i){
		cin>>b;
		char c=b[0],d=b[1];
		if(b[0]=='D')c=1;
		else if(c=='C')c=2;
		else if(c=='H')c=3;
		else if(c=='S')c=4;
		
		if(d=='A')d=1;
		else if(d=='T')d=10;
		else if(d=='J')d=11;
		else if(d=='Q')d=12;
		else if(d=='K')d=13;
		
		if(a[c][d]==0){
			all--;
			a[c][d]=1;
		}else{
			continue;
		}
	}
	cout<<all;
	
	fclose(stdin);
	fclose(stdout);
}
