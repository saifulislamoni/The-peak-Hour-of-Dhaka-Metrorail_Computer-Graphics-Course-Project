/*
    Saiful Islam Oni ->  22-49196-3
    Md Sazzad Khan   ->  22-49172-3
*/


#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<string.h>
#include<math.h>


GLfloat positioX = -3.0f;
GLfloat positioGateXL = 0.0f,LiftGateXL=1.0f;
GLfloat positioGateXR = 0.0f,LiftGateXR=1.0f;
bool isGateOpen = false; // Gate is closed initially

GLfloat D3positionMenX = 0.01f;
GLfloat D3positionMenY = 0.01f;
GLfloat D3ManScalX = 0.8f;
GLfloat D3ManScalY = 0.8f;

GLfloat D5positionMenX = 0.01f;
GLfloat D5positionMenY = 0.01f;
GLfloat D5ManScalX = 0.7f;
GLfloat D5ManScalY = 0.7f;

GLfloat D11positionMenX = 0.00f;
GLfloat D11positionMenY = 0.35f;
GLfloat D11ManScalX = 0.00f;
GLfloat D11ManScalY = 0.00f;


GLfloat positionMenX = 0.01f;
GLfloat positionMenY = 0.01f;


GLfloat ManScalX = 0.6f;
GLfloat ManScalY = 0.6f;


GLfloat LiftMenX = -0.1f;
GLfloat LiftMenY = -0.1f;
GLfloat LiftManScalX = 0.9f;
GLfloat LiftManScalY = 0.9f;


GLfloat D13LiftManScalX=0.00f;
GLfloat D13LiftManScalY=0.00f;
GLfloat D13LiftMenX = -0.1f;
GLfloat D13LiftMenY = -0.1f;

GLfloat Speed_positionMenX = 0.01f;
GLfloat Speed_positionMenY = 0.01f;
GLfloat speed = 0.1f;
GLfloat speedrTrainAtStation=0.01f;
GLfloat SkyR=0.60f,SkyG=0.84f, SkyB=1.0f;
GLfloat WR=0.92f, WG=0.95f, WB=0.45f;
//For Display TEXT
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_HELVETICA_18;

void update(int value)
{

    if(positioX>3.96)
    {
        positioX =-3.96f;
    }
    if (positionMenX < -1.0f || positionMenY < -1.0f)
    {
        Speed_positionMenX = -Speed_positionMenX; // Reverse direction
        Speed_positionMenY = -Speed_positionMenY;
    }

    positioX += speed;

    glutPostRedisplay();
    glutTimerFunc(50,update,0);
}


void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void drawMan()
{


    // Head (Circle)
    glPushMatrix();
    glColor3f(0.9f, 0.7f, 0.6f); // Skin color
    glTranslatef(0.0f,-0.05f, 0.0f); // Position the head
    float headRadius = 0.1f;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 100; i++)
    {
        float angle = 2.0f * 3.1416f * i / 100; // Angle in radians
        float x = headRadius * cos(angle);
        float y = headRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Body (Rectangle)
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.5f); // Blue shirt
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.15f); // Top-left
    glVertex2f(0.1f, -0.15f);  // Top-right
    glVertex2f(0.1f, -0.45f); // Bottom-right
    glVertex2f(-0.1f, -0.45f); // Bottom-left
    glEnd();
    glPopMatrix();

    // Left Arm (Rectangle)
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.5f); // Blue shirt
    glBegin(GL_POLYGON);
    glVertex2f(-0.1f, -0.15f); // Top-right
    glVertex2f(-0.12f, -0.15f); // Top-left
    glVertex2f(-0.170f, -0.45f); // Bottom-right
    glVertex2f(-0.125f, -0.45f); // Bottom-left
    glVertex2f(-0.1f, -0.25f); // Top-right
    glEnd();
    glPopMatrix();

    // Right Arm (Rectangle)
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.5f); // Blue shirt
    glBegin(GL_POLYGON);
    glVertex2f(0.1f, -0.15f); // Top-left
    glVertex2f(0.12f, -0.15f); // Top-right
    glVertex2f(0.170f,-0.45f); // Bottom-right
    glVertex2f(0.125f, -0.45f); // Bottom-left
    glVertex2f(0.1f, -0.25f);
    glEnd();
    glPopMatrix();

    // Left Leg (Rectangle)
    glPushMatrix();
    glColor3f(0.15f, 0.0f, 0.0f); // Black pants
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.45f); // Top-left
    glVertex2f(0.0f, -0.45f);  // Top-right
    glVertex2f(-0.015f, -0.75f);  // Bottom-right
    glVertex2f(-0.1f, -0.75f); // Bottom-left
    glEnd();
    glPopMatrix();

    // Right Leg (Rectangle)
    glPushMatrix();
    glColor3f(0.15f, 0.0f, 0.0f); // Black pants
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -0.45f);  // Top-left
    glVertex2f(0.1f, -0.45f); // Top-right
    glVertex2f(0.1f, -0.75f); // Bottom-right
    glVertex2f(0.015f, -0.75f);  // Bottom-left
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}




