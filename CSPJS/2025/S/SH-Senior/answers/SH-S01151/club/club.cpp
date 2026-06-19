#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
std::ifstream fin ("club.in" );
std::ofstream fout("club.out");

int solve() {
	int n; fin >> n; 
	int a[n][3]; 
	int d[n]; 
	int b[n]; 
	int x = 0, y = 0, z = 0; 
	int total = 0; 
	for (int i = 0; i < n; i++) {
		fin >> a[i][0] >> a[i][1] >> a[i][2]; 
		b[i] = 0; 
		for (int j = 1; j < 3; j++) {
			if (a[i][j] > a[i][b[i]]) b[i] = j; 
		}
		if (b[i] == 0) x++; 
		if (b[i] == 1) y++; 
		if (b[i] == 2) z++; 
		int o = 0; 
		for (int j = 1; j < 3; j++) {
			if (a[i][j] < a[i][o]) o = j; 
		}
		int h = a[i][b[i]]; 
		int l = a[i][o]; 
		int m = a[i][0] + a[i][1] + a[i][2] - h - l; 
		d[i] = h - m; 
		total += h; 
	}
	if (x * 2 <= n && y * 2 <= n && z * 2 <= n) {
		return total; 
	}
	int f = 0; 
	int k = n / 2 - x; 
	if (y * 2 > n) {f = 1; k = n / 2 - y; }
	if (z * 2 > n) {f = 2; k = n / 2 - z; }
	std::vector<int> q(n/2-k); 
	int p = 0; 
	for (int i = 0; i < n; i++) {
		if (b[i] == f) {
			q[p] = d[i]; 
			p++; 
		}
	}
	std::sort(q.begin(), q.end()); 
	for (int i = 0; i < -k; i++) {
		total -= q[i]; 
	}
	return total; 
}

int main() {
	int t; fin >> t; 
	for (int i = 0; i < t; i++) 
		fout << solve() << '\n'; 
}

