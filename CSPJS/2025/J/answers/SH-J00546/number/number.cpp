#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
long long ans,num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	long long j = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[j] = s[i]-'0';
			j++;
		}
	}
	sort(num,num+j,greater<long long>());
	for(long long i=0; i<j; i++)	cout << num[i];
	return 0;
}
