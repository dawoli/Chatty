#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using std::fstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::multimap;


int main(){
	fstream in("replace.in");
	std::ofstream out("replace.out");
	auto suffix=[](const string &a,const string &b)->bool{
		if(b.size()<a.size()) return a.compare(0,b.size(),b);
		else return b.compare(0,a.size(),a);  	
	};
	std::multimap<string,string,decltype(suffix)> a2b(suffix);
	int n,q; in>>n>>q;
	for(int i=0;i<n;++i){
		string a,b; in>>a>>b;
		a2b.emplace(a,b);
	}
	
	for(int i=0;i<q;++i){
		string t1,t2;
		int ans=0;
		in>>t1>>t2;
		int first=0;
		for(;first<t1.size();++first){
			if(t1[first]!=t2[first]) break;
		}
		int last=t1.size()-1;
		for(;last>=0;--last){
			if(t1[last]!=t2[last]) break;
		}
		++last;
		for(int i=0;i<=first;++i){
			auto s=a2b.equal_range(t1.substr(i,last-i)).first;
			auto e=a2b.equal_range(t1.substr(i,last-i)).second;
			for(;s!=e;++s){
				auto get=s->second;
				if(t2.substr(i,get.size()).compare(get)==0) ++ans;
			}	
		}
		out<<ans<<endl;
	}
	return 0;
	
}


