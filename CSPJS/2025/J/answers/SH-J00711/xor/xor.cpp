#include<bits/stdc++.h>
using namespace std;
long long n,k;
int y[20],z[20];
long long f(long long a,long long b){
	//cout<<"ok";
	int c1=0,c2=0;
	while(a>=1){
		y[++c1]=a%2;
		a/=2;
	}
	//for(int i=19;i>0;i--)cout<<y[i];
	//cout<<endl;
	while(b>=1){
		z[++c2]=b%2;
		b/=2;
	}
	//for(int i=19;i>0;i--)cout<<z[i];
	//cout<<endl;
	if(c2>c1)swap(c1,c2);
	for(int i=1;i<20;i++){
		if(y[i]!=z[i])y[i]=1;
		else y[i]=0;
	}
	//for(int i=19;i>0;i--)cout<<y[i];
	//cout<<endl<<c1<<endl;
	long long two=1,ans=y[1];
	for(int i=2;i<=c1;i++){
		two*=2;
		ans+=y[i]*two;
		//cout<<ans<<two<<y[20-i]<<i<<endl;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long a[n],l=0;
	bool b[n];
	memset(b,0,sizeof(b));
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			b[i]=1;
			l=i;
		}
		else if(i-1!=l&&i!=0){
			//cout<<"ok";
			long long x=f(a[i-1],a[i]);
			if(x==k){
				l=i;
				b[i]=1;
			}
			else{
				//cout<<x;
				for(long long j=i-2;j>=l+1&&j>=0;j--){
					if(f(x,a[j])==k){
						l=i;
						b[i]=1;
					}
				}
			}
			
		}
	}
	//for(int i=0;i<n;i++)cout<<b[i];
	long long ans=0;
	for(long long i=0;i<n;i++)if(b[i]==1)ans++;
	cout<<ans<<endl;
	return 0;
}