///////////////////////////////////////////////////////Metro Station Start/////////////////////////////////////////////////////////////
void MetroStationInside()
{
    //Back Wall
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.80,0.8f,0.80f); // Red
    glVertex2f(1.2f,0.6f);
    glVertex2f(-1.5f,0.6f);
    glVertex2f(-1.5f, -0.5f);
    glVertex2f(1.2f, -0.5f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


    //Upper Wall
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.70,0.7f,0.70f); // Red
    glVertex2f(1.2f,0.6f);
    glVertex2f(1.2f,1.0f);
    glVertex2f(-1.5f,1.0f);
    glVertex2f(-1.5f,0.6f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix



    //Front Floor
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.20,0.2f,0.20f); // Red
    glVertex2f(1.2, -0.5f);
    glVertex2f(-1.5f, -0.5f);
    glVertex2f(-1.5f,-1.6f);
    glVertex2f(1.5f,-1.6f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


    // TOP Sign Board
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.0,0.6f,0.0f); // Red
    glVertex2f(0.4f,0.525f);
    glVertex2f(-0.4f,0.525f);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(0.4f, 0.4f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

    glColor3f(1.0,1.0,1.0);
    char string[]="Metro Rail Ticket Counter";
    glRasterPos2f(-0.330f,0.435f);
    int len=strlen(string);
    for(int i=0; i<len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }

}
void MetroTicketCounter()
{
    /////////////////////////////////////////////////////////////////Ticket Counter Middle
    //Main Body

    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.292f,0.292f,0.292f); // Red
    glVertex2f(0.20f,0.225f);
    glVertex2f( -0.20f, 0.225f);
    glVertex2f( -0.20f,-0.50f);
    glVertex2f(0.20f, -0.50f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

    // Upper Green Part
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.0,0.6f,0.0f); // Red
    glVertex2f(0.175f,0.2f);
    glVertex2f(-0.175f,0.2f);
    glVertex2f(-0.175f,0.125f);
    glVertex2f(0.175f,0.125f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

//TEXT for Ticket Counter
    glColor3f(1.0,1.0,1.0);
    char string[]="Ticket Counter";
    glRasterPos2f(-0.15f,0.145f);
    int len=strlen(string);
    for(int i=0; i<len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
    }

    //Screen Body
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.412f,0.412f,0.412f); // Red
    glVertex2f(0.15f,0.075f);
    glVertex2f(-0.15f,0.075f);
    glVertex2f(-0.15f,-0.2f);
    glVertex2f(0.15f,-0.2f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


    //Screen Border top
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.128,0.128f,0.128f); // Red
    glVertex2f(0.15f,0.075f);
    glVertex2f(0.15f,0.1f);
    glVertex2f(-0.15f,0.1f);
    glVertex2f(-0.15f,0.075f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

    //Screen Border left
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.128,0.128f,0.128f); // Red
    glVertex2f(-0.15f,0.1f);
    glVertex2f(-0.175f,0.1f);
    glVertex2f(-0.175f,-0.2f);
    glVertex2f(-0.15f,-0.2f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

    //Screen Border Right
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.128,0.128f,0.128f); // Red
    glVertex2f(0.15f,0.1f);
    glVertex2f(0.175f,0.1f);
    glVertex2f(0.175f,-0.2f);
    glVertex2f(0.15f,-0.2f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

    //Main Screen
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.3f,0.6f,0.9f); // Red
    glVertex2f(0.075f,0.05f);
    glVertex2f(-0.075f,0.05f);
    glVertex2f(-0.075f,-0.125f);
    glVertex2f(0.075f,-0.125f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


    //Pocket Right
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.128f,0.128f,0.128f); // Red
    glVertex2f(0.075f,-0.15f);
    glVertex2f(0.075f,-0.175f);
    glVertex2f(0.125f,-0.175f);
    glVertex2f(0.125f,-0.15f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

    //Pocket Left
    glPushMatrix();
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.128f,0.128f,0.128f); // Red
    glVertex2f(-0.075f,-0.15f);
    glVertex2f(-0.075f,-0.175f);
    glVertex2f(-0.125f,-0.175f);
    glVertex2f(-0.125f,-0.15f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


    // Lower Green Part
    glPushMatrix(); // Save model-view matrix setting
    // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.0,0.6f,0.0f); // Red
    glVertex2f(0.175f,-0.25f);
    glVertex2f(-0.175f,-0.25f);
    glVertex2f(-0.175f,-0.325f);
    glVertex2f(0.175f,0-.325f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix
}

/////////////////////////////////////////////////////////////////////////Metro Station End///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////Metro Rail Departure Starts/////////////////////////////////////////////////////////////

void MetroStation(char str[])
{
    //Back Wall
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.80,0.8f,0.80f); // Red
    glVertex2f(1.2f,0.6f);
    glVertex2f(-1.5f,0.6f);
    glVertex2f(-1.5f, -0.2f);
    glVertex2f(1.2f, -0.2f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


    //Upper Wall
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.70,0.7f,0.70f); // Red
    glVertex2f(1.2f,0.6f);
    glVertex2f(1.2f,1.0f);
    glVertex2f(-1.5f,1.0f);
    glVertex2f(-1.5f,0.6f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

    //Front Floor
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.20,0.2f,0.20f); // Red
    glVertex2f(1.2, -0.3f);
    glVertex2f(-1.5f, -0.3f);
    glVertex2f(-1.5f,-1.6f);
    glVertex2f(1.5f,-1.6f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


    // TOP Sign Board
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.0,0.6f,0.0f); // Red
    glVertex2f(0.32f,0.75f);
    glVertex2f(-0.32f,0.75f);
    glVertex2f(-0.32f, 0.625f);
    glVertex2f(0.32f, 0.625f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.3f,0.660f);
    int len=strlen(str);
    for(int i=0; i<len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
    }

}


