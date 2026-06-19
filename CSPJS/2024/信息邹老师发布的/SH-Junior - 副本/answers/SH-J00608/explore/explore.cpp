#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("explore.in","r",stdin);
	//freopen("explore.out","w",stdout);
	int f,x,y,p,q,c,n;
	cin>>n;
	while(cin>>x>>y>>c>>p>>q>>f;){
	    char a[x][y];
	    for (int i=0;i<x;i++){
    		for (int j=0;j<y;j++){
    			cin>>a[i][j];
    		}
    	}
      	int s=0;
    	for (int i=0;i<c;i++){
    		if(c==0){
    		    if (a[p][q+1]=='x'){
    		    	c=1;
    			}
    			else{
    				q++;
    				s++;
    			}
    	    }
    	    else if(c==1){
    		    if (a[p-1][q]=='x'){
    		    	c=2;
    			}
    			else{
    				p--;
    				s++;
    			}
    	    }
    	    else if(c==2){
    		    if (a[p][q-1]=='x'){
    		    	c=3;
    			}
    			else{
    				q--;
    				s++;
    			}
    	    }
    	    else if(c==3){
    		    if (a[p++][q]=='x'){
    		    	c=0;
    			}
    			else{
    				p++;
    				s++;
    			}
    	    }
    	}
    	cout<<s;
    	}
	
	
	return 0;
} 