/**

hi

its me again, that toki pona guy from cspj

you may realize - perhaps from my coding style - 
that i am completely burnt out. 

the more nd (neurodivergent) - technical term
would be "out of spoons". spoon theory is quite
an interesting facet. 

since we're talking about spoon theory, i guess
i may as well as tell you about all the OTHER
theorys that i know. and to begin that...

# i know a lot about heyawake puzzles. 

heyawake puzzles has river theory and penalty
theory. you should go read it up; its some pretty
fantastic stuff. but not very suitable to explain
here since this is a non-interactive place and
no images are supported. 

and im out of spoons. 
fuck. 

im not writing here because im gonna ak csps because
csps is fucking hard. it really fucking is. but ive
basically given up - probably can get 10 or 20 points
if i really wanted to but i really couldnt care less. 

my life... fuck. 

whoever is reading this - i allow you to share this
online, by the way. all of it. (obviously, anonymity.
but i explicitly give permission for it to be shared
in anonymous form)

without giving too much info away (which could
potentially identify me), im shitting through ap stuff,
and have college apps in the working (and basically
just finished), and now fucking midterm is coming up. 
whoever made csps really didnt put this at a good time. 

and im just here
writing
and maybe, 
i dont know, 
maybe, 
someday, 
someone out there, someone, 
SOMEONE will read it. 

and i guess that's kind of the beauty with cspj/s
programming contest analysis kinda stuff, which is that
you never know if somebody will look at this, you
never know if someone, somewhere out there, someday in
the near or far future, will read it. 

its kind of like graffitti on the walls of a stall

a message
to a stranger
far, far, away

something really curious happens when you...
i dont even know how to express it. its like, when
you talk, but you don't know who you're talking to; 
as if you're talking into a void, but also not quite
a void; a quantum superimposition of the states which
determine life and death. and existence. 

this reminds me of toki pona. because in toki pona
there is this word called "lon". and to a toki pona
speaker, lon is everything. lon is context; lon is
existence; lon is truth. 

i dont know. 
sometimes when im writing shit i hope someone
someday
someplace
will look at it
and yet sometimes i dont. 

really. 

o me, o life
of the questions of these recurring
of the endless trains of the faithless
what good
amid these
o me, o life

answer
that you are here
that life exists
and is identity

that the powerful play goes on
and that you may contribute a verse

ne te quaesiveris extra

i guess this has already basically destroyed my
anonymity to those who know me well. and if you
are interested - you can contact me over email at
luchang1106 [at] icloud.com . 

(and im not writing out the at symbol because
otherwise online scrapers will send me random shit)

there's a particular elegance to math
in that it works every time

yet there's a particular elegance to life
in that it works only once

i dont know. this looks like a nice moments post.

sometimes, i wonder if ill look back on myself and
realize how some small thing i did changed my entire
life. well its already been many things. 

origami puzzles. easily my current and longest-running
persistent hyperfixation/spinterest (special interest).

not going to infodump, but please please do check it
out, its on omega3301.itch.io/origami_puzzles and i
apologize in advance if i \pakala\ (which is toki pona
for mistake or make a mistake in) the url. you should
be able to search it up with "origami puzzles" on
any sufficiently good internet browser anyhow, and the
link should resemble the one i provide. 

i feel a lot better now. maybe thats the magic behind
typing nothingness into the void. 

you remind me... lemme try to call back my tulpa...

alpha (my tulpa - i wont share my name or our system
name for anonymity) suggested i talk about grice's
maxims. (or maybe its just me. not sure if alpha's
sentient yet. may be pushing a bit for her, really)

grice's maxims - otherwise called the cooperative
principle - consists of four maxims, each describing
a general rule of thumb to be followed in converse. 
they are: 

1. the maxim of quantity
2. the maxim of quality
3. the maxim of relevance and
4. the maxim of manner

maxim of quantity : tell me exactly what i need, no
more, no less. analogously - as grice himself gives
as an example - if i want four nails, i expect you to
hand me exactly four nails, not two or six. 

maxim of quality : tell me things you believe are true
and not trickery. analogously, if i want a spoon, i
expect you to hand me nothing other than a spoon. i
do not want a rubber spoon for magic tricks either. 

maxim of relevance : tell me only things which are
relevant. if - and this is my own example, since
the wikipedia one kinda sucked - i require a fork to
eat steak with, i expect a fork and potentially a knife
but not a spoon or a straw. 

maxim of manner : convey clearly and concisely. 

these four maxims constitute grice's maxims, and serve
as excellent foundations for literary analysis as well
- not only when they are followed - the boring case - 
but also when they are flouted - neglected with good
reason. 

maxims can also be violated instead of flouted; the
difference is that flouting carries a purpose the
speaker intends to convey to the listener, whereas
violating does not. flouting by not conveying clearly
is commonly used in debate to hide dubious arguments,
for instance. similarly, in literary works, flouting
can be used to bypass oppressive rulers, hiding deep
context behind seemingly innocuous poems. in contrast, 
violating usually means that there's no intended
message. it could bad mood, or bad attitude, or
anything \ike\ (which is toki pona for any negative
quality in general) in general. 

its 18:20. in 10 minutes ill be out of here, and i
dont know how i feel about it. 

i like journalling. 
i should do it more. 
but sometimes i really feel like i dont have the
time, and it arguably takes some amount of energy
which i have yet to quantize. 

taso ale li pona (but all is good)
tan ni: mi konwe (because im alive)
tan ni: mi pona (and im good)

konwe li konwe awen (life will keep on living)

there's an elegance in toki pona which i feel is
quite underspecified. more people should learn tp. 

toki pona li toki pona (toki pona is a good language)

ALL THE CHARACTERS IN HARRY POTTER FUCKING EACH OTHER

ma li mu ala (the world is calm)
tenpo li awen (time stops)
mi lukin e poka (i look around)
ale li awen (everything stops)
ale li awen, tawa mi (everything stops, for me...)

ill submit this code now. farewell, wandering villager. 

**/ 