///////////////////////////////////////////////////////Metro Rail Departure Ends/////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////Metro Rail Transition Starts/////////////////////////////////////////////////////////////



void Sky()
{
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(SkyR,SkyG,SkyB); // Red
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f,0.5f);
    glVertex2f(1.0f,0.5f);
    glVertex2f(1.0f,1.0f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix
}

void Windows()
{
//windows right
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(WR,WG,WB); // Red
    glVertex2f(-0.08f, 0.7f);
    glVertex2f(-0.08f,0.5f);
    glVertex2f(-0.275f,0.5f);
    glVertex2f(-0.275f,0.7f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

//windows left
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(WR,WG,WB); // Red
    glVertex2f(-0.52f,0.7f);
    glVertex2f(-0.52f,0.5f);
    glVertex2f(-0.325f,0.5f);
    glVertex2f(-0.325f,0.7f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

}
void building0()
{
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.25f, 0.359f, 0.650f); // Red
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(0.0f,-1.0f);
    glVertex2f(0.0f,0.6f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix
}

void building01()
{
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.25f, 0.159f, 0.950f); // Red
    glVertex2f(0.0f, 0.9f);
    glVertex2f(0.0f,-1.0f);
    glVertex2f(0.6f,-1.0f);
    glVertex2f(0.6f,0.9f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

    glTranslatef(0.6f,0.0f,0.0f);
    Windows();
    glTranslatef(0.0f,-0.4f,0.0f);
    Windows();
    glTranslatef(0.0f,-0.4f,0.0f);
    Windows();
    glTranslatef(0.0f,-0.4f,0.0f);
    Windows();
}
void Building1()
{
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.125f, 0.159f, 0.350f); // Red
    glVertex2f(-0.6f, 0.8f);
    glVertex2f(-0.6f,-1.0f);
    glVertex2f(0.0f,-1.0f);
    glVertex2f(0.0f,0.8f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

    Windows();
    glTranslatef(0.0f,-0.4f,0.0f);
    Windows();
    glTranslatef(0.0f,-0.4f,0.0f);
    Windows();
    glTranslatef(0.0f,-0.4f,0.0f);
    Windows();

}

void Building2()
{
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.125f, 0.159f, 0.350f); // Red
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f,-1.0f);
    glVertex2f(0.2f,-1.0f);
    glVertex2f(0.2f,1.0f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


}

void MetroBoggy()
{
    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(positioX, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f); // Red
    glVertex2f(-1.96f, -0.3f);
    glVertex2f(-0.66f, -0.3f);
    glVertex2f(-0.66f, 0.2f);
    glVertex2f(-1.96f, 0.2f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

// Roof TOP
    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(positioX, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.6f, 0.6f, 0.6f); // Red
    glVertex2f(-1.96f, 0.2f);
    glVertex2f(-0.66f, 0.2f);
    glVertex2f(-0.715f,0.27f);
    glVertex2f(-1.905f, 0.27f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

// Green Line top of Gate
    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(positioX, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.5f, 0.0f); // Red
    glVertex2f(-1.96f, 0.12f);
    glVertex2f(-0.66f, 0.12f);
    glVertex2f(-0.66f, 0.17f);
    glVertex2f(-1.96f, 0.17f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


// Metro Gate inside view
    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(positioX, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.3f, 0.3f, 0.3f); // Red
    glVertex2f(-1.16f, 0.05f);
    glVertex2f(-1.46f, 0.05f);
    glVertex2f(-1.46f, -0.28f);
    glVertex2f(-1.16f, -0.28f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix



// Metro Gate Right
    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(positioX, 0.0f, 0.0f); // Translate
    glTranslatef(positioGateXR, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.6f, 0.6f, 0.6f); // Red
    glVertex2f(-1.16f, 0.05f);
    glVertex2f(-1.31f, 0.05f);
    glVertex2f(-1.31f, -0.28f);
    glVertex2f(-1.16f, -0.28f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


// Metro Gate Left
    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(positioX, 0.0f, 0.0f); // Translate
    glTranslatef(positioGateXL, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.6f, 0.6f, 0.6f); // Red
    glVertex2f(-1.31f, 0.05f);
    glVertex2f(-1.46f, 0.05f);
    glVertex2f(-1.46f, -0.28f);
    glVertex2f(-1.31f, -0.28f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


    if (!isGateOpen)
    {
        // RED BOX
        glPushMatrix(); // Save model-view matrix setting
        glTranslatef(positioX, 0.0f, 0.0f); // Translate
        glBegin(GL_QUADS); // Each set of 4 vertices form a quad
        glColor3f(0.8f, 0.0f, 0.0f); // Red
        glVertex2f(-1.29f, 0.05f);
        glVertex2f(-1.33f, 0.05f);
        glVertex2f(-1.33f, -0.28f);
        glVertex2f(-1.29f, -0.28f);
        glEnd();
        glPopMatrix(); // Restore the model-view matrix

        // Middle Line
        glPushMatrix(); // Save model-view matrix setting
        glTranslatef(positioX, 0.0f, 0.0f); // Translate
        glBegin(GL_LINES); // Each set of 4 vertices form a quad
        glColor3f(0.0f, 0.0f, 0.0f); // Red
        glVertex2f(-1.31f, 0.05f);
        glVertex2f(-1.31f, -0.28f);
        glEnd();
        glPopMatrix(); // Restore the model-view matrix
    }

// Right Window
    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(positioX, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.4f, 0.4f, 0.4f); // Red
    glVertex2f(-1.01f, 0.05f);
    glVertex2f(-1.01f, -0.15f);
    glVertex2f(-0.76f, -0.15f);
    glVertex2f(-0.76f, 0.05f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

// Left Window
    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(positioX, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.4f, 0.4f, 0.4f); // Red
    glVertex2f(-1.61f, 0.05f);
    glVertex2f(-1.61f, -0.15f);
    glVertex2f(-1.86f, -0.15f);
    glVertex2f(-1.86f, 0.05);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


}

void MetroStationFront()
{

// Metro Span
    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(0.0f, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.4f, 0.4f, 0.4f); // Red
    glVertex2f(-0.5f, -0.53f);
    glVertex2f(-0.5f, -0.28f);
    glVertex2f(1.0f, -0.28f);
    glVertex2f(1.0f, -0.53f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

// Metro SPan_Support
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.30f, -0.45f);
    glVertex2f(0.35f, -0.6f);
    glVertex2f(0.5f, -0.6f);
    glVertex2f(0.55f, -0.45f);
    glEnd();
    glPopMatrix();

// Metro Pillar
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.35f, -0.6f);
    glVertex2f(0.35f, -1.0f);
    glVertex2f(0.5f, -1.0f);
    glVertex2f(0.5f, -0.6f);
    glEnd();
    glPopMatrix();

// Metro Station Pillar

    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(0.0f, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.8f, 0.8f, 0.8f); // Red
    glVertex2f(-0.9f, -0.6f);
    glVertex2f(-0.9f, -1.0f);
    glVertex2f(-0.60f, -1.0f);
    glVertex2f(-0.60f, -0.6f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


// Metro Station Beem

    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(0.0f, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.8f, 0.8f, 0.8f); // Red
    glVertex2f(-0.5f, -0.6f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(-0.5f, -0.15f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

//Metro Station Beam Support
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-0.5f, -0.6f);
    glVertex2f(-0.45f, -0.53f);
    glVertex2f(-0.5f, -0.53f);
    glEnd();
    glPopMatrix();


// Metro Station Outer Red Wall
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.493f, 0.159f, 0.125f);
    glVertex2f(-0.5f, 0.45f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(-0.5f, -0.15f);
    glEnd();
    glPopMatrix();

// Metro Station upper Tin Shade
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(-0.50f, 0.45f);
    glVertex2f(-1.0f, 0.45f);
    glVertex2f(-1.0f, 0.75f);
    glVertex2f(-0.45f, 0.75f);
    glEnd();
    glPopMatrix();
}

void MetroStationBack()
{
    // Metro Station Outer Red Wall back

    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(0.0f, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.350f, 0.159f, 0.125f); // Red
    glVertex2f(-0.5f, 0.46f);
    glVertex2f(-0.42f, 0.47f);
    glVertex2f(-0.42f, -0.3f);
    glVertex2f(-0.5f, -0.3f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

// Metro Station upper Tin Shade back

    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(0.0f, 0.0, 0.0f); // Translate
    glBegin(GL_TRIANGLES); // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.4f, 0.0f); // Red
    glVertex2f(-0.45f, 0.75f);
    glVertex2f(-0.40f, 0.47f);
    glVertex2f(-0.55f, 0.45);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

// Metro Station back Beam

    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(0.0f, 0.0f, 0.0f); // Translate
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.8f, 0.8f, 0.8f); // Red
    glVertex2f(-0.5f, -0.15f);
    glVertex2f(-0.42f, -0.1);
    glVertex2f(-0.42f, -0.3f);
    glVertex2f(-0.5f, -0.3f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix
}




void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        SkyR=0.60f;
        SkyG=0.84f;
        SkyB=1.0f;
        WR=0.88f, WG=0.96f, WB=1.0f;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        SkyR=0.0f;
        SkyG=0.28f;
        SkyB=0.39f;
        WR=0.92f, WG=0.95f, WB=0.45f;
    }
    glutPostRedisplay();
}




void OuterSation(char str[])
{
    //Metro station outer pillar
    glPushMatrix(); // Save model-view matrix setting
    glTranslatef(0.0f, 0.0f, 0.0f); // Translate
    glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
    glColor3f(0.8f, 0.8f, 0.8f); // Red
    glVertex2f(-0.2f, 0.3f);
    glVertex2f(-0.2f,-1.0f);
    glVertex2f(0.1f,-1.0f);
    glVertex2f(0.1f,0.0f);
    glVertex2f(1.0f,0.0f);
    glVertex2f(1.0f,0.3f);
    glVertex2f(0.0f,0.3f);
    glVertex2f(0.0f,1.0f);
    glVertex2f(-0.2f,1.0f);
    glVertex2f(-0.2f,0.3f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix


    //Metro Station Outer Red Wall
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.493f, 0.159f, 0.125f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(1.0f, 0.3f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();
    glPopMatrix();

    //Metro Station Outer lift wall
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(0.0f, -1.0f);
    glEnd();
    glPopMatrix();

    //Metro Station Outer lift
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(-0.8f, -1.0f);
    glVertex2f(-0.8f, -0.1f);
    glEnd();
    glPopMatrix();

    //Metro Station Outer lift
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(-0.8f, -1.0f);
    glVertex2f(-0.8f, -0.1f);
    glEnd();
    glPopMatrix();



    //Metro Station Outer lift gate right
    glPushMatrix();
    glScalef(LiftGateXR,1.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.225f, -0.130f);
    glVertex2f(-0.225f, -1.0f);
    glVertex2f(-0.495f, -1.0f);
    glVertex2f(-0.495f, -0.130f);
    glEnd();
    glPopMatrix();

    //Metro Station Outer lift gate left
    glPushMatrix();
    glScalef(LiftGateXL,1.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.775f, -0.130f);
    glVertex2f(-0.775f, -1.0f);
    glVertex2f(-0.51f, -1.0f);
    glVertex2f(-0.51f, -0.130f);
    glEnd();
    glPopMatrix();


    // Upper Green Part
    glPushMatrix(); // Save model-view matrix setting
    glBegin(GL_QUADS); // Each set of 4 vertices form a quad
    glColor3f(0.0,0.6f,0.0f); // Red
    glVertex2f(-0.2f,0.1f);
    glVertex2f(-0.8f,0.1f);
    glVertex2f(-0.8f,-0.05f);
    glVertex2f(-0.2f,-0.05f);
    glEnd();
    glPopMatrix(); // Restore the model-view matrix

//TEXT for Ticket Counter
    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.75f,0.0f);
    int len=strlen(str);
    for(int i=0; i<len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
    }


}

void handleKeypress13(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'o':
        LiftGateXL=0.0f;
        LiftGateXR=0.0f;
        break;
    case 'c':
        LiftGateXL=1.0f;
        LiftGateXR=1.0f;
        break;
    case 'w':
        D13LiftMenY+= 0.05f; // Adjust step size as needed
        D13LiftManScalX-=0.034f;
        D13LiftManScalY-=0.070f;

        if(D13LiftMenY>0.0f)
        {
            D13LiftManScalX=0.0068f;
            D13LiftManScalY-=0.0120f;
        }
        break;
    case 's': // Move backward
        D13LiftMenY-= 0.05f; // Adjust step size as needed
        D13LiftManScalX+=0.136f;
        D13LiftManScalY+=0.240f;
        break;
    case 'a':
        D13LiftMenX-=0.01f;
        break;
    case 'd':
        D13LiftMenX+=0.01f;
        break;
    }

    glutPostRedisplay();
}

void display13()
{
    glClear(GL_COLOR_BUFFER_BIT);
    char str[]="Mirpur 12 Metro Station";
    OuterSation(str);

    glPushMatrix();

    glScalef(0.9f,0.9f,0.0f);
    glTranslatef(D13LiftMenX-0.60f,D13LiftMenY-0.37f,0.0f);
    glScalef(D13LiftManScalX,D13LiftManScalY, 0.0f);
    drawMan();
    glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

void display12(int val)
{
    glutDisplayFunc(display13);
    glutKeyboardFunc(handleKeypress13);
    glutPostRedisplay();
}


void handleKeypress11(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'o':
        isGateOpen = true; // Set gate state to open
        positioGateXL= fmax(speed-0.14,-1.51f);
        positioGateXR=fmax(speed+0.14,-1.01);
        break;
    case 'c':
        isGateOpen = false; // Set gate state to closed
        positioGateXL= fmax(speed+0.16,-1.46f);
        positioGateXR=fmax(speed-0.16,-1.16);
        break;
    case 'e':
        speed = 0.0f;
        break;
    case 'q':
        speed += 0.1f;
        break;
    case 'w':
        D11positionMenY+= 0.05f; // Adjust step size as needed
        D11ManScalX-=0.068f;
        D11ManScalY-=0.120f;

        if(D11positionMenY>0.3f)
        {
            D11ManScalX=0.0034f;
            D11ManScalY=0.0070f;
        }
        break;
    case 's': // Move backward
        D11positionMenY-= 0.05f; // Adjust step size as needed
        D11ManScalX+=0.068f;
        D11ManScalY+=0.120f;
        break;
    case 'a':
        D11positionMenX -= 0.05f;
        break;
    case 'd':
        D11positionMenX += 0.05f;
        break;
    }

    glutPostRedisplay();
}


void display11() //Exit From Metro Rail
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (!isGateOpen && speed != 0.0f && speed != 0.01f)
    {
        speed = 0.03f; // Slow down the train at the station
    }

    char str[]="Mirpur 12 Metro Station";
    MetroStation(str); // Render the final scene

    glPushMatrix();
    glTranslatef(0.0f,0.0f,0.0f);
    MetroBoggy();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-1.32,0.0f,0.0f);
    MetroBoggy();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.32,0.0f,0.0f);
    MetroBoggy();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(D11positionMenX, D11positionMenY - 0.3f, 0.0f);
    glScalef(D11ManScalX,D11ManScalY, 0.0f);
    drawMan(); // Render the man
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.3,-0.2f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(-0.3,-0.2f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.6,-0.45f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(-0.6,-0.45f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.9,-0.35f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(-0.9,-0.35f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(1.2,-0.50f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(-1.2,-0.50f,0.0f);
    drawMan();
    glPopMatrix();


    glutTimerFunc(18000,display12,0);
    glutSwapBuffers();
    glFlush();
}

void display10(int val)
{
    glutDisplayFunc(display11);
    glutKeyboardFunc(handleKeypress11);
    glutPostRedisplay();
}


void handleKeypress7(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'e':
        speed = 0.0f;
        break;
    case 'q':
        speed += 0.1f;
        break;
    case 'D':
        SkyR=0.60f;
        SkyG=0.84f;
        SkyB=1.0f;
        WR=0.88f, WG=0.96f, WB=1.0f;
        break;
    case 'N':
        SkyR=0.0f;
        SkyG=0.28f;
        SkyB=0.39f;
        WR=0.92f, WG=0.95f, WB=0.45f;
        break;
    }

    glutPostRedisplay();
}

void display9()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    Building1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8f,0.0f,0.0f);
    Building1();
    glPopMatrix();

    glPushMatrix();
    building01();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8f,0.0f,0.0f);
    building01();
    glPopMatrix();

    glPushMatrix();
    glScalef(-1.0f,1.0f,0.0f);
    MetroStationBack();
    glPopMatrix();


    glPushMatrix();
    MetroBoggy();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.32f,0.0f,0.0f);
    MetroBoggy();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.32f,0.0f,0.0f);
    MetroBoggy();
    glPopMatrix();


    glPushMatrix();
    glScalef(-1.0f,1.0f,0.0f);
    MetroStationFront();
    glPopMatrix();


    glutTimerFunc(10000,display10,0);
    glutSwapBuffers();
    glFlush();
}

void display8(int val)
{
    glutDisplayFunc(display9);
    glutKeyboardFunc(handleKeypress7);
    glutPostRedisplay();
}



void display7()
{
    glClear(GL_COLOR_BUFFER_BIT);

    Sky();

    building01();
    glTranslatef(-1.6f,1.2f,0.0f);
    building01();

    glTranslatef(0.4f,1.2f,0.0f);
    Building1();
    glTranslatef(1.2f,1.2f,0.0f);
    Building1();

    glTranslatef(-1.2f,1.2f,0.0f);
    MetroStationBack();



    MetroBoggy();
    glTranslatef(1.32f, 0.0f,0.0f);
    MetroBoggy();
    glTranslatef(1.32f, 0.0f,0.0f);
    MetroBoggy();



    glTranslatef(-2.64f,0.0f,0.0f);
    MetroStationFront();

    glutTimerFunc(10000,display8,0);
    glutSwapBuffers(); // Double buffered - swap the front and back buffers
    glFlush();

}





void display6(int val)
{
    glutDisplayFunc(display7);
    glutKeyboardFunc(handleKeypress7);
    glutPostRedisplay();
}

void handleKeypress5(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'o':
        isGateOpen = true; // Set gate state to open
        positioGateXL= fmax(speed-0.14,-1.51f);
        positioGateXR=fmax(speed+0.14,-1.01);
        break;
    case 'c':
        isGateOpen = false; // Set gate state to closed
        positioGateXL= fmax(speed+0.16,-1.46f);
        positioGateXR=fmax(speed-0.16,-1.16);
        break;
    case 'e':
        speed = 0.0f;
        break;
    case 'q':
        speed += 0.1f;
        break;
    case 'w':
        D5positionMenY+= 0.05f; // Adjust step size as needed
        D5ManScalX-=0.068f;
        D5ManScalY-=0.120f;

        if(D5positionMenY>0.3f)
        {
            D5ManScalX=0.0068f;
            D5ManScalY=0.0120f;
        }
        break;
    case 's': // Move backward
        D5positionMenY-= 0.05f; // Adjust step size as needed
        D5ManScalX+=0.068f;
        D5ManScalY+=0.120f;
        break;
    case 'a':
        D5positionMenX -= 0.05f;
        break;
    case 'd':
        D5positionMenX += 0.05f;
        break;
    }

    glutPostRedisplay();
}


void display5()//Enter to Metro Rail
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (!isGateOpen && speed != 0.0f && speed != 0.01f)
    {
        speed = 0.03f; // Slow down the train at the station
    }


    char str[]="Mirpur 10 Metro Station";
    MetroStation(str); // Render the final scene

    glPushMatrix();
    glTranslatef(0.0f,0.0f,0.0f);
    MetroBoggy();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-1.32,0.0f,0.0f);
    MetroBoggy();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.32,0.0f,0.0f);
    MetroBoggy();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(D5positionMenX, D5positionMenY - 0.3f, 0.0f);
    glScalef(D5ManScalX,D5ManScalY, 0.0f);
    drawMan(); // Render the man
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.3,-0.2f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(-0.3,-0.2f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.6,-0.45f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(-0.6,-0.45f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.9,-0.35f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(-0.9,-0.35f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(1.2,-0.50f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(-1.2,-0.50f,0.0f);
    drawMan();
    glPopMatrix();


    glutTimerFunc(10000,display6,0);
    glutSwapBuffers();
    glFlush();
}





void display4(int val)
{
    glutDisplayFunc(display5);
    glutKeyboardFunc(handleKeypress5);
    glutPostRedisplay();
}
void handleKeypress3(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        D3positionMenY += 0.05f; // Adjust step size as needed
        D3ManScalX-=0.034f;
        D3ManScalY-=0.070f;

        if(D3positionMenY>0.3f)
        {
            D3ManScalX=0.0034f;
            D3ManScalY=0.0070f;
        }
        break;
    case 's': // Move backward
        D3positionMenY -= 0.05f; // Adjust step size as needed
        D3ManScalX+=0.034f;
        D3ManScalY+=0.070f;
        break;
    case 'a':
        D3positionMenX -= 0.05f;
        break;
    case 'd':
        D3positionMenX += 0.05f;
        break;
    }

    glutPostRedisplay();
}

void display3()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    MetroStationInside();

    // Draw the first ticket counter
    glPushMatrix();
    MetroTicketCounter();
    glPopMatrix();

    // Translate and draw the second ticket counter
    glPushMatrix();
    glTranslatef(0.6f, 0.0f, 0.0f);
    MetroTicketCounter();
    glPopMatrix();

    // Translate and draw the third ticket counter
    glPushMatrix();
    glTranslatef(-0.6f, 0.0f, 0.0f);
    MetroTicketCounter();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(D3positionMenX,D3positionMenY,0.0f);
    drawMan();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.6f,0.0f,0.0f);
    drawMan();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.5f,-0.2f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7f,-0.4f,0.0f);
    drawMan();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.6f,0.0f,0.0f);
    drawMan();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.8f,-0.2f,0.0f);
    drawMan();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7f,-0.4f,0.0f);
    drawMan();
    glPopMatrix();

    glutTimerFunc(10000, display4,0);


    glutSwapBuffers(); // Double buffered - swap the front and back buffers
    glFlush();
}

