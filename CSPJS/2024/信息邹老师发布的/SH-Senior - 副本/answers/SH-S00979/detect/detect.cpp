#include<bits/stdc++.h>
using namespace std;

int T,n,M,l,v,p[100001],cs,a1,a2;
struct car{
	int d;
	int v;
	int a;
	int out;
	int m;
};
car a[100001];

int chao(car a){
	if(a.a==0){
		if(a.v>0)return a.out=1;
		else return a.out=0;
	}
	int vs2;
	if(a.a>0){
		if((pow(a.v,2)+2*a.a*p[M])<v)return a.out=0;
		else {
			return a.out=1;
			for(int i=1;i<=M;i++){
				vs2=pow(a.v,2)+2*a.a*p[M];
				if(vs2>v*v)return a.m=i;
			}
		}
	}
	if(a.a<0){
		if(a.v<v)return a.out=0;
		else{
			return a.out=1;
			for(int i=1;i<=M;i++){
				vs2=pow(a.v,2)+2*a.a*p[M];
				if(vs2<v*v)return a.m=i;
			}	
		}
	}
}


int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	cin>>n>>M>>l>>v;
	for(int i=1;i<=n;i++){
		cin>>a[i].d>>a[i].v>>a[i].a;
	}
	for(int i=1;i<=M;i++){
		cin>>p[i];
	}
	
	
	int f=0;
	for(int i=1;i<=n;i++){
		if(a[i].a!=0){f=1;break;}
		else if(a[i].v>v)cs++;
	}
	if(f==0){cout<<cs<<' '<<M-1;return 0;}
	
	
	for(int i=1;i<=n;i++){
		chao(a[i]);
	}
	
	for(int j=1;j<=M;j++){
		for(int i=1;i<=n;i++){
			if(a[i].out==0)break;
			else{
				a1++;
				if(a[i].a>0&&j<a[i].m)break;
				if(a[i].a<0&&j>=a[i].m)break;
			}
		a2++;
		}
	}

	cout<<a1<<' '<<M-a2;
	return 0;
}

