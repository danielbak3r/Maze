#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include "source.h"
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;



void nowy_wynik(int wymiar, int ruchy)
{
	system("cls");
	int poziom;
	string nick;
	wyniki tablica[9];
	wyniki nowy{ " ",ruchy };

	//przepisywanie wyników do tablicy obiektów
	fstream plik;
	plik.open("wyniki.txt", ios::in);
	if (plik.is_open())
	{
		for (int i = 0; i < 9; i++)
		{
			plik >> tablica[i].imie;
			plik >> tablica[i].punkty;
		}
	}
	else
		cout << "nie mozna otworzyc pliku";
	plik.close();
	//0-³atwy, 1-œredni, 2-trudny
	switch (wymiar)
	{
	case 21://11 i kolejne liczby zmienic na rozmiary labiryntu
	{
		poziom = 0;
		break;
	}
	case 31:
	{
		poziom = 1;
		break;
	}
	case 51:
	{
		poziom = 2;
		break;
	}
	}
	//zapisywanie nowego rekordu
	if (nowy.punkty < tablica[3 * poziom + 2].punkty)
	{
		cout << endl << "Ustanowiono nowy rekord. Podaj nick:";
		cin >> nick;
		nowy.imie = nick;

		if (nowy.punkty < tablica[3 * poziom].punkty)
		{
			tablica[3 * poziom + 2].punkty = tablica[3 * poziom + 1].punkty;
			tablica[3 * poziom + 2].imie = tablica[3 * poziom + 1].imie;
			tablica[3 * poziom + 1].punkty = tablica[3 * poziom].punkty;
			tablica[3 * poziom + 1].imie = tablica[3 * poziom].imie;
			tablica[3 * poziom].punkty = nowy.punkty;
			tablica[3 * poziom].imie = nowy.imie;
		}
		else if (nowy.punkty < tablica[3 * poziom + 1].punkty)
		{
			tablica[3 * poziom + 2].punkty = tablica[3 * poziom + 1].punkty;
			tablica[3 * poziom + 2].imie = tablica[3 * poziom + 1].imie;
			tablica[3 * poziom + 1].punkty = nowy.punkty;
			tablica[3 * poziom + 1].imie = nowy.imie;
		}
		else
		{
			tablica[3 * poziom + 2].punkty = nowy.punkty;
			tablica[3 * poziom + 2].imie = nowy.imie;
		}

	}
	//zapisywanie do pliku tekstowego
	plik.open("wyniki.txt", ios::out);
	if (plik.is_open()) {
		for (int i = 0; i < 9; i++)
		{
			plik << tablica[i].imie << " ";
			plik << tablica[i].punkty << endl;
		}
	}
	else
		cout << "Blad otwarcia pliku z wynikami";
	plik.close();
}

void show(char **maze, int rozmiar)
{
    //wypisanie labiryntu
    cout<<endl;
    for(int y=1; y<=rozmiar; y++)
    {
        cout<<"  ";
        for(int x=1; x<=rozmiar; x++)
        {
            cout<<maze[x][y];
        }
        cout<<endl;
    }
}

void wyswietl_wyniki()//ta funkcja w¹cza siê po zakonczeniu gry
{
    string zmienna;

    ifstream plik;
    plik.open("wyniki.txt");
    if (plik.is_open())
    {
        for (int i = 0; i < 9; i++)
        {
            switch (i)
            {
            case 0:
                cout << "Poziom latwy :" << endl;
                break;
            case 3:
                cout << "Poziom sredni :" << endl;
                break;
            case 6:
                cout << "Poziom trudny :" << endl;
                break;
            default:
                break;
            }
            plik >> zmienna;
            cout << zmienna << "   ";
            plik >> zmienna;
            cout << zmienna << endl;
        }
    }
    else
        cout << "nie mozna otworzyc pliku";
    plik.close();
}

