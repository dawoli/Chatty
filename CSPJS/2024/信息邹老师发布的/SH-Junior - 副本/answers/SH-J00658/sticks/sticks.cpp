#include<iostream>
#include<algorithm>
using namespace std;
int t,n,ans;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int loc[6]={8,0,2,4,7,1};


int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		string a="";
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		if(n<=50){
			for(long long i=0;;i++){
				long long k=i;
				int sum=0;
				while(k){
					sum+=num[k%10];
					k/=10;
				}
				if(sum==n){
					cout<<i<<endl;
					break;
				}
			}
		}else {
			int p=0,f=1;
			char c[1000020]={},cnt=0;
			while(n){
				if(n<2) {
					if(n==0) break;
					n+=num[loc[p++]];
					if(p==6) {c[0]='-';break;}
					c[--cnt]=0;
				}
				c[cnt++]='0'+loc[p];
				n-=num[loc[p]];
			}
			sort(c,c+cnt);
			for(int i=0;i<cnt;i++) {
				if(c[i]!='0') {
					if(i>0) swap(c[0],c[i]);
					f=0;
					break;
				}
			}
			if(f) c[0]='6';
			for(int i=0;i<cnt;i++) cout<<c[i];
			cout<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
