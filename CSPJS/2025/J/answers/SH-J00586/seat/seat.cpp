#include<bits/stdc++.h>
using namespace std;
int n,m,r=0,xy,rg;
int a[25][25]; 
int g[105];
bool cmp(const int x,const int y){
	return x>y;
}
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	
	cin >> n >> m;
	r=n*m;
	for(int i=0;i<r;i++){
		cin >> g[i];
	}
	rg=g[0];
	sort(g,g+r,cmp);
	for(int i=0;i<r;i++){
		if(g[i]==rg){
			xy=i;
			break;
		}
	}
	int xx=xy/n,yy=xy%n;
	if(xx%2==1)yy=n-yy-1;
	cout << xx+1 << " " << yy+1;
}/*
3 3
94 95 96 97 98 99 100 93 92

2 2
98 99 100 97
*/
