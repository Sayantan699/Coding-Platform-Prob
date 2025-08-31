
string to_upper(string str)
{
    // code
    // User function Template for Java

    for (int ind = 0; ind < str.size(); ind++)
    {
        if (str[ind] >= 97 && str[ind] <= 122)
        { // lowercase

            str[ind] -= 32; // convert to lowercase
        }
    }

    return str;
}
