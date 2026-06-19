#include<iostream>
using namespace std;
int main(){
	freopen("poker2.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=52;
	cin>>n;
	string s[55];
	for(int i=0;i<n;i++){
		cin>>s[i];
		int f=0;
		for(int j=0;j<i;j++){
			if(s[j]==s[i]){
				f=1;
				break;
			}
		}
		if(f==0)cnt--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
