// Defanging IP Address
//  Given a valid(IPv4)
//  IP address, return a defanged version of that IP address.
//  A defanged IP address replaces every period "." with "[.]".

// Example 1 : Input : address = "1.1.1.1" Output : "1[.]1[.]1[.]1"

#include <iostream>
using namespace std;
string defangIPaddr(string address)
{
    int ind = 0;
    string ans = "";
    while (ind < address.size())
    {
        if (address[ind] == '.')
            ans += "[.]";
        else
            ans += address[ind];
        ind++;
    }
    return ans;
}
int main()
{
    string str;
    cout << "Enter the String: " << endl;
    getline(cin, str);

    cout << defangIPaddr(str);

    return 0;
}