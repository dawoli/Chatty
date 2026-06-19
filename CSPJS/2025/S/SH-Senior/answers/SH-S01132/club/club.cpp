#include<bits/stdc++.h>
using namespace std;
struct CLUB{
	long long cb_vl_1;
	long long cb_vl_2;
	long long cb_vl_3;
};
struct CHOOSE{
	long long ch_vl;
	long long ch_cb;
};
CLUB x[100009];
CHOOSE y[100009];
bool cmp(const CHOOSE &s1,const CHOOSE &s2){
	return s1.ch_vl<s2.ch_vl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long nn = 0;
	cin>>nn;
	for(long long ff = 1;ff<=nn;ff++){
		long long n = 0;
		long long m1 = 0;
		long long m2 = 0;
		long long m3 = 0;
		long long a = 0;
		cin>>n;
		for(long long f = 1;f<=n;f++){
			long long o = 0;
			cin>>x[f].cb_vl_1>>x[f].cb_vl_2>>x[f].cb_vl_3;
			o=max(max(x[f].cb_vl_1,x[f].cb_vl_2),x[f].cb_vl_3);
			a+=o;
			if(o==x[f].cb_vl_1){
				m1++;
				y[f].ch_cb=1;
				y[f].ch_vl=min(x[f].cb_vl_1-x[f].cb_vl_2,x[f].cb_vl_1-x[f].cb_vl_3);
			}else if(o==x[f].cb_vl_2){
				m2++;
				y[f].ch_cb=2;
				y[f].ch_vl=min(x[f].cb_vl_2-x[f].cb_vl_1,x[f].cb_vl_2-x[f].cb_vl_3);
			}else if(o==x[f].cb_vl_3){
				m3++;
				y[f].ch_cb=3;
				y[f].ch_vl=min(x[f].cb_vl_3-x[f].cb_vl_1,x[f].cb_vl_3-x[f].cb_vl_2);
			}
		}
		if(m1<=n/2&&m2<=n/2&&m3<=n/2){
			cout<<a<<endl;
		}else{
			sort(y+1,y+1+n,cmp);
			if(m1>n/2){//
				for(long long f = 1;f<=n;f++){
					if(m1==n/2){
						break;
					}
					if(y[f].ch_cb!=1){
						continue;
					}
					a-=y[f].ch_vl;
					m1--;
//					cout<<a<<" "<<m1<<endl;
				}
				cout<<a<<endl;
			}else if(m2>n/2){
				for(long long f = 1;f<=n;f++){
					if(m2==n/2){
						break;
					}
					if(y[f].ch_cb!=2){
						continue;
					}
					a-=y[f].ch_vl;
					m2--;
				}
				cout<<a<<endl;
			}else{
				for(long long f = 1;f<=n;f++){
					if(m3==n/2){
						break;
					}
					if(y[f].ch_cb!=3){
						continue;
					}
					a-=y[f].ch_vl;
					m3--;
				}
				cout<<a<<endl;
			}
		}
		for(long long f = 1;f<=n;f++){
			x[f].cb_vl_1=x[f].cb_vl_2=x[f].cb_vl_3=0;
			y[f].ch_cb=y[f].ch_vl=0;
		}
	}
	return 0;
};
