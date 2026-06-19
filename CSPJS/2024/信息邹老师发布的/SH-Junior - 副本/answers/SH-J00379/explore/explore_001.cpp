#include <fstream>
long long T;
long long n,m,k;
long long x[1005],y[1005],d[1005];
char forest[1005][1005];
bool yesforest[1005][1005];
std::ifstream fin("explore.in");
std::ofstream fout("explore.out");
void secondmain(){
	fin>>n>>m>>k>>x[0]>>y[0]>>d[0];
	for(int i=1;i<=1004;i++){
		for(int j=1;j<=1004;j++){
			yesforest[i][j]=0;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			fin>>forest[i][j];
		}
	}
	for(long long i=1;i<=k;i++){
		long long x1,y1;
		if(d[i]==0)
			y1=y[i]+1;
		if(d[i]==2)
			y1=y[i]-1;
		if(d[i]==1)
			x1=x[i]+1;
		if(d[i]==3)
			x1=x[i]-1;
		if(1<=x1&&x1<=n&&1<=y1&&y1<=m&&forest[x1][y1]=='.')
		{
			x[i+1]=x1;
			y[i+1]=y1;
			yesforest[x1][y1]=1;
			fout<<"("<<x1<<","<<y1<<")"<<"\n";
		}
		else
		{
			d[i+1]=(d[i]+1)%4;
			x[i+1]=x[i];
			y[i+1]=y[i];
			fout<<"right"<<"\n";
		}
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(yesforest[i][j])
				ans++;
		}
	}
	fout<<ans<<"\n";
}
int main(){
	fin>>T;
	for(long long i=1;i<=T;i++){
		secondmain();
	}
	return 0;
}
