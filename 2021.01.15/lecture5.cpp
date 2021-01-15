#include <iostream>
#include <string>

using namespace std;

bool isWoman(int num)
{
    return (num == 2 || num == 4);
}
bool isAfterMillennium(int num)
{
    return (num == 3 || num == 4);
}

int main()
{
    string input, gender;

    int curYear = 2019;
    int genderNum;
    int age;

    cin >> input;
    genderNum = stoi(input.substr(7, 1));

    if (isWoman(genderNum))
        gender = "W";
    else
        gender = "M";

    if (isAfterMillennium(genderNum))
        age = curYear - (2000 + stoi(input.substr(0, 2))) + 1;
    else
        age = curYear - (1900 + stoi(input.substr(0, 2))) + 1;

    cout << age << " " << gender << endl;

    return 0;
}
