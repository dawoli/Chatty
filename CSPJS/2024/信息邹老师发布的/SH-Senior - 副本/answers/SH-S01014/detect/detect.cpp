#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("detect.in");
ofstream fout("detect.out");
const int maxn=1e5+5;
long long d[maxn],v[maxn],a[maxn];
int p[maxn];
bool keep[maxn];
int main(){
	int T;
	fin >> T;
	while (T--){
		int n,m,L,V;
		bool A=1,B=1;
		fin >> n >> m >> L >> V;
		for (int i=0;i<n;i++){
			fin >> d[i] >> v[i] >> a[i];
			if (a[i]!=0)
				A=0;
			if (a[i]<=0)
				B=0;
		}
		for (int i=0;i<m;i++)
			fin >> p[i];
		int ans1=0,ans2=m;
		if (A){
			for (int i=0;i<n;i++)
				if (v[i]>V and d[i]<=p[m-1])
					ans1++;
			if (ans1!=0)
				ans2-=1;
		}
		else if (B){
			for (int i=0;i<n;i++)
				if (sqrt(v[i]*v[i]+a[i]*(p[m-1]-d[i])*2)>V and d[i]<=p[m-1])
					ans1++;
			if (ans1!=0)
				ans2-=1;
		}
		else{
			bool keep1=0,keep2=0;
			for (int i=0;i<n;i++){
				double speed1=-1,speed2=-1;
				for (int j=0;j<m;j++)
					if (p[j]>=d[i]){
						speed1=sqrt(v[i]*v[i]+a[i]*(p[j]-d[i])*2);
						break;
					}
				if (p[m-1]>=d[i])
					if (v[i]*v[i]+a[i]*(p[m-1]-d[i])*2>=0)
						speed2=sqrt(v[i]*v[i]+a[i]*(p[m-1]-d[i])*2);
				ans1++;
				if (speed1>V)
					keep1=1;
				else if (speed2>V)
					keep2=1;
				else
					ans1--;
			}
			ans2-=keep1+keep2;
		}
		fout << ans1 << " " << ans2 << endl;
	}
	return 0;
}
