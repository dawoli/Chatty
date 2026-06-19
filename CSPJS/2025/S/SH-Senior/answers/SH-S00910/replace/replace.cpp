#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int lena=a.length();
		int lenb=b.length();
		if(lena!=lenb){
			cout<<"0\n";
			continue;
		}
		int cnt=0;
		int num=0;
		for(int i=0;i<lena;i++){
			if(a[i]!=b[i]) num++;
		}
		for(int i=1;i<=n;i++){
			if((int)a.find(s1[i])>=0&&(int)a.find(s1[i])<lena&&(int)b.find(s2[i])>=0&&(int)b.find(s2[i])<=lenb&&(int)s1[i].length()>=num){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
