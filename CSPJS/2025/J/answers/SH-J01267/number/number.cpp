#include<bits/stdc++.h>
using namespace std;
string a;int num[19],cnt=0;
string ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.length()-1;i++){
		if(int(a[i]-'0')<=9 and int(a[i]-'0')>=0){
			num[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(1){
			if(num[i]<=0){
				break;
			}
			num[i]--;
			ans[cnt]=char(char(i)+'0');
			cnt++;
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<ans[i];
	}
	return 0;
}
