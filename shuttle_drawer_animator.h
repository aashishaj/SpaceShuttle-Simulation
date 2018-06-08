//
// Created by Aman on 21-05-2018.
//

#ifndef SSPROJ_SHUTTLE_DRAWER_H
#define SSPROJ_SHUTTLE_DRAWER_H

#endif //SSPROJ_SHUTTLE_DRAWER_H

/* You must have seen the Orange color tank on which shuttle hangs when the shuttle launches,
 * this function builds that Orange Tank.
 */
void shuttle_main_tank(){
    glPushMatrix ();
    maintank = gluNewQuadric();
    gluQuadricDrawStyle(maintank, GLU_FILL);
    gluQuadricNormals(maintank, GLU_SMOOTH);
    gluQuadricOrientation(maintank, GLU_OUTSIDE);

    glColor3f(1, 0.51, 0.04);
    // for Top of Main Orange Color Tank
    float h=0;
    for(float r= 4.7; r>=0; r-= 0.5){

        glPushMatrix();
        glTranslated(7.5, 22+h, 0);         // Flexible to take it up and down
        glTranslated(0, 0, z_viewvol);            // Translation ....must for cylinders
        glRotated(-90, 1, 0, 0);              // Rotation.....must for cylinders
        gluCylinder(maintank, r, r, 1 , 100, 100);
        h++;
        glPopMatrix();
    }

    glTranslated(7.5, -18, z_viewvol);
    glRotated(-90, 1, 0, 0);
    gluCylinder(maintank, 4.7, 4.7, 40, 32, 32);                  // Main Tank...orange color...completes main cylinder
    glPopMatrix();

    glPushMatrix();                          // for spherical bottom of main tank...
    glTranslated(7.5, -18, z_viewvol);
    glRotated(-90, 1, 0, 0);                    // Rotate Cylinder along X-axis...to make it look vertical
    glutSolidSphere(4.7, 32, 32);
    glPopMatrix();
}

/* This function builds both wings of shuttle.
 */

void shuttle_plate(){                // Shuttle Plate == Shuttle Wings.....Wings make in 3 sections
    glColor3f(1, 1, 1);
    for(int i=0; i<3; i++){         // ShuttlePlates: 0: Top Plate, 1: Middle Plate, 2: Bottom Plate
        glPushMatrix ();
        glTranslated(6.7, Shuttle_Plates[i][0], 6+z_viewvol);
        glScalef(5, Shuttle_Plates[i][1], 0);
        glRotated(-90, 1, 0, 0);
        gluCylinder(shuttle, Shuttle_Plates[i][2], Shuttle_Plates[i][3], 1, 32, 32);
        glPopMatrix();
    }

    glColor3f(0.2, 0.2, 0.2);
    //  For all Black Strips on Shuttle around wings // 0:LeftStripTopWing, 1:RightStripTopWing, 2:LeftStripMiddleWing, 3:RightStripMiddleWing,
    //  4:LeftStripBottomWing, 5:RightStripBottomWing, 6:HorizontalBottomStripBottomWing
    for(int i=0; i<7; i++){
        glPushMatrix ();
        glTranslated(BlackStripPlate[i][0], BlackStripPlate[i][1], 6+z_viewvol);
        glRotated(-90, 1, 0, 0);
        glRotated(BlackStripPlate[i][2], 0, 1, 0);
        gluCylinder(shuttle, 0.2, 0.2, BlackStripPlate[i][3], 32, 32);               // Cylindrical Black strip along wings
        glPopMatrix();
    } // for Loop Ends here
}



/*  This function gives the effect of fire, when the shuttle launches
 */


/*  This function builds the tail of shuttle
 */
