#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class CoffeeBeans
{
    // Access specifier
    public:
  
    // Data Members
    int *ozOfBeans = new int;
  
    // Member Functions()
    void AddBeans()
    {
        cout << "Add how many oz of coffee beans?" << endl;
        //sscanf(cin, "%d", &ozOfBeans)  + &ozOfBeans >> &ozOfBeans;
        &ozOfBeans = stoi(oz) + &ozOfBeans;
    }
};

int main()
{
    
    return 0;
}