void menu()
{

    char wybor, wybor2, poziomtrudnosci;
    system("cls");
    cout.width(13);
    cout.fill(' ');
    cout << "LABIRYNT" << endl;
    cout << setfill('*') << setw(20) << " " << endl;
    cout << "1. Zagraj" << endl;
    cout << "2. Ranking" << endl;
    cout << "3. Zasady gry" << endl;
    cout << "4. Wyjscie" << endl;
    wybor=getche();
    system("cls");

    if (wybor == '1')
    {
        cout.width(13);
        cout.fill(' ');
        cout << "LABIRYNT" << endl;
        cout << setfill('*') << setw(20) << " " << endl;
        cout << "Wybierz poziom trudnosci:" << endl;
        cout << "1. Latwy" << endl;
        cout << "2. Normalny" << endl;
        cout << "3. Trudny" << endl;
        cout<< "4. Niestandardowy"<<endl;
        cout << setfill('*') << setw(20) << " " << endl;
        cout << "5. Menu" << endl;
        poziomtrudnosci=getche();
        system("cls");

        while (poziomtrudnosci != '5' && poziomtrudnosci != '1' && poziomtrudnosci != '2' && poziomtrudnosci != '3' && poziomtrudnosci != '4')
        {
            system("cls");
                    cout.width(13);
        cout.fill(' ');
        cout << "LABIRYNT" << endl;
        cout << setfill('*') << setw(20) << " " << endl;
        cout << "Wybierz poziom trudnosci:" << endl;
        cout << "1. Latwy" << endl;
        cout << "2. Normalny" << endl;
        cout << "3. Trudny" << endl;
        cout<< "4. Niestandardowy"<<endl;
        cout << setfill('*') << setw(20) << " " << endl;
        cout << "5. Menu" << endl;
        poziomtrudnosci=getche();
        }

        if (poziomtrudnosci == '1')
        {
            //rozmiar nieparzysty 11/21/31/57/101/201
            int rozmiar=21;
            char **maze=new char*[rozmiar];
            for(int i=1;i<=rozmiar;i++){
            maze[i]=new char[rozmiar];
            }
        Maze_Generator P1;

        P1.correct_road(maze, rozmiar);
        P1.inside(maze, rozmiar);

        Player P2;
        P2.movement(maze, rozmiar);
        }

        if (poziomtrudnosci == '2')
        {
            //rozmiar nieparzysty 11/21/31/57/101/201
            int rozmiar=31;
            char **maze=new char*[rozmiar];
            for(int i=1;i<=rozmiar;i++){
            maze[i]=new char[rozmiar];
            }
        Maze_Generator P1;

        P1.correct_road(maze, rozmiar);
        P1.inside(maze, rozmiar);

        Player P2;
        P2.movement(maze, rozmiar);
    }

        if (poziomtrudnosci == '3')
        {
            //rozmiar nieparzysty 11/21/31/57/101/201
            int rozmiar=51;
            char **maze=new char*[rozmiar];
            for(int i=1;i<=rozmiar;i++){
            maze[i]=new char[rozmiar];
            }
        Maze_Generator P1;

        P1.correct_road(maze, rozmiar);
        P1.inside(maze, rozmiar);

        Player P2;
        P2.movement(maze, rozmiar);
    }
    if(poziomtrudnosci=='4'){
        int rozmiar;
        cout<<"Podaj rozmiar (nieparzysty): ";
        cin>>rozmiar;
        while(rozmiar%2==0){
            system("cls");
            cout<<"Podaj rozmiar (nieparzysty): ";
            cin>>rozmiar;
        }
        char **maze=new char*[rozmiar];
        for(int i=1;i<=rozmiar;i++){
            maze[i]=new char[rozmiar];
            }
        Maze_Generator P1;

        P1.correct_road(maze, rozmiar);
        P1.inside(maze, rozmiar);

        Player P2;
        P2.movement(maze, rozmiar);
    }
        }

        if (poziomtrudnosci == '5')
        {
            system("cls");
            menu();
        }


    else if (wybor == '2')
    {
        cout.width(13);
        cout.fill(' ');
        cout << "RANKING" << endl;
        cout << setfill('*') << setw(20) << " " << endl;

        wyswietl_wyniki();

        cout << setfill('*') << setw(20) << " " << endl;
        cout << "4. Menu" << endl;
        wybor2=getche();

    while (wybor2 != '4')
    {
        system("cls");
                cout.width(13);
        cout.fill(' ');
        cout << "RANKING" << endl;
        cout << setfill('*') << setw(20) << " " << endl;

        wyswietl_wyniki();

        cout << setfill('*') << setw(20) << " " << endl;
        cout << "4. Menu" << endl;
        wybor2=getche();
    }

        if (wybor2 == '4')
        {
            system("cls");
            menu();
        }



    }

   else if (wybor == '3')
    {
        cout.width(13);
        cout.fill(' ');
        cout << "ZASADY GRY" << endl;
        cout << setfill('*') << setw(20) << " " << endl;
        cout << "Labirynt - gra komputerowa o charakterze logiczno-zrecznosciowym.\nGracz " << char(4) << " ma za zadanie znalezienie wyjscia w labiryncie." << endl;
        cout << "Za kazde poruszenie sie (gora, dol, prawko, lewo) naliczany jest 1 ruch.\nRuchy sumuja sie i zostaja zapisane na koniec gry do rankingu." << endl;
        cout << setfill('*') << setw(20) << " " << endl;
        cout << "4. Menu" << endl;
        wybor2=getche();

        while (wybor2 != '4')
        {
        system("cls");
        cout.width(13);
        cout.fill(' ');
        cout << "ZASADY GRY" << endl;
        cout << setfill('*') << setw(20) << " " << endl;
        cout << "Labirynt - gra komputerowa o charakterze logiczno-zrecznosciowym.\nGracz " << char(4) << " ma za zadanie znalezienie wyjscia w labiryncie." << endl;
        cout << "Za kazde poruszenie sie (gora, dol, prawko, lewo) naliczany jest 1 ruch.\nRuchy sumuja sie i zostaja zapisane na koniec gry do rankingu." << endl;
        cout << setfill('*') << setw(20) << " " << endl;
        cout << "4. Menu" << endl;
        wybor2=getche();
        }

        if (wybor2 == '4')
        {
            system("cls");
            menu();
        }




    }

   else if (wybor == '4')
    {

    }

    else
        menu();

}

