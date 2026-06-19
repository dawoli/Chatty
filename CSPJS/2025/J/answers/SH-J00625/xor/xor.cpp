#include <iostream>
using namespace std;
long long num[1000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool specialA=true;
	int n;
	bool specialB=true;
	int sB=0;
	bool sBc1=false;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
		if(num[i]!=0){
			specialA=false;
		}if(num[i]!=0&&num[i]!=1){
			specialB=false;
		}
		if(num[i]==0){
			sB++;
			sBc1=false;
			//cout<<"sB++!"<<sB<<endl;
		}
		if(num[i]==1){
			if(sBc1){
				sB++;
				//cout<<"sB++!"<<sB<<endl;
			}
			sBc1=!sBc1;
		}
		
	}
	
	
	if(specialA){
		cout<<n/2;
		return 0;
	}
	if(specialB){
		cout<<sB;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
