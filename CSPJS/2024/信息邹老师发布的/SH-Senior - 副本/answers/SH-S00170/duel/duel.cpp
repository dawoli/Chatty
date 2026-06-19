#include<bits/stdc++.h>
#define int long long
//#define fin std::cin
//#define fout std::cout
//DELETE!!DELETE!!FILE!!FILE!!
using std::ifstream;
using std::ofstream;
using std::sort;
using std::cerr;
ifstream fin("duel.in");
ofstream fout("duel.out");
const int maxn=100005;
int n;
int r[maxn];
bool ko[maxn];
bool valid[maxn];
signed main(){
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>r[i];
	}
	for(int i=0;i<n;i++) valid[i]=true;
	sort(r,r+n);
	for(int i=0;i<n;i++){
		//cerr<<"In i=["<<i<<"]:\n";
		//cerr<<"    ko[i]="<<ko[i]<<"\n";
		if(not ko[i]){
			int j=i;
			bool flag=true;
			while(flag){
				j++;
				if(j<n){
					if(r[j]>r[i] and valid[j]){
						valid[j]=false;
						break;
					}
				}
				else break;
			}
			//cerr<<"        j="<<j<<"\n";
			if(j<n) ko[i]=true;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(!ko[i]) ans++;
	}
	fout<<ans;
	return 0;
}
