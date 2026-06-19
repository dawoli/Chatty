#include<bits/stdc++.h>
using namespace std;
int t;
bool ma[1005][1005],flag[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				flag[i][j]=0;
				char temp;
				cin>>temp;
				if(temp=='.') ma[i][j]=1;
				else ma[i][j]=0;
			}
		}
		int i=x,j=y;
		flag[i][j]=1;
		while(k--){
			if((d==0&&!ma[i][j+1])||(d==1&&!ma[i+1][j])||(d==2&&!ma[i][j-1])||(d==3&&!ma[i-1][j]))
				d=((d+1)%4);
			else if(d==0){
				flag[i][j+1]=1;
				j++;
			}
			else if(d==1){
				flag[i+1][j]=1;
				i++;
			}
			else if(d==2){
				flag[i][j-1]=1;
				j--;
			}
			else if(d==3){
				flag[i-1][j]=1;
				i--;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				if(flag[i][j]==1) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