void shuttleTail(){
    glColor3f(0.4, 0.4, 0.4);
    glPushMatrix ();
    glTranslated(6.7, -11, 10+z_viewvol);
    glRotated(50, 1, 0, 0);
    glScalef(1, 4, 7);
    gluCylinder(shuttle, 0.8, 0.5, 1, 32, 32);
    glPopMatrix();

    glPushMatrix ();                     // Tail...help
    glTranslated(6.7, -16.5, 13.3+z_viewvol);
    glScalef(1, 4, 2.5);
    gluCylinder(shuttle, 0.3, 0.5, 1, 32, 32);
    glPopMatrix();

    glPushMatrix ();                     // Tail...help
    glTranslated(6.7, -15.30, 14+z_viewvol);
    glRotated(90, 1, 0, 0);
    glScalef(1, 4, 2.5);
    gluCylinder(shuttle, 0.3, 0.3, 1, 32, 32);                  // Main cylinder of shuttle...white color...completes main cylinder
    glPopMatrix();
}

/*  This function builds the exhaust of shuttle
 */
void fire(int j){

    glPushMatrix();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glEnable(GL_BLEND);

    float flamethrower[5][3]={ {7,-20, 8.5}, {6,-20,7.5}, {8,-20,7.5}, {0,-25,0}, {15,-25,0}  };    // {T_x, T_y, T_z} for diferent boosters and shuttle

    for(int i=0; i<200; i++){
        glPushMatrix();
        glTranslated(flamethrower[j][0] + random(-3,3), flamethrower[j][1]-random2(0,20), flamethrower[j][2]+random(0,5));
        glTranslated(0, 0, z_viewvol);                // Translation ....must for cylinders

        if(i%3==0){
            glColor3f(1,0.46, 0);
            glutWireSphere(0.5, 32,32);
        }
        else if(i%2==0)
        { glColor3f(1,0.64,0);
            glutWireTetrahedron();
        }
        else{
            glColor3f(0.95,0.95,0.2);
            glutSolidOctahedron();
        }
        glPopMatrix();
    }  // for loop ends here

    glDisable(GL_BLEND);
    glPopMatrix();
}

void shuttle_exhaust(){                    // Use 7 cylindrical rings and 2 cones for each exhaust(Silencer) of Shuttle
    float r=1, T_y=-16, height;
    float exhaust[3][2] = { {6.7, 12}, {5, 7}, {9, 7} };             // {T_x, T_y}

    for(int j=0; j<3; j++){
        glColor3f(0, 0, 0);
        r=1;
        T_y = -16;

        for(int i=0; i<7; i++){
            glPushMatrix ();                                // for shuttle exhaust
            glTranslated(exhaust[j][0], T_y, exhaust[j][1]+z_viewvol);
            glRotated(-90, 1, 0, 0);                      // Rotation.....must for cylinders
            gluCylinder(shuttle, r, r, 0.40, 32, 32);                  // Main cylinder of shuttle...white color...completes main cylinder
            glPopMatrix();
            T_y = T_y - 0.5;
            r= r+0.15;
        }
        height=0;
        glColor3f(0.3, 0.3, 0.3);

        for(int i=0; i<2; i++)  {
            glPushMatrix ();                                // for shuttle exhaust
            glTranslated(exhaust[j][0], T_y, exhaust[j][1]+z_viewvol);
            glRotated(-90, 1, 0, 0);                      // Rotation.....must for cylinders
            height = -T_y -16;
            glutSolidCone(r, height, 32,32);                  // One Cone in the exhaust ring
            glPopMatrix();

            glColor3f(.92,0.75,0.05);
            T_y = T_y -0.2;
        }
    }// Main for loop ends here
}
/*  This function builds the main cylndrical body of space shuttle
 */

