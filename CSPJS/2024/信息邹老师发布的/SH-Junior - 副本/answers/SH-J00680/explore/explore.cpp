#include<bits/stdc++.h>
using namespace std;
int a[1002][1002]={};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i+=1){
		int n,m,k,x,y,d,num=1,f=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(int j=1;j<=n;j+=1){
			for(int l=1;l<=m;l+=1){
				char s;
				cin>>s;
				if(s=='.'){
					a[j][l]=0;
				}
				if(s=='x'){
					a[j][l]=-1;
				}
			}
		}
		a[x][y]=1;
		for(int j=0;j<k;j+=1){
			int xx=x,yy=y;
			if(d==0){
				yy=y+1;
			}
			if(d==1){
				xx=x+1;
			}
			if(d==2){
				yy=y-1;
			}
			if(d==3){
				xx=x-1;
			}
			if(xx<1||yy<1||xx>n||yy>m||a[xx][yy]==-1){
				d=(d+1)%4;
			}
			else{
				if(f!=0&&a[xx][yy]==f+1){
					break;
				}
				f=a[x][y];
				if(a[xx][yy]==0){
					num+=1;
				}
				a[xx][yy]=a[x][y]+1;
				x=xx;
				y=yy;
			}
		}
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

