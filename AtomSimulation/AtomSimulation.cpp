#include <stdio.h>
#include <math.h>
#include <glut.h>
#define pi 3.142
static GLfloat angle = 0;

static int submenu;
static int mainmenu;
static int value = -1;

void init()
{
    gluOrtho2D(-1000, 1000, -1000, 1000);
}

void circle(float rad)
{
    glBegin(GL_POINTS);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad * cos(i), rad * sin(i));
    }
    glEnd();
}

void drawString(float x, float y, float z, char* string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }
}

void drawhead(float x, float y, float z, char* string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawsubhead(float x, float y, float z, char* string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}

void nuc(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}

void eleright(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad + 20 * cos(i), 20 * sin(i));
    }
    glEnd();
}

void eleleft(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-(rad + 20 * cos(i)), 20 * sin(i));
    }
    glEnd();
}

void eletop(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), rad + 20 * sin(i));
    }
    glEnd();
}

void eledown(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), -(rad + 20 * sin(i)));
    }
    glEnd();
}

void eletr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

void eletl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

void eledl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

void eledr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

void display()
{
    glClearColor(0, 0, 0.1, 0.9);

    if (value == -1)
    {
        char cn[] = "UNIVERSITAS SUMATERA UTARA";
        drawhead(-390, 900, 0, cn);
        char pn[] = "Medan, Indonesia";
        drawsubhead(-150, 850, 0, pn);

        char dn[] = "S-1 ILMU KOMPUTER";
        drawhead(-270, 650, 0, dn);

        char prn[] = "A Mini Project On";
        drawsubhead(-150, 450, 0, prn);
        char pro[] = "ATOM SIMULATION";
        drawhead(-250, 350, 0, pro);

        char pb[] = "PROJECT BY: ";
        drawhead(-690, -150, 0, pb);

        char p1[] = "Imanda Tamara";
        drawhead(-690, -250, 0, p1);
        char p1u[] = "211401011";
        drawsubhead(-690, -300, 0, p1u);

        char p2[] = "Rani Widya";
        drawhead(-690, -400, 0, p2);
        char p2u[] = "211401018";
        drawsubhead(-690, -450, 0, p2u);

        char g1[] = "Helga Pricilla";
        drawhead(290, -250, 0, g1);
        char d1[] = "211401067";
        drawsubhead(290, -300, 0, d1);

        char g2[] = "Tessa Agitha";
        drawhead(290, -400, 0, g2);
        char d2[] = "211401138";
        drawsubhead(290, -450, 0, d2);

        char gb[] = "DOSEN PENGAMPU: ";
        drawhead(-690, -650, 0, gb);

        char g3[] = "Herriyance S.T., M.Kom.";
        drawhead(-690, -750, 0, g3);

        char in[] = "Press enter to Continue";
        drawhead(-250, -950, 0, in);

        glutSwapBuffers();
        glutDetachMenu(GLUT_RIGHT_BUTTON);
    }
    if (value != -1)
    {
        nuc(250); // membuat nucleus biru dengan nilai radian 250 (jari-jari 250)
        char n[] = "NUCLEUS";
        drawString(-90, 20, 0, n);
        char d[] = "(NEUTRON + PROTON)";
        drawString(-225, -30, 0, d);

        
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();

        if (value == 0)
        {
            char t[] = "NITROGEN";
            drawhead(-100, 900, 0, t);
        }
    }

    glutSwapBuffers();
}

void rotate()
{
    angle = angle + 1.0;
    if (angle > 360)
    {
        angle = angle - 360;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
}

void mouseControl(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(rotate);
        break;
    default:
        break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 13)
    {
        value = 0;
        glClear(GL_COLOR_BUFFER_BIT);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutPostRedisplay();
    }
    else if (key == 's')
    {
        glutIdleFunc(NULL);
    }
    else if (key == 32)
    {
        glutIdleFunc(rotate);
    }
    else if (key == 'q' || key == 'Q')
    {
        exit(0);
    }
    else if (key == 27)
    {
        glutReshapeWindow(700, 700);
    }
}

void fkey(int key, int x, int y)
{

    if (key == GLUT_KEY_F10)
    {
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    }
}

void menu(int option)
{
    if (option == 13)
    {
        exit(0);
    }
    else if (option == 11)
    {
        glutIdleFunc(rotate);
    }
    else if (option == 12)
    {
        glutIdleFunc(NULL);
    }
    else if (option == 14) {
        value = -1;
    }
    else
    {
        value = option;
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glutPostRedisplay();
}

void createMenu(void)
{
    mainmenu = glutCreateMenu(menu);
    glutAddMenuEntry("START SIMULATION", 11);
    glutAddMenuEntry("STOP SIMULATION", 12);
    glutAddMenuEntry("GOTO HOME SCREEN", 14);
    glutAddMenuEntry("EXIT", 13);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("ATOM SIMULATION");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseControl);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(fkey);
    createMenu();
    glutMainLoop();
    return 0;
}