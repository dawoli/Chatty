#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int num[1000005],sum=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'){
			sum++;
			num[sum]=s[i];
		}
	}
	sort(num+1,num+sum+1,cmp);
	for(int i=1;i<=sum;i++)cout<<num[i]-48;
	fclose(stdin); 
	fclose(stdout); 
	return 0;
}
