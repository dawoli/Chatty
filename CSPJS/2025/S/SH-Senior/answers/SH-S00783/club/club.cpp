#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,z,num1,num2,num3,num;
}k[111111];
bool cmp(node a,node b){
	if(a.num1==b.num1){
		return a.num>b.num;
	}
	return a.num1<b.num1;
}
int main(){
	freopen(" club.in","r",stdin);
	freopen(" club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long n,a[5][111111],ans=0,l2=0,l3=0,k1=0,k2=0,k3=0,f1=0,f2=0,f3=0;
		cin>>n;
		l2=n;
		l3=n;
		for(int i=0;i<n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			k[i].x=max(a[0][i],max(a[1][i],a[2][i]));
			k[i].z=min(a[0][i],min(a[1][i],a[2][i]));
			k[i].y=a[0][i]+a[1][i]+a[2][i]-k[i].x-k[i].z;
			if(k[i].x==a[0][i]){
				k[i].num1=0;
				if(k[i].z==a[1][i]){
					k[i].num2=2;
					k[i].num3=1;
				}
				else{
					k[i].num2=1;
					k[i].num3=2;
				}
			}
			else if(k[i].x==a[1][i]){
				k[i].num1=1;
				if(k[i].z==a[0][i]){
					k[i].num2=2;
					k[i].num3=0;
				}
				else{
					k[i].num2=0;
					k[i].num3=2;
				}
			}
			else{
				k[i].num1=2;
				if(k[i].z==a[1][i]){
					k[i].num2=0;
					k[i].num3=1;
				}
				else{
					k[i].num2=1;
					k[i].num3=0;
				}
			}
			k[i].num=k[i].x-k[i].y;
			ans+=k[i].x;
		}	
		sort(k,k+n,cmp);

		for(int i=0;i<n;i++){
			if(k[i].num1==0&& !f1){
				f1=1;
			}
			else if(k[i].num1==1&& !f2){
				f2=1;
				l2=i;
			}
			else if(k[i].num1==3&& !f3){
				f3=1;
				l3=i;
			}
			
			if(f1 && !f2) k1++;
			else if(f2 && !f3) k2++;
			else k3++;
			
		}	
		long long ma,w=n/2,r;
		ma=max(k1,max(k2,k3));
		if(ma>w){
			if(ma==k1){
				r=l2-1;
			}
			else if(ma==k2){
				r=l3-1;
			}
			else{
				r=n-1;
			}
			while(ma>w){
				ans-=k[r].num;
				r--;
				ma--;
			}
		}
		cout<<ans<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
