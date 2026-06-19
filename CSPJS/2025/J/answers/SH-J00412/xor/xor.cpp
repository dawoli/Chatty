#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int N12=1e3+5;
int n,k,a[N],f[N12][N12],anszb[N12*N12][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			f[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				f[i][j]=a[i];
			}
			else{
				f[i][j]=(f[i][j-1]^a[j]);
			}
		}
	}
	int x=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[i][j]==k){
				anszb[x][0]=i;
				anszb[x][1]=j;
				x++;
			}
		}
	}
	for(int i=1;i<x;i++){
		for(int j=1;j<x;j++){
			if(anszb[i][1]>anszb[j][0]){
				if((anszb[i][1]-anszb[i][0]+1)>(anszb[j][1]-anszb[j][0]+1)){
					anszb[i][0]=-1;
					anszb[i][1]=-1;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<x;i++){
		if(anszb[i][0]>0&&anszb[i][1]>0) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
  0 1 2 3 4
0 - - - - -
1 - 2 3 3 0
2 - - 1 1 2 
3 - - - 0 3
4 - - - - 3
*/
