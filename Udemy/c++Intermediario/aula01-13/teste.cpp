#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n1, n2;
    float var;
    //bloco0
    n1 = 10;
    n2 = 20;
    var = n1 % n2;
    var++;
    cout << var;
    cout << '\n';
    cout << '-';
    cout << '\n';

    //bloco1
    if (true)
    {
        cout << 'o';
        cout << '\n';
    }

    bool var2 = true;
    if (var2)
    {
        cout << var2;
        cout << '\n';
    }

    cout << '\n';
    cout << '-';
    cout << '\n';

    //bloco2
    cout << "Escreve um numero: ";
    cin >> n1;
    cout << '\n';

    switch (n1)
    {
    case 10:
        cout << "n1 e 10";
        cout << '\n';
        break;
    case 9:
        cout << "n1 e 9";
        cout << '\n';
        break;
    default:
        cout << "n1 diferente de 9 e 10";
        cout << '\n';
        break;
    }
    cout << '\n';
    cout << '-';
    cout << '\n';

    //bloco3
    var = 3;
    cout << "divisao float de 3 por 2: ";
    cout << var / 2;
    cout << '\n';

    n1 = 3;
    cout << "divisao int de 3 por 2: ";
    cout << n1 / 2;
    cout << '\n';

    cout << '\n';
    cout << '-';
    cout << '\n';

    //bloco4
    n1 = 0;
    char parar = 'n';
    while (n1 < 10)
    {
        cout << n1;
        if (n1 == 5)
        {
            cout << "\nparar?[S]";
            cin >> parar;
            if (parar == 'S')
                break;
        }
        n1++;
        cout << "\n";
    }
    cout << '\n';
    cout << '-';
    cout << "\n\n";

    //bloco5
    n1 = 0;
    while (n1 < 10)
    {

        if (n1 == 0)
        {
            cout << "pares?[S]";
            cin >> parar;
        }
        if ((parar == 'S') && (n1%2!= 0)){
            n1++;
            continue;
        }
        cout << n1;
        cout << "\n";
        n1++;
    }
    cout << '\n';
    cout << '-';
    cout << '\n';

    //bloco6
    for ( n1 = 0, n2 =2; n1 < 10; n1++,n2++)
    {
        cout<<"n1:" << n1 << ' ';
        cout<<"n2:" << n2 << '\n';

    }

    return 0;
}
