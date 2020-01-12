#include "headers.h"

using namespace std;

class Solution
{
public:
    int add(int a, int b) 
    {
        return a + b;
    }
};

TEST(TestSuit1, test1) 
{

}

int main()
{

    vector<string> msg {"Hello", "World"};

    for (const string& word : msg)
    {
        cout << word << " "; 
    }
    cout << endl;
}


