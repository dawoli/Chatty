#include<bits/stdc++.h>
using namespace std;
int T,m,n,L,V,x,cnt,b[1000002],vis[1000002];
struct car{
	int d,v,ad,chao=0;
}a[1000002];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>L>>V;
		int dec=0;
		for(int j=1;j<=n;j++){
			cin>>a[j].d>>a[j].v>>a[j].ad;
		}
		for(int j=1;j<=m;j++){
			cin>>b[j];
		}
		for(int k=1;k<=n;k++){
			for(int j=1;j<=m;j++){
			    if(b[j]>=a[k].d&&(a[k].ad>=0||b[j]<=a[k].d-(a[k].v/a[k].ad))){
		    	    if(sqrt(a[k].v*a[k].v+2*(b[j]-a[k].d)*a[k].ad)>V){
		    	    	vis[j]++;
		    		    if(a[k].chao==0){
		    		     	cnt++;
		    		        a[k].chao=1;
					    }
				    }
			    }
		    }
	    }
	    for(int j=1;j<=m;j++){
	        if(vis[j]==0)dec++;
		}
		cout<<cnt<<" "<<dec<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
