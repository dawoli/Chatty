#include<bits/stdc++.h> 
using namespace std;
int d[1000005],i,j;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	while(s[j]!=' '){
		if(s[j]-'0'>=0&&s[j]-'0'<=9){
			d[i]=s[j]-48;
			i++;
		}
		j++;
		if(j>=n)
			break;
	}
	sort(d,d+i,cmp);
	for(int z=0;z<i;z++)
		cout<<d[z];
	return 0;
}
