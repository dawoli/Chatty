#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
string t1[N],t2[N];
vector<long long>sum[N][2];
vector<long long>sum2[N][2];
long long ans[N];
long long mod=1e9+7,flag=27;
int a[N],b[N];
int c[N],d[N],vis[N];
const int M=5e6+5;
long long flagg[M];
long long ask(int id,int l,int r,int op1,int op2){
	if(op1==1){
		long long v;
		if(l>=1)	v=sum[id][op2-1][r]-sum[id][op2-1][l-1]*flagg[r-l+1];
		else	v=sum[id][op2-1][r];
		v%=mod;
		v=(v+mod)%mod;
		return v;
	}
	else{
		long long v;
		if(l>=1)	v=sum2[id][op2-1][r]-sum2[id][op2-1][l-1]*flagg[r-l+1];
		else	v=sum2[id][op2-1][r];
		v%=mod;
		v=(v+mod)%mod;
		return v;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].length();j++){
			sum[i][0].push_back(0);
			sum[i][1].push_back(0);
		}
		for(int j=0;j<s1[i].length();j++){
			if(j!=0)	sum[i][0][j]=sum[i][0][j-1]*flag+(s1[i][j]-'a'+1);
			else	sum[i][0][j]=(s1[i][j]-'a'+1);
			sum[i][0][j]%=mod;
		}
		for(int j=0;j<s1[i].length();j++){
			if(j!=0)	sum[i][1][j]=sum[i][1][j-1]*flag+(s2[i][j]-'a'+1);
			else	sum[i][1][j]=(s2[i][j]-'a'+1);
			sum[i][1][j]%=mod;
		} 
	}
	//cout<<s1[3][0]<<" "<<s1[3][1]<<endl;
	//cout<<sum[3][0][0]<<" "<<sum[3][0][1]<<" "<<s1[3][1]-'a'+1<<endl;
	flagg[0]=1;
	for(int i=1;i<=5e6;i++){
		flagg[i]=flagg[i-1]*flag;
		flagg[i]%=mod;
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		for(int j=0;j<t1[i].length();j++){
			sum2[i][0].push_back(0);
			sum2[i][1].push_back(0);
		}
		for(int j=0;j<t1[i].length();j++){
			if(j!=0)	sum2[i][0][j]=sum2[i][0][j-1]*flag+(t1[i][j]-'a'+1);
			else	sum2[i][0][j]=(t1[i][j]-'a'+1);
			sum2[i][0][j]%=mod;
		}
		for(int j=0;j<t1[i].length();j++){
			if(j!=0)	sum2[i][1][j]=sum2[i][1][j-1]*flag+(t2[i][j]-'a'+1);
			else	sum2[i][1][j]=(t2[i][j]-'a'+1);
			sum2[i][1][j]%=mod;
		} 
	}
	for(int i=1;i<=n;i++){
		if(s1[i]==s2[i]){
			vis[i]=-1;
			continue;	
		}
		int ans1=0,ans2=0;
		for(int j=0;j<s1[i].length();j++){
			if(s1[i][j]==s2[i][j])	ans1++;
			else	break;
		}
		for(int j=s1[i].length()-1;j>=0;j--){
			if(s2[i][j]==s1[i][j])	ans2++;
			else	break;
		}
		a[i]=ans1,b[i]=ans2;
		//cout<<a[i]<<" "<<b[i]<<endl;
	}
	for(int i=1;i<=q;i++){
		for(int j=0;j<t1[i].length();j++){
			if(t1[i][j]==t2[i][j])	c[i]++;
			else	break;
		}
		for(int j=t1[i].length()-1;j>=0;j--){
			if(t1[i][j]==t2[i][j])	d[i]++;
			else	break;
		}
		//cout<<c[i]<<" "<<d[i]<<endl;
	}
	//cout<<t1[2].length()<<" "<<s1[1].length()<<" "<<(int)t1[2].length()-(int)s1[1].length()<<endl;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			//cout<<j<<" "<<t1[i].length()-s1[j].length()<<endl;
			if(vis[j]==-1)	continue;
			for(int z=0;z<=(int)t1[i].length()-(int)s1[j].length();z++){
				//cout<<"#"<<z<<endl;
				//if(j==1 && i==1 && z==0)	cout<<ask(i,z,z+s1[j].length()-1,2,2)<<" "<<ask(j,0,s1[j].length()-1,1,2)<<endl;
				if(ask(i,z,z+s1[j].length()-1,2,1)==ask(j,0,s1[j].length()-1,1,1) && ask(i,z,z+s1[j].length()-1,2,2)==ask(j,0,s1[j].length()-1,1,2) && c[i]>=z && t1[i].length()-d[i]-1<=z+s1[j].length()-1){
					ans[i]++;
				}
			}
		}
		cout<<ans[i]<<"\n";
	} 
	return 0;
} 
