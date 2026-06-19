#include<bits/stdc++.h>
using namespace std;
struct C{
	int x,y,z,dir,maa;
}c[100001];
int ff(C a,C b){
	return a.maa>b.maa;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	int t,n,ans;
	C di[100001];
	cin>>t;
    for(int o=0;o<t;o++){
    	ans=0;
    	cin>>n;
    	int a1=n/2,b1=n/2,c1=n/2;
    	for(int i=0;i<n;i++){
    	int A,B,C;
    	cin>>A>>B>>C;
    	di[i].x=A,di[i].y=B,di[i].z=C;
    	c[i].x=A-B-C;
    	c[i].y=B-A-C;
    	c[i].z=C-B-A;
    	c[i].dir=i;
    	c[i].maa=max(c[i].x,max(c[i].y,c[i].z));
	}
		sort(c,c+n,ff);
		for(int i=0;i<n;i++){
		if(a1==0){
			int ma=max(c[i].y,c[i].z);
			if(ma==c[i].y){
			b1--;
			ans+=di[c[i].dir].y;
		}
			else if(ma==c[i].z){
			c1--;
			ans+=di[c[i].dir].z;
		}
			c[i].x=INT_MIN;
			c[i].y=INT_MIN;
			c[i].z=INT_MIN;
		}
		else if(b1==0){
				int ma=max(c[i].x,c[i].z);
			if(ma==c[i].x){
			a1--;
			ans+=di[c[i].dir].x;
		}
			else if(ma==c[i].z){
			c1--;
			ans+=di[c[i].dir].z;
		}
			c[i].x=INT_MIN;
			c[i].y=INT_MIN;
			c[i].z=INT_MIN;
		}
			else if(c1==0){
				int ma=max(c[i].x,c[i].y);
			if(ma==c[i].x){
			a1--;
			ans+=di[c[i].dir].x;
		}
			else if(ma==c[i].y){
			b1--;
			ans+=di[c[i].dir].y;
		}
			c[i].x=INT_MIN;
			c[i].y=INT_MIN;
			c[i].z=INT_MIN;
		}
		else{
		int ma=max(c[i].x,max(c[i].y,c[i].z));
		if(ma==c[i].x){
		a1--;
		ans+=di[c[i].dir].x;
	}
		else if(ma==c[i].y){
		b1--;
		ans+=di[c[i].dir].y;
	}
		else if(ma==c[i].z){
		c1--;
		ans+=di[c[i].dir].z;
	}
		c[i].x=INT_MIN;
		c[i].y=INT_MIN;
		c[i].z=INT_MIN;
	}

}
cout<<ans<<endl;
	}
	
	return 0;
}
