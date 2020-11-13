#include <iostream>
#include <vector>
#include <python3.8/Python.h>

using namespace std;

vector <string> commands= {"Help","FrontListClients","FrontPopShell","FrontSendFile", "FrontReciveFile","FrontExecProgram","FrontInstall"};

#define N_ARG   2

int
main (int argc, char** argv) 
{

    if (argc!=N_ARG)
    {
        cout << "Incorrect use.\nDo: \n\n\t$" << argv[0] << " " <<commands[0] << "\n\nknow how to use this program" << endl;
        return 1;
    }

    bool foundCommand = false;

    for (unsigned index = 0;index<commands.size();index ++)
    {
        if (commands[index] == argv[1])
        {
            foundCommand = true;
            switch (index)
            {
                case 0: //help
            
                    cout << "help" <<endl;
            
                    break;
            
                case 1: //FrontListClients

                    cout << "FrontListClients" << endl;

                    break;
            
                case 2: //FrontPopShell

                    cout << "FrontPopShell" << endl;

                    break;
            
                case 3: //FrontSendFile

                    cout << "FrontSendFile" << endl;

                    break;
            
                case 4: //FrontExecProgram

                    cout << "FrontExecProgram" << endl;

                    break;
            
                case 5: //FrontListClients

                    cout << "FrontListClients" << endl;

                    break;
            
                case 6: //FrontInstall

                    cout << "FrontInstall" << endl;

                    break;

                default:
                    cout << "Unknown error." <<endl;
                    cout << " Do: \n\n\t$" << argv[0] << " " <<commands[0] << "\n\nknow how to use this program" << endl;
                    return 1;
                    break;
                index = commands.size();
            }

        }

    }

    if (foundCommand==false)
    {
        cout << "Command not found.\nDo: \n\n\t$" << argv[0] << " " <<commands[0] << "\n\nknow the list of commands" << endl;
        return 1;
    }




    return 0;
}
