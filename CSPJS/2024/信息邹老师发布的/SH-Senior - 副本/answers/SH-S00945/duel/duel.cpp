#include<bits/stdc++.h>
using namespace std;
const int N = 100003;
int n,r[N],cnt;
bool beat[N];
void solveBF(){
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(r[i]!=r[j]&&!beat[j]){
				++cnt;
				beat[j] = 1;
			}
		}
	}
	cout<<n-cnt;
}
struct group{
	int val,cnt;
}g[N];
int cntg,cntAlive;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	//OK for every sample 
	//Dui Pai
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>r[i];
	sort(r+1,r+1+n);
	if(n<=30){
		solveBF();
		return 0;
	}
	for(int i = 1;i<=n;i++){
		if(r[i]==r[i-1]){
			g[cntg].cnt++;
		}
		else{
			g[++cntg].val = r[i];
			g[cntg].cnt = 1;
		}
	}
	cntAlive = 0;
	for(int i = 1;i<=cntg;i++){
		//beat
		if(cntAlive<=g[i].cnt){
			cntAlive = 0;
		}
		else{
			cntAlive-=g[i].cnt; 
		}
		//alive
		cntAlive+=g[i].cnt;
	}
	cout<<cntAlive;
	return 0;
}
