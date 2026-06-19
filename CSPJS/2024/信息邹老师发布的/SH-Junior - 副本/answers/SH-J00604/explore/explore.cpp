#include<bits/stdc++.h>
using namespace std;
char Map[1001][1001];
int t;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
	    int m,n,k,sx,sy,dir;
	    cin>>n>>m>>k>>sx>>sy>>dir;
	    for(int i=1;i<=m;i++)
	        for(int j=1;j<=n;j++)
	            cin>>Map[i][j];
	    if(k==1){
		    if(dir==0&&Map[sy+1][sx]=='.')
		        cout<<2<<endl;
		    else if(dir==2&&Map[sy-1][sx]=='.')
		        cout<<2<<endl;
		    else if(dir==1&&Map[sy][sx+1]=='.')
		        cout<<2<<endl;
		    else if(dir==1&&Map[sy][sx-1]=='.')
		        cout<<2<<endl;
		    else
			    cout<<1<<endl;
	    }
	    else if(n==1){
	    	int num=0;
	    	if(dir==0||dir==3){
	    		if(dir==3)
	    		    num++;
	    		if(k<sy-m)
	    		    num=num+k+1;
	    		else if(k<(sy-m)*2+2)
	    		    num=num+m-sy+1;
				else if(k<sy-1+sy-m+2)
				    num=num+k-(sy-m)+1;
				else
				    num=sy;
			}
			if(dir==1||dir==2){
	    		if(dir==1)
	    		    num++;
	    		if(k<m-sx)
	    		    num=num+k+1;
	    		else if(k<(m-sx)*2+2)
	    		    num=num+sx-m+1;
				else if(k<sy-1+m-sx+2)
				    num=num+k-(m-sx)+1;
				else
				    num=sy;
			}
			cout<<num;
		}
    } 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
