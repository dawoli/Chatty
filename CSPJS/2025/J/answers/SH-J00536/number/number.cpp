#include<bits/stdc++.h>
using namespace std;
#define ll long long
int num[1000010];
string s;
int id=0,ans=0;
int maxn=INT_MIN;

bool isnum(char a){
	if((int)a>=48 && (int)a<=57){
		return true;
	}
	return false;
}
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	ll l = s.size();
	for(int i=0;i<l;i++){
		if(isnum(s[i])) {
			num[id] = s[i]-'0';
			id++;
		}
	}
	
	sort(num,num+id,cmp);

	for(int i=0;i<id;i++) cout<<num[i];
	return 0;
}

