#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stout);
	int T,temp1,temp2;
	cin>>T;
	char weizhi[1005][1005];
	int n[6],m[6],k[6];
	int x0[6],y0[6],d0[6];
	for(int i=1;i<=T;i++){
		cin>>n[i]>>m[i]>>k[i];
		cin>>x0[i]>>y0[i]>>d0[i];
		for(int a=1;a<=n[i];a++){
			for(int b=1;b<=m[i];b++){
				cin>>weizhi[a][b];
			}
		} 
	}
	for(int i=1;i<=T;i++){
			if(d0[i]==0){
				temp1=x0[i];
				temp2=y0[i]+1;
			}
			if(d0[i]==1){
				temp1=x0[i]+1;
				temp2=y0[i];
			}
			if(d0[i]==2){
				temp1=x0[i];
				temp2=y0[i]-1;
			}
			if(d0[i]=3){
				temp1=x0[i]-1;
				temp2=y0[i];
			}
			if(1<=temp1&&temp1<=n[i]&&1<=temp2&&temp2<=m[i]&&weizhi[temp1][temp2]=='.'){
			cout<<"2"<<endl;
		}
		else cout<<"1"<<endl;
		}
		return 0;
 } 