void shuttle_Discovery(){
    glTranslated(0, -3, 0);
    shuttle = gluNewQuadric();
    gluQuadricDrawStyle(shuttle, GLU_FILL);
    gluQuadricNormals(shuttle, GLU_SMOOTH);
    gluQuadricOrientation(shuttle, GLU_OUTSIDE);

    glColor3f(0, 0, 0);
    glPushMatrix ();                                // for hemispherical topmost front of shuttle...
    glTranslated(6.7, 13.5, 9+z_viewvol);
    glutSolidSphere(1.4, 32, 32);
    glPopMatrix();

    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix ();                               // for front curve of shuttle...where we have windscreen and stuff
    glTranslated(6.7, 7, 9+z_viewvol);
    glRotated(-90, 1, 0, 0);
    gluCylinder(shuttle, 3.2, 1.4, 6.5, 32, 32);
    glPopMatrix();

    glColor3f(0.3, 0.3, 0.3);                  // Color for Windscreen
    // 0: middle windscreen, 1: left windscreen, 2: right windscreen {T_x, T_y, T_z, R_y}  R_y: Rotation along y-axis
    float windscreens[3][4] = { {6.7, 9, 10.9, 0}, {5.3, 8.4, 10.7, 1}, {8, 8.4, 10.7, -1} };

    for(int i=0; i<3; i++){
        glPushMatrix ();                     // for front windscreen middle
        glTranslated(windscreens[i][0], windscreens[i][1], windscreens[i][2]+z_viewvol);
        glRotated(45, 1, windscreens[i][3], 0);              // Rotation.....must for cylinders
        gluCylinder(shuttle, 1, 0.5, 1, 32, 32);
        glPopMatrix();
    }

    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix ();                         // Main Cylindrical Body of Shuttle
    glTranslated(6.7, -12, 9+z_viewvol);
    glRotated(-90, 1, 0, 0);
    gluCylinder(shuttle, 3.2, 3.2, 19, 32, 32);     // Main cylinder of Shuttle
    glPopMatrix();

    glColor3f(0, 0, 0);                   // Color for Windows
    int windowsY[5]={3, 0, -3, -6, -9};                 // Window pipes in horizontal direction.... 5 Windows in Shuttle
    for(int i=0; i<5; i++){
        glPushMatrix ();                     // Cubic Windows
        glTranslated(6.7, windowsY[i], 10+z_viewvol);       // change 6 to new value..after using cube.....
        glScalef(6.1, 1, 1);
        glutSolidCube(1);
        glPopMatrix();
    }

    glColor3f(0.6, 0.6, 0.6);
    // merging cylinders
    glPushMatrix ();                     // Tail Bottom Tank...1st merging cylinder
    glTranslated(6.7, -15, 9+z_viewvol);
    glRotated(-90, 1, 0, 0);
    gluCylinder(shuttle, 3.2, 3.2, 3, 32, 32);
    glPopMatrix();

    glPushMatrix ();                     // Tail Bottom Tank...2nd merging Cylinder
    glTranslated(6.7, -15, 10+z_viewvol);
    glRotated(-90, 1, 0, 0);
    gluCylinder(shuttle, 3.2, 3.2, 3, 32, 32);
    glPopMatrix();

    // for shuttle....exhaust....
    shuttle_exhaust();
    glColor3f(0.4, 0.4, 0.4);
    shuttleTail();
    shuttle_plate();                 // for shuttle plates and strip
    //fire(0);
    //fire(1);
    //fire(2);
}
/*  This function builds the left solid booster of shuttle
 */
void shuttle_leftBooster(bool callfromRight){               // left solid booster

    leftbooster = gluNewQuadric();
    gluQuadricDrawStyle(leftbooster, GLU_FILL);
    gluQuadricNormals(leftbooster, GLU_SMOOTH);
    gluQuadricOrientation(leftbooster, GLU_OUTSIDE);

    int j, height=0;       // j to control other array.....height(in the upcoming loop) from prev. loop case...used in next case...
    for(int i=0; i < 21; i++){
        j = BsterCylOrder[i];
        height = height + BsterCylTypes[j][2];         // Total Height needed for translation
        glPushMatrix();
        glColor3f(BsterCylTypes[j][3], BsterCylTypes[j][3], BsterCylTypes[j][3]);
        glTranslated(0, 20-height, 0);         // Flexible to take it up and down
        glTranslated(0, 0, z_viewvol);
        glRotated(-90, 1, 0, 0);              // Rotation.....must for cylinders
        gluCylinder(leftbooster, BsterCylTypes[j][0], BsterCylTypes[j][1], BsterCylTypes[j][2], 40, 100);
        glPopMatrix();
    }
    if(callfromRight==true)
        return;

    fire(3);
}
/*  This function builds the right solid booster of shuttle
 */

void shuttle_rightBooster(){              // right solid booster
    glPushMatrix ();
    glTranslated(15, 0, 0);
    shuttle_leftBooster(true);
    glPopMatrix();
    fire(4);                            // Starts fire for Right Booster
}
