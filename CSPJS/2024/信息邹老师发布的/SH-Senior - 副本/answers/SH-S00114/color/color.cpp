#include<iostream>
#include<cstdio>
using namespace std;
const int N=200020;
int n,arr[N],b1[N],b2[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>arr[i];
		int l1=1,l2=1;
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(arr[i]==arr[i-1]){
				ans+=arr[i];
				if(b1[l1]==arr[i-1])b1[++l1]=arr[i];
				else b2[++l2]=arr[i];
			}
			else{
				if(b1[l1]==arr[i-1]){
					b2[++l2]=arr[i];
					if(b2[l2]==b2[l2-1])ans+=b2[l2];
				}
				else{
					b1[++l1]=arr[i];
					if(b1[l1]==b1[l1-1])ans+=b1[l1]; 
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
