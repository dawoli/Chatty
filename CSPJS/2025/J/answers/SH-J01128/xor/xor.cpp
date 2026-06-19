#include<bits/stdc++.h>
using namespace std;
int n,k,cnt3;
int a[500001];
int ki=1;
string to2(int n){
	string ans;
	while(n){
		ans+=n%2+'0';
		n/=2;
	}
	reverse(ans.begin(),ans.end());
}
string yh(string a,string b){
	string ans;
	if(a.size()>b.size())swap(a,b);
	for(int i=0;i<a.size();i++){
		int tmp=(a[i]-'0')^(b[i]-'0');
		ans+=char(tmp+'0');
	}
	for(int i=a.size();i<b.size();i++)ans+=b[i];
	return ans;
}
int to10(string s){
	int j=1,ans;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		ans+=(s[i]-'0')*j;
		j*=2;
	}
	return ans;
}
void ki3(int s1,int s2,string t1,string t2,int cnt){
	if(cnt>cnt3)cnt3=cnt;
	if(s1!=-1)t1=to2(a[s1]);t2=to2(a[s2]);
	string temp=yh(t1,t2);
	int dqz=to10(temp);
	if(dqz==k){
		cnt++;
		ki3(s1+2,s2+2,t1,t2,cnt);
	}
	else ki3(-1,s2+1,temp,t2,cnt);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0 && ki==1)ki=2;
		if(a[i]>1)ki=3;
	}
	if(ki==1)
		if(k==1){
			cout<<n<<endl;
		if(k==0)
			cout<<n/2<<endl;
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(ki==2){
		int cnt=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)cnt++;
				if(a[i]==1&&a[i+1]==1){
					cnt++;i++;
				}
			}
		}
		if(k==1){
			int c_1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	if(ki==3){
/*		string t1=to2(a[1]),t2=to2(a[2]);
		ki3(1,2,t1,t2,0);
		cout<<cnt3<<endl;*/
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
