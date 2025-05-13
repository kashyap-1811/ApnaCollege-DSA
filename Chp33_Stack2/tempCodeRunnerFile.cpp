     BRUTE FORCE
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>heigth={2,1,5,6,2,3};

    int area=0;

    for(int i=0;i<heigth.size();i++)
    {
        int width=1,j=i-1,k=i+1;

        while(k<(heigth.size()))
        {
            if(heigth[i]<=heigth[k])
            {
                width++;
            }
            else{
                break;
            }
            k++;
        }
        while(j>0)
        {
            if(heigth[i]<=heigth[j])
            {
                width++;
            }
            else
            {
                break;
            }
            j--;
        }

        if(area<(heigth[i]*width))
        {
            area=heigth[i]*width;
        }
    }

    cout<<endl<<"Max area is:  "<<area;
    return 0;
}