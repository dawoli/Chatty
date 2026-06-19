#include<bits/stdc++.h>
using namespace std;
string s;
long long sum;
int b[int(1e6+5)],t,k,k1;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[k1]=s[i]-48;
			t++;
			k1++;
		}
	}
	sort(b,b+t,cmp);
	for(int i=0;i<t;i++){
		if(i==0) sum+=b[i];
		else{
			for(int j=0;j<i;j++) b[i]*=10;
			sum+=b[i];
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
