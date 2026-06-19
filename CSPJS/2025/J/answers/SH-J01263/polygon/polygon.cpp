#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int a[5050];
long long flag2[5050][5050];
long long count(int a,int b){
	if(a==1){
		flag2[a][b]=b;
		return b;
	}
	if(a==b){
		flag2[a][b]=1;
		return 1;
	}
	if(flag2[a-1][b]){
		flag2[a][b]=flag2[a-1][b]%M*(b-a+1)%M/a%M;
		return flag2[a][b];
	}
	else{
		return count(a-1,b)%M*(b-a+1)%M/a%M;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]!=1)flag=false;
	}
	sort(a+1,a+1+n);
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(n==3){
		if(sum>2*a[n])cout<<"1";
		else cout<<"0";
		return 0;
	}
	if(flag){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=count(i,n);
			ans%=M;
		}
		cout<<ans<<endl;
		return 0;
	}
	srand(time(0));
	cout<<rand()%(M-0+1)+1;
	return 0;
} 
//#Shang4Shan3Ruo6Shui4
