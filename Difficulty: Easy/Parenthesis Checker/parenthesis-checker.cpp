//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
    for (char &ch : x)
    {
        if (s.empty())
        {
            s.push(ch);
            continue;
        }
        int c = s.top();
        if ((c == '[' && ch == ']') || (c == '{' && ch == '}') || (c == '(' && ch == ')'))
        {
            s.pop();
        }
        else
        {
            s.push(ch);
        }
    }
    return s.empty();

    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends