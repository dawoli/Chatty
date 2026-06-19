#include<bits/stdc++.h>
using namespace std;

struct STRING{
	string str_s1;
	string str_s2;
};
STRING x[200009];
long long x_len[200009][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n = 0;
	long long m = 0;
	cin>>n>>m;
	for(long long f = 1;f<=n;f++){
		cin>>x[f].str_s1>>x[f].str_s2;
		x_len[f][0]=x[f].str_s1.length();
		x_len[f][1]=x[f].str_s2.length();
	}
	for(long long f = 1;f<=m;f++){
		string o1 = "";
		string o2 = "";
		cin>>o1>>o2;
		long long o_n = 0;
		string o_s1_dif = "";
		string o_s2_dif = "";
		long long s_p = 0;
		long long s_q = 0;
		long long a = 0;
		o_n=o1.length();
		if(o_n!=o2.length()){
			cout<<0<<endl;
			continue;
		}
		for(long long f = 0;f<o_n;f++){
			if(o1[f]!=o2[f]){
				s_p=f;
				break;
			}
		}
		for(long long f = o_n-1;f>=0;f--){
			if(o1[f]!=o2[f]){
				s_q=f;
				break;
			}
		}
		for(long long f = s_p;f<=s_q;f++){
			o_s1_dif+=o1[f];
			o_s2_dif+=o2[f];
		}
//		cout<<s_p<<" "<<s_q<<" "<<o_s1_dif<<" "<<o_s2_dif<<endl;
		//check x contain s1_dif?
		for(long long f1 = 1;f1<=n;f1++){
			if(x_len[f1][0]<s_q-s_p+1){
				continue;
			}
			for(long long f2 = 0;f2<x_len[f1][0];f2++){
				bool ok = 1;
				for(long long f3 = 0;f3<s_q-s_p+1;f3++){
					if(x[f1].str_s1[f2+f3]!=o_s1_dif[f3]){
						ok=0;
						break;
					}
				}
				if(ok==1){
					bool ok_2 = 1;
					for(long long f3 = f2;f3<f2+s_q-s_p+1;f3++){
						if(x[f1].str_s2[f3]!=o_s2_dif[f3-f2]){
							ok_2=0;
							break;
						}
					}
					if(ok_2==1){
						if(s_p>=f2&&x_len[f1][0]-(f2+s_q-s_p)<=o_n-s_q){
//							cout<<"YES:"<<f1<<" "<<f2<<endl;
							a++;
						}
					}
				}
			}
		}
		cout<<a<<endl;
	}
	return 0;
}
