#include<fstream>
std::ifstream fin("color.in");
std::ofstream fout("color.out");
long long a[11][20];
long long co[11][20];
long long n,i,ans,ma;
void c(int order){
	if(order==n+1){
		long long last0=0,last1=0;
		for(int k=1;k<=n;k++){
			if(co[i][k]==0){
				if(a[i][k]==a[i][last0]) ans+=a[i][last0];
				last0=k;
			}
			if(co[i][k]==1){
				if(a[i][k]==a[i][last1]) ans+=a[i][k];
				last1=k;
			}
		}
		if(ma<ans) ma=ans;
		ans=0;
		return;
	}
	else{
		co[i][order]=0;
		c(order+1);
		co[i][order]=1;
		c(order+1);
	}
}
int main(){
	long long t;
	fin>>t;
	for(i=0;i<t;i++){
		fin>>n;
		for(int j=1;j<=n;j++){
			fin>>a[i][j];
		}
		c(1);
		fout<<ma<<"\n";
		ma=0;
		ans=0;
	}
	return 0;
}
