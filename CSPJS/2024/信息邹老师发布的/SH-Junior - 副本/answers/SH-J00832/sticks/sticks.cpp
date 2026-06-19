#include<bits/stdc++.h>
using namespace std;

int T,n,t,tt,i,c;
string s;
bool f[6][60];

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		i=0;
		if(n==1){
			cout<<"-1\n";
			continue;
		}
		if(n==2){
			cout<<"1\n";
			continue;
		}
		while(1){
			i++;
			t=i;
			c=0;
			while(t!=0){
				tt=t%10;
				if(tt==1) c+=2;
				if(tt==7) c+=3;
				if(tt==4) c+=4;
				if(tt==2||tt==3) c+=5;
				if(tt==0||tt==6||tt==9) c+=6;
				if(tt==8) c+=7;
				t/=10;
			}
			if(c==n){
				cout<<i<<"\n";
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