void Maze_Generator::border(char **maze, int rozmiar)
{
    //obramowanie
    for(int y=1; y<=rozmiar; y++)
    {
        for(int x=1; x<=rozmiar; x++)
        {
            if(y==1 || y==rozmiar)
            {
                maze[x][y]=char(219);
            }

            else if(x==1 || x==rozmiar)
            {
                maze[x][y]=char(219);
            }
            else
            {
                maze[x][y]=' ';
            }
        }
    }
    //siatka
    for(int y=2; y<=rozmiar; y++)
    {
        for(int x=2; x<=rozmiar; x++)
        {
            if(maze[x][y]==' ')
            {
                if(x%2!=0)
                {
                    maze[x][y]=char(178);
                }
                else if(y%2!=0)
                {
                    maze[x][y]=char(178);
                }
                else
                {

                }
            }
        }
    }
}

void Maze_Generator::inside(char **maze, int rozmiar)
{
    //Wypelnianie labiryntu
    bool first=true;
    for(int Y=2; Y<=rozmiar-1; Y++)
    {
        for(int X=2; X<=rozmiar-1; X++)
        {
            if(maze[X][Y]==' ' && maze[X][Y+1]!=' ' && maze[X][Y-1]!=' ' && maze[X+1][Y]!=' ' && maze[X-1][Y]!=' ' && X%2==0)
            {
                int OX=X;
                int OY=Y;
                bool check=true;

                int link=rand()%4+1;
                while(check==true && first!=true)
                {
                    //1 gora, 2 dol, 3 lewo, 4 prawo
                    //laczenie korytarzy
                    if(link==1 && maze[X][Y-2]==' ' && OY!=2 && Y!=2 || (maze[X+1][Y-2]==' ' || maze[X-1][Y-2]==' ' || maze[X][Y-3]==' '))
                    {
                        maze[X][Y-1]=' ';
                        check=false;

                    }
                    else if(link==2 && maze[X][Y+2]==' ' || (maze[X+1][Y+2]==' ' || maze[X-1][Y+2]==' ' || maze[X][Y+3]==' '))
                    {
                        maze[X][Y+1]=' ';
                        check=false;

                    }
                    else if(link==3 && maze[X-2][Y]==' ' || (maze[X-2][Y+1]==' ' || maze[X-2][Y-1]==' ' || maze[X-3][Y]==' '))
                    {
                        maze[X-1][Y]=' ';
                        check=false;
                    }
                    else if(link==4 && maze[X+2][Y]==' ' || (maze[X+2][Y+1]==' ' || maze[X+2][Y-1]==' ' || maze[X+3][Y]==' '))
                    {
                        maze[X+1][Y]=' ';
                        check=false;
                    }
                    else
                    {
                        link=rand()%4+1;
                        check=true;
                    }
                }
                first=false;


                bool flag[4]= {true, true, true, true};

                while(flag[0]==true || flag[1]==true || flag[2]==true || flag[3]==true)
                {
                    //1 gora, 2 dol, 3 lewo, 4 prawo
                    int direction=rand()%4+1;

                    if(direction==1 && flag[0]==true)
                    {
                        if(maze[OX][OY-1]!=char(219) && maze[OX][OY-1]!=' ' && OX%2==0)
                        {
                            if(maze[OX][OY-3]==' ' || maze[OX+1][OY-2]==' ' || maze[OX-1][OY-2]==' ')
                            {
                                flag[0]=false;
                            }
                            else
                            {
                                OY--;
                                maze[OX][OY]=' ';
                                OY--;

                                flag[0]=true;
                                flag[1]=true;
                                flag[2]=true;
                                flag[3]=true;
                            }

                        }
                        else
                        {
                            flag[0]=false;
                        }
                    }
                    else if(direction==2 && flag[1]==true)
                    {
                        if(maze[OX][OY+1]!=char(219) && maze[OX][OY+1]!=' ' && OX%2==0)
                        {
                            if(maze[OX][OY+3]==' ' || maze[OX+1][OY+2]==' ' || maze[OX-1][OY+2]==' ')
                            {
                                flag[1]=false;
                            }
                            else
                            {
                                OY++;
                                maze[OX][OY]=' ';
                                OY++;

                                flag[0]=true;
                                flag[1]=true;
                                flag[2]=true;
                                flag[3]=true;
                            }
                        }
                        else
                        {
                            flag[1]=false;
                        }
                    }
                    else if(direction==3 && flag[2]==true)
                    {
                        if(maze[OX-1][OY]!=char(219) && maze[OX-1][OY]!=' ' && OY%2==0)
                        {
                            if(maze[OX-3][OY]==' ' || maze[OX-2][OY+1]==' ' || maze[OX-2][OY-1]==' ')
                            {
                                flag[2]=false;
                            }
                            else
                            {
                                OX--;
                                maze[OX][OY]=' ';
                                OX--;

                                flag[0]=true;
                                flag[1]=true;
                                flag[2]=true;
                                flag[3]=true;
                            }
                        }
                        else
                        {
                            flag[2]=false;
                        }
                    }
                    else if(direction==4 && flag[3]==true)
                    {
                        if(maze[OX+1][OY]!=char(219) && maze[OX+1][OY]!=' ' && OY%2==0)
                        {
                            if(maze[OX+3][OY]==' ' || maze[OX+2][OY+1]==' ' || maze[OX+2][OY-1]==' ')
                            {
                                flag[3]=false;
                            }
                            else
                            {
                                OX++;
                                maze[OX][OY]=' ';
                                OX++;

                                flag[0]=true;
                                flag[1]=true;
                                flag[2]=true;
                                flag[3]=true;
                            }
                        }
                        else
                        {
                            flag[3]=false;
                        }
                    }
                }
            }
        }
    }
}

