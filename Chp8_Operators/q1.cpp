#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int x=2,y=5;
    int exp1=(x*y/x);
    int exp2=(x*(y/x));
    cout<<exp1<<endl<<exp2;
    return 0;
}