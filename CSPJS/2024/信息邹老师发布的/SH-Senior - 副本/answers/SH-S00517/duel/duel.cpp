#include<iostream>
using namespace std;
int main(){ 
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int a[100005];
	int b[100005];
	int q=0;
	int p=0;
	int ans=0;
	int o=0;
	for(int i=0;i<n;i++){cin>>a[i];}
	for(int i=0;i<n;i++){for(int j=i;j<n;j++){if(a[j]<a[i]){p=a[i];a[i]=a[j];a[j]=p;}}}
	for(int i=0;i<100005;i++){b[i]=0;}
	for(int i=1;i<n;i++){if(a[i]!=a[i-1]){b[o]=i-q;q=i;o++;}b[o]=n-q;}
	for(int i=0;i<o;i++){if(b[i]>b[i+1]){ans+=b[i]-b[i+1];
	}}
	ans+=n-q;
	cout<<ans;
	return 0;
}

