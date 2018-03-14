#include <fstream>
#include <allocator.h>
#include <assertions.h>
#include <autolink.h>
#include <config.h>
#include <features.h>
#include <forwards.h>
#include <json.h>
#include <reader.h>
#include <value.h>
#include <version.h>
#include <writer.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(){


Json::Value peoples;
std::ifstream people_file("people.json", std::ifstream::binary);
people_file >> peoples;


     // runs trough file to get the array size.

    int arraysize = 0;

    while(!people_file.eof())
    {
       cout << peoples[arraysize]["age"]<< " | " << peoples[arraysize]["lastname"] << ", " << peoples[arraysize]["firstname"] << " | " << peoples[arraysize]["eyecolor"] << " | " << peoples[arraysize]["gender"] << endl;
       arraysize++;
    }

   cout << "the total number of people is: " << arraysize << endl;


   //scan for active males with blue eyes over the age of 30.

   int blue30s = 0;

   for(int k = 0;k<=arraysize;k++){

        if(peoples [k]["eyes"]== "blue" && peoples [k]["is active"]== true && peoples [k]["gender"]== "male" && peoples [k]["age"]>= 30 )
            {
            cout << peoples[k]["age"]<< " | " << peoples[k]["lastname"] << ", " << peoples[k]["firstname"] << " | " << peoples[k]["eyecolor"] << " | " << peoples[k]["gender"] << endl;
            blue30s++;
            }
     }

   cout << "the number of active males with blues eyes is: " << blue30s << endl; // print out number of males over 30 w/ blue eyes.


   //scan for number of people with less than 3 friends.

    int lonelypeople = 0;

    for(int k = 0;k<=arraysize;k++){

        if(peoples [k]["friends"].size() < 3 ) // checks to see if the size of the friends array is less than 3 people.
            {
                lonelypeople++;
            }
    }
        cout << "the number of people with less than 3 friends is: " << lonelypeople << endl;


return 0;
}


