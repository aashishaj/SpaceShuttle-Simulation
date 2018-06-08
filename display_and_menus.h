//
// Created by Aman on 21-05-2018.
//

#ifndef SSPROJ_DISPLAY_AND_MENUS_H
#define SSPROJ_DISPLAY_AND_MENUS_H

#endif //SSPROJ_DISPLAY_AND_MENUS_H

#include <windows.h>
#include <iostream>
using namespace std;
void Display_Control_Menu(){

    fprintf(stdout, "Rocket Animation Project by Mrunal and Kiran");
    cout<<"\n\nPress 's' to Start Main Project....\nPress 'o' to see only Shuttle \nPress 'r' to see shuttle in different angle"<<endl;
    cout<<"Press 'd' to see shuttle only on different view along different axis \nPress 'g' to see Solar System or Galaxy"<<endl;
    cout<<"Press 'p' to seperate shuttle\nPress 'l' to see booster only\n";
    cout<<"Press 'k' to see shuttle discovery only\nPress 'm' to see orange main tank only\nPress 'q' to quit\n";
}

void keyboard(unsigned char key, int x, int y){
    if(key=='s'||key=='o'||key=='r'||key=='d'||key=='g'||key=='p'||key=='l'||key=='k'||key=='m'||key=='q' )
    {    mainkey = key;                // main key used in display function...
        if (key=='p')
            theta = 45;
        else if(key == 's')
        {
            theta = 0;
            T_z = 200;
        }

    }

    else{
        mainkey='s';

    }

    glutPostRedisplay();

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();		//Preserve the CTM that Puts the objects in View Volume.

    glLightfv(GL_LIGHT0, GL_POSITION, pos);                  // lighting on shuttle

    switch(mainkey){

        case 's':{
            // Displays all Planets
            glPushMatrix();
            glTranslated(0, 0, T_z);
            BackGroundSphere();
            AllPlanets();
            Jupiter_Moon();
            glPopMatrix();

            T_z= T_z + 10;                               // To Move along z-axis towards origin.....for moving effect

            if(theta>359 && theta < 360)                  // just for reseeting the values....when theta reaches 360
            {  T_z = 0;
                z_viewvol= -120;
            }

            if(theta < 46)
            {
                glPushMatrix(); 				//Preserve CTM for object
                glTranslated(tx, ty, 0);
                glTranslated(6, 0, -120);
                glRotated(-theta*1.3, 1, 0, 0);
                glTranslated(-6, 0, 120);
                shuttle_main();                  // Shuttle Main
                glPopMatrix();

            }
            else if(theta>=46 && theta < 80){
                glPushMatrix();
                glTranslated(6.7, 0, -120);
                glRotated(-62, 1, 0, 0); 	//rotate light around z
                glTranslated(-6.7, 0, 120);
                shuttle_seperate();            // Shuttle Seperate
                glPopMatrix();
            }
            else{
                glPushMatrix();

                glTranslated(random(-1,1)*0.05, Trans_y + random(-1,1)*0.05, random(-1,1)*0.05 );

                glTranslated(6.7, 0, -120);
                glRotated(-48, 1, 0, 0);
                glTranslated(-6.7,0,120);

                glPushMatrix();
                glTranslated(6.7, 0, -120);
                glRotated(alpha, 0, 1, 0);
                alpha = alpha+1;                // for rotation angle...
                glTranslated(-6.7, 0, 120);

                shuttle_Discovery();          // Only Shuttle...no main tank...no boosters
                fire(1);
                if(T_z > 3600)
                    z_viewvol-=0.20;
                glPopMatrix();

                glPopMatrix();
            }
            break;        // case 's': start ends here
        }

        case 'o': shuttle_main();                   // Case: 'o'  for only shuttle....display shuttle only
            break;
        case 'r': glTranslated(6.7, 0, -100);         // case: 'r' for main shuttle in differetn view
            glRotated(-40, 1, 0, 0);
            glTranslated(-6.7, 0, 100);
            shuttle_main();
            break;
        case 'd': glTranslated(6.7, 0, -100);          // case: 'd' for main shuttle in different view...along z-axis
            glRotated(-40, 1, 0, 1);
            glTranslated(-6.7, 0, 100);
            shuttle_main();
            break;
        case 'g':  BackGroundSphere();                 // case: 'g' for galaxy view...or solar system view
            AllPlanets();
            Jupiter_Moon();
            break;
        case 'p': shuttle_seperate();                  // case: 'p' for space shuttle seperate view
            break;
        case 'l': shuttle_leftBooster(false);
            break;
        case 'k': shuttle_Discovery();
            break;
        case 'm': shuttle_main_tank();
            break;
        case 'q':
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        //glClearColor(0,0,0,0);
        frontscreendisp();
        //Sleep(100);
        break;
    }// Switch ends here

    glPopMatrix();  						         //restore CTM for object
    glutSwapBuffers();
}

void idle(void){
    theta = (theta <360) ? theta+dt:dt; //increment rotation angle
    tx= tx - 0.05;
    ty = ty + 0.08;
    glutPostRedisplay();
}
