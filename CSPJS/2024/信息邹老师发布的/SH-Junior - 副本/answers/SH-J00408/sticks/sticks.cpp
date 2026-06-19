#include<bits/stdc++.h>
#define N 200010
using namespace std;
typedef long long ll;
ll _,n;
void solveBF(){
	ll len=n+1;string Ans;
	for(int i=1;i<=n;++i)
		Ans+="9";
	for(int c6=0;c6<=1;++c6)
		for(int c8=0;c8*7+c6*6<=n;++c8)
			for(int c0=0;c0*6+c8*7+c6*6<=n;++c0)
				for(int c2=0;c2<=n;++c2){
					if(c2*5+c0*6+c8*7+c6*6>n)
						continue;
					for(int c4=0;c4<=n;++c4){
						if(c2*5+c0*6+c8*7+c6*6+c4*4>n)
							continue;
						for(int c7=0;c7<=n;++c7){
//							cout<<"\n";
							if(c2*5+c0*6+c8*7+c6*6+c4*4+c7*3>n)
								continue;
							if((n-(c2*5+c0*6+c8*7+c6*6+c4*4+c7*3))%2!=0)
								continue;
							
							ll c1=(n-(c2*5+c0*6+c8*7+c6*6+c4*4+c7*3))/2;
//							cout<<(c2*5+c0*6+c8*7+c6*6+c4*4+c7*3)<<"\n";
//							cout<<c0<<" "<<c2<<" "<<c4<<" "<<c6<<" "<<c7<<" "<<c8<<" "<<c1<<"\n";
							if(c1+c2+c4+c6+c7+c8==0) continue;
							if(c0+c1+c2+c4+c6+c7+c8>len) continue;
							else{string ans;ll r;
								if(c1) ans+="1",--c1,r=1;
								else if(c2) ans+="2",--c2,r=2;
								else if(c4) ans+="4",--c4,r=4;
								else if(c6) ans+="6",--c6,r=6;
								else if(c7) ans+="7",--c7,r=7;
								else if(c8) ans+="8",--c8,r=8;
								for(int i=1;i<=c0;++i)
									ans+="0";
								for(int i=1;i<=c1;++i)
									ans+="1";
								for(int i=1;i<=c2;++i)
									ans+="2";
								for(int i=1;i<=c4;++i)
									ans+="4";
								for(int i=1;i<=c6;++i)
									ans+="6";
								for(int i=1;i<=c7;++i)
									ans+="7";
								for(int i=1;i<=c8;++i)
									ans+="8";
//								cout<<ans<<" "<<Ans<<"\n";
								if((ll)ans.size()<len)
									Ans=ans;
								else if(ans<Ans&&len==(ll)ans.size()) Ans=ans;
								len=Ans.size();
								if(r==1) ++c1;
								if(r==2) ++c2;
								if(r==4) ++c4;
								if(r==6) ++c6;
								if(r==7) ++c7;
								if(r==8) ++c8;
							}
						}
					}
				}
	cout<<Ans;	
}
void solve7(){
	ll k=n/7;
	for(int i=1;i<=k;++i)
		cout<<"8";
}
void solve(){
	ll r=n,k=n/7-4;
	if(k>=0) n-=k*7;
	solveBF();
	for(int i=1;i<=k;++i)
		cout<<"8";
	n=r;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>_;n=0;
	while(_--){
		cin>>n;
		if(n==1){
			cout<<"-1"<<endl;
			continue;
		}
		if(n<=100) solveBF();
		else if(n%7==0) solve7();
		else solve();
		cout<<endl;
	}
	return 0;
}
