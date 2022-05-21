#include <iostream>
#include <ctime>  
#include <conio.h>
#include <Windows.h>// for time
#include <mmsystem.h>
#include <thread>
#include "World.h"
using namespace std;

int main()
{
	PlaySound(TEXT("c:\\temp\\music.wav"), NULL, SND_ASYNC);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout.width(100);
	cout << "  ><< <<  ><<< ><<<<<<      ><       ><<<<<<<    ><<< ><<<<<<" << endl;
	cout.width(100);
	cout << "><<    ><<     ><<         >< <<     ><<    ><<       ><<    " << endl;
	cout.width(100);
	cout << " ><<           ><<        ><  ><<    ><<    ><<       ><<    " << endl;
	cout.width(100);
	cout << "   ><<         ><<       ><<   ><<   >< ><<           ><<    " << endl;
	cout.width(100);
	cout << "      ><<      ><<      ><<<<<< ><<  ><<  ><<         ><<    " << endl;
	cout.width(100);
	cout << "><<    ><<     ><<     ><<       ><< ><<    ><<       ><<    " << endl;
	cout.width(100);
	cout << "  ><< <<       ><<    ><<         ><<><<      ><<     ><<    " << endl;
	char ch;
	while (cin.get(ch))
	{
		system("cls");
			World myWorld(time(0));
			myWorld.display();
			while (1)
			{
				system("cls");
				myWorld.simulateOneStep();
				myWorld.display();

				if (_kbhit())
				{
					if (!myWorld.check_Full())
					{
						ch = _getch();
						if (ch == 'S' || ch == 's')
							myWorld.add_Organism(SUPERANT);
						if (ch == 'B' || ch == 'b')
							myWorld.add_Organism(BUG);
						if (ch == 'O' || ch == 'o')
							myWorld.add_Organism(BOMB_BUG);
						if (ch == 'A' || ch == 'a')
							myWorld.add_Organism(ANT);
						if (ch == 'Q' || ch == 'q')
							system("cls");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						cout << "  _______ _    _          _   _ _  __ __     ______  _    _ _ " << endl;
						cout << " |__   __| |  | |   /\   | \ | | |/ / \ \   / / __ \| |  | | |" << endl;
						cout << "    | |  | |__| |  /  \  |  \| | ' /   \ \_/ / |  | | |  | | |" << endl;
						cout << "    | |  |  __  | / /\ \ | . ` |  <     \   /| |  | | |  | | |" << endl;
						cout << "    | |  | |  | |/ ____ \| |\  | . \     | | | |__| | |__| |_|" << endl;
						cout << "    |_|  |_|  |_/_/    \_\_| \_|_|\_\    |_|  \____/ \____/(_)" << endl;
						cout << "                                                              " << endl;
						system("cls");
						Sleep(1500);
						exit(0);
					}
				}
				Sleep(500);
			}
		}
	return 0;
}