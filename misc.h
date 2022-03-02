//
// Created by Aman on 21-05-2018.
//

#ifndef SSPROJ_MISC_H
#define SSPROJ_MISC_H

#endif //SSPROJ_MISC_H

float random2(int min, int max){                // needed to throw flames

    again: int i=(rand()%100);
    if(i>=min && i<=max)
        return i;
    else
        goto again;
}

float random(int min, int max){            // random function: self defined....needed to throw flames

    again: int i=(rand()%100)/10;
    if(max < 7){
        if(i==8||i==7)
            i= -1;
        else if(i==9)
            i = -2;
    }

    if(i>=min && i<=max)
        return i;
    else
        goto again;
}

void drawBitmapText( float x, float y, float z,char *string)
{
    char *c;
    glRasterPos3f(x, y, z);

    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}

void frontscreendisp(void)
{
    int const w = glutGet(GLUT_WINDOW_WIDTH);
    int const h = glutGet(GLUT_WINDOW_HEIGHT);
    char ch;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1,0.5,0);
    drawBitmapText(275+50,200,0.0,"A MINI PROJECT ON:");
    glColor3f(1,0,0);
    drawBitmapText(275+50,225,0.0,"ROCKET SIMULATION");
    glColor3f(1,0.5,0);
    drawBitmapText(150+50,250,0.0,"BY:");
    glColor3f(0.5,0,0.5);
    drawBitmapText(150+50,275,0.0,"Khatri Mrunal Mohan                 (USN:1MV15CS049)");
    drawBitmapText(150+50,300,0.0,"Aashish Prakash                     (USN:1MV15CS002)");
    glColor3f(1,0.5,0);
    drawBitmapText(500+50,475,0.0,"PLEASE CLOSE THE WINDOW");

}
