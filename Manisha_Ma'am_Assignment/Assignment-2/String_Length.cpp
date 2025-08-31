// Length of a string.

#include <iostream>
using namespace std;

int Count_Characters(char *str) 
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return count;
}

int main(){
    char str[100];

    cout << "Enter String: ";
    cin.getline(str, 100);

    cout << "The length of string is " << Count_Characters(str) << ". " << endl ;

    return 0;
}