#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[15],c=0;
	for(int i=0;i<10;i++)a[i]=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[int(s[i])-int('0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
