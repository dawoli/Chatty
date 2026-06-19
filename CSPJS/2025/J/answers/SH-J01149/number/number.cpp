#include<fstream>
#include<iostream>
std::ifstream fin ("number.in" );
std::ofstream fout("number.out");
int main() {
	std::string s; 
	fin >> s; 
	
	
	int count[10];
	for (int i = 0; i < 10; i++)
		count[i] = 0;
	
	for (int i = 0; i < s.length(); i++) {
		char a = s[i]; 
		if (a == '0') count[0]++; 
		if (a == '1') count[1]++; 
		if (a == '2') count[2]++; 
		if (a == '3') count[3]++; 
		if (a == '4') count[4]++; 
		if (a == '5') count[5]++; 
		if (a == '6') count[6]++; 
		if (a == '7') count[7]++; 
		if (a == '8') count[8]++; 
		if (a == '9') count[9]++; 
	}
	for (int i = 9; i > -1; i--)
		for (int c = 0; c < count[i]; c++)
			fout << i; 
	
}

/**


hi, wandering villager; 
thought i might as well as document
my journey here, since i have ~1.75
hours left to spare and certainly will
die of boredom otherwise. 
for context, i have scratch open
in another tab. 

im bilingual, and id actually prefer
english simply because its easier to type, 
as un-patriotic as others might say it is. 
im here because cs is fun i guess. 
got 0'd last time because my programming
language of choice is python, not c++. 

so i didnt know how to write (or read)
files. and we all know how that goes. 

anyhow. surely my files won't become a problem
again this time. 


now for this question specifically
(other questions in their relevant programs)

obviously the sol is simple: count numbers, 
output in another order. could sort, but
magnitude of digits low enough that simply
countsort is superior. so thats the alg

you might ask why it took 16 mins to
implement (im looking at edit time, which
i would assume would no longer be available
for you since it would instead be this edit)

recall that i dont fucking use c++. 
i dont fucking know how i/o works. 
so i was fucked several times, trying to
repeatedly read chars, finding that it
doesnt fucking halt. i thought i'd read like
a 10 or a 0 or a 32 or something. 
nothing. fucked. 

so uh i tried string and it worked i guess
i have no recall of how string works but
this passes all cases so i assume its fine. 

you may also notice that the coding style
is slightly fucked. thats because i dont
fucking use c++. i know you can probably
just like '0'+a to get the chars but
im too lazy to figure out how that works. 

actually i have like 1.5 hours so i did
figure out that it works, but not gonna
change anything because, like, why. 

to call notice to this code i guess ill insert
in some shit code

std::cin << a; 
std::cout >> b; 
for (int i = 0; i < n; j++)
a = 1
b = 2; 
i dont really know what to do here
freopen("number.in", "i");
or something
freopen("number.in", 'r');
freopen("number.in", 'w');
freopen("number.in", "r"); 

i honestly dont give a shit about c++
python is supreme
python supremecy


**/ 
