#include<bits/stdc++.h>
using namespace std;
bool b[4][13];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int a;
	cin>>a;
	int c,e,f=0;
	string d;
	int g[36]={1,2,3,4,5,6,7,8,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,2,0,10,12,0,0,0,0,0,11,0,3,9};
	for(c=0;c<a;c++){
		cin>>d;
		b[g[int(d[0])-49]][g[int(d[1])-49]]=true;
	}
	for(c=0;c<4;c++){
		for(e=0;e<13;e++){
			if(!b[c][e]) f++;
		}
	}
	cout<<f;
	return 0;
}
