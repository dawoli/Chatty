#include<bits/stdc++.h>
using namespace std;
int d[100001],v[100001],a[100001],p[100001];
bool y[100001],h;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
    	int n,m,l,v1;
    	cin>>n>>m>>l>>v1;
    	for(int j=1;j<=n;j++){
    		cin>>d[i]>>v[i]>>a[i];
		}
		for(int k=1;k<=m;k++){
			cin>>p[i];
		}
		for(int f=m;f>0;f--){
		    if(v[f]<=v1&&a[f]<=0){
               y[f]=1;
		       h=1;	
		    }else{
		       h=0;
		    }
		    if(h==0){
			   cout<<i+1<<endl;
			   return 0;
		    }
	    }
	}
	return 0;
}
