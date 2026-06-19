#include<iostream>
using namespace std;
int t;
int n,m;
int k;
int x0,y0,d0;
int tmp_x,tmp_y;
int sum=0;
char mp[1010][1010];
void judge(){
	tmp_x=x0;
	tmp_y=y0;
	if(d0==0){
		tmp_y++;
	}
	if(d0==1){
		tmp_x++;
	}
	if(d0==2){
		tmp_y--;
	}
	if(d0==3){
		tmp_x--;
	}
	if(tmp_x<0 || tmp_x>=n || tmp_y<0 || tmp_y>=m || mp[tmp_x][tmp_y]=='x'){
		d0=(d0+1)%4;
	}else{
		x0=tmp_x;
		y0=tmp_y;
		if(mp[x0][y0]!='n'){
			sum++;
			mp[x0][y0]='n';
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		x0--;
		y0--;
		sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>mp[i][j];
			}
		}
		sum++;
		mp[x0][y0]='n';
		while(k--){
			judge();
		}
		cout<<sum<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
