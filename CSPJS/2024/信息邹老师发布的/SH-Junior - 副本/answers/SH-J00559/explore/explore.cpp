#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
int t;
int n,m;
int k,d;
int x,y;
int cnt=1;
bool check(int,int,int,int,int);
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++) {
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int q=1;q<=n;q++)
			for(int w=1;w<=m;w++)
				cin>>a[q][w];
		for(int g=1;g<=k;g++)
			if(check(x,y,d,n,m))
				cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
bool check(int x,int y,int d,int n,int m) {
	if(d==0) {
		y++;
		if(y>m||a[x][y]!='.') {
			d++;
			d%=4;
			y--;
			return false;
		}
	}
	if(d==1) {
		x++;
		if(x>n||a[x][y]!='.') {
			d++;
			d%=4;
			x--;
			return false;
		}
	}
	if(d==2) {
		y--;
		if(y<=0||a[x][y]!='.') {
			d++;
			d%=4;
			y++;
			return false;
		}
	}
	if(d==3) {
		x--;
		if(x<=0||a[x][y]!='.') {
			d++;
			d%=4;
			x++;
			return false;
		}
	}
	return true;
}
