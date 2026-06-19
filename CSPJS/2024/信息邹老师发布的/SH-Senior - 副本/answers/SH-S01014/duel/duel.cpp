#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("duel.in");
ofstream fout("duel.out");
const int maxn=1e5+5;
int r[maxn];
int main(){
	int n;
	fin >> n;
	for (int i=0;i<n;i++)
		fin >> r[i];
	sort(r,r+n);
	int prev=1,cur=1;
	int i,compare=r[0];
	for (i=1;i<n;i++){
		if (r[i]>compare){
			compare=r[i];
			break;
		}
		prev++;
	}
	int death=0;
	for (;i<n;i++){
		for (;i<n;i++){
			if (i==n-1 or r[i]>compare){
				death+=min(prev,cur);
				if (cur>=prev)
					prev=cur;
				cur=1;
				compare=r[i]; 
				break;
			}
			cur++;
		}
	}
	fout << n-death << endl;
	return 0;
}
