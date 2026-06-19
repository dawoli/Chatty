#include<bits/stdc++.h> 
using namespace std;


int t,result=1;
int n,m,k;
string a[1010];
bool c[1010][1010];
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
int x,y,tx,ty,d;
int b[6];


int main(){
	
	
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>k;
		for(int j=0;j<n;j++){
			fill(c[j],c[j]+m,1);
		}
		cin>>x>>y>>d;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		x--;y--;
		c[x][y]=0;
		for(int j=0;j<k;j++){
			tx=x+fx[d];ty=y+fy[d];
			if(tx>=0 and tx<n and ty>=0 and ty<m and a[tx][ty]=='.'){
				x=tx;y=ty;
				if(c[x][y]){
					result++;
					c[x][y]=0;
				}
			}
			else{
				d=(d+1)%4;
			}
		}
		b[i]=result;
		result=1;
	}
	for(int i=0;i<t;i++){
		cout<<b[i]<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}




//GL@17SXYZ
