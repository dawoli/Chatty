#include<bits/stdc++.h>
using namespace std;
const int N=509;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) ok=0;
	}
	int sub=0;
	int mx=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n;j++){
			sub=a[i]+a[j+1]+a[j];
			mx=max(a[i],max(a[j],a[j+1]));
			if(sub>2*mx) ans++;
		}
	}
	if(n>=4){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n-1;j++){
			sub=a[i]+a[j+1]+a[j]+a[j+2];
			mx=max(a[i],max(a[j],max(a[j+1],a[j+2])));
			if(sub>2*mx) ans++;
		}
	}
}
	if(n>=5){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n-2;j++){
			sub=a[i]+a[j+1]+a[j]+a[j+2]+a[j+3];
			mx=max(a[i],max(a[j],max(a[j+1],max(a[j+2],a[j+3]))));
			if(sub>2*mx) ans++;
		}
	}
}
	if(n>=6){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n-3;j++){
			sub=a[i]+a[j+1]+a[j]+a[j+2]+a[j+3]+a[j+4];
			mx=max(a[i],max(a[j],max(a[j+1],max(a[j+2],max(a[j+3],a[j+4])))));
			if(sub>2*mx) ans++;
		}
	}
}
	if(n>=7){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n-4;j++){
			sub=a[i]+a[j+1]+a[j]+a[j+2]+a[j+3]+a[j+4]+a[j+5];
			mx=max(a[i],max(a[j],max(a[j+1],max(a[j+2],max(a[j+3],max(a[j+4],a[j+5]))))));
			if(sub>2*mx) ans++;
		}
	}
}
	if(n>=8){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n-5;j++){
			sub=a[i]+a[j+1]+a[j]+a[j+2]+a[j+3]+a[j+4]+a[j+5]+a[j+6];
			mx=max(a[i],max(a[j],max(a[j+1],max(a[j+2],max(a[j+3],max(a[j+4],max(a[j+5],a[j+6])))))));
			if(sub>2*mx) ans++;
		}
	}
}
	if(n>=9){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n-6;j++){
			sub=a[i]+a[j+1]+a[j]+a[j+2]+a[j+3]+a[j+4]+a[j+5]+a[j+6]+a[j+7];
			mx=max(a[i],max(a[j],max(a[j+1],max(a[j+2],max(a[j+3],max(a[j+4],max(a[j+5],max(a[j+6],a[j+7]))))))));
			if(sub>2*mx) ans++;
		}
	}
}
	if(n>=9){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n-7;j++){
			sub=a[i]+a[j+1]+a[j]+a[j+2]+a[j+3]+a[j+4]+a[j+5]+a[j+6]+a[j+7]+a[j+8];
			mx=max(a[i],max(a[j],max(a[j+1],max(a[j+2],max(a[j+3],max(a[j+4],max(a[j+5],max(a[j+6],max(a[j+7],a[j+8])))))))));
			if(sub>2*mx) ans++;
		}
	}
}
	int ans1=0;
	if(ok){
		for(int i=1;i<=n;i++){
			ans1+=i;
		}
		cout<<ans1<<endl;
	}else{
		cout<<ans<<endl;
	}
	return 0;
}
