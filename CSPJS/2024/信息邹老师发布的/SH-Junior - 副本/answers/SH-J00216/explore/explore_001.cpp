#include<iostream>
#include<cstdio>
bool c[1001][1001];
bool v[1001][1001];
int n,m,k,x0,y0,d0;
bool check(int x,int y){
	if(x<=0||x>n||y<=0||y>m)return false;
	else if(c[x][y])return true;
	else return false;
} 
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	std::cin>>t;
	for(int d=0;d<t;d++){
		std::cin>>n>>m>>k>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			std::string s;
			std::cin>>s;
			for(int j=0;j<m;j++){
				char x=s[j];
				if(x=='.')c[i][j+1]=1;
				else c[i][j+1]=0;
				v[i][j+1]=0;
			}
		}
		long long sum=1;v[x0][y0]=1;
		for(int i=0;i<k;i++){
			int nx,ny;
			if(d0==0){
				nx=x0;
				ny=y0+1;
			}
			else if(d0==1){
				nx=x0+1;
				ny=y0;
			}
			else if(d0==2){
				nx=x0;
				ny=y0-1;
			}
			else{
				nx=x0-1;
				ny=y0;
			}
			if(check(nx,ny)){
				x0=nx;
				y0=ny;
				if(v[x0][y0]==0)sum++;
				v[x0][y0]=1;
			}
			else d0=(d0+1)%4;
		}
		std::cout<<sum<<"\n";
	}
	return 0;
}
