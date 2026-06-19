#include<fstream>
using namespace std;
ifstream fin("duel.in");
ofstream fout("duel.out");
int n;
int r[100005];
int cnt[100005];
int ans=0;
int main(){
	fin>>n;
	for(int i=0;i<n;i++)fin>>r[i];
	for(int i=0;i<n;i++)cnt[r[i]]++;
	for(int i=0;i<n;i++)ans=max(ans,cnt[r[i]]);
	fout<<ans<<endl;
	return 0;
} 
