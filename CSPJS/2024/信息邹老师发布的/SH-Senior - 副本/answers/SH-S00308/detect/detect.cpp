#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,T=0;
double L=0,V=0;
int s[100009];
int ans=0;
double d[100009],v[100009],a[100009],l[100009],r[100009];
double p[100009];
bool K[100009];
bool check(id,pid){
	if(d[id]>p[pid]){
		return false;
	}
	if(sqrt(v[id]*v[id]+2*a[id]*(p[pid]-d[id]))>V){
		return true;
	}
	else{
		return false;
	}
}
int search(tar){
	
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int ZZZZZ=0;ZZZZZ<T;ZZZZZ++){
		cin>>n>>m>>L>>V;
		for(int i=0;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=0;i<=m;i++){
			cin>>p[i];
		}
	}
	return 0;
} 
