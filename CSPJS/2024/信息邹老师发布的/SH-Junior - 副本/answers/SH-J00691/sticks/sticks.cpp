#include<bits/stdc++.h>
using namespace std;
int number[10]={6,2,5,5,4,5,6,3,7,6};
vector<long long> v;
long long ans;
string s;
int n; 
long long MIN;
long long cnt;
void trans(){
	for(int k=s.size()-1;k>=0;k--){
		ans=s[s.size()-k-1]*pow(10,k);
	}
	v[cnt++]=ans;
	return;
}
void d(int m){
	s="";
	cnt=0;
	if(m==2){
		s+='1';
		n-=2;
		if(n==1){
			s=""; return;
		}else if(n==0){
			trans(); return;
		}else{
			if(n<=7) for(int h=2;h<=n;h++) d(h);
			else for(int h=2;h<=7;h++) d(h);
		}
	}
	else if(m==3){
		s+='7';
		n-=3;
		if(n==1){
			s=""; return;
		}else if(n==0){
			trans(); return;
		}else{
			if(n<=7) for(int h=2;h<=n;h++) d(h);
			else for(int h=2;h<=7;h++) d(h);
		}
	}
	else if(m==4){
		s+='4';
		n-=4;
		if(n==1){
			s=""; return;
		}else if(n==0){
			trans(); return;
		}else{
			if(n<=7) for(int h=2;h<=n;h++) d(h);
			else for(int h=2;h<=7;h++) d(h);
		}
	}
	else if(m==5){
		for(int i=1;i<=3;i++){
			if(i==1){
				s+='2';
				n-=5;
				if(n==1){
					s=""; return;
				}else if(n==0){
					trans(); return;
				}else{
					if(n<=7) for(int h=2;h<=n;h++) d(h);
					else for(int h=2;h<=7;h++) d(h);
				}
			}
			if(i==2){
				s+='3';
				n-=5;
				if(n==1){
					s=""; return;
				}else if(n==0){
					trans(); return;
				}else{
					if(n<=7) for(int h=2;h<=n;h++) d(h);
					else for(int h=2;h<=7;h++) d(h);
				}
			}
			if(i==3){
				s+='5';
				n-=5;
				if(n==1){
					s=""; return;
				}else if(n==0){
					trans(); return;
				}else{
					if(n<=7) for(int h=2;h<=n;h++) d(h);
					else for(int h=2;h<=7;h++) d(h);
				}
			}
		}
	}else if(m==6){
		for(int i=1;i<=3;i++){
			if(i==1&&s!=""){
				s+='0';
				n-=6;
				if(n==1){
					s=""; return;
				}else if(n==0){
					trans(); return;
				}else{
					if(n<=7) for(int h=2;h<=n;h++) d(h);
					else for(int h=2;h<=7;h++) d(h);
				}
			}
			if(i==2){
				s+='6';
				n-=6;
				if(n==1){
					s=""; return;
				}else if(n==0){
					trans(); return;
				}else{
					if(n<=7) for(int h=2;h<=n;h++) d(h);
					else for(int h=2;h<=7;h++) d(h);
				}
			}
			if(i=3){
				s+='9';
				n-=6;
				if(n==1){
					s=""; return;
				}else if(n==0){
					trans(); return;
				}else{
					if(n<=7) for(int h=2;h<=n;h++) d(h);
					else for(int h=2;h<=7;h++) d(h);
				}
			}
		}
	}else{
		s+='8';
		n-=7;
		if(n==1){
			s=""; return;
		}else if(n==0){
			trans(); return;
		}else{
			if(n<=7) for(int h=2;h<=n;h++) d(h);
			else for(int h=2;h<=7;h++) d(h);
		}
	}
}
void min(){
	MIN=v[0];
	for(int q=0;q<v.size();q++){
		MIN=min(MIN,v[q]);
	}
}
void solve(){
	if(n<=7) for(int o=2;o<=n;o++) d(o);
	else for(int o=2;o<=7;o++) d(o);
	min();
}
void SV(){
	cin>>n;
	if(n<=1) cout<<-1;
	else{
		solve();
		cout<<MIN<<endl;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		SV(); 
	}
	return 0;
} 
