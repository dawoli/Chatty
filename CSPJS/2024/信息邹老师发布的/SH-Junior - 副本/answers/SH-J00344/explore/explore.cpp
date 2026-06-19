#include<bits/stdc++.h>
using namespace std;
bool vst[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int g=1;g<=t;g++){
		int n,m,k,x,y,d,cnt=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				vst[i][j]=0;
		char a[1009][1009];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=1;i<=k;i++){
			vst[x][y]=1;
			if(d==0&&y==m){
				d++;
				continue;
			}
			else if(d==1&&x==n){
				d++;
				continue;
			}
			else if(d==2&&y==1){
				d++;
				continue;
			}
			else if(d==3&&x==1){
				d=0;
				continue;
			}
			if(d==0&&a[x][y+1]=='x'){
				d++;
				continue;
			}
			else if(d==1&&a[x+1][y]=='x'){
				d++;
				continue;
			}
			else if(d==2&&a[x][y-1]=='x'){
				d++;
				continue;
			}
			else if(d==3&&a[x-1][y]=='x'){
				d=0;
				continue;
			}
			if(d==0)
				y++;
			else if(d==1)
				x++;
			else if(d==2)
				y--;
			else if(d==3)
				x--;
			if(!vst[x][y])
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
