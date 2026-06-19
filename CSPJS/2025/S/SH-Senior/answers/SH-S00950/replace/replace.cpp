#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n,q;
string l[200005];
int noob_hash[22114518];
string k[5000005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> l[2*i-1] >> l[2*i];
		long long p=0;
		int m=0;
		for(m=0;m<l[2*i-1].length();m++){
			if(l[2*i-1][m]!=l[2*i][m])break;
		}
		for(int j=m;j<l[2*i-1].length();j++){
			p+=(j-m+13)*((l[2*i-1][j]*l[2*i-1][j]-13*l[2*i-1][j]+114514)-(l[2*i][j]*l[2*i][j]-13*l[2*i][j]+114514));
		}
		if(p<=0)p+=(long long)22114513000; 
		noob_hash[p%22114513]++;
	}
	for(int i=1;i<=q;i++){
		cin >> k[2*i-1] >> k[2*i];
		if(k[2*i-1].length()!=k[2*i].length()){
			cout << 0 << endl;
			continue;
		}
		long long p=0;
		int j=0;
		int m=0;
		for(m=0;m<k[2*i-1].length();m++){
			if(k[2*i-1][m]!=k[2*i][m])break;
		}
		for(int j=m;j<k[2*i-1].length();j++){
			p+=(j-m+13)*((k[2*i-1][j]*k[2*i-1][j]-13*k[2*i-1][j]+114514)-(k[2*i][j]*k[2*i][j]-13*k[2*i][j]+114514));
		}
		if(p<=0)p+=(long long)22114513000; 
		cout << noob_hash[p%22114513] << endl;
	}
	
	
	return 0;
}
