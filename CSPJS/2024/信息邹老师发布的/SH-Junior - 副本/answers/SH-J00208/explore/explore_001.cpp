#include<bits/stdc++.h>
using namespace std;

int T,n,m,k,x0,y0,d0,rst,yes,answers[10];
char maze[1005][1005];
bool steps[1005][1005][4];//zhuangtai
bool visited[1005][1005];
bool determine(int d){
	return steps[x0][y0][d0];
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int t = 0;t<T;t++){
		rst = 0;yes = 0;
		cin>>n>>m>>k>>x0>>y0>>d0;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++)
			{
				cin>>maze[i+1][j+1];
				visited[i+1][j+1] = false;
				for(int i = 0;i<4;i++){
					steps[i+1][j+1][i] = false;
				}
			}
		}
		steps[x0][y0][d0] = true;
		rst++;
		visited[x0][y0] = true;
		for(int i = 0;i<k;i++){
			if(d0==0) y0++;
			if(d0==1) x0++;
			if(d0==2) y0--;
			if(d0==3) x0--;
			if(0<x0 && x0<= n && 
			0<y0 && y0<= m && maze[x0][y0] == '.'){
				if(determine(d0))
				{
					answers[t] = rst;
					yes = 1;
					break;	
				}else{
					steps[x0][y0][d0] = true;
					if(!visited[x0][y0]){
						rst++;
						visited[x0][y0] = true;
					}
				}
			}else{
				if(d0==0) y0--;
				if(d0==1) x0--;
				if(d0==2) y0++;
				if(d0==3) x0++;
				d0 = (d0+1)%4;
				if(determine(d0)){
					answers[t] = rst;
					yes = 1;
					break;
				}
				steps[x0][y0][d0] = true;
			}
		}
		if(!yes) answers[t] = rst;
	}
	for(int i = 0;i<T;i++){
		cout<<answers[i]<<endl;
	}
	return 0;
}
