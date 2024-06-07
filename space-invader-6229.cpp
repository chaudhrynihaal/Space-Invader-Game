#include "mygraphics.h"
#include "myconsole.h"
#include<conio.h>
#include<windows.h>
#include <cstdlib>                                               
                                                                    //Roll Number : 6229 Nihaal Asif
                                                                    //Roll Number : 6258 Soha Bilal
#include <fstream>
#include <string>
#include<iostream>
#include <sstream>
using namespace std;
void maxWin() {
	HWND max = GetConsoleWindow();
	ShowWindow(max, SW_SHOWMAXIMIZED);
}
int main() {
	int hscore[100] = {};
	char line[100];
	int temp;
	int color[5][11], xc[5][11], xd[5][11], yi[5][11], yf[5][11];                                // initial declare of Alliens x,y co-ordinates
	int width, height;                                                                           // introducing window co ordinates
	maxWin();
	GetWindowDimensions(width, height);
	int x1 = width - (width / 2), x2 = x1 + 40, y1 = height - 45, y2 = height - 25;
	int input = 0;
	int myposition = 0;
	int limit2 = 30, limit3 = 1, limit4 = 1;
	int count = 0, count2, count3 = 1;
	int m = 30, f = 1;                                                                                                //initialization of game variables
	int bulletcolor = 255, bulletx1 = (x1 + x2) / 2, bullety1 = y1, bulletx2 = bulletx1, bullety2 = y1 + 10, b = 20;
	int total = 0, lx1 = 10, lx2 = width - 10, ly1 = 10, ly2 = height - 20;
	int deaths, livs = 3;
	int random = 0;
	bool kil[5][11], finish = false;
	int speed = 0, track = 0;
	int out[1000];
	ofstream order;
	ifstream orderread;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{                                                                                 // telling us that in start all deaths are false, and all aliens are alive
			kil[i][j] = false;
		}
	}
	int ballx = width / 2, bally = height - 100;
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                                                                                              ~ WELCOME TO SPACE INVADERS ~                                    " << endl;
	cout << "                                                                            ~ 'left key' to move left, 'right key' to move right, 'enter' to quit anytime ~ " << endl;
	cout << "                                                                                         ~ 'up key' to move up, 'down key' to move down ~                            " << endl;
	cout << "                                                                                 ~ Your game is ready to begin, press any key to play ~          " << endl;
	cout << "                                                                                     ~ Press 'g' to save the current game process ~                  " << endl;
	cout << "                                                                                        ~ Press 'x' to pause the current game  ~                  " << endl;
	cout << "                                                                                                  ~ BEST OF LUCK !!! ~                                             " << endl;



	system("pause");
	while (count < 5)
	{
		count2 = 0;
		while (count2 < 11)
		{
			xc[count][count2] = limit2;
			yi[count][count2] = m;                                                                      //Array positioning in start and further of alliems
			xd[count][count2] = xc[count][count2] + 30;
			yf[count][count2] = yi[count][count2] + 40;
			limit2 = limit2 + 70;
			count2++;
		}
		count++;
		limit2 = 30;
		m = m + 50;
	}

	count = 0;
	while (count < 5)
	{
		count2 = 0;
		while (count2 < 11)
		{			                                                                                                             //Drawing aliens
			color[count][count2] = 255;
			count2++;
		}
		count++;
	}
	cout << "If you wish to continue your previous game than press 'l' " << endl;
	char key = _getch();
	system("pause");                                                                             //asking user if he wants to load previous game 
	if (key == 'l')
	{
		string outlin;
		int num, work = 0;
		orderread.open("order.txt");
		while (getline(orderread, outlin))
		{
			num = stoi(outlin);
			out[work] = num;
			work++;
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				xc[i][j] = out[track];
				track++;
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				xd[i][j] = out[track];
				track++;
			}
		}                                                                                           // storing data of co-ordinates of the current status of game before saving it
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				yi[i][j] = out[track];
				track++;
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				yf[i][j] = out[track];
				track++;
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				kil[i][j] = out[track];
				track++;
			}
		}
		ballx = out[track];
		++track;
		bally = out[track];
		++track;
		total = out[track];
		++track;
		livs = out[track];
		++track;
		orderread.close();
	}

	while (true)
	{
		if (count3 % 20 == 0)
		{
			
			count = 0;
			while (count < 5)
			{
				count2 = 0;
				while (count2 < 11)
				{
					if (!kil[count][count2])
						myRect(xc[count][count2], yi[count][count2], xd[count][count2], yf[count][count2], (255, 255, 255), (255, 255, 255)); // when aliens are not killed it remains the same
					count2++;
				}
				count++;
			}


			if (count3 % 20 == 0)
			{							

				if (f == 1)
				{										//player fire
					bulletcolor = 255;
					myLine(bulletx1, bullety1 -= b, bulletx2, bullety2 -= b, RGB(210, bulletcolor, 210));
				}

				if (bulletcolor == 0)
				{
					bulletx1 = bulletx1 + myposition;
					bulletx2 = bulletx2 + myposition;
				}
				if (bullety1 == 100)
				{				                                                         	// reloading
					bulletcolor = 0;
					f = 0;
					bulletcolor = 0;
					bulletx1 = (x1 + x2) / 2;
					bulletx2 = bulletx1;
					bullety2 = y1;                                                               // again defining bullet position
					bullety1 = y1 - 10;
				}
				for (count = 0; count < 5; count++)
				{                                                        						//Collision detection of allien and bullet 
					for (count2 = 0; count2 < 11; count2++)
					{
						if (bulletx1 >= xc[count][count2] && bulletx1 <= xd[count][count2] && bullety1 <= yf[count][count2] && bullety1 >= yi[count][count2] && color[count][count2] == 255)
						{
							color[count][count2] = 0;
							f= 0;
							bulletcolor = 0;
							bulletx1 = (x1 + x2) / 2;
							bulletx2 = bulletx1;
							bullety2 = y1;
							bullety1 = y1 - 10;
							total = total + 1;
							kil[count][count2] = true;
							myRect(xc[count][count2] = xc[count][count2], yi[count][count2] += limit3, xd[count][count2] = xd[count][count2], yf[count][count2] += limit3, (11, 12, 13), (11, 12, 13));
						}
					}
				}
				for (int i = 0; i < 5; i++)
				{		                                // If any alien reaches bottom thengame gets over
					for (int j = 0; j < 11; j++)
					{
						if (color[i][j] != 0)
						{
							if (yf[i][j] == height - 20)
							{
								finish = true;
								break;
							}
						}
					}
					if (finish)
						break;
				}
				if (finish)
					break;

				for (count = 0; count < 5; count++)
				{					                                                      	//Collision between ball and aliens
					for (count2 = 0; count2 < 11; count2++)
					{
						if (ballx >= xc[count][count2] && ballx <= xd[count][count2] && bally <= yf[count][count2] && bally >= yi[count][count2] && color[count][count2] == 255) {
							color[count][count2] = 0;
							livs--;
							ballx = width / 2; bally = height - 100;
						}
					}
				}
				PlaceCursor(10, 50);
				cout << " Your Score: " << total << endl;
				cout << " Remaining livs: " << livs << endl;                                         //display of score and livs while game is running 
				if (bullety1 <= 30)
				{
					f = 0;
					bulletx1 = (x1 + x2) / 2; bulletx2 = bulletx1; bullety2 = y1; bullety1 = y1 - 10;
				}
				if (livs == 0)
				{
					break;
				}
				for (count = 0; count < 5; count++)
				{
					for (count2 = 0; count2 < 11; count2++)
					{
						if (yf[count][count2] >= height - 50 && color[count][count2] == 255)
						{                                                                                                      //if the player loses
							break;
						}
					}
				}
				myRect(0, 0, width, height, (0, 0, 0), (0, 0, 0));
				myposition = 0;
			}
			char space[] = { "Space Invaders" };
			myDrawTextWithFont(width + 70, 0, 60, space, RGB(0, 0, 0), RGB(255, 255, 255));
			myEllipse(ballx, bally, ballx + 30, bally + 30, RGB(255, 255, 255), RGB(255, 255, 255));
			mySetPixel(5, 10, (250, 250, 250));
			myLine(lx1, ly1, lx1, ly2, RGB(255, 255, 255));
			myLine(lx1, ly2, lx2, ly2, RGB(255, 255, 255));
			myLine(lx1, ly1, lx2, ly1, RGB(255, 255, 255));
			myLine(lx2, ly1, lx2, ly2, RGB(255, 255, 255));
		}

		if (ballx <= 0)
		{	                                                             	//defining ball movement limits
			ballx = 10;
		}
		if (ballx >= width - 40)
		{
			ballx = width - 40;
		}
		if (bally >= height - 50)
		{
			bally = height - 50;
		}
		if (bally <= 0) {
			bally = 10;
		}

		count3++;
		int entered = CheckKeyPressed1();

		if (entered == 13)
		{
			cout << "  YOU CHOSE GAME OVER  " << endl;
			break;
		}
		if (entered == 75)
		{ // moving left
			ballx -= 20;
		}
		if (entered == 72)
		{ // moving up
			bally -= 20;

		}
		if (entered == 80)
		{ // moving down
			bally += 20;

		}
		if (entered == 'g')
			// save progress of game at the moment.
		{
			order.open("order.txt");
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 11; j++)
				{
					order << xc[i][j] << endl;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 11; j++)
				{
					order << xd[i][j] << endl;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 11; j++)
				{
					order << yi[i][j] << endl;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 11; j++)
				{
					order << yf[i][j] << endl;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 11; j++)
				{
					order << kil[i][j] << endl;
				}
			}
			order << ballx << endl;
			order << bally << endl;
			order << total << endl;
			order << livs << endl;
			order.close();
		}
		if (entered == 'x')
		{ //pause
			char input_again = '0';
			while (input_again != 'x')
			{
				char write[] = { "GAME PAUSED" };
				myDrawTextWithFont(400, 400, 100, write, RGB(255, 255, 255), RGB(0, 0, 0));
				input_again = _getch();
			}
		}
		if (entered == 77)
		{ // moving right
			ballx += 20;
		}
		if (entered == ' ')
		{ // firing from spaceship
			f= 1;
			bulletx1 = (ballx + (ballx + 30)) / 2;
			bulletx2 = bulletx1;
			bullety2 = bally;
			bullety1 = bally - 10;

		}
		input = '\0'; // reassigning null character
		deaths = 0;
		count = 0;
		while (count < 5)
		{ //decides whether the player won or lost.
			count2 = 0;
			for (count2 = 0; count2 < 11; count2++)
			{
				if (color[count][count2] == 0) { deaths++; }
				if (deaths == 55)
				{
					break;
				}
			}
			count++;
		}
		speed++;
		if (speed % 150 == 0)		//controlling speed of aliens
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 11; j++)
				{              //Moving aliens downwards
					yi[i][j] += 1;
					yf[i][j] += 1;
				}
			}
		}
	}
	ofstream highscore;
	ifstream hsscore;

	highscore.open("highscore1.data", ios::app);
	highscore << total << " " << endl;
	highscore.close();

	hsscore.open("highscore1.data");
	string temp_score;
	int score_lenght = 0;
	if (hsscore.is_open())
	{
		while (getline(hsscore, temp_score))
		{

			int i = stoi(temp_score);
			hscore[score_lenght] = i;
			score_lenght++;
		}
	}
	else cout << "Unable to open file";


	hsscore.close();
	int z;
	for (int i = 0; i < score_lenght - 1; i++)
	{
		z = 0;
		for (int j = 0; j < score_lenght - 1 - i; j++)
		{
			if (hscore[j] < hscore[j + 1])
			{
				temp = hscore[j + 1];
				hscore[j + 1] = hscore[j];
				hscore[j] = temp;
				z++;
			}
		}

	}
	for (int i = 0; i < 5; i++)
	{
		cout << " High Score =  " << hscore[i] << endl;
	}

	PlaceCursor(20, 50); // controlling position
	if (deaths < 50 && input == 13)
	{
		cout << " YOU CHOSE TO QUITE THE GAME" << endl;
		cout << " You lost and your score is:  " << total << endl;
		cout << endl;

		system("pause");
		system("cls");
	}
	else if (deaths < 50)
	{
		cout << "You lost & Your score is : " << total << endl;
	}
	else
	{
		cout << " YOU WIN ";
	}

	system("pause");
	return 0;
}