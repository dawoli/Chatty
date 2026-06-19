#include<bits/stdc++.h>
using namespace std;
const int N=505,Mod=998244353;
int n,m,c[N],a[N],cnt,t,v,ans;
string s;
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int x=n;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			a[++cnt]=c[i];
			t++;
			v++;
		}
		else{
			if(v>=c[i]){
				t++;
				a[x--]=c[i];
			}else{
				a[++cnt]=c[i];
			}
		}
	}
	//n-t为最多录取数
	if(n-t>=m)ans=1;
	else ans=0;
	ans*=(n-t)%Mod;
	for(int i=1;i<=n-m;i++){
		ans*=i;  
		ans%=Mod; 
	} 
	 
	cout<<ans<<endl;
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
