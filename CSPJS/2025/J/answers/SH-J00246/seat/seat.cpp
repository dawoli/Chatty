#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],c=1,r=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;a[i]!=b[1];i++){
		if(c&1){
			if(r==n)
				c++;
			else
				r++;
	    }
	    else{
	    	if(r==1)
	    		c++;
	    	else
	    		r--;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
