#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,q;
string str,str2;
string s3,s4;
int cnt;
int flag1[N],flag2[N],flag3,flag4;//前面有几个a，b的挪动 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str>>str2;
		int len=str.size();
		for(int j=0;j<len;j++){
			if(str[j]=='b'){
				flag1[i]=j;
				break;
			}
		}
		len=str2.size();
		for(int j=0;j<len;j++){
			if(str2[j]=='b'){
				flag2[i]=j;
				break;
			}
		}
	}
	while(q--){
		cnt=0;
		flag3=flag4=-1;
		cin>>s3>>s4;
		int len2=s3.size();
		for(int j=0;j<len2;j++){
			if(s3[j]=='b'){
				flag3=j;
				break;
			}
		}
		len2=s4.size();
		for(int j=0;j<len2;j++){
			if(s4[j]=='b'){
				flag4=j;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(flag1[j]-flag2[j]==flag3-flag4){
				if(flag1[j]<=flag3&&flag2[j]<=flag4){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
