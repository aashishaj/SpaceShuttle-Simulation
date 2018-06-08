
#include <iostream>
#include <gl/glut.h>            // OpenGL Graphics Utility Library
#include <gl/glu.h>
#include <math.h>
#include <stdio.h>
#include "misc.h"
#include "decl.h"
#include "drawings.h"
#include "shuttle_drawer_animator.h"
#include "planets_drawer.h"
#include "display_and_menus.h"
using namespace std;

void main(int argc, char **argv){

    pos[2] = z_viewvol+20;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Rocket 3D Animation - striker");
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 20, 9000);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, back_amb_diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spe);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, spe2);

    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    Display_Control_Menu();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutMainLoop();
}