void Maze_Generator::correct_road(char **maze, int rozmiar)
{
    //Poprawna droga
    bool main_flag=false;
    while(main_flag==false)
    {

        border(maze, rozmiar);

        int entry_exit=rand()%(rozmiar-2)+2;
        while(entry_exit%2!=0)
        {
            entry_exit=rand()%(rozmiar-2)+2;
        }
        maze[entry_exit][1]=' ';

        int OX=entry_exit;
        int OY=2;
        bool flag[4]= {true, true, true, true};

        while(flag[0]==true || flag[1]==true || flag[2]==true || flag[3]==true)
        {
            //1 gora, 2 dol, 3 lewo, 4 prawo
            int direction=rand()%100+1;
            if(direction==1 && flag[0]==true)
            {
                if(maze[OX][OY-1]!=char(219) && maze[OX][OY-1]!=' ' && OX%2==0)
                {
                    if(maze[OX][OY-3]==' ' || maze[OX+1][OY-2]==' ' || maze[OX-1][OY-2]==' ')
                    {
                        flag[0]=false;
                    }
                    else
                    {
                        OY--;
                        maze[OX][OY]=' ';
                        OY--;

                        flag[0]=true;
                        flag[1]=true;
                        flag[2]=true;
                        flag[3]=true;
                    }
                }
                else
                {
                    flag[0]=false;
                }
            }
            else if(direction==2 && flag[1]==true)
            {
                if(maze[OX][OY+1]!=char(219) && maze[OX][OY+1]!=' ' && OX%2==0)
                {
                    if(maze[OX][OY+3]==' ' || maze[OX+1][OY+2]==' ' || maze[OX-1][OY+2]==' ')
                    {
                        flag[1]=false;
                    }
                    else
                    {
                        OY++;
                        maze[OX][OY]=' ';
                        OY++;

                        flag[0]=true;
                        flag[1]=true;
                        flag[2]=true;
                        flag[3]=true;
                    }
                }
                else
                {
                    flag[1]=false;
                }
            }
            else if(direction==3 && flag[2]==true && OY!=rozmiar-1)
            {
                if(maze[OX-1][OY]!=char(219) && maze[OX-1][OY]!=' ' && OY%2==0)
                {
                    if(maze[OX-3][OY]==' ' || maze[OX-2][OY+1]==' ' || maze[OX-2][OY-1]==' ')
                    {
                        flag[2]=false;
                    }
                    else
                    {
                        OX--;
                        maze[OX][OY]=' ';
                        OX--;

                        flag[0]=true;
                        flag[1]=true;
                        flag[2]=true;
                        flag[3]=true;
                    }
                }
                else
                {
                    flag[2]=false;
                }
            }
            else if(direction==4 && flag[3]==true && OY!=rozmiar-1)
            {
                if(maze[OX+1][OY]!=char(219) && maze[OX+1][OY]!=' ' && OY%2==0)
                {
                    if(maze[OX+3][OY]==' ' || maze[OX+2][OY+1]==' ' || maze[OX+2][OY-1]==' ')
                    {
                        flag[3]=false;
                    }
                    else
                    {
                        OX++;
                        maze[OX][OY]=' ';
                        OX++;

                        flag[0]=true;
                        flag[1]=true;
                        flag[2]=true;
                        flag[3]=true;
                    }
                }
                else
                {
                    flag[3]=false;
                }
            }
            else
            {
                if(OY==(rozmiar-1))
                {
                    flag[0]=false;
                    flag[1]=false;
                    flag[2]=false;
                    flag[3]=false;
                    maze[OX][OY+1]=' ';
                    main_flag=true;


                }
            }
        }
    }
}

