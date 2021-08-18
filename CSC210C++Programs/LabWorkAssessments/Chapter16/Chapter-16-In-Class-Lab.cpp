//Create a program that uses the Sequential Search Algorithm
// to search a STRING VECTOR OBJECT.
//  You may use the Sequential search algorithm in the text page 1016
//    or on slide 5 or implement in your own way
//  Create a vector object and request a list of names from the
//    user, first names are adequate.  Store the names in a string vector.
//  Request a sentinel value to end the input sequence 
//  Request a search name from the user
//  Call the sequential search function
//  Upon return from the search, display an appropriate message indicating
//   whether the name was or was not found
//  
//  You may download and use the 'primer' which should get you started using
//    the sequential search prototype defined.  You DO NOT have to use this

//Portions courtesy of: John Bill Danny Minnie Lisa Jack Susan Pluto zzz
 
#include <iostream>
#include <string>
#include <vector> 

using namespace std;

int seqSearch(vector<string>, int, string);

int main()
{
    vector<string> nameList;                              
    string name;                                     
    int index;
    unsigned int listLen;                                         

    cout << "Enter first names (zzz to end the input)." << endl;  
	
    cin >> name;

    while (name != "zzz")
    {         
        nameList.push_back(name);
        cin >> name; 
    }

    cout << endl;    
    
    listLen = nameList.size();

    cout << "Enter the name to be searched: ";  
    cin >> name;     
    cout << endl;                                         
	 
    index = seqSearch(nameList, listLen, name);  

    if (index != -1)                                    
        cout << name << " is found in the list." << endl;                                     
    else                             
        cout << name << " is not in the list." << endl;     

    system("pause");
    return 0;                                        
}

int seqSearch(vector<string> list, int llen, string searchItem)
{
    for (int loc = 0; loc < llen; loc++)
        if (list[loc] == searchItem)
            return loc;

    return -1;
}
