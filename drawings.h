//
// Created by Aman on 21-05-2018.
//

#ifndef SSPROJ_DRAWINGS_H
#define SSPROJ_DRAWINGS_H

#endif //SSPROJ_DRAWINGS_H

void BackGroundSphere(){

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslated(0, 0, -4000);
    glutWireSphere(4000, 12, 12);                      // Big Wire Sphere.....to give feel of order in Solar System
    glPopMatrix();
}
