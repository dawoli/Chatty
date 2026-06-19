#include<bits/stdc++.h>
using namespace std;

string str;
long long a[100009];

bool cmp (int a, int b) {
	return a>b;
}

int main ()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	
	cin>>str;
	
	int temp=0;
	
	for (int i=0; i<str.size(); i++) {
		if (int(str[i])>=int('0')&&int(str[i])<=int('9')) {
			a[temp]=int(str[i])-int('0');
			temp++;
		}
	}
	
	sort (a,a+temp,cmp);
	
	for (int i=0; i<temp; i++) {
		cout<<a[i];
	}
	
	return 0;
}
