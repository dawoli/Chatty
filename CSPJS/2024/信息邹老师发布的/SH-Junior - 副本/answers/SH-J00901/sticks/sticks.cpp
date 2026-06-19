/*
SQRT ONE SHIFT EIGHT DOWN
TWO SEVEN EQUAL UP LEFT
SHIFT DOT LEFT LEFT RIGHT
FRACTION DELETE DELETE
DELETE RIGHT RIGHT SQRT
SHIFT SEVEN ONE ONE SHIFT
SEVEN TWO TWO SHIFT SEVEN
THREE THREE SHIFT SEVEN
FOUR FOUR RIGHT RIGHT
DELETE DELETE DELETE
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int f[N][N],n,fp[N][N];
int main(){
//	for(int i=1;i<=10000;i++)cout<<i<<" "; 
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(f,0x3f,sizeof f);
		memset(fp,0x3f,sizeof fp);
		cin>>n;
		for(int i=0;i<9;i++){
			if(f[1][a[i]]>1e9)f[1][a[i]]=i;
		}
		for(int i=1;i<9;i++){
			if(fp[1][a[i]]>1e9)fp[1][a[i]]=i;
		}
		if(fp[1][n]<1e9){
			cout<<fp[1][n]<<endl;
			continue;
		} 
		bool ok=0;
		int t=max(n/7-3,0);
		n-=7*t;
		for(int dg=2;dg<=n;dg++){
			for(int x=0;x<9;x++){
				for(int t=0;t+a[x]<=n;t++){
					if(f[dg-1][t]<1e9&&f[dg][t+a[x]]>1e9)f[dg][t+a[x]]=x;
				}
			}
			for(int x=1;x<9;x++){
				for(int t=0;t+a[x]<=n;t++){
					if(f[dg-1][t]<1e9&&fp[dg][t+a[x]]>1e9)fp[dg][t+a[x]]=x;
				}
			}
			if(fp[dg][n]<1e9){
				cout<<fp[dg][n];
//				cout<<dg<<fp[dg][n];
				int x=n-a[fp[dg][n]],d=dg-1;
				while(x){
//					cout<<" "<<x<<","<<f[d][x];
					cout<<f[d][x];
					x=x-a[f[d][x]];
					d--;
				}
				for(int i=1;i<=t;i++)cout<<8;
				cout<<endl;
				ok=1;
				break;
			}
//			cout<<fp[dg][n]<<endl;
		} 
//		cout<<"-";
		if(!ok){
			cout<<-1<<endl;
		}
	}
	return 0;
}
