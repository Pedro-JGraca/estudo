#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n1,n2;
    float var;

    n1 = 10;
    n2= 20;
    var = n1 %n2;
    var ++;
    cout << var;
    cout << '\n';

    if (true){
        cout<< 'o';
        cout << '\n';
    }

    bool var2 = true;
    if (var2){
        cout << var2;
        cout << '\n';

    }

    int num;
    cin >> num;

    switch (num)
    {
    case 10 :
        cout<< "num e 10";
        cout << '\n';
        break;
    case 9 :
        cout<< "num e 9";
        cout << '\n';
        break;
    default:
        cout<< "num nao encontrado";
        cout << '\n';
        break;
    }

    float div =3;
    cout << div/2;
    cout << '\n';

    int i = 3;
    cout << i/2;
    cout << '\n';
    return 0;
}
