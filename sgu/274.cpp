//递归下降文法
/*
<letter> ::= a|b|...|z|A|B|...|Z

<symbol> ::= <letter>|0|1|...|9|_|-

<word> ::= <symbol>|<symbol><word>

<prefix> ::= <word>|<prefix>.<word>

<domain> ::= <letter><letter>|<letter><letter><letter>

<suffix> ::= <prefix>.<domain>

<address> ::= <prefix>@<suffix>
*/
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
using namespace std;

bool issymbol(char ch){
    return isalpha(ch) || isdigit(ch) || ch=='_' || ch=='-';
}

bool word(string& s, int a, int b){
    if(a==b) return issymbol(s[a]);
    else return issymbol(s[a]) && word(s, a+1, b);
}

bool prefix(string& s, int a, int b){
    int i=b;
    while(i>=a && s[i]!='.') i--;
    if(i<a) return word(s, a, b);
    else return prefix(s, a, i-1) && word(s, i+1, b);
}

bool domain(string& s, int a, int b){
    if(b==a+1) return isalpha(s[a]) && isalpha(s[a+1]);
    else if(b==a+2) return isalpha(s[a]) && isalpha(s[a+1]) && isalpha(s[a+2]);
    else return false;
}

bool suffix(string& s, int a, int b){
    if(s[b-2]=='.') return prefix(s, a, b-3) && domain(s, b-1, b);
    else if(s[b-3]=='.') return prefix(s, a, b-4) && domain(s, b-2, b);
    else return false;
}

bool address(string& s, int a, int b){
    int i=a;
    while(i<=b && s[i]!='@') i++;
    if(i>b) return false;
    return prefix(s, a, i-1) && suffix(s, i+1, b);
}

int main(){
    int n;
    string s;
    cin>>n;
    getchar();
    for(int tc=0; tc<n; tc++){
        getline(cin, s);
        int l = s.length();
        if(address(s, 0, l-1))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}