//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int n=str1.size();
        
        bool flag1=true,flag2=true;
        for(int i=0;i<n;i++){
            if(str2[i]!=str1[(i+2)%n]){
                flag1=false;
            }
            if(str2[i]!=str1[(i-2+n)%n]){
                flag2=false;
            }
        }
        
        return flag1|flag2;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends