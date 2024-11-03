#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <char> vowels {'a','e','i','o','u'};
    cout << vowels.at(1)<<endl;

    vector <vector <int>> movieRatings {
        {9,10,9,10},
        {7,5,3,8},
        {10,10,1,9}
    };
    cout<< movieRatings.size()<< endl;
    for (int i = 0; i < movieRatings.size(); i++)
    {
        for(int j = 0;j < movieRatings[i].size();j++){
            cout<<"Movie rating ["<<movieRatings[i][j]<<"] ";
        };
        cout << endl;
    };
    
    return 0;
}