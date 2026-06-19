#include <bits/stdc++.h>
using namespace std;
char a[106][106];
int d,n,m,z,x,y,k,ans=0,u[10];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
cin>>d;
	for(int i=1;i<=d;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>z;
		for(int b=1;b<=n;b++)
			for(int c=1;c<=m;c++)
				cin>>a[b][c];
			if(z==0){
				if(a[x][y+1]=='x')
				u[i]=0;
				else
				u[i]=1;
			}
		if(z==1){
				if(a[x+1][y]=='x')
				u[i]=0;
				else
				u[i]=1;
			}
		if(z==2){
				if(a[x][y-1]=='x'||y-1==0)
				u[i]=0;
				else
				u[i]=1;
			}	
			if(z==3){
				if(a[x-1][y]=='x'||x-1==0)
				u[i]=0;
				else
				u[i]=1;
			}	
	}
	for(int i=1;i<=d;i++)
	cout<<u[i]<<endl;
	fclose(stdin);
	fclose(stdout);
}
