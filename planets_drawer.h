//
// Created by Aman on 21-05-2018.
//

#ifndef SSPROJ_PLANETS_DRAWER_H
#define SSPROJ_PLANETS_DRAWER_H

#endif //SSPROJ_PLANETS_DRAWER_H

void Jupiter_Moon(){
    // Array stores...{Tx, Tz} of Moons to display them near Jupiter
    int moon[3][2] = {{20, -3600}, {80, -3540}, {80, 3660}};
    for(int i=0; i<3; i++){
        glPushMatrix();
        glColor3f(1, 0.8, 0.8);
        glTranslated(moon[i][0], -20, moon[i][1]);                     // centre at Tx, Ty, Tz
        glutSolidSphere(5, 32, 32);                     //radius: 50
        glPopMatrix();
    }
}

void AllPlanets(){                              // All planets and Sun

    for(int i=0; i<6;i++){
        glPushMatrix();
        glColor3f(planets[i][0], planets[i][1], planets[i][2]);
        if(i==3){
            glTranslated(planets[i][3]+saturn_tx, planets[i][4], planets[i][5]);
            saturn_tx += 1;
        }else{
            glTranslated(planets[i][3], planets[i][4], planets[i][5]);                // centre at Tx, Ty, Tz
        }
        glutSolidSphere(planets[i][6], 32, 32);
        glPopMatrix();
    }
}

// Assembles all part of Space Shuttle: L and R Boosters, Main Tank, Main Shuttle-Discovery
void shuttle_main(){
    shuttle_leftBooster(false);        // false: for not calling from right booster function...
    shuttle_rightBooster();
    shuttle_main_tank();
    shuttle_Discovery();
}

/*  This function gives effect of shuttle seperating from solid boosters & orange color tank
 */
void shuttle_seperate(){
    theta = theta-45;
    glPushMatrix(); 				    // for left booster
    glRotated(theta, 1, 1, 0);
    shuttle_leftBooster(false);
    glPopMatrix();

    glPushMatrix(); 				    //  for right booster
    glRotated(theta, 1, -1, 0);
    shuttle_rightBooster();
    glPopMatrix();

    glPushMatrix(); 				   //for Orange main tank
    glRotated(theta, -1, 0, 1);
    shuttle_main_tank();
    glPopMatrix();

    glPushMatrix(); 				       //for shuttle
    glRotated(theta/3, 1, 0, 0);
    shuttle_Discovery();
    glPopMatrix();

    theta = theta +45;                   // Resetting theta

}
