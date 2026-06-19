#include<bits/stdc++.h>
using namespace std;
int n,k,s[500005],b[500005],ans=0;
bool flag=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		if(s[i]>1) flag=false;
		b[i]=b[i-1]^s[i];
	}
	if(k==0 && flag){
		int x=0;
		for(int i=1;i<=n;i++){
		    if(s[i]==0){
		    	ans++;
		    	x=0;
			}
		    if(s[i]==1){
			    x++;
			    if(x==2){
			    	x=0;
			    	ans++;
				}
		    }
	    } 
	}
	else if(k==1 && flag){
		int x=0;
		for(int i=1;i<=n;i++){
		    if(s[i]==1){
			    ans++;
		    }
	    } 
	}
	else{
		int l=-1,r=-1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++){
			    if((b[i+j]^b[i-1])==k && (i>r || i+j<l)){
			    	if(l==-1 && r==-1){
			    		l=i;
			    		r=i+j;
					}
			    	else if(i>r) r=i+j;
			    	else l=i;
			    	ans+=1;
				}
		    } 
		}
	}
	printf("%d",ans);
	return 0;
} 
