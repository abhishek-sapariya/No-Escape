#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream>
#define xcr1 80
#define xcr2 1270
#define ycr1 80
#define ycr2 620
using namespace std;
class Game
{
    int i,y=167;
public:
    int welcome_screen();
    void initialize(int i=16);
    int help();
    void endgame();
    int exitgame1();
    int exitgame();
    void developer();
    void gamewon();
    int difficulty();
    int lines(int,int,int,int,float cx,float cy);
}g;
int Game :: difficulty()
{
    char choice8;
    int count_c,i;
    initwindow(1350,700,"Select the difficulty...");
     settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
     setcolor(5);
     rectangle(50,50,1300,650);
     setcolor(15);
     outtextxy(250,150,"select the difficulty of the game...");
     setcolor(GREEN);
      outtextxy(400,280,"a.   easy");
      setcolor(YELLOW);
       outtextxy(400,320,"b.   medium");
       setcolor(RED);
        outtextxy(400,360,"c.   hard");
          setcolor(5);
          outtextxy(400,400,"please enter your choice...");
           setcolor(CYAN);
          outtextxy(250,550,"Press Esc To Get Back To Main Menu...");
           choice8=getch();
          if(choice8=='a' || choice8=='A' || choice8=='b' || choice8=='B' || choice8=='c' || choice8=='C')
          {
              count_c=1;
          }
          i=16;
          if(choice8=='a' || choice8=='A')
          {
              i=21;
          }

          if(choice8=='b' || choice8=='B')
          {
              i=13;
          }

          if(choice8=='c' || choice8=='C')
          {
              i=7;
          }
     if(choice8==27)
     {
         closegraph();
        g.welcome_screen();
     }
     else if(count_c==1)
        {
            closegraph();
            g.initialize(i);
        }
        else{
            closegraph();
            g.difficulty();
        }
}
int Game :: exitgame1()
{
    system("CLS");
    initwindow(1350,700,"Visit Again... :)");
    settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
    setcolor(YELLOW);
    outtextxy(420,320,"Thank you...visit again");
    getch();
    closegraph();
    return 0;
}
int Game :: welcome_screen()
{
     char ch;
    initwindow(1350,700,"Welcome to No Escape...");

    do
    {
        setcolor(5);
	rectangle(50,50,1300,650);
	setcolor(9);
		settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
		outtextxy(450,190,"NO ESCAPE...");
		setcolor(GREEN);
		settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
		outtextxy(450,320,"a. Play");
		outtextxy(450,350,"b. Help");
		outtextxy(450,380,"c. Developers");
		outtextxy(450,410,"d. Exit");
		setcolor(15);
		outtextxy(450,500,"Enter Your Choice...");
		ch=getch();
		system("CLS");
            switch(ch)
            {
            case 'a':
                system("CLS");
                closegraph();
                g.difficulty();
                break;
                    case 'A':
                    system("CLS");
                    closegraph();
                    break;
            case 'b':
                system("CLS");
                closegraph();
                g.help();
                break;
                    case 'B':
                    system("CLS");
                    closegraph();
                    g.help();
                    break;
            case 'c':
                system("CLS");
                closegraph();
                g.developer();
                break;
                    case 'C':
                    system("CLS");
                    closegraph();
                    g.developer();
                    break;
            case 'd':
                closegraph();
                g.exitgame1();
                break;
                    case 'D':
                        closegraph();
                    g.exitgame1();
                    break;
            }
    }while(ch!='d'||ch!='D');
    return 0;
}
int Game :: exitgame()
{
    system("CLS");
    initwindow(1350,700,"Visit Again... :)");
    settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
    setcolor(5);
    rectangle(50,50,1300,650);
    setcolor(15);
    outtextxy(520,320,"THANKS FOR PLAYING...");
    getch();
    closegraph();
    return 0;
}
void Game::gamewon()
{
    char choice4;
    cleardevice();
    setcolor(5);
    rectangle(50,50,1300,650);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    setcolor(CYAN);
    outtextxy(220,200,"Congratulations...You Won The Game...!!!");
    settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
    setcolor(15);
    outtextxy(220,450,"Do You Want To Play Again...? (Y or N)");
    setcolor(GREEN);
     outtextxy(220,520,"or press escape to get back to main menu...");
    choice4=getch();
        if(choice4=='y'||choice4=='Y')
    {
       g.difficulty();
    }
    else if(choice4=='n' || choice4=='N')
    {
      g.exitgame();
      getch();
      closegraph();
    }
    else if(choice4==27)
    {
        g.welcome_screen();
    }
    else
    {
        cleardevice();
        g.gamewon();
    }
}
int Game :: lines(int w,int x,int y,int z,float cx,float cy)
{
   line(w,x,y,z);
 if(cy>=x && cy<= x+30 && cx>=(w-25) && cx<=(y+25))
   {
       g.endgame();
   }
  else if(cy<=x && cy>=x-30 && cx>=(w-25) && cx<=(y+25))
  {
    g.endgame();
  }
  if(cx<80 || cx>1270 || cy>620)
  {
      g.endgame();
  }
  if(cy<80)
  {
      g.gamewon();
  }
     return 0;
}
void Game::initialize(int q)
{
    Game g1;
    int i,j,z;
    int x=675,y=500,speed=3;
    initwindow(1350,700,"Focus On The Game... :)");
     setcolor(YELLOW);
          settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
	      outtextxy(440,340,"PRESS ANY KEY TO START THE GAME...");
	      getch();
	      cleardevice();
    for(z=1;z>0;)
    {
    for(i=50;i<1600;i++)
    {
        POINT cursorPosition;
    float cx,cy;
    GetCursorPos(&cursorPosition);
    cx=cursorPosition.x ;
     cy= cursorPosition.y ;

       setcolor(5);
       rectangle(50,50,1300,650);
       setcolor(2);

            setcolor(CYAN);
             circle(cx,cy,30);
        setcolor(GREEN);
       if(i<250){
       lines(730,i+400,1300,i+400,cx,cy);}
       if(i<350){
       lines(50,i+300,650,i+300,cx,cy);}
       if(i<450){
       lines(600,i+200,1300,i+200,cx,cy);}
       if(i<550){
       lines(50,i+100,650,i+100,cx,cy);}
       if(i<630){
       lines(710,i+20,1300,i+20,cx,cy);}
       if(i>100&&i<700){
       lines(50,i-50,650,i-50,cx,cy);}
       if(i>150&&i<750){
       lines(50,i-100,740,i-100,cx,cy);}
       if(i>230&&i<830){
       lines(730,i-180,1300,i-180,cx,cy);}
       if(i>330&&i<930){
       lines(50,i-280,150,i-280,cx,cy);
       lines(250,i-280,1300,i-280,cx,cy);}
       if(i>490&&i<1090){
       lines(50,i-440,100,i-440,cx,cy);
       lines(160,i-440,600,i-440,cx,cy);
       lines(800,i-440,1300,i-440,cx,cy);}
       if(i>5190&&i<1190){
       lines(50,i-540,500,i-540,cx,cy);
       lines(640,i-540,1300,i-540,cx,cy);}
       if(i>750&&i<1350){
       lines(50,i-700,150,i-700,cx,cy);
       lines(230,i-700,850,i-700,cx,cy);
       lines(950,i-700,1300,i-700,cx,cy);}
        if(i>850&&i<1450){
        lines(50,i-800,570,i-800,cx,cy);
        lines(680,i-800,1300,i-800,cx,cy);}
        if(i>1000&&i<1600){
          lines(40,i-950,150,i-950,cx,cy);
          lines(220,i-950,390,i-950,cx,cy);
          lines(490,i-950,690,i-950,cx,cy);
          lines(790,i-950,900,i-950,cx,cy);
          lines(890,i-950,1000,i-950,cx,cy);
          lines(1100,i-950,1200,i-950,cx,cy);}
          setcolor(3);
       delay(q);
          cleardevice();
    }

}
    getch();
    delay(0.1);
      getch();
}
int Game::help()
{
    char choice3;
    initwindow(1350,700,"Help...");
    settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
    setcolor(5);
    rectangle(50,50,1300,650);
    setcolor(BLUE);
    outtextxy(100,100,"Instructions...");
    setcolor(YELLOW);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
    setcolor(3);
    outtextxy(250,150,"-> you are given a ball");
    setcolor(YELLOW);
    outtextxy(250,180,"-> press left arrow key to move  left");
    outtextxy(250,210,"-> press right arrow key to move right");
    outtextxy(250,240,"-> press up arrow key to move upwards");
    outtextxy(250,270,"-> press down arrow key to move downwards");
    setcolor(15);
    outtextxy(250,300,"-> avoid getting hit by the obstacles coming in your way");
    outtextxy(250,330,"-> if the ball touches the obstacles or any of the three bottom sides of the");
    outtextxy(250,360,"     rectangle...you are out...");
    setcolor(GREEN);
    outtextxy(250,390,"-> if the ball reaches to the upper line of the rectangle...you win...");
    settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
    setcolor(5);
    outtextxy(560,480,"ALL THE BEST");
    settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
    setcolor(4);
    outtextxy(250,550,"Press Esc To Get Back To Main Menu...");
     choice3=getch();
     if(choice3==27)
     {
         closegraph();
        g.welcome_screen();
     }
     else
        {
            closegraph();
            g.help();
        }
    closegraph();
}
void Game::developer()
{
    char choice2;
    initwindow(1350,700,"Developers of No Escape...");
     settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
     setcolor(5);
     rectangle(50,50,1300,650);
     setcolor(BLUE);
     outtextxy(250,150,"Game Developed By...");
     setcolor(15);
      outtextxy(400,280,"Vishal Shah");
       outtextxy(400,320,"Abhishek Sapariya");
        outtextxy(400,360,"Kalind Sarda");
          outtextxy(400,400,"Ishaan Santhis");
          outtextxy(400,440,"Preet Shah");
          setcolor(GREEN);
          outtextxy(250,550,"Press Esc To Get Back To Main Menu...");
     choice2=getch();
     if(choice2==27)
     {
         closegraph();
        g.welcome_screen();
     }
     else
        {
            closegraph();
            g.developer();
        }
}
void Game::endgame()
{
    char choice;
    system("CLS");
    initwindow(1350,700,"The game is over...try once more...");
    setcolor(5);
    rectangle(50,50,1300,650);
    setcolor(3);
    circle(675,350,100);
    arc(625,335,0,180,20);
    arc(730,335,0,180,20);
    arc(625,335,180,360,20);
    arc(730,335,180,360,20);
    arc(674,370,180,360,50);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
    setcolor(YELLOW);
    outtextxy(460,160,"GAME OVER...");
    setcolor(GREEN);
    outtextxy(440,500,"-------LOL!!!-------");
    settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
    setcolor(RED);
    outtextxy(420,610,"Do You Want To Play Again...? (Y or N)");
    choice=getch();
    if(choice=='y'||choice=='Y')
    {
       g.difficulty();
    }
    else if(choice=='n' || choice=='N')
    {
      g.exitgame();
      getch();
      closegraph();
    }
    else
    {
        closegraph();
        g.endgame();
    }
    exit(0);
}
int main()
{
    g.welcome_screen();
    return 0;
}
