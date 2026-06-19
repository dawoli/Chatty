#include<bits/stdc++.h>
using namespace std;
const int KS=1e3+10;
bool a[KS][KS];
char c[KS][KS];
bool can(int x,int n){
	if(x>=1&&x<=n){
		return true;
	}
	return false;
}
void work(){
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,d;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
	        cin>>c[i][j];	
	    }
	}
	memset(a,0,sizeof(a));
	a[x][y]=true;
	for(int i=1;i<=k;i++){
        bool p=false;
		    int x1=x;
		    int y1=y;
		    if(d==0){
			    y1=y+1;
		    }else if(d==1){
			    x1=x+1;
		    }else if(d==2){
			    y1=y-1;
		    }else{
			    x1=x-1;
		    }
	        if(can(x1,n)&&can(y1,m)&&c[x1][y1]=='.'){
	    	    x=x1;
	    	    y=y1;
	     	    a[x][y]=true;
	    	    p=true;
		    }else{
		    d=(d+1)%4;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		    if(a[i][j]==true){
			    sum++;
			}
	    }
	}
	cout<<sum<<"\n";
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
    	work();
	}
	return 0;
}
