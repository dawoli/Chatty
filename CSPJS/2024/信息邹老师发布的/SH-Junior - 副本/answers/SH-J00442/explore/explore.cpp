#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	int t,sum=1;
	int x,y,d,n,m,k;
	int x1,y1;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
	   cin>>n>>m>>k;
	   cin>>x>>y>>d;
	   char a[n][m];
	   for(int j=1;j<=n;j++){
	   
	       for(int z=1;z<=m;z++){
		   cin>>a[j][z];
	        }
	    }

    for(int i=1;i<=k;i++){
    	if(d==0){
    		x1=x;
    		y1=y+1;
    		if(y1>m || a[x1][y1]==x){
    			d=(d+1)%4;
			}
			else{
				x=x1;
				y=y1;
				sum+=1;
			}
		}
		if(d==1){
    		x1=x+1;
    		y1=y;
    		if(x1>n||a[x1][y1]==x){
    			d=(d+1)%4;
			}
			else{
				x=x1;
				y=y1;
				sum+=1;
			}
		}
		if(d==2){
    		x1=x;
    		y1=y-1;
    		if(y1<1||a[x1][y1]==x){
    			d=(d+1)%4;
			}
			else{
				x=x1;
				y=y1;
				sum+=1;
			}
		}
		if(d==3){
    		x1=x-1;
    		y1=y;
    		if(x1<1||a[x1][y1]==x){
    			d=(d+1)%4;
			}
			else{
				x=x1;
				y=y1;
				sum+=1;
			    }
		    }
	    }
	cout<<sum-1<<endl;   
    }
    fclose(stdin);
    fclose(stdout);
     
	
	return 0;
}
