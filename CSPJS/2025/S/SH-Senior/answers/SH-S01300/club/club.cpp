#include<bits/stdc++.h>
using namespace std;
struct xx{
	int a;
	int b;
	bool operator>(const xx&y)const{
	return a>y.a;
}
};

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	int n=0;
	cin>>n;
	int a[100005]={0},b[100005]={0},c[100005]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int x=0,y=0,z=0;
	int zd=0;
	int cd=0;
	priority_queue<xx,vector<xx>,greater<xx> >chax;
	priority_queue<xx,vector<xx>,greater<xx> >chay;
	priority_queue<xx,vector<xx>,greater<xx> >chaz;
	int ans=0;
	for(int i=1;i<=n;i++){
		zd=max(a[i],max(b[i],c[i]));
		if(zd==a[i]){
			x++;
			cd=max(b[i],c[i]);
			chax.push({zd-cd,cd});
		}
		else if(zd==b[i]){
			y++;
			cd=max(a[i],c[i]);
			chay.push({zd-cd,cd});
		}
		else{
			z++;
			cd=max(a[i],b[i]);
			chaz.push({zd-cd,cd});
		}
	    ans+=zd;
	    if(x>n/2){
	    
	    	x--;
	    	ans-=chax.top().a;
	    	chax.pop();
		} 
		else if(y>n/2){
		
		y--;
			ans-=chay.top().a;
	    	chay.pop();
		}
		else if(z>n/2){
	
z--;
			ans-=chaz.top().a;
	    	chaz.pop();
		}

	}
	cout<<ans<<endl;
}
return 0;
}
