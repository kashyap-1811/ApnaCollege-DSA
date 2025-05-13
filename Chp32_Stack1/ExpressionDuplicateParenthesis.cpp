#include <bits/stdc++.h>

using namespace std;

bool findDuplicate(string input)
{
    stack<char>s;
    for(int i=0;i<input.size();i++)
    {
        if(input[i] == '(')
        {
            s.push(input[i]);
        }
        else if(input[i] == '+')
        {
            if(s.empty())
            {
                return false;
            }
            else{
                s.pop();
            }
        }
    }

    return s.empty();
}

int main()
{
    string abc = "(a+b)";// 
    cout<<(findDuplicate(abc)?"true: Valid":"false: Invalid ");
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// bool findDuplicate(string input)
// {
//     stack<char> st;

//     for (char ch : input)
//     {
//         if (ch == ')')
//         {
//             char top = st.top();
//             st.pop();
//             int elementsInside = 0;

//             while (top != '(')
//             {
//                 elementsInside++;
//                 top = st.top();
//                 st.pop();
//             }

//             if (elementsInside < 1)
//             {
//                 return true; // Found duplicate parentheses
//             }
//         }
//         else
//         {
//             st.push(ch);
//         }
//     }

//     return false; // No duplicate parentheses found
// }

// int main()
// {
//     string abc = "((a+b)+(c+(b)))";
//     cout << (findDuplicate(abc) ? "Yes" : "No") << endl;
//     return 0;
// }
