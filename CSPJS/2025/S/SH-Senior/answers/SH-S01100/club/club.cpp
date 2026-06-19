#include <bits/stdc++.h>
using namespace std;
int a[100000][3];
int t,n,b=0,c=0,d=0,e=0;
void g(int j,int k,int l)
{
	for(int i=1;i<=n; i++) {
		if(a[i][j]>b/4){
			e+=a[i][j];
		}
		else
		{
			if(a[i][k]>c/4){
				e+=a[i][k];
			}
			else
			{
				if(a[i][l]>d/4){
					e+=a[i][l];
				}
			}
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t; i++) {
		cin>>n;
		int b=0,c=0,d=0,e=0;
		for(int i=1;i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b+=a[i][1];
			c+=a[i][2];
			d+=a[i][3];
		}
		if(b>c&&b>d){
			if(c>d){
				g(1,2,3);
			}
			else{
				g(1,3,2);
			}
		}
		if(c>b&&c>d){
			if(b>d){
				g(2,1,3);
			}
			else{
				g(2,3,1);
			}
		}
		if(d>b&&d>c){
			if(b>c){
				g(3,1,2);
			}
			else{
				g(3,2,1);
			}
		}
		
		cout<<e<<endl;
	}
	return 0;
}
