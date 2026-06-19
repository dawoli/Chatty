#include<bits/stdc++.h>
#define N 100009
#define M 100009
using namespace std;
int T,n,m,L,V;
int d[N],v[N],a[N];
int p[M]; 
bool ov[N];

void solveBF(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p[j]<d[i]) continue;
			
		}
	}
}

//void solveA(){
//	int cnt=0;
//	for(int i=1;i<=n;i++){
//		if(v[i]<=V) continue;
//		for(int j=1;j<=m;j++){
//			if(p[j]<d[i]) continue;
//			cnt++;
//		}
//	}
//	cout<<cnt<<" ";
//	
//	
//}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int a=1;a<=T;a++){
		bool flagA=true;
		
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0) flagA=false;
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		
//		if(flagA){
//			solveA();
//		}
		if(n<=20&&m<=20){
			solveBF();
		}
		
	}
	return 0;
} 
