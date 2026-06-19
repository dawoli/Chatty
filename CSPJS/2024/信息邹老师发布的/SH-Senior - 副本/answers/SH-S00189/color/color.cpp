#include<bits/stdc++.h>
using namespace std;
void fre(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
}
long long a[200005],n;
int main(){
	fre();
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		long long ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n-1;i++){
			if(a[i]==a[i+1])ans+=a[i],i++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
