#include<bits/stdc++.h>
using namespace std;
struct f{
	char c;
	int xyz=0;
}a[1001][1001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long T;
	cin>>T;
	while(T--){
		long long n,m,k;
		cin>>n>>m>>k;
		long long x,y,d;
		long long sum=1; //最后的答案 
		cin>>x>>y>>d;
		//读入数据 
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>a[i][j].c;
				a[i][j].xyz=0;
			}
		}
		a[x][y].xyz=1;
		//不断地走步数，直到走完 
		while (k--){
			//向右 
			if (d==0){
				if (a[x][y+1].c!='x' && y+1<=m){
					y++;
					if (a[x][y].xyz==0) {
						a[x][y].xyz=1;
						sum++; 
					}
				}else{//旋转
					d=(d+1)%4;
				}
			}else if(d==1){ //向下 
				if (a[x+1][y].c!='x' && x+1<=n){
					x++;
					if (a[x][y].xyz==0) {
						a[x][y].xyz=1;
						sum++; 
					}
				}else{//旋转
					d=(d+1)%4;
				}
			}else if(d==2){ //向左 
				if (a[x][y-1].c!='x' && y-1>0){
					y--;
					if (a[x][y].xyz==0) {
						a[x][y].xyz=1;
						sum++; 
					}
				}else{//旋转
					d=(d+1)%4;
				}
			}else if(d==3){ //向上 
				if (a[x-1][y].c!='x' && x-1>0){
					x--;
					if (a[x][y].xyz==0) {
						a[x][y].xyz=1;
						sum++; 
					}
				}else{//旋转 
					d=(d+1)%4;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
