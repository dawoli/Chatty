#include<bits/stdc++.h> 
using namespace std;
const int N=1050;
int n,k,temp;
int ks[N][N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(ks,0,sizeof(ks));
	for(int i=1;i<=n;i++){
		cin>>temp;
		ks[i][i]=temp;
		for(int j=1;j<i;j++){
			ks[j][i]=(ks[j][i-1]^temp);
		}
	}
	
	int re=0,last,tempcnt;
	for(int i=1;i<=n;i++){
		tempcnt=0;
		last=i;
		for(int j=1;j<=n;j++){
			if(ks[last][j]==k){
				tempcnt++;
				last=j+1;
			}
		}
		re=max(re,tempcnt);
	}
	cout<<re;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
