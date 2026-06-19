#include<fstream>
std::ifstream fin("detect.in");
std::ofstream fout("detect.out");
long long d[100005],v[100005],a[100005];
int main(){
	int t;
	fin>>t;
	long long car=0,ans;
	for(int i=0;i<t;i++){
		long long n,m,l,V;
		fin>>n>>m>>l>>V;
		ans=m-1;
		for(int j=0;j<n;j++){
			fin>>d[j]>>v[j]>>a[j];
			if(a[j]==0){
				if(v[j]>V) car++;
			}
		}
		long long last=0;
		for(int j=0;j<m;j++){
			long long p;
			fin>>p;
			last=p;
		}
		for(int j=0;j<n;j++){
			if(2*a[j]*(last-d[j])+v[j]*v[j]>V*V) car++;
		}
		fout<<car<<" "<<ans<<"\n";
	}
	return 0;
}
