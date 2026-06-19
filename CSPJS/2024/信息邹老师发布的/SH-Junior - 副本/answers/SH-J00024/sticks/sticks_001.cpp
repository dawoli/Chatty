#include <bits/stdc++.h>
using namespace std;

unsigned long long t,n,f[100005],w[15]={6,2,5,5,4,5,6,3,7,6};
//8 11 10 12 9 13 7 6 5 2 3 4 
string itoc(unsigned long long x){
	if(x==0) return "0";
	if(x==1) return "1";
	if(x==2) return "2";
	if(x==3) return "3";
	if(x==4) return "4";
	if(x==5) return "5";
	if(x==6) return "6";
	if(x==7) return "7";
	if(x==8) return "8";
	if(x==9) return "9";
}

void m(unsigned long long x){
	string s="";
	bool flag=false;
	while(x){
		s=itoc(x%10)+s;
		x/=10;
	}
	for(int i=0;i<s.size();i++){
		if(flag&&(s[i]=='6'||s[i]=='9')){
			s[i]='0';
		}
		if(!flag&&s[i]!='0') flag=true;
	}
	cout<<s.c_str()<<endl;
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		memset(f,0x3f3f3f3f,sizeof(f));
		f[0]=0;
		for(int i=1;i<=10;i++){
			bool flag=false;
			for(int j=w[i-1];j<=n;j++){
				if(min(f[j],f[j-w[i-1]]*10+i-1)==f[j-w[i-1]]*10+i-1){
					if(!flag){
						if(i==1) continue;
					}
				}
	            if(i!=1) flag=true;
				f[j]=min(f[j],f[j-w[i-1]]*10+i-1);
			}
		}
		if(f[n]==0x3f3f3f3f) cout<<-1<<endl;
		else m(f[n]);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
