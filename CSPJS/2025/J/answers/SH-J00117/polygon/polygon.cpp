#include<bits/stdc++.h>
using namespace std;
int s[5005],ans=0;
//This program only aims to get partial marks and is incredibly inefficient.
int triangle(int a,int b,int c){
	//Sides already sorted
	if(a+b>c)
		return 1;
	return 0;
}
int quad(int a,int b,int c,int d){
	if(a+b+c>d)
		return 1;
	return 0;
}
int pent(int a,int b,int c,int d,int e){
	if(a+b+c+d>e)
		return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	int v=1,w=2,x=3,y=4,z=5;
	while(x<n){
		ans+=triangle(s[v],s[w],s[x]);
		x++; 
	}
	while(w<n-1){
		ans+=triangle(s[v],s[w],s[x]);
		w++;
	}
	while(v<=n-2){
		ans+=triangle(s[v],s[w],s[x]);
		v++;
	}
	v=1,w=2,x=3;
	while(y<n){
		ans+=quad(s[v],s[w],s[x],s[y]);
		y++;
	}
	while(x<n-1){
		ans+=quad(s[v],s[w],s[x],s[y]);
		x++;
	}
	while(w<n-2){
		ans+=quad(s[v],s[w],s[x],s[y]);
		w++;
	}
	while(v<=n-3){
		ans+=quad(s[v],s[w],s[x],s[y]);
		v++;
	}
	v=1,w=2,x=3,y=4;
	while(z<n){
		ans+=pent(s[v],s[w],s[x],s[y],s[z]);
		z++;
	}
	while(y<n-1){
		ans+=pent(s[v],s[w],s[x],s[y],s[z]);
		y++;
	}
	while(x<n-2){
		ans+=pent(s[v],s[w],s[x],s[y],s[z]);
		x++;
	}
		while(w<n-3){
		ans+=pent(s[v],s[w],s[x],s[y],s[z]);
		w++;
	}
	while(v<=n-4){
		ans+=pent(s[v],s[w],s[x],s[y],s[z]);
		v++;
	}
	cout<<ans;
	return 0;
}
