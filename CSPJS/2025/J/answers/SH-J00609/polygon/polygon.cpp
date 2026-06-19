#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[n+1];
	int num=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		    for(int k=j+1;k<n;k++){
			    if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))num++;
	        }
	    }
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		    for(int k=j+1;k<n;k++){
			    for(int l=k+1;l<n;l++){
			        if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l]))))num++;
	            }
	        }
	    }
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		    for(int k=j+1;k<n;k++){
			    for(int l=k+1;l<n;l++){
			        for(int m=l+1;m<n;m++){
			            if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[m])))))num++;
	                }
	            }
	        }
	    }
	}
	cout<<num;
	return 0;
} 
