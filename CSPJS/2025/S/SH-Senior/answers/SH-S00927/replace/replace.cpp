#include<bits/stdc++.h>
using namespace std;

struct stringpairint
{
	string str;
	int int_;
	bool operator==(const string& s)
	{
		return str==s;
	}
} g[100001];

string s1[100001],s2[100001],t1,t2;
int u;
int n,q;
int a[26];
int b[26][26];
int c[26][26][26];
int d[26][26][26][26];
int e[26][26][26][26][26];
int f[26][26][26][26][26][26];
int gmax;

inline void tr(int i,int j)
{
	string s1_=s1[i],s2_=s2[i],t1_=t1;
	int len=s1_.length();
	for(int i=0;i<len;i++)
	{
		t1_[j+i]=s2_[i];
	}
	if(t1_==t2) u++;
}

inline void tr(stringpairint* i,int j)
{
	if(i) tr(i->int_,j);
}

int main()
{
	ifstream in("replace.in");
	ofstream out("replace.out");
	in>>n>>q;
	for(int i=1;i<=n;i++)
	{
		in>>s1[i]>>s2[i];
		if(s1[i].length()==1) a[s1[i][0]-'a']=i;
		if(s1[i].length()==2) b[s1[i][0]-'a'][s1[i][1]-'a']=i;
		if(s1[i].length()==3) c[s1[i][0]-'a'][s1[i][1]-'a'][s1[i][2]-'a']=i;
		if(s1[i].length()==4) d[s1[i][0]-'a'][s1[i][1]-'a'][s1[i][2]-'a'][s1[i][3]-'a']=i;
		if(s1[i].length()==5) e[s1[i][0]-'a'][s1[i][1]-'a'][s1[i][2]-'a'][s1[i][3]-'a'][s1[i][4]-'a']=i;
		if(s1[i].length()==6) f[s1[i][0]-'a'][s1[i][1]-'a'][s1[i][2]-'a'][s1[i][3]-'a'][s1[i][4]-'a'][s1[i][5]-'a']=i;
		if(s1[i].length()>6)
		{
			g[gmax].str=s1[i];
			g[gmax].int_=i;
		}
	}
	for(int i=0;i<q;i++)
	{
		in>>t1>>t2;
		u=0;
		for(int j=0;j<t1.length();j++)
		{
			if(t1.length()-j>=1) tr(a[t1[j+0]-'a'],j);
			if(t1.length()-j>=2) tr(b[t1[j+0]-'a'][t1[j+1]-'a'],j);
			if(t1.length()-j>=3) tr(c[t1[j+0]-'a'][t1[j+1]-'a'][t1[j+2]-'a'],j);
			if(t1.length()-j>=4) tr(d[t1[j+0]-'a'][t1[j+1]-'a'][t1[j+2]-'a'][t1[j+3]-'a'],j);
			if(t1.length()-j>=5) tr(e[t1[j+0]-'a'][t1[j+1]-'a'][t1[j+2]-'a'][t1[j+3]-'a'][t1[j+4]-'a'],j);
			if(t1.length()-j>=6) tr(f[t1[j+0]-'a'][t1[j+1]-'a'][t1[j+2]-'a'][t1[j+3]-'a'][t1[j+4]-'a'][t1[j+5]-'a'],j);
			if(t1.length()-j>=7) tr(find(g,g+gmax,t1.substr(j,7)),j);
			if(t1.length()-j>=8) tr(find(g,g+gmax,t1.substr(j,8)),j);
			if(t1.length()-j>=9) tr(find(g,g+gmax,t1.substr(j,9)),j);
			if(t1.length()-j>=10) tr(find(g,g+gmax,t1.substr(j,10)),j);
			if(t1.length()-j>=11) tr(find(g,g+gmax,t1.substr(j,11)),j);
			if(t1.length()-j>=12) tr(find(g,g+gmax,t1.substr(j,12)),j);
			if(t1.length()-j>=13) tr(find(g,g+gmax,t1.substr(j,13)),j);
			if(t1.length()-j>=14) tr(find(g,g+gmax,t1.substr(j,14)),j);
			if(t1.length()-j>=15) tr(find(g,g+gmax,t1.substr(j,15)),j);
			if(t1.length()-j>=16) tr(find(g,g+gmax,t1.substr(j,16)),j);
			if(t1.length()-j>=17) tr(find(g,g+gmax,t1.substr(j,17)),j);
			if(t1.length()-j>=18) tr(find(g,g+gmax,t1.substr(j,18)),j);
			if(t1.length()-j>=19) tr(find(g,g+gmax,t1.substr(j,19)),j);
			if(t1.length()-j>=20) tr(find(g,g+gmax,t1.substr(j,20)),j);
			if(t1.length()-j>=21) tr(find(g,g+gmax,t1.substr(j,21)),j);
			if(t1.length()-j>=22) tr(find(g,g+gmax,t1.substr(j,22)),j);
			if(t1.length()-j>=23) tr(find(g,g+gmax,t1.substr(j,23)),j);
			if(t1.length()-j>=24) tr(find(g,g+gmax,t1.substr(j,24)),j);
			if(t1.length()-j>=25) tr(find(g,g+gmax,t1.substr(j,25)),j);
			if(t1.length()-j>=26) tr(find(g,g+gmax,t1.substr(j,26)),j);
			if(t1.length()-j>=27) tr(find(g,g+gmax,t1.substr(j,27)),j);
			if(t1.length()-j>=28) tr(find(g,g+gmax,t1.substr(j,28)),j);
			if(t1.length()-j>=29) tr(find(g,g+gmax,t1.substr(j,29)),j);
			if(t1.length()-j>=30) tr(find(g,g+gmax,t1.substr(j,30)),j);
			if(t1.length()-j>=31) tr(find(g,g+gmax,t1.substr(j,31)),j);
			if(t1.length()-j>=32) tr(find(g,g+gmax,t1.substr(j,32)),j);
			if(t1.length()-j>=33) tr(find(g,g+gmax,t1.substr(j,33)),j);
			if(t1.length()-j>=34) tr(find(g,g+gmax,t1.substr(j,34)),j);
			if(t1.length()-j>=35) tr(find(g,g+gmax,t1.substr(j,35)),j);
			if(t1.length()-j>=36) tr(find(g,g+gmax,t1.substr(j,36)),j);
			if(t1.length()-j>=37) tr(find(g,g+gmax,t1.substr(j,37)),j);
			if(t1.length()-j>=38) tr(find(g,g+gmax,t1.substr(j,38)),j);
			if(t1.length()-j>=39) tr(find(g,g+gmax,t1.substr(j,39)),j);
			if(t1.length()-j>=40) tr(find(g,g+gmax,t1.substr(j,40)),j);
			if(t1.length()-j>=41) tr(find(g,g+gmax,t1.substr(j,41)),j);
			if(t1.length()-j>=42) tr(find(g,g+gmax,t1.substr(j,42)),j);
			if(t1.length()-j>=43) tr(find(g,g+gmax,t1.substr(j,43)),j);
			if(t1.length()-j>=44) tr(find(g,g+gmax,t1.substr(j,44)),j);
			if(t1.length()-j>=45) tr(find(g,g+gmax,t1.substr(j,45)),j);
			if(t1.length()-j>=46) tr(find(g,g+gmax,t1.substr(j,46)),j);
			if(t1.length()-j>=47) tr(find(g,g+gmax,t1.substr(j,47)),j);
			if(t1.length()-j>=48) tr(find(g,g+gmax,t1.substr(j,48)),j);
			if(t1.length()-j>=49) tr(find(g,g+gmax,t1.substr(j,49)),j);
			if(t1.length()-j>=50) tr(find(g,g+gmax,t1.substr(j,50)),j);
			if(t1.length()-j>=51) tr(find(g,g+gmax,t1.substr(j,51)),j);
			if(t1.length()-j>=52) tr(find(g,g+gmax,t1.substr(j,52)),j);
			if(t1.length()-j>=53) tr(find(g,g+gmax,t1.substr(j,53)),j);
			if(t1.length()-j>=54) tr(find(g,g+gmax,t1.substr(j,54)),j);
			if(t1.length()-j>=55) tr(find(g,g+gmax,t1.substr(j,55)),j);
			if(t1.length()-j>=56) tr(find(g,g+gmax,t1.substr(j,56)),j);
			if(t1.length()-j>=57) tr(find(g,g+gmax,t1.substr(j,57)),j);
			if(t1.length()-j>=58) tr(find(g,g+gmax,t1.substr(j,58)),j);
			if(t1.length()-j>=59) tr(find(g,g+gmax,t1.substr(j,59)),j);
			if(t1.length()-j>=60) tr(find(g,g+gmax,t1.substr(j,60)),j);
			if(t1.length()-j>=61) tr(find(g,g+gmax,t1.substr(j,61)),j);
			if(t1.length()-j>=62) tr(find(g,g+gmax,t1.substr(j,62)),j);
			if(t1.length()-j>=63) tr(find(g,g+gmax,t1.substr(j,63)),j);
			if(t1.length()-j>=64) tr(find(g,g+gmax,t1.substr(j,64)),j);
			if(t1.length()-j>=65) tr(find(g,g+gmax,t1.substr(j,65)),j);
			if(t1.length()-j>=66) tr(find(g,g+gmax,t1.substr(j,66)),j);
			if(t1.length()-j>=67) tr(find(g,g+gmax,t1.substr(j,67)),j);
			if(t1.length()-j>=68) tr(find(g,g+gmax,t1.substr(j,68)),j);
			if(t1.length()-j>=69) tr(find(g,g+gmax,t1.substr(j,69)),j);
			if(t1.length()-j>=70) tr(find(g,g+gmax,t1.substr(j,70)),j);
			if(t1.length()-j>=71) tr(find(g,g+gmax,t1.substr(j,71)),j);
			if(t1.length()-j>=72) tr(find(g,g+gmax,t1.substr(j,72)),j);
			if(t1.length()-j>=73) tr(find(g,g+gmax,t1.substr(j,73)),j);
			if(t1.length()-j>=74) tr(find(g,g+gmax,t1.substr(j,74)),j);
			if(t1.length()-j>=75) tr(find(g,g+gmax,t1.substr(j,75)),j);
			if(t1.length()-j>=76) tr(find(g,g+gmax,t1.substr(j,76)),j);
			if(t1.length()-j>=77) tr(find(g,g+gmax,t1.substr(j,77)),j);
			if(t1.length()-j>=78) tr(find(g,g+gmax,t1.substr(j,78)),j);
			if(t1.length()-j>=79) tr(find(g,g+gmax,t1.substr(j,79)),j);
			if(t1.length()-j>=80) tr(find(g,g+gmax,t1.substr(j,80)),j);
			if(t1.length()-j>=81) tr(find(g,g+gmax,t1.substr(j,81)),j);
			if(t1.length()-j>=82) tr(find(g,g+gmax,t1.substr(j,82)),j);
			if(t1.length()-j>=83) tr(find(g,g+gmax,t1.substr(j,83)),j);
			if(t1.length()-j>=84) tr(find(g,g+gmax,t1.substr(j,84)),j);
			if(t1.length()-j>=85) tr(find(g,g+gmax,t1.substr(j,85)),j);
			if(t1.length()-j>=86) tr(find(g,g+gmax,t1.substr(j,86)),j);
			if(t1.length()-j>=87) tr(find(g,g+gmax,t1.substr(j,87)),j);
			if(t1.length()-j>=88) tr(find(g,g+gmax,t1.substr(j,88)),j);
			if(t1.length()-j>=89) tr(find(g,g+gmax,t1.substr(j,89)),j);
			if(t1.length()-j>=90) tr(find(g,g+gmax,t1.substr(j,90)),j);
			if(t1.length()-j>=91) tr(find(g,g+gmax,t1.substr(j,91)),j);
			if(t1.length()-j>=92) tr(find(g,g+gmax,t1.substr(j,92)),j);
			if(t1.length()-j>=93) tr(find(g,g+gmax,t1.substr(j,93)),j);
			if(t1.length()-j>=94) tr(find(g,g+gmax,t1.substr(j,94)),j);
			if(t1.length()-j>=95) tr(find(g,g+gmax,t1.substr(j,95)),j);
			if(t1.length()-j>=96) tr(find(g,g+gmax,t1.substr(j,96)),j);
			if(t1.length()-j>=97) tr(find(g,g+gmax,t1.substr(j,97)),j);
			if(t1.length()-j>=98) tr(find(g,g+gmax,t1.substr(j,98)),j);
			if(t1.length()-j>=99) tr(find(g,g+gmax,t1.substr(j,99)),j);
			if(t1.length()-j>=100) tr(find(g,g+gmax,t1.substr(j,100)),j);
		}
		out<<u<<endl;
	}
	return 0;
}
