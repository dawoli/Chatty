#include <fstream>
using namespace std;
ifstream fin("color.in");
ofstream fout("color.out");
const int maxn=2e5+5;
int n;
int a[maxn];
bool color[maxn];
bool have[maxn*5];
long long calc(){
	int r=-1,b=-1;
	long long ans=0;
	for (int i=0;i<n;i++){
		if (color[i]){
			if (r!=-1 and a[i]==a[r])
				ans+=a[i];
			r=i;
		}
		else{
			if (b!=-1 and a[i]==a[b])
				ans+=a[i];
			b=i;
		}
	}
	return ans;
}
long long dp(int digit){
	if (digit==n-1){
		color[digit]=0;
		long long ans1=calc();
		color[digit]=1;
		long long ans2=calc();
		return max(ans1,ans2); 
	}
	color[digit]=0;
	long long ans1=dp(digit+1);
	color[digit]=1;
	long long ans2=dp(digit+1);
	return max(ans1,ans2);
}
int main(){
	int T;
	fin >> T;
	while (T--){
		bool A=1;
		fin >> n;
		for (int i=0;i<n;i++){
			fin >> a[i];
			if (have[a[i]])
				A=0;
			else
				have[a[i]]=1;
		}
		if (A){
			for (int i=0;i<n;i++)
				have[a[i]]=0;
			fout << 0 << endl;
			break;
		}
		fout << dp(0) << endl;
	}
	return 0;
} 
