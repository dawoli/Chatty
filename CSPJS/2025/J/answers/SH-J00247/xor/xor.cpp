#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int x(int a, int b){
	int max1=1,sumx=0;
	bool a1=false,b1=false;
	if(a<b)swap(a,b);
	for(int i=1;i<a*4;i=i*2){
		max1++;
	}
	for(int i=pow(2,max1);i>=1;i=i/2){
		a1=false;
		b1=false;
		if(a>=i){
			a1=true;
			a=a-i;
		}
		if(b>=i){
			b1=true;
			b=b-i;
		}
		if((a1==true&&b1==false)||(a1==false&&b1==true))sumx=sumx+i;
	}
	return sumx;
}
int n,k,ans=0;
int a[500000];
void find_(int place, int block, int number, int use){
	number=x(number,a[place]);
	if(number==k)use++;
	if(place==n-1){
		ans=max(ans,use);
		return;
	}
	find_(place+1,block,number,use);
	find_(place+1,block+1,0,use);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	find_(0,1,0,0);
	cout<<ans;
	return 0;
}
