#include <iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	int fl=1;
	long long ji[15]={0};
	cin>>s;
	long long i=0;
	while(fl){
		//cin>>s;
		if(int(s[i])<48)break;
		if(int(s[i])>=48 &&int(s[i])<=57){
			ji[int(s[i])-48]++;
		}
		i++;
	}
	for(long long i=9;i>=0;i--){
		if(ji[i]){
			for(long long j=0;j<ji[i];j++){
				cout<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
