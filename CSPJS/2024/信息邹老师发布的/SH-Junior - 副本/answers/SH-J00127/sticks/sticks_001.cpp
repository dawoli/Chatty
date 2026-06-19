#include<bits/stdc++.h>
using namespace std;
long long int n,eight_num,eight_pls,t,_cnt;
int _num[20001];
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(_num,0,sizeof(_num));
		_cnt=0;
		cin>>n;
		eight_num=n/7;
		eight_pls=n%7;
		if(n==1) {
			cout<<-1<<endl;
			continue;
		} else if(eight_pls==4) {
			for(int i=1; i<=eight_num-1; i++) {
				_num[i]=8;
			}
			_num[eight_num]=0;
			_num[eight_num+1]=2;
			_cnt=eight_num+1;
		} else if(eight_pls==2) {
			for(int i=1; i<=eight_num; i++) {
				_num[i]=8;
			}
			_num[eight_num+1]=1;
			_cnt=eight_num+1;
		} else if(eight_pls==1) {
			for(int i=1; i<=eight_num-1; i++) {
				_num[i]=8;
			}
			_num[eight_num]=0;
			_num[eight_num+1]=1;
			_cnt=eight_num+1;
		} else if(eight_pls==3) {
			for(int i=1; i<=eight_num; i++) {
				_num[i]=8;
			}
			_num[eight_num+1]=7;
			_cnt=eight_num+1;
		} else if(eight_pls==0) {
			for(int i=1; i<=eight_num; i++) {
				_num[i]=8;
			}
			_cnt=eight_num;
		} else if(eight_pls==5) {
			for(int i=1; i<=eight_num; i++) {
				_num[i]=8;
			}
			_num[eight_num+1]=2;
			_cnt=eight_num+1;
		} else {
			for(int i=1; i<=eight_num; i++) {
				_num[i]=8;
			}
			_num[eight_num+1]=6;
			_cnt=eight_num+1;
		}
		for(int i=_cnt; i>=1; i--) {
			cout<<_num[i];
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
