#include <bits/stdc++.h>
using namespace std;
string er(long long a){
	string m;
	while(a){
		m += (char)('0' + a%2);
		a/=2;
	}
	reverse(m.begin(),m.end());
	return m;
}
string huo(long long a,long long b){
	if(a<b){
		long long temp = a;
		a = b;
		b = temp;
	}
	//cout << a << b;
	string c,d;
	c = er(a);
	d = er(b);
	//cout << c << ' ' << d << endl;
	string s;
	long long x = c.length()-1,y = d.length()-1;
	//cout << d[0] << ' ' << c[0] << endl;
	//cout << x << ' ' << y << endl;
	for(long long i = 0;i <= y;i++){
		if(d[y-i] == '1' && c[x-i] == '1' || d[y-i] == '0' && c[x-i] == '0') s += '0';
		else s += '1';
		//cout << s << endl;
	}
	//cout << s << endl;
	reverse(s.begin(),s.end());
	//cout << c[0] << endl;
	if(c.length() > d.length())
		for(int i = 0;i < c.length()-d.length();i++)
			s = c[i] + s;
	return s;
}
long long cf(long long a,long long b){
	long long m = 1;
	for(int i = 0;i < b;i++)m *= a;
	//cout << m << endl;
	return m;
}
long long shi(long long c,long long d){
	string a = huo(c,d);
	long long m = 0;
	for(int i = 0;i < a.length();i++){
		//cout << a[a.length()-1-i] << ' ' << cf(2,i) << endl;;
		m += (a[a.length()-1-i]-'0') * cf(2,i);
		//cout << "m = " << m << endl;
	}
	//cout << m << endl;
	return m;
}
struct st{
	long long start;long long end;
};
int main(){
	//long long a = 1,b = 2,c = 2000;
	//cout << huo(5,8);
	//cout << shi(shi(1,2),0);
	long long n,k;
	cin >> n >> k;
	long long a[n];
	vector<st> l;
	for(int i = 0;i < n;i++) cin >> a[i];
	if(n == 1){
		if(a[0] == k){
			cout << 1;
			return 0;
		}
		else {
			cout << 0;
			return 0;
		}
	}
	if(n == 2){
		int ans = 0;
		for(int i = 0;i <= 1;i++){
			if(a[i] == k) ans++;
		}
		if(ans == 0){
			if(shi(a[0],a[1]) == k) ans++;
		}
		cout << ans;
		return 0;
	}
	for(int i = 0;i < n;i++){
		for(int j = i;j < n;j++){
			long long num = 0;
			if(i == j && a[i] == k){
				st o;
				o.start = i;
				o.end = j;
				l.push_back(o);
				continue;
			}
			for(int x = i;x <= j;x++){
				num = shi(num,a[x]);
				//cout << a[x] << ' ';
			}
			//cout << num << endl;
			if(num == k){
				//cout << endl << i << ' ' << j << "yes" << endl;;
				st o;
				o.start = i;
				o.end = j;
				l.push_back(o);
			}
		}
	}
	/*for(int i = 0;i < l.size();i++)
		cout << l[i].start << ' ' << l[i].end << endl;*/
	long long ans = 1;
	for(int i = 1;i < l.size();i++){
		if(l[i].start >= l[i-1].end) ans++;
	}
	cout << ans;
	return 0;
}
