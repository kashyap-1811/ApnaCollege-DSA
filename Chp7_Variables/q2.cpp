//total cost

#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the cost of Pencil: ";
    float pencil;cin>>pencil;

    cout<<"Enter the cost of Eraser: ";
    float eraser;cin>>eraser;

    cout<<"Enter the cost of pen: ";
    float pen;cin>>pen;

    float total=pencil+eraser+pen;

    cout<<"Total cost: "<<total<<endl;

    cout<<"Total cost with Gst: "<<(total+total*0.18);
    return 0;
}