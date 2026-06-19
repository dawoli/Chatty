#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,cnt=0;
string lo[100001],p;

int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	int num[T];
	for (int i=0;i<T;i++) {
		cnt=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for (int j=0;j<n;j++) {
			cin>>p;
			lo[j]=p;
		} 
		for (int i=0;i<k;i++) {
			if (d==0) {
				if (lo[y+1][x]!='x'&&y+1>=1&&y+1<=m) {
					y+=1;cnt++;
				}else {
					d=(d+1)%4;
				}
			}
			if (d==1) {
				if (lo[y][x+1]!='x'&&x+1>=1&&x+1<=m) {
					x+=1;cnt++;
				}else {
					d=(d+1)%4;
					}
				}
			if (d==2) {
				if (lo[y-1][x]!='x'&&y-1>=1&&y-1<=m) {
					y-=1;cnt++;
				}else {
					d=(d+1)%4;
				}
			}
			if (d==3) {
				if (lo[y][x-1]!='x'&&x-1>=1&&x-1<=m) {
					y+=1;cnt++;
				}else {
					d=(d+1)%4;
				}
			}
		}
		num[i]=cnt;
	}
	for (int i=0;i<T;i++) cout<<num[i]<<endl;
	return 0;
} 
