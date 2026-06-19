# include <bits/stdc++.h>
using namespace std;//                           0      1      2       3       4       5       6       7       8       9
int a[10]={6,2,5,5,4,5,6,3,7,6};string b[100010]={     "-1",    "-1",    "1" ,    "7"  ,    "4"  ,    "2"  ,    "6"  ,    "8"  ,    "10" ,    "18" ,
                                               "33" ,   "20" ,   "28" ,   "68"  ,   "88"  ,   "108" ,   "188" ,   "200" ,   "208" ,   "288" ,
										      "688" ,  "888" ,  "1088",  "1888" ,  "2008" ,  "2088" ,  "2888" ,  "6888" ,  "8888" ,  "10888",
											 "18888", "20088", "20888", "28888" , "68888" , "88888" , "108888", "188888", "200888", "208888",
											"288888","688888","888888","1088888","1888888","2008888","2088888","2888888","6888888","8888888",
										   "1088888"};
bool c(string x,string y){
	if (x.length()<y.length()) return true;
	else if (x.length()>y.length()) return false;
	else{
		for (int i=0;i<x.length();i++){
			if (x[i]<y[i]) return true;
			else if (x[i]>y[i]) return false;
		}
		return false;
	}
}
string f(int n){
	string x=b[n-7],x2=b[n-6];
	string y=x+'8',y2;y2+=x2[0]+'0';
	for (int i=1;i<y2.length();i++){
		y2+=x[i];
	}
	if (c(y,y2)) return y;
	else return y2;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;cin >> t;
	for (int i=0;i<t;i++){
		int n;cin >> n;
		if (n<=50) cout << b[n] << endl;
		else cout << f(n) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
