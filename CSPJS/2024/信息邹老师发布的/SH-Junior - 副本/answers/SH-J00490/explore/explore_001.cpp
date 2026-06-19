#include<bits/stdc++.h>
using namespace std;
bool isblank(int pos,char a,char b,char c,char d,int x,int y){
	if (pos==0){
		if(a=='.'){
			return 1;
		}else{
			return 0;
		}
	}else if (pos==1){
		if(b=='.'){
			return 1;
		}else{
			return 0;
		}
	}else if (pos==2){
		if(c=='.'){
			return 1;
		}else{
			return 0;
		}
	}else if (pos==3){
		if(d=='.'){
			return 1;
		}else{
			return 0;
		}
	}
}
int nextstepx(int s,int x){
	if (s==0){
		return x;
	}else if (s==1){
		return x+1;
	}else if (s==2){
		return x;
	}else if (s==3){
		return x-1;
	}
}
int nextstepy(int s,int y){
	if (s==0){
		return y+1;
	}else if (s==1){
		return y;
	}else if (s==2){
		return y-1;
	}else if (s==3){
		return y;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for (int sa=1;sa<=t;sa++){
		int goplace=1;
	    int n,m,k;
	    cin>>n>>m>>k;
	    int x,y,d;
	    cin>>x>>y>>d;
	    char a[n+1][m+1];
	    for (int i=1;i<=n;i++){
		    for (int j=1;j<=n;j++){
	            cin>>a[i][j];
	        }
	    }
	    for (int i=1;i<=k;i++){
		    if ( (( ( nextstepx(d,x)>=1 ) && ( nextstepx(d,x)<=n ) ) && ( ( nextstepy(d,y)>=1 )&&( nextstepy(d,y)<=m ) )) && (isblank(d,a[x][y+1],a[x+1][y],a[x][y-1],a[x-1][y],x,y)) ){
			    x=nextstepx(d,x);
			    y=nextstepy(d,y);
			    goplace++;
		    }else{
			    d=(d+1)%4;
		    }
	    }
	    cout<<goplace<<endl;
	} 
	return 0;        
}
