#include <iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0,len=0;
	len=s.length();
	char arr[len]={};
	for(int i=0;i<len;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			arr[cnt]=s[i];
			cnt++;
		}
	}
	int a,num=cnt;
	while(cnt>0){
		for(int i=0;i<cnt-1;i++){
			if(arr[i]<arr[i+1]){
				a=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=a;
			}
		}
		cnt--;
	}
	for(int i=0;i<num;i++){
		cout<<arr[i];
	}
	return 0;
} 
