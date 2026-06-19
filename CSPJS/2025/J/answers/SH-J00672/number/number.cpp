#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	cnt=s.size();
	for(int i=0,j=0;i<s.size();i++)
	{
		if(isdigit(s[i])){
			a[j]=s[i]-'0';
			j++;
		}else{
			cnt--;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}


