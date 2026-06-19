#include <bits/stdc++.h> 
using namespace std;
int a[1000001],sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int f=s.length();
	for(int i=0;i<f;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+1+sum);
	for(int i=sum;i>=1;i--)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
}
 
