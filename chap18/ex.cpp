#include <iostream>
#include <stdexcept>

using namespace std;

/*1. Write a function, char* strdup(const char*), that copies a C-style string
   into memory it allocates on the free store. Do not use any standard library
   functions. Do not use subscripting; use the dereference operator * instead.
*/
int length(const char* s){
    int len = 0;
    while(*s++) len++;
    return len;
}

char* strdup(const char* s){
    char* buf = new char[length(s)];
    // while(*buf++ = *s++);
    for(int i = 0; buf[i] = s[i]; i++);
    return buf;
}
/*
2. Write a function, char* findx(const char* s, const char* x), that finds the
   first occurrence of the C-style string x ins. Do not use any standard library
   functions. Do not use subscripting; use the dereference operator * instead.
*/
const char* findx(const char* s, const char* x){
    while(*s++){
        const char* p = s;
        const char* q = x;
        while(*p++ == *q++);
        if(*q == '\0') return s;
    }
    return nullptr;
}

/*
3. Write a function, int strcmp(const char* s1, const char* s2), that compares
   C-style strings. Let it return a negative number if s1 is lexicographically
   before s2, zero if s1 equals s2, and a positive number if s1 is
   lexicographically after s2. Do not use any standard library functions. Do not
   use subscripting; use the dereference operator * instead.
*/
int strcmp(const char* s1, const char* s2){
    while(*s1++ == *s2++ && *s1 != '\0' && *s2 != '\0');
    if(*s1 == '\0' && *s2 == '\0') return 0;
    return *s1 > *s2 ? 1 : -1;
}
/*
4. Consider what happens if you give strdup(), findx(), and strcmp() an argument
   that is not a C-style string. Try it! First figure out how to get a char*
   that doesn’t point to a zero-terminated array of characters and then use it
   (never do this in real — non-experimental — code; it can create havoc). Try
   it with free-store-allocated and stack-allocated “fake C-style strings.” If
   the results still look reasonable, turn off debug mode. Redesign and re-
   implement those three functions so that they take another argument giving the
   maximum number of elements allowed in argument strings. Then, test that with
   correct C-style strings and “bad” strings.
*/



/*
5. Write a function, string cat_dot(const string& s1, const string& s2), that
   concatenates two strings with a dot in between. For example, cat_dot("Niels",
   "Bohr") will return a string containing Niels.Bohr.
*/
string cat_dot(const string& s1, const string& s2){
    return s1 +"."+ s2;
}
/*
6. Modify cat_dot() from the previous exercise to take a string to be used as
   the separator (rather than dot) as its third argument.
*/

/*
7. Write versions of the cat_dot()s from the previous exercises to take C-style
   strings as arguments and return a free-store- allocated C-style string as the
   result. Do not use standard library functions or types in the implementation.
   Test these functions with several strings. Be sure to free (using delete) all
   the memory you allocated from free store (using new). Compare the effort
   involved in this exercise with the effort involved for exercises 5 and 6.
*/
char* cat_dot_cstr(const char* s1, const char* s2){
    char* ret = new char[length(s1) + length(s2) + 1];
    char* p = ret;

    while(*s1) *p++ = *s1++;
    *p++ = '.';
    while(*p++ = *s2++);

    return ret;
}

/*
8. Rewrite all the functions in §18.7 to use the approach of making a backward
   copy of the string and then comparing; for example, take "home", generate
   "emoh", and compare those two strings to see that they are different, so home
   isn’t a palindrome.
*/
char* revert_str(const char* s){
    int len = length(s);
    char* ret = new char[len];
    for(int i = 0; i < len; ++i)
        ret[i] = s[len -i -1];
    return ret;
}

bool is_palidrome(const char* s){
    return (!strcmp(s, revert_str(s)));
}
/*
9. Consider the memory layout in §17.4. Write a program that tells the order in
   which static storage, the stack, and the free store are laid out in memory.
   In which direction does the stack grow: upward toward higher addresses or
   downward toward lower addresses? In an array on the free store, are elements
   with higher indices allocated at higher or lower addresses?
*/

/*
10. Look at the “array solution” to the palindrome problem in §18.7.2. Fix it to
    deal with long strings by (a) reporting if an input string was too long and
    (b) allowing an arbitrarily long string. Comment on the complexity of the
    two versions.
*/

/*
11. Look up (e.g., on the web) skip list and implement that kind of list. This
    is not an easy exercise.
*/

/*
12. Implement a version of the game “Hunt the Wumpus.” “Hunt the Wumpus” (or
    just “Wump”) is a simple (non-graphical) computer game originally invented
    by Gregory Yob. The basic premise is that a rather smelly monster lives in a
    dark cave consisting of connected rooms. Your job is to slay the wumpus
    using bow and arrow. In addition to the wumpus, the cave has two hazards:
    bottomless pits and giant bats. If you enter a room with a bottomless pit,
    it’s the end of the game for you. If you enter a room with a bat, the bat
    picks you up and drops you into another room. If you enter the room with the
    wumpus or he enters yours, he eats you. When you enter a room you will be
    told if a hazard is nearby: “I smell the wumpus”: It’s in an adjoining room.
    “I feel a breeze”: One of the adjoining rooms is a bottomless pit. “I hear a
    bat”: A giant bat is in an adjoining room. For your convenience, rooms are
    numbered. Every room is connected by tunnels to three other rooms. When
    entering a room, you are told something like “You are in room 12; there are
    tunnels to rooms 1, 13, and 4; move or shoot?” Possible answers are m13
    (“Move to room 13”) and s13–4–3 (“Shoot an arrow through rooms 13, 4, and
    3”). The range of an arrow is three rooms. At the start of the game, you
    have five arrows. The snag about shooting is that it wakes up the wumpus and
    he moves to a room adjoining the one he was in — that could be your room.
    Probably the trickiest part of the exercise is to make the cave by selecting
    which rooms are connected with whichother rooms. You’ll probably want to use
    a random number generator (e.g., randint() from std_lib_facilities.h) to
    make different runs of the program use different caves and to move around
    the bats and the wumpus. Hint: Be sure to have a way to produce a debug
    output of the state of the cave.
*/

int main(int argc, char const *argv[])
{
    // char* s2 = strdup("Chap 18");
    // cout << s2 << endl;

    // const char* s3 = findx("Hello Wor!", "World!");

    // cout << s3 <<endl;

    cout << "\nTest strcmp: ";
    cout << strcmp("abc", "abc") << endl;
    cout << cat_dot("letrungkien","k53.hut@gmail.com") << endl;

    cout << "Test cat_dot_cstr" << endl;
    cout << cat_dot_cstr("asdf","@gmail.com") << endl;

    cout << is_palidrome("HooH") << endl;

    return 0;
}
