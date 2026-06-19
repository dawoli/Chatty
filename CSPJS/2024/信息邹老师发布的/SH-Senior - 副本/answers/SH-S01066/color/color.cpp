#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	long long T,n,cur,acur,dcur,st=0;
	long long vl=0;
	cin>>T;
	for(int e=0;e<T;e++){
		cin>>n;
		vl=0;
	    int list[n];
	    int color[n];
	    int val[n];
	    for(int i=0;i<n;i++){
	    	cin>>list[i];
	    	if(i==0){
	    	    color[i]=0;
		        continue;
		    };
	    	color[i]=1-color[i-1];
	    	st=cur=0;acur=dcur=0;
    		for(int j=i-1;j>=0;j--){
    			if(list[i]!=list[j]){
    			    if(color[j]!=color[i]){
    			    	if(list[acur]==list[j]&&acur-j>1) st+=val[j];
    			    	acur=j;
				    }//else{
				    	//if(list[dcur]==list[j]) st+=val[j];
    			    	//dcur=j;
					//}
				}else{
					if(st<list[i]+val[j]){
						for(int k=j+1;k<i;k++) color[k]=1-color[i];
						if(color[i]==color[j]){
						    vl+=list[i]-st;
						    val[i]=list[i];
						}else{
							for(int l=0;l<=j;l++) color[l]=1-color[l];
							vl+=list[i]-st;
						    val[i]=list[i];
						}
					};
					break;
				}
			}
	    };
	    cout<<vl<<endl;
	};
	fclose(stdin);
	fclose(stdout);
	return 0;
}
