#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[100009],vst[100009],m[100009];
void pan(){
	ll t=a[1],j=1,sum=0;
	for(int i=2;i<=n;i++){
		if(t==a[i]){
			vst[j]++;	
			m[j]=t;		
		}
		else{
			t=a[i];
			j++;
			vst[j]++;
			m[j]=t;
		}
	}
	for(int i=1;i<=j;i++)
		if(vst[i]>=2)
			sum+=(vst[i]-1)*m[i];
	cout<<sum<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int hh=1;hh<=T;hh++){
		cin>>n;
		for(int i=1;i<=n;i++)
			vst[i]=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a,a+n+1);
		vst[1]=1;
		pan();	
	}
	return 0;
} 
