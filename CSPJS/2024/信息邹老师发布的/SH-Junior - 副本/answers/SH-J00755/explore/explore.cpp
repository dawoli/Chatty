#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,m,n,k,x0,y0,d0,o=1,p=0;
	string s;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>m>>n>>k>>x0>>y0>>d0;
		for(int j=0;j<=m;j++){
			a[j][0]='x';
		}
		for(int j=0;j<=n;j++){
			a[0][j]='x';
		}
		for(int j=0;j<=n;j++){
			a[m+1][j]='x';
	
		}
		for(int j=0;j<=m;j++){
			a[j][n+1]='x';

		}
		for(int j=1;j<=m;j++){
			cin>>s;
			for(int l=0;l<s.size();l++){
			a[j][l+1]=s[l];
		}
		}
	
		for(int j=0;j<k;j++){
			if(p==k)
			break;
			if(d0==0){
				
				if(a[x0][y0+1]!='x'){
					a[x0][y0]='x';
			      y0++;
			      o++;
			      p++;
			}
			else{
				d0=(d0+1)%4;
				p++;
			}
			}
			else if(d0==1){
				
				if(a[x0+1][y0]!='x'){
					a[x0][y0]='x';
			      x0++;
			      o++;
			      p++;
			}
			else{
				d0=(d0+1)%4;
				p++;
			}
			}
			else if(d0==2){
				
				if(a[x0][y0-1]!='x'){
					 a[x0][y0]='x';
			      y0--;
			      o++;
			      p++;
			}
			else{
				d0=(d0+1)%4;
				p++;
			}
			}
		else if(d0==3){
			if(a[x0-1][y0]!='x'){
				 a[x0][y0]='x';
			      x0--;
			      o++;
			      p++;
			}
			else{
				d0=(d0+1)%4;
				p++;
			}
		}	
		}
		p=0;
		cout<<o<<endl;
		o=1;
	}
	return 0;
}