void Player::movement(char** maze, int rozmiar)
{
    int entry;
    int exit;
    char ruch;
    int count_movement=0;
    for(int i=1; i<=rozmiar; i++)
    {
        if(maze[i][1]==' ')
        {
            entry=i;
            maze[entry][1]=char(4);
        }
    }
    for(int i=1; i<=rozmiar; i++)
    {
        if(maze[i][rozmiar]==' ')
        {
            exit=i;
        }
    }
    int x=entry;
    int y=1;
    bool reset=false;
    show(maze, rozmiar);
    cout<<"\n  Ruch: "<<count_movement<<"   Sterowanie: w-gora s-dol a-lewo d-prawo r-reset";
    while(maze[exit][rozmiar]!=char(4) && reset==false)
    {

        ruch=getche();
        system("cls");
        if(ruch=='w' || ruch=='a' || ruch=='s' || ruch=='d' || ruch=='r')
        {

            switch(ruch)
            {
            case 'w':
                if(maze[x][y-1]==' ')
                {
                    maze[x][y]=' ';
                    maze[x][--y]=char(4);
                    show(maze, rozmiar);
                    cout<<"\n  Ruch: "<<++count_movement<<"   Sterowanie: w-gora s-dol a-lewo d-prawo r-reset";
                }
                else
                {
                    show(maze, rozmiar);
                    cout<<"\n  Ruch: "<<count_movement<<"   Sterowanie: w-gora s-dol a-lewo d-prawo r-reset";
                }
                break;
            case 's':
                if(maze[x][y+1]==' ')
                {
                    maze[x][y]=' ';
                    maze[x][++y]=char(4);
                    show(maze, rozmiar);
                    cout<<"\n  Ruch: "<<++count_movement<<"   Sterowanie: w-gora s-dol a-lewo d-prawo r-reset";
                }
                else
                {
                    show(maze, rozmiar);
                    cout<<"\n  Ruch: "<<count_movement<<"   Sterowanie: w-gora s-dol a-lewo d-prawo r-reset";
                }
                break;
            case 'a':
                if(maze[x-1][y]==' ')
                {
                    maze[x][y]=' ';
                    maze[--x][y]=char(4);
                    show(maze, rozmiar);
                    cout<<"\n  Ruch: "<<++count_movement<<"   Sterowanie: w-gora s-dol a-lewo d-prawo r-reset";
                }
                else
                {
                    show(maze, rozmiar);
                    cout<<"\n  Ruch: "<<count_movement<<"   Sterowanie: w-gora s-dol a-lewo d-prawo r-reset";
                }
                break;
            case 'd':
                if(maze[x+1][y]==' ')
                {
                    maze[x][y]=' ';
                    maze[++x][y]=char(4);
                    show(maze, rozmiar);
                    cout<<"\n  Ruch: "<<++count_movement<<"   Sterowanie: w-gora s-dol a-lewo d-prawo r-reset";
                }
                else
                {
                    show(maze, rozmiar);
                    cout<<"\n  Ruch: "<<count_movement<<"   Sterowanie: w-gora s-dol a-lewo d-prawo r-reset";
                }
                break;
            case 'r':
                reset=true;
                break;
            }
        }
        else
        {
            show(maze, rozmiar);
            cout<<"\n  Ruch: "<<count_movement<<"   Sterowanie: w-gora s-dol a-lewo d-prawo r-reset";
        }
    }
    system( "cls" );
    if(maze[exit][rozmiar]==char(4))
    {
        cout<<"Przeszedles labirynt w "<<count_movement<<" ruchach!\nGRATULACJE!";
        Sleep(1000);
        if(rozmiar==21 || rozmiar==31 || rozmiar==51){
        nowy_wynik(rozmiar, count_movement);
        }
        menu();
    }
    else
    {
        Maze_Generator P1;

        P1.correct_road(maze, rozmiar);
        P1.inside(maze, rozmiar);
        movement(maze, rozmiar);
    }
}


