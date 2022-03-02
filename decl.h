//
// Created by Aashish  on 21-05-2018.
//

#ifndef SSPROJ_DECL_H
#define SSPROJ_DECL_H

#endif //SSPROJ_DECL_H

float tx=0,ty=0,tz=0, Trans_y=0, alpha=0, T_z=200, z_viewvol= -120, saturn_tx=0;
unsigned char mainkey='s';

// 0:Sun, 1:Jupiter, 2:RedPlanet, 3:Saturn, 4:BluePlanet, 5: LovePlanet 6: LastPlanet  {R, G, B, Tx, Ty, Tz, Radius}....eachplanet: SolidSphere
float planets[6][7]= { {0.96,0.96,0.5,0,65,-2400,60}, {1,0.1,0.1,80,-30,-3600,50}, {0.96,0.33,0.33,-300,0,-1800,30},
                       {0.96,0.9,1,-440,20,-4200,50}, {0.67,0.95,0.365,100,0,-800,30}, {0.16,0.7,0.96,10,-70,-1600,50}  };

// {Base_Radius, Top_Radius, height, all-color}   // Seperate Color for array...
float BsterCylTypes[9][4]= {{1, 0.1, 3, 0.6}, {1, 0.9, 0.5, 0}, {2, 1, 3, 0.6}, {2, 2, 6, 0.6}, {2.05, 2.05, 0.3, 0},
                            {2.2, 1.7, 1, 0}, {2.2, 1.7, 1, 0.4}, {2.7, 2.2, 1.5, 0.4}, {2.4, 1.8, 2, 0.6} };                        // total 9 rings

int BsterCylOrder[] = {0, 1, 2, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 5, 6, 5, 6, 5, 6, 7, 8};             // Total 19

float BlackStripPlate[7][4] = { {1.9,-6,13,10.31},  {11.7,-6,-13,10.31}, {-2.7,-11,43,7}, {16.2,-11,-42,7},
                                {-3.8,-14,19,3.17}, {17.2,-14,-19,3.17}, {-3.8,-14,90,21} };

float Shuttle_Plates[3][4] = { {-6,10,1,0.5}, {-11,5,1.9,1}, {-14,3,2.1,1.9} };

GLUquadricObj* leftbooster, *maintank, *shuttle;
GLfloat pos[]= { -10, 20, -60, 1};						//light position         //{-2,4,5,1}
GLfloat amb [] = {0.7, 0.7, 0.7, 1.0};				//Ambient intensity 
GLfloat front_amb_diff[]= {0.8, 0.7, 0.7,1.0};	//Front side property
GLfloat back_amb_diff[]= {0.4,0.7,0.1,1.0};		//Back side property
GLfloat spe[]= {0.25,0.25,0.25,1.0};			//Property for front and back
GLfloat spe2[]= {80};			            //Property for front and back
GLfloat theta=0,dt=0.7, axes[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
int axis = 0; 					         	//0:x, 1:Y, 2:Z, 3:light aroundz
