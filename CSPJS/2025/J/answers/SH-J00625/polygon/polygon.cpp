#include <iostream>
using namespace std;
long long num[5050];
long long trying=0;
long long Get[5050];
long long n;
long long f(long long n){
	long long ans=1;
	for(long long i=0;i<n;i++){
		ans=ans*2;
	}
	return ans;
}
bool bitRead(long long Read,long long bit){
	return (Read>>(bit))%2;
	
}
bool test(long long trying){
	//cout<<"testing"<<trying<<endl;
	long long sum=0;
	long long Max=-1;
	long long cnt=0;
	for(long long i=0;i<n;i++){
		if(bitRead(trying,i)){
			//cout<<num[i]<<" ";
			sum+=num[i];
			Max=max(Max,num[i]);
			cnt++;
		}
	}
	//cout<<endl;
	if(cnt<3){
		//cout<<"failed!cnt<3!"<<endl;
		return false;
	}
	if(sum<=2*Max){
		//cout<<"failed!"<<sum<<"<2*"<<Max<<endl;
		return false;
	}
	//cout<<"succeed!!!"<<endl;
	return true;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long ans=0;
	for(long long i=0;i<n;i++){
		cin>>num[i];
	}
	//cout<<"n="<<n;
	long long MAX=f(n);
	//cout<<"  MAX="<<MAX<<endl;
	for(;trying<MAX;){
		//cout<<trying<<"<"<<MAX<<"  ";
		if(test(trying)){
			ans=(ans+1)%998244353;
			//cout<<"ans="<<ans<<endl;
		}
		trying++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
