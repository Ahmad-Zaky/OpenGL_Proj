#include"stdafx.h"
#include "stdio.h"
#include <math.h>
#include<iostream>
#include <GL/glut.h>

using namespace std;

// All variables needed clarified global

char WinName[5];
int WinPositionX,WinPositionY;
int WinSizeX,WinSizeY;
int choice;
char pcolor;
int PChoice;
GLenum premitive;
int transformation;



//-------------------------------------
float radius ,Xcenter ,Ycenter     ,Xradius ,Yradius ,XcOval ,YcOval   ,xs,ys,xe,ye;


int Xl0,Yl0 ,Xl1 ,Yl1            ,Xp0 ,Yp0 ,Xp1 ,Yp1 ;

float r,g,b   ,r1,g1,b1  ,r2,g2,b2  ,r3,g3,b3  ,r4,g4,b4  ,r5,g5,b5  ,r6,g6,b6 ,rp,gp,bp ;


float tx,ty   ,px,py   ,sx,sy  ,th,thstate;

void UserOptions();
void pointColor();
void pointsColor();
void points();
void backgroundColor_and_Orthog();
void Transformations();
void premitives();


void DrawCircle(float r, float Xc , float Yc);
void EllipseShape(float a,float b , float Xc , float Yc);
void StraightLine_Slope_eq(int X0 , int Y0 , int X1 , int Y1);
void StraightLine_Parametric_eq(int X0 , int Y0 , int X1 , int Y1);




void display()
{
	
	
	glClear(GL_COLOR_BUFFER_BIT); 	//default color 

	//---------------------------------------------------
    //draw the x and y axis

	
	glBegin(GL_LINES);  
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(xs, 0.0f, 0.0f); 

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(xe, 0.0f, 0.0f); 


	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, ys, 0.0f); 


    glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, ye, 0.0f); 

	glEnd();






	
//Here we call func. for Circle & EllipseShape & Lines Algorithms

	switch (choice)
{
	case 1:
		glBegin(GL_POINTS);
        StraightLine_Slope_eq(Xl0 , Yl0 , Xl1 , Yl1);
		glEnd();
    break;
	case 2:
		glBegin(GL_POINTS);
		StraightLine_Parametric_eq(Xp0 , Yp0 , Xp1 , Yp1);
		glEnd();
	break;
	case 3:
		glBegin(GL_POINTS);
		DrawCircle(radius,Xcenter,Ycenter);
		glEnd();
	break;
	case 4:
		glBegin(GL_POINTS);
        EllipseShape(Xradius,Yradius,XcOval,YcOval);
		glEnd();

    break;
    case 5:

    //--------------------------------------------------
    //Open GL perimitives

    // We have 10 Premitives (1-GL_POINTS      6-GL_TRIANGLE_STRIP
	                        //2-GL_LINES       7-GL_TRIANGLE_FAN
	                        //3-GL_LINE_STRIP  8-GL_QUADS
	                        //4-GL_LINE_LOOP   9-GL_QUAD_STRIP
	                        //5-GL_TRIANGLES   10-GL_POLYGON).
	glBegin(premitive);           
	
	
points();
 glEnd();
	break;
	case 6:

//------------------------------------------------
    //Transformations (Translate - Rotate[origin point - not on origin point] - Scale -> Reflection [Case from Scale ]  )
 
		glBegin(premitive);           
	points();

 glEnd();


 //=================================================================
 switch (transformation)
 {
	
case 1 :

	 glTranslatef(tx,ty,0.0); //»Õ—ﬂ «·‘ﬂ· „‰ „ﬂ«‰ ·„ﬂ«‰


break;
case 2 :
	
	if(thstate = 'y')
		glRotatef(-th,0.0,0.0,1.0); //»·› «·‘ﬂ· »“«ÊÌ… „⁄Ì‰… Õ«Ê«·Ì‰ ‰›”Â „‰ ‰ﬁÿ… «·«’·
	else
		glRotatef(th,0.0,0.0,1.0);

break;
case 3 :

	glTranslatef(px,py,0.0);

	if(thstate = 'y')
        glRotatef(-th,0.0,0.0,1.0); //»·› «·‘ﬂ· »“«ÊÌ… „⁄Ì‰… Õ«Ê«·Ì‰ ‰›”Â ·ﬂ‰ „‘ „‰ ‰ﬁÿ… «·«’·
    else
		glRotatef(th,0.0,0.0,1.0);

	glTranslatef(-px,-py,0.0);

break;
case 4 :
	glTranslatef(4.0,4.0,0.0);
	glScalef(sx,sy,1.0);       // »ﬂ»— «·‘ﬂ· „„ﬂ‰ «ﬂ»—Â ⁄·Ï »⁄÷Â «Ê«ﬂ»— Ã“¡ Ê«À»  Ã“¡
	glTranslatef(-4.0,-4.0,0.0);
break;
case 5 :
//Â‰« »«⁄„· «·«‰⁄ﬂ«” ··‘ﬂ· ›Ï «Ì —»⁄ „‰ „” ÊÏ «·«Õœ«ÀÌ« 
//Reflection
	glScalef(1.0,-1.0,1.0); //X-axis

break;
case 6 :

	glScalef(-1.0,1.0,1.0); //y-axis

break;
case 7 :

	glScalef(-1.0,-1.0,1.0);//origin point
 }
//=================================================================


 glBegin(premitive);          
	
    points();
 
	glEnd();
	

}

	
    glFlush();

}


void init ()
{
glClearColor (r, g, b, 1.0);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

glOrtho(xs, xe, ys, ye, -1.0, 1.0);
}


void main(int argc, char** argv)
{
	cout<<"Write Name for your Window : "; cin >> WinName;
	cout<<"Enter intitial size of your window (X and y coordinates) = ";cin >>WinSizeX;cin >>WinSizeY;
	cout<<"Enter intitial Position of your window (X and y coordinates) = ";cin >>WinPositionX;cin >>WinPositionY;
		
	backgroundColor_and_Orthog();
	UserOptions();


glutInit(&argc, argv);

glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

glutInitWindowSize (WinSizeX, WinSizeY);

glutInitWindowPosition (WinPositionX, WinPositionY);

glutCreateWindow (WinName);

init ();
glutDisplayFunc(display);

glutMainLoop();


}

/*==================================================================================================================
====================================================================================================================*/


void DrawCircle(float r, float Xc , float Yc)
{

	
	 
	float X, Y;

	glVertex2f(Xc , Yc );

	for (float th=0.0f ; th<=360.0f ; th+=0.2)
	{
		X = r*sin(th) + Xc;
               
		Y = r*cos(th) + Yc;
	        
		    glColor3f(0.0f, 1.0f, 1.0f);
			glVertex2f(X , Y );
	}

	
}


void EllipseShape(float a,float b , float Xc , float Yc)
{ 
	float X, Y;

	for (float th=0.0f ; th<=360.0f ; th+=0.2)
	{
		X = a*sin(th) + Xc;
               
		Y = b*cos(th) + Yc;
	        
		    glColor3f(0.0f, 1.0f, 1.0f);
			glVertex2f(X , Y );
	}

	
}

void StraightLine_Slope_eq(int X0 , int Y0 , int X1 , int Y1)
{
	float X , Y , M = (Y1 - Y0)/(X1 - X0);

	for(X = X0 ; X <= X1 ; X+=0.01)
	{
		  Y = (X-X0)*M +Y0 ;
    
	    glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2d(X,Y);
	
	}

 
   
}



void StraightLine_Parametric_eq(int X0 , int Y0 , int X1 , int Y1)
{
  int Xr = X1-X0 ;
  int Yr = Y1-Y0 ;

  for(float lamda=0 ; lamda <=1 ; lamda+=0.01 )
  {
   float  X = X0 + lamda*Xr ;
    
   float  Y = Y0 + lamda*Yr ;

    
	glVertex2d(X,Y);
  }
}



//============================================================================
void points()
{
    //point 1
	glColor3f(r1,g1,b1);
	glVertex3f(4.0f, 8.0f, 0.0f); 
    
	//point 2
	glColor3f(r2,g2,b2);
	glVertex3f(10.0f, 8.0f, 0.0f);
	
	//point 3 
	glColor3f(r3,g3,b3);
	glVertex3f(12.0f, 6.0f, 0.0f);
    
	//point 4
   glColor3f(r4,g4,b4);
   glVertex3f(10.0f, 4.0f, 0.0f);
	
	//point 5
    glColor3f(r5,g5,b5);
	glVertex3f(4.0f, 4.0f, 0.0f);
	
	//point 6
    glColor3f(r6,g6,b6);
	glVertex3f(2.0f, 6.0f, 0.0f);


}




void pointColor()
{
	cout<< "Color of the Points [RGB System] = "; cin>>rp ; cin>>gp ;cin>>bp ;
	glColor3f(rp,gp,bp);
}


void pointsColor()
{

	cout<<"\n\nif you want to put your color for each Point write y for (yes) any keyword for (no) : "; cin>>pcolor;

				if(pcolor == 'y')
				{
					cout<< "(hint: color rate must between (0-1).)\n\n\nColor Point 1 [RGB System] = "; cin>>r1 ; cin>>g1 ;cin>>b1 ;
					cout<< "Color Point 2[RGB System] = "; cin>>r2 ; cin>>g2 ;cin>>b2 ;
					cout<< "Color Point 3[RGB System] = "; cin>>r3 ; cin>>g3 ;cin>>b3 ;
					cout<< "Color Point 4[RGB System] = "; cin>>r4 ; cin>>g4 ;cin>>b4 ;
                    cout<< "Color Point 5[RGB System] = "; cin>>r5 ; cin>>g5 ;cin>>b5;
                    cout<< "Color Point 6[RGB System] = "; cin>>r6 ; cin>>g6 ;cin>>b6 ;



				
				}


}

void backgroundColor_and_Orthog()
{
do{ 
	
	cout<<"please set the backgraoud color parameters (between 0 to 1 )";
	cout <<"\n red = "; cin>>r;
	cout<<"\n green ="; cin>>g;
	cout<<"\n blue = "; cin>>b;
	
	}while ((r < 0 || r > 1) && (g < 0 || g > 1) && (b < 0 || b > 1)  );

cout<<"please set the orthogonality ";
	cout <<"\n x_start = "; cin>>xs;
	cout <<"\n x_end = "; cin>>xe;
	cout <<"\n y_start = "; cin>>ys;
	cout <<"\n y_end = "; cin>>ye;

}

//==================================================================================================================

void premitives()
{
cout << "\n\nThere many perimitives try with anyone you want.\n\n (hint: We use 6 Points for drawing your Premitives and you write only NO. of\n the Premitive.)\n\n";
				cout <<"         ( 1-GL_POINTS      6-GL_TRIANGLE_STRIP\n";
	            cout <<"           2-GL_LINES       7-GL_TRIANGLE_FAN\n";
	            cout <<"           3-GL_LINE_STRIP  8-GL_QUADS\n";
	            cout <<"           4-GL_LINE_LOOP   9-GL_QUAD_STRIP\n";
	            cout <<"           5-GL_TRIANGLES   10-GL_POLYGON ).\n\nYour choice is = "; cin >> PChoice;

				


				switch (PChoice)
				{

			case 1 :
				premitive = GL_POINTS;
				break;
			case 2 :
				premitive = GL_LINES;
				break;
			case 3 :
				premitive = GL_LINE_STRIP;
				break;
			case 4 :
				premitive = GL_LINE_LOOP;
				break;
            case 5 :
				premitive = GL_TRIANGLES;
				break;
            case 6 :
				premitive = GL_TRIANGLE_STRIP;
				break;
            case 7 :
				premitive = GL_TRIANGLE_FAN;
				break;
			case 8 :
				premitive = GL_QUADS;
				break;
			case 9 :
				premitive = GL_QUAD_STRIP;
				break;
			case 10 :
				premitive = GL_POLYGON;
				}

				
}

void Transformations()
{
	premitives();


				cout <<"We have many types of transformation choose whatever you want(Write only No. of your choice.):\n\n";
				cout<<"1-Translate.\t2-Rotate(Origin).\t3-Rotate(pivotPoint).\n\n4-Scale(PivotPoint).\t5-Reflection about x-axis.\t6-Reflection about y-axis.\n\n7-Reflection about originPoint.";
				cout<<"\n\nYour choice is : ";cin>>transformation;

				
				pointsColor();

				switch (transformation)
				
				{
			
				case 1:
					cout<<"Enter tx = "; cin>>tx;
					cout<<"Enter ty = "; cin>>ty;
					break;
				case 2:
					cout<<"If Rotate is ClockWise write (y), any keyword if Rotate is UntiClockWise: "; cin>>thstate;
				    
					cout<<"Enter Theata = "; cin>>th;
					break;
				case 3:
					cout<<"Enter px = "; cin>>px;
					cout<<"Enter py = "; cin>>py;
					cout<<"Enter Theata = "; cin>>th;
					cout<<"If Rotate is ClockWise write (y), any keyword if Rotate is UntiClockWise: "; cin>>thstate;
					break;
				case 4:
					cout<<"Enter Sx = "; cin>>sx;
					cout<<"Enter Sy = "; cin>>sy;
					
				}
}



//==================================================================================================================



void UserOptions()
{

do{

	
			cout << "\n\nchoose from the following what you want to draw :\n\n";
			cout<<"(Hint:We using only six Points in our program if you choose (Primitives or Transformations))\n\n";
			cout<<" (write the No. of what you have choosed)\n\n\n";
			cout <<"1-Line (StraitLine eq).\t2-Line(Parametric eq).\n\n3-Circle.\t4-EllipseShape.\n\n5-Premitives.\t6-Transformations.\n\n\n Your choice is = "; cin>>choice;
	
		}while(choice > 6 || choice < 1);


		

		
		switch (choice)
 
		{
			case 1 :
				cout << "\n\nEnter your First Point : \n X0 =  "; cin>>Xl0; cout<<"\n Y0 = "; cin>>Yl0;
				cout << "\n\nEnter your Second Point : \n X1 =  "; cin>>Xl1; cout<<"\n Y1 = "; cin>>Yl1;
				pointColor();
				break;
			case 2 :
				cout << "\n\nEnter your First Point : \n X0 =  "; cin>>Xp0; cout<<"\n Y0 = "; cin>>Yp0;
				cout << "\n\nEnter your Second Point : \n X1 =  "; cin>>Xp1; cout<<"\n Y1 = "; cin>>Yp1;
				pointColor();
					
			break;
            case 3 :
	
			cout << "\n\nEnter your radius = "; cin >>radius;
          	cout << "\n\nEnter your Xcenter,Ycenter  = "; cin >> Xcenter; cin >> Ycenter;
           pointColor();
  
			break;
			case 4:

		    cout << "\n\nEnter your radius of X-axis = "; cin >>Xradius;
			cout << "\n\nEnter your radius of Y-axis = "; cin >>Yradius;
          	cout << "\n\nEnter your Xcenter,Ycenter  = "; cin >> XcOval; cin >> YcOval;
           pointColor();

			break;
			case 5 :
				premitives();

				pointsColor();
			break;
			case 6 :

				Transformations();
				
		}
		
}
