//Writeafunctionthatacceptsacharacter(ch)
//asparameters&returnsthecharacterthatoccursafterchintheEnglishalphabe

#include <iostream>

using namespace std;

char next_char(char ch)
{
    if(ch==90)
        return 'A';
    else if(ch==122)
        return 'a';
    else
        return ch+1;
}

int main()
{
    char ch;
    cout<<"Give the character: ";
    cin>>ch;

    char next=next_char(ch);
    cout<<"Next Character: "<<next;
    return 0;
}