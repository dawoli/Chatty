#include <iostream>
using namespace std;
int num[1000001];

int cnt=0;

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int Size=s.size();
	for(int i=0;i<Size;i++){
		if(s[i]>=48&&s[i]<=57){
			num[cnt]=s[i]-48;
			cnt++;
		}
	}
	cnt--;
	bool Flag=false;
	while(!Flag){
		Flag=true;
		for(int i=0;i<cnt;i++){
			if(num[i]>num[i+1]){
				swap(num[i],num[i+1]);
				Flag=false;
			}
		}
	}
	for(int i=cnt;i>=0;i--){
		cout<<num[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
