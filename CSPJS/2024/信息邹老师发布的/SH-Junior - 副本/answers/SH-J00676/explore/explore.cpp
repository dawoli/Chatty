#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
long long n,m,k,t;
int f(int x,int y,int d,int s){
	if(k==0){
		return s;
	}
	if(t<=s){
		return t;
	}
	if(d==0){
		if(y+1>m||a[x][y+1]==1){
			d++;
			k--;
			return f(x,y,d,s);
		}else{
			if(a[x][y+1]==0)s++;
			k--;
			a[x][y+1]=-1;
			return f(x,y+1,d,s);
		}
	}
	if(d==1){
		if(x+1>n||a[x+1][y]==1){
			d++;
			k--;
			return f(x,y,d,s);
		}else{
			if(a[x+1][y]==0)s++;
			k--;
			a[x+1][y]=-1;
			return f(x+1,y,d,s);
		}
	}if(d==2){
		if(y-1<=0||a[x][y-1]==1){
			d++;
			k--;
			return f(x,y,d,s);
		}else{
			if(a[x][y-1]==0)s++;
			k--;
			a[x][y-1]=-1;
			return f(x,y-1,d,s);
		}
	}if(d==3){
		if(x-1<=0||a[x-1][y]==1){
			d=0;
			k--;
			return f(x,y,d,s);
		}else{
			if(a[x-1][y]==0)s++;
			k--;
			a[x-1][y]=-1;
			return f(x-1,y,d,s);
		}
	}
} 
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,x0,y0,d0;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				char r;
				cin>>r;
				if(r=='x')a[j][k]=1;
				else {
					a[j][k]=0;
					t++;
				}
			}
		}
		a[x0][y0]=-1;
		cout<<f(x0,y0,d0,1)<<endl;
	}
	return 0;
}