void display2(int val)
{
    glutDisplayFunc(display3);
    glutKeyboardFunc(handleKeypress3);
    glutPostRedisplay();
}

void handleKeypress1(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'o':
        LiftGateXL=0.0f;
        LiftGateXR=0.0f;
        break;
    case 'c':
        LiftGateXL=1.0f;
        LiftGateXR=1.0f;
        break;
    case 'w':
        LiftMenY+= 0.05f; // Adjust step size as needed
        LiftManScalX-=0.034f;
        LiftManScalY-=0.070f;

        if(LiftMenY>-0.0f)
        {
            LiftManScalX=0.0034f;
            LiftManScalY-=0.0070f;
        }
        break;
    case 's': // Move backward
        LiftMenY-= 0.05f; // Adjust step size as needed
        LiftManScalX+=0.034f;
        LiftManScalY+=0.070f;
        break;
    case 'a':
        LiftMenX-=0.01f;
        break;
    case 'd':
        LiftMenX+=0.01f;
        break;
    }

    glutPostRedisplay();
}

void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);

    char str[]="Mirpur 10 Metro Station";
    glPushMatrix();
    OuterSation(str);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.9f,0.9f,0.0f);
    glTranslatef(LiftMenX-0.60f,LiftMenY-0.37f,0.0f);
    glScalef(LiftManScalX,LiftManScalY, 0.0f);
    drawMan();
    glPopMatrix();


    glutTimerFunc(10000,display2,0);
    glutSwapBuffers();
    glFlush();
}
void display(int val)
{
    glutDisplayFunc(display1);
    glutKeyboardFunc(handleKeypress1);
    glutPostRedisplay();
}
void Instraction()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.6f,0.6f);
    glVertex2f(1.0f,1.0f);
    glVertex2f(-1.0f,1.0f);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f,-1.0f);
    glEnd();



    glColor3f(1.0,1.0,1.0);
    char string[]="Every 10 second a new Scene will appear. So Do fast! ";
    glRasterPos2f(-0.60f,0.65f);
    int len=strlen(string);
    for(int i=0; i<len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }

    glColor3f(1.0,1.0,1.0);
    char string2[]="User Control Information";
    glRasterPos2f(-0.310f,0.35f);
    int len2=strlen(string2);
    for(int i=0; i<len2; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string2[i]);
    }

    glColor3f(1.0,1.0,1.0);
    char string3[]="Man Movement";
    glRasterPos2f(-0.150f,0.225f);
    int len3=strlen(string3);
    for(int i=0; i<len3; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string3[i]);
    }


    glColor3f(1.0,1.0,1.0);
    char string4[]="a -> Left";
    glRasterPos2f(-0.750f,0.1f);
    int len4=strlen(string4);
    for(int i=0; i<len4; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string4[i]);
    }

    glColor3f(1.0,1.0,1.0);
    char string5[]="d -> Right";
    glRasterPos2f(-0.350f,0.1f);
    int len5=strlen(string5);
    for(int i=0; i<len5; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string5[i]);
    }

    glColor3f(1.0,1.0,1.0);
    char string6[]="w -> Up";
    glRasterPos2f(0.050f,0.1f);
    int len6=strlen(string6);
    for(int i=0; i<len6; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string6[i]);
    }

    glColor3f(1.0,1.0,1.0);
    char string7[]="s -> Down";
    glRasterPos2f(0.450f,0.1f);
    int len7=strlen(string7);
    for(int i=0; i<len7; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string7[i]);
    }


    glColor3f(1.0,1.0,1.0);
    char string8[]="Train Movement";
    glRasterPos2f(-0.150f,-0.05f);
    int len8=strlen(string8);
    for(int i=0; i<len8; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string8[i]);
    }


    glColor3f(1.0,1.0,1.0);
    char string9[]="o -> open";
    glRasterPos2f(-0.750f,-0.150f);
    int len9=strlen(string9);
    for(int i=0; i<len9; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string9[i]);
    }

    glColor3f(1.0,1.0,1.0);
    char string10[]="c -> Close";
    glRasterPos2f(-0.350f,-0.150f);
    int len10=strlen(string10);
    for(int i=0; i<len10; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string10[i]);
    }

    glColor3f(1.0,1.0,1.0);
    char string11[]="e -> Stop";
    glRasterPos2f(0.050f,-0.150f);
    int len11=strlen(string11);
    for(int i=0; i<len11; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string11[i]);
    }

    glColor3f(1.0,1.0,1.0);
    char string12[]="q -> Start / Speed up";
    glRasterPos2f(0.450f,-0.150f);
    int len12=strlen(string12);
    for(int i=0; i<len12; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string12[i]);
    }


    glColor3f(1.0,1.0,1.0);
    char string13[]="Day Night Change";
    glRasterPos2f(-0.150f,-0.30f);
    int len13=strlen(string13);
    for(int i=0; i<len13; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string13[i]);
    }

    glColor3f(1.0,1.0,1.0);
    char string14[]="D -> Day";
    glRasterPos2f(-0.350f,-0.450f);
    int len14=strlen(string14);
    for(int i=0; i<len14; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string14[i]);
    }

    glColor3f(1.0,1.0,1.0);
    char string15[]="N -> Night";
    glRasterPos2f(0.050f,-0.450f);
    int len15=strlen(string15);
    for(int i=0; i<len15; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string15[i]);
    }



    glutTimerFunc(10000,display,0);
    glutSwapBuffers();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(350, 150);
    glutCreateWindow("Translation Animation");
    glutDisplayFunc(Instraction);
    init();
    glutTimerFunc(50, update, 0);
    glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}
