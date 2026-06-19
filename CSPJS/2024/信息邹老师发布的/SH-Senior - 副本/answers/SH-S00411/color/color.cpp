#include<fstream>
using namespace std;
ifstream fin("color.in");
ofstream fout("color.out");
int T;
int n;
long long a[200005];
long long sum[200005];
int pre[200005];
int now[1000005];
long long f[200005];
int main(){
	fin>>T;
	for(int testcaseid=0;testcaseid<T;testcaseid++){
		fin>>n;
		for(int i=0;i<n;i++)fin>>a[i];
		for(int i=0;i<=1000000;i++)now[i]=-1;
		for(int i=0;i<n;i++)pre[i]=now[a[i]],now[a[i]]=i;
		sum[0]=0;
		for(int i=1;i<n;i++)sum[i]=sum[i-1]+a[i]*(a[i]==a[i-1]);
		f[0]=0;
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1])f[i]=f[i-1]+a[i];
			else if(pre[i]==-1)f[i]=f[i-1];
			else f[i]=max(f[i-1],f[pre[i]+1]+sum[i-1]-sum[pre[i]+1]+a[i]);
		}
		fout<<f[n-1]<<endl;
	}
	return 0;
}
