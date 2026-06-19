#include<bits/stdc++.h> 
using namespace std;
int a[4];
int x[4];
int main(){
	long long t,n,b=0,c=0,ans=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int h[t-1];
	for(int z=0;z<t;z++){
		cin>>n;
		x[0] = 0;
		x[1] = 0;
		x[2] = 0;
		for(int y=0;y<n;y++){
			for(int i=0;i<=2;i++){
				cin>>a[i];
				if(a[i]>=b && x[i]<n/2){
					b=a[i];
					c=i;
				}
			}
			ans+=b;
			x[c]++;
			b = 0;
		}h[z] = ans;
		ans = 0;
	}for(int i=0;i<t;i++){
		cout<<h[i]<<endl;
	}
	return 0;
}
