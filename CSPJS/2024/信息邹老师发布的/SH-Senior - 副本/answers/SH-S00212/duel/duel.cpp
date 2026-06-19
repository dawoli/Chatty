#include<bits/stdc++.h>
using namespace std;
#define long long int
const int N=100050;

int main(){
	ifstream fin("duel1.in");
	ofstream fout("duel1.out");
	int n,r[N],rp[N]={0},gj[N]={0},ans=0,flag=0;
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>r[i];
		rp[r[i]]++;
		gj[r[i]]++;
	}
	for(int i=1;i<N;i++){
		if(rp[i]==0) continue;
		while(rp[i]>0){
			for(int j=i+1;j<=N;j++){
				if(gj[j]!=0){
					rp[i]--;
					gj[j]--;
					gj[i]--;
					break;
				}
			}
			if(rp[i]==flag) break;
			else flag=rp[i];
		}
	}
	for(int i=1;i<=N;i++){
		ans+=rp[i];
	}
	fout<<ans;
	fin.close();
	fout.close();
	return 0;
}
