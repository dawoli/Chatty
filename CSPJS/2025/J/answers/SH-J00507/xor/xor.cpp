#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,k;
int a[200005];
string sk;

string turn(int a){
	string sum="";
	while(a){
		sum+=(a%2)+'0';
		a/=2;
	}
	reverse(sum.begin(),sum.end());
	if(sum!="") return sum;
	else return "0";
}

string cal(string a,string b){
	string sum="";
	int lena=a.length();
	int lenb=b.length();
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	if(lena>lenb) sum=a;
	else sum=b;
	for(int i=0;i<min(lena,lenb);i++){
		if((a[i]=='0' && b[i]=='0')||(a[i]=='1' && b[i]=='1')) sum[i]='0';
		else sum[i]='1';
	}
	reverse(sum.begin(),sum.end());
	return sum;
}

void dfs(int x,string sum,int cnt){
	if(x>n){
		if(sum==sk) ans=max(ans,(cnt+1)*1ll);
		if(sum=="") ans=max(ans,1ll*cnt);
		return;
	}
	if(sum==""){
		dfs(x+1,turn(a[x]),cnt);
		dfs(x+1,"",cnt);
	}
	if(sum==sk){
		dfs(x+1,turn(a[x]),cnt+1);
		dfs(x+1,"",cnt+1);
	} 
	dfs(x+1,cal(sum,turn(a[x])),cnt);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	sk=turn(k);
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(k==0 && flag){
		cout<<n/2<<endl;
		return 0;
	}
	dfs(1,"",0);
	cout<<ans<<endl;
	return 0;
}
