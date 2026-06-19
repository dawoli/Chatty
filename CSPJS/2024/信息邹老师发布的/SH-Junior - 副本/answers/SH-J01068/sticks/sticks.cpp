#include<bits/stdc++.h>
using namespace std;
long long n,i,t;
int a[15]={6,2,5,5,4,5,6,3,7,6};
long long stick(long long x){
	long long ans=0;
	while(x!=0){
		ans+=a[x%10];
		x/=10;
	}
	return ans;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int p=0;p<t;p++){
		i=1;
		cin>>n;
		if(n==1) cout<<-1<<endl;
		else{
			int st=0;
			while(st!=n){
				i++;
				st=stick(i);
			}
			cout<<i<<endl;
		}
	}
	return 0;
} 

