#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    int int_a, int_b;
    char tmp;

    cin >> a >> b;

    tmp = a[0];
    a[0] = a[2];
    a[2] = tmp;

    tmp = b[0];
    b[0] = b[2];
    b[2] = tmp;

    int_a = stoi(a);
    int_b = stoi(b);

    if (int_a > int_b)
        cout << int_a << endl;
    else
        cout << int_b << endl;
}
