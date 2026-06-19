#include<bits/stdc++.h>
using namespace std;
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m);
	int sum=0;
	for(int i=n*m;i>=1;i--){
		sum++;
		if(a[i]==x)break;
	}
	int ans1,ans2;//ans1为行，ans2为列 
	ans2=sum/n;
	if(sum%n!=0)ans2++;
	if(ans2%2==0){
		ans1=1+ans2*n-sum;
	}
	else ans1=n-(ans2*n-sum);
	cout<<ans2<<" "<<ans1;//先列后行 
	//#Shang4Shan3Ruo6Shui4
	return 0;
}
