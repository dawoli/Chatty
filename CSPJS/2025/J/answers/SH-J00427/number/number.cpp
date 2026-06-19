#include <iostream>
#include <string>
std::string s;
long long a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]<=60){
			long long n=s[i]-48;
			a[n]++;
		}	
	}
	for(long long i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			std::cout << i;
		}
	}
	return 0;
}
