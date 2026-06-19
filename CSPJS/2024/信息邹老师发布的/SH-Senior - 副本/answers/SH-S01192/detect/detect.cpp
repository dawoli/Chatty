#include<bits/stdc++.h>
using namespace std;
int a;
int n,m,L,V;
struct sudu{
	int a,b,c;
	bool d;
}sudu[V];
int speed[V];
bool sudu(sudu d,int x){
	if(d.a<x)return 0;
	b=d.a*d.a+2*d.a*(x-d.c);
	if(d.a>x)return 1;
	return 0;
}
int main(){
	freopen("detect","r",stdin);
	freopen("detect","w",stdout)
	int K;
	sudu i;
	int chaosu=0;
	for(int i=0;i<n;i++){
		cin>>sudu.a>>sudu.b>>sudu.c>>sudu.d;
	}
	while(K--){
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;i++){
				bool sudu=0;
				chaosu++;
			}
		}
	}
	cout<<chaosu;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
