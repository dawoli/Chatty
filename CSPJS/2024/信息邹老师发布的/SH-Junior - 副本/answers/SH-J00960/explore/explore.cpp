#include<bits/stdc++.h>
using namespace std;
short ma[1005][1005];
int dir[2][4] = {{0,1,0,-1},{1,0,-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int z=0;z<t;z++){
		for(int i=0;i<1005;i++){
			for(int j=0;j<1005;j++){
				ma[i][j] = 0;
			}
		}
		int n,m,k;
		cin>>n>>m>>k;
		int xs,ys,ds;
		cin>>xs>>ys>>ds;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				char a;
				cin>>a;
				if(a=='x') ma[i+1][j+1] = 1;
			}
		}
		int res=0;
		res++;
		ma[xs][ys]=-1;
		for(int i=0;i<k;i++){
			if(xs+dir[0][ds]>=1 && xs+dir[0][ds]<=n&&ys+dir[1][ds]>=1 && ys+dir[1][ds]<=m&&ma[xs+dir[0][ds]][ys+dir[1][ds]]!=1){
				xs+=dir[0][ds];
				ys+=dir[1][ds];
				if(ma[xs][ys]!=-1){
					res++;
					ma[xs][ys]=-1;
				}
			}
			else{
				ds++;
				ds%=4;
			}
		}
		cout<<res<<endl;
	}
}
