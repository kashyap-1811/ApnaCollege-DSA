#include <iostream>

using namespace std;

class complex{
    int re;
    int img;

    public:
    complex()
    {
        re=img=0;
    }

    complex(int re,int img)
    {
        this->re=re;
        this->img=img;
    }

    complex operator+(complex &c)
    {
        return complex(re+c.re,img+c.img);
    }

    void print()
    {
        cout<<re<<" + j"<<img;
    }
};

int main()
{
    complex c1(5,6);
    complex c2(4,5);

    complex c3=c1+c2;
    c3.print();
    
    return 0;
}