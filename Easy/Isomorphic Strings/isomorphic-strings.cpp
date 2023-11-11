//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int n1=str1.size(), n2=str2.size();
        if(n1 != n2) return false;
        vector<char> child(26,'0');
        vector<char> parent(26,'0');
        for(int i=0; i<n1; ++i){
            if(child[str1[i]-'a']=='0' && parent[str2[i]-'a']=='0'){
                child[str1[i]-'a']=str2[i];
                parent[str2[i]-'a']=str1[i];
            }else{
                if(child[str1[i]-'a']!=str2[i]){
                    return false;
                }
            }
        }
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends