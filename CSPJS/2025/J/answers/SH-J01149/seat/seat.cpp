#include<fstream>
#include<iostream>
std::ifstream fin ("seat.in" );
std::ofstream fout("seat.out");
int main() {
	int n, m; 
	fin >> n >> m; 
	if (m == n && n == 1) fout << "1 1"; 
	else {
		int t; int c=0; 
		fin >> t; 
		for (int i = 1; i < n*m; i++) {
			int x; 
			fin >> x; 
			if (x > t) {c++;} 
		}
	int a = c / n; 
	int b = c % n; 
	if (a % 2 == 1) b = n-b-1; 
	fout << a+1 << ' ' << b+1; 
	}
}
/**


uh huh. this problem. 
obviously nothing too hard about it, 
i think most of my thought process is obvious
through code. 

in hindsight the m==n&&n==1 clause was
completely unnecessary, but i thought it
could matter which is why it was there

because, you know, i have no fucking
idea how c++ i/o works and didnt want to take
my chances. 

messed up way too many things in debug phase
than i should have, including forgetting to
initialize the variable `c` and getting the
a%2 check flipped (since i forgot it was still
0-indexed at that point, and therefore thought
that the even rows are flipped)

not much to say here i guess. im kind of
glad i didnt run into many problems with this
one but regardless took 12 mins to solve. 

pretty sure w/ python id only have taken
12 mins or less on both probs

speaking of times i was nearly or on the
advent of code leaderboard in 2024, it was nice

go do advent of code this year
(unfortunately its only 12 days this year. 
sadge.) 


**/ 
