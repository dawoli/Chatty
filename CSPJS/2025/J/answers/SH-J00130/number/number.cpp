#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int num[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string str;
	cin>>str;
	int t,n=0;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9'){
			t=str[i]-'0';
			v.push_back(t);
			n++;
		}
	}
	for(int i=0;i<n;i++)
		num[i]=v[i];
	sort(num,num+n,cmp);
	for(int i=0;i<n;i++)
		cout<<num[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
