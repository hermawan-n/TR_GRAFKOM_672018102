#include <windows.h>
#include <gl/glut.h>
#include <cmath>
#define deltat .001


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse (int button, int state, int x, int y);
void mouseMotion(int x, int y);
int dy;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

GLUquadricObj *qobj;

int main (int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Hermawan Nugroho - 672018102");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutMainLoop();
    return 0;
}

void init(void){
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHT0);
    glLineWidth(0.1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
}

void ngon(float X, float Y, float cX, float cY, float jumlah, float rotangle){
    GLfloat derajat = (360.0f / jumlah) * M_PI / 180.0f;
    glBegin(GL_TRIANGLE_FAN);
        GLfloat angle = 0.0f - rotangle;
        for (int n = 0; n < jumlah; ++n)
        {
            glVertex2f(X + (cX * cos(angle)), Y + (cY * sin(angle)));
            angle += derajat;
        }
    glEnd();
}

void gedungkiri(void){

    glBegin(GL_POLYGON);//atap
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-30.0, 95.0, -38.0);
    glVertex3f(-50.0, 98.0, -31.5);
    glVertex3f(-30.0, 95.0, -38.0);
    glVertex3f(-20.0, 90.0, -49.0);
    glVertex3f(-50.0, 98.0, -31.5);
    glVertex3f(-56.5, 100.0, -35.0);
    glVertex3f(-20, 90.0, -49.0);
    glVertex3f(-24.0, 90.0, -65.0);
    glVertex3f(-30.0, 90.0, -68.5);
    glVertex3f(-24.0, 90.0, -65.0);
    glVertex3f(-30.0, 90.0, -68.5);
    glVertex3f(-50.0, 100.0, -62.65);
    glVertex3f(-58.0, 100.0, -50.0);//kiri atas
    glVertex3f(-56.5, 100.0, -35.0);
    glVertex3f(-58.0, 100.0, -50.0);//weird kiri
    glVertex3f(-50.0, 100.0, -62.65);
    glEnd();

    glBegin(GL_POLYGON);//dpn atas
    glColor3f(1.0,0.5,0.0);
    glVertex3f(-54.0, 80.0, -30.3);
    glVertex3f(-28.8, 80.0, -38.5);
    glVertex3f(-30.0, 95.0, -38.0);
    glVertex3f(-50.0, 98.0, -31.5);
    glEnd();
    glBegin(GL_POLYGON);//dpn tengah
    glColor3f(1.0,1.5,0.0);
    glVertex3f(-55.0, 20.0, -30.0);
    glVertex3f(-25.0, 20.0, -40.0);
    glVertex3f(-28.8, 80.0, -38.5);
    glVertex3f(-55.0, 80.0, -30.0);
    glEnd();
    glBegin(GL_POLYGON);//dpn bawah
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-55.0, -30.0, -30.0);
    glVertex3f(-28.0, -30.0, -39.6);
    glVertex3f(-25.0, 20.0, -40.0);
    glVertex3f(-55.0, 20.0, -30.0);
    glEnd();

    glBegin(GL_POLYGON);//depan atas weird kanan
    glColor3f(1.0,0,1.0);
    glVertex3f(-20.0, 20.0, -46.0);
    glVertex3f(-25.0, 20.0, -40.0);
    glVertex3f(-30.0, 95.0, -38.0);
    glVertex3f(-20.0, 90.0, -49.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);//dpn bawah weird kanan
    glVertex3f(-28.0, -30.0, -39.6);
    glVertex3f(-20.0, -30.0, -50.0);
    glVertex3f(-20.0, 20.0, -46.0);
    glVertex3f(-25.0, 20.0, -40.0);
    glEnd();
    glBegin(GL_POLYGON);//dpn weird kiri
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-50.0, 98.0, -31.5);
    glVertex3f(-54.0, 80.0, -30.3);
    glVertex3f(-55.3, 80.0, -31.0);
    glVertex3f(-56.5, 100.0, -35.0);
    glEnd();
    glBegin(GL_POLYGON);//dpn weird kiri
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-55.0, 80.0, -30.0);
    glVertex3f(-54.0, 80.0, -30.3);
    glVertex3f(-55.3, 80.0, -31.0);
    glEnd();

    glBegin(GL_POLYGON);//kanan
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-20.0, -30.0, -50.0);
    glVertex3f(-20.0, 20.0, -46.0);
    glVertex3f(-25.0, 20.0, -70.0);
    glVertex3f(-25.0, -30.0, -70.0);
    glEnd();
    glBegin(GL_POLYGON);//kanan
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-20.0, 20.0, -46.0);
    glVertex3f(-20, 80.0, -48.0);
    glVertex3f(-25.0, 80.0, -70.0);
    glVertex3f(-25.0, 20.0, -70.0);
    glEnd();
    glBegin(GL_POLYGON);//kanan
    glColor3f(0.5,0.5,1.0);
    glVertex3f(-20, 80.0, -48.0);
    glVertex3f(-20, 90.0, -49.0);
    glVertex3f(-24.0, 90.0, -65.0);
    glVertex3f(-24.8, 80.0, -69);
    glEnd();

    glBegin(GL_POLYGON);//kanan weird
    glColor3f(1.5,1.5,1.0);
    glVertex3f(-26.0, 80.0, -69.71);
    glVertex3f(-30.0, 90.0, -68.5);
    glVertex3f(-24.0, 90.0, -65.0);
    glVertex3f(-24.8, 80.0, -69);
    glEnd();
    glBegin(GL_POLYGON);//segitiga kanan weird
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-26.0, 80.0, -69.71);
    glVertex3f(-24.8, 80.0, -69);
    glVertex3f(-25.0, 80.0, -70.0);
    glEnd();

    glBegin(GL_POLYGON);//blkng atas
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-54.5, 80.0, -61.5);
    glVertex3f(-26.0, 80.0, -69.71);
    glVertex3f(-30.0, 90.0, -68.5);
    glVertex3f(-50.0, 100.0, -62.65);
    glEnd();
    glBegin(GL_POLYGON);//blkng tengah atas
    glColor3f(0.0,0.2,1.0);
    glVertex3f(-59.0, 60.0, -60.30);
    glVertex3f(-25.0, 60.0, -70.0);
    glVertex3f(-25.0, 80.0, -70.0);
    glVertex3f(-54.5, 80.0, -61.5);
    glEnd();
    glBegin(GL_POLYGON);//blkng tengah bawah
    glColor3f(0.0,0.5,1.0);
    glVertex3f(-60.0, -10.0, -60.0);
    glVertex3f(-25.0, -10.0, -70.0);
    glVertex3f(-25.0, 60.0, -70.0);
    glVertex3f(-60.0, 60.0, -60.0);
    glEnd();
    glBegin(GL_POLYGON);//blkng tengah bawah
    glColor3f(1.0,0.5,0.0);
    glVertex3f(-56.0, -30.0, -60.9);
    glVertex3f(-25.0, -30.0, -70.0);
    glVertex3f(-25.0, -10.0, -70.0);
    glVertex3f(-59.0, -10.0, -60.3);
    glEnd();

    glBegin(GL_POLYGON);//skiri atas
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-55.3, 80.0, -31.0);
    glVertex3f(-59.0, 80.0, -54.5);
    glVertex3f(-58.0, 100.0, -50.0);
    glVertex3f(-56.5, 100.0, -35.0);
    glEnd();
    glBegin(GL_POLYGON);//skiri tengah atas
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-55.0, 60.0, -30.0);
    glVertex3f(-59.9, 60.0, -59.0);
    glVertex3f(-59.0, 80.0, -54.5);
    glVertex3f(-55.0, 80.0, -30.0);
    glEnd();
    glBegin(GL_POLYGON);//skiri tengah bawah
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-55.0, -10.0, -30.0);
    glVertex3f(-60.0, -10.0, -60.0);
    glVertex3f(-60.0, 60.0, -60.0);
    glVertex3f(-55.0, 60.0, -30.0);
    glEnd();
    glBegin(GL_POLYGON);//skiri bawah
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-55.0, -10.0, -30.0);
    glVertex3f(-59.9, -10.0, -59.0);
    glVertex3f(-59.1, -30.0, -56.0);
    glVertex3f(-55.0, -30.0, -30.0);
    glEnd();

    glBegin(GL_POLYGON);//weird belakang atas
    glColor3f(1.5,0.0,0.5);
    glVertex3f(-58.0, 100.0, -50.0);
    glVertex3f(-59.9, 60.0, -59.0);
    glVertex3f(-59.0, 60.0, -60.30);
    glVertex3f(-50.0, 100.0, -62.65);
    glEnd();
    glBegin(GL_POLYGON);//segitiga weird belakang atas
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-59.0, 60.0, -60.30);
    glVertex3f(-60.0, 60.0, -60.0);
    glVertex3f(-59.9, 60.0, -59.0);
    glEnd();
    glBegin(GL_POLYGON);//weird belakang bawah
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-56.0, -30.0, -60.9);
    glVertex3f(-59.0, -10.0, -60.3);
    glVertex3f(-59.9, -10.0, -59.0);
    glVertex3f(-59.1, -30.0, -56.0);
    glEnd();
    glBegin(GL_POLYGON);//segitiga weird belakang bawah
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-59.0, -10.0, -60.3);
    glVertex3f(-60.0, -10.0, -60.0);
    glVertex3f(-59.9, -10.0, -59.0);
    glEnd();

    glBegin(GL_LINES);//depan
    glColor3f(0.0, 0.0,0.0);
    glVertex3f(-26.0, 35.0, -39.0);
    glVertex3f(-26.0, 0.0, -39.5);
    glVertex3f(-27.0, 50.0, -39.0);
    glVertex3f(-27.0, -10.0, -39.5);
    glVertex3f(-28.0, 73.0, -38.0);
    glVertex3f(-28.0, -30.0, -38.5);
    glVertex3f(-29.0, 84.0, -38.0);
    glVertex3f(-29.0, -30.0, -38.5);
    glVertex3f(-30.0, 95.0, -38.0);
    glVertex3f(-30.0, -30.0, -38.5);
    glVertex3f(-31.0, 95.3, -37.6);
    glVertex3f(-31.0, -30.0, -38.2);
    glVertex3f(-32.0, 95.5, -37.3);
    glVertex3f(-32.0, -30.0, -37.5);
    glVertex3f(-33.0, 95.7, -36.8);
    glVertex3f(-33.0, -30.0, -37.1);
    glVertex3f(-34.0, 96.0, -36.7);
    glVertex3f(-34.0, -30.0, -36.8);
    glVertex3f(-35.0, 96.4, -36.3);
    glVertex3f(-35.0, -30.0, -36.3);
    glVertex3f(-36.0, 96.4, -35.9);
    glVertex3f(-36.0, -30.0, -36.0);
    glVertex3f(-37.0, 96.6, -35.7);
    glVertex3f(-37.0, -30.0, -36.0);
    glVertex3f(-38.0, 96.6, -35.3);
    glVertex3f(-38.0, -30.0, -35.7);
    glVertex3f(-39.0, 96.6, -34.8);
    glVertex3f(-39.0, -30.0, -35.5);
    glVertex3f(-40.0, 96.6, -34.6);
    glVertex3f(-40.0, -30.0, -35.1);
    glVertex3f(-41.0, 96.6, -34.2);
    glVertex3f(-41.0, -30.0, -34.8);
    glVertex3f(-42.0, 96.7, -34.0);
    glVertex3f(-42.0, -30.0, -34.4);
    glVertex3f(-43.0, 96.8, -33.7);
    glVertex3f(-43.0, -30.0, -34.0);
    glVertex3f(-44.0, 96.9, -33.4);
    glVertex3f(-44.0, -30.0, -33.6);
    glVertex3f(-45.0, 97.0, -33.0);
    glVertex3f(-45.0, -30.0, -33.3);
    glVertex3f(-46.0, 97.2, -32.7);
    glVertex3f(-46.0, -30.0, -33.0);
    glVertex3f(-47.0, 97.3, -32.3);
    glVertex3f(-47.0, -30.0, -32.7);
    glVertex3f(-48.0, 97.5, -32.0);
    glVertex3f(-48.0, -30.0, -31.8);
    glVertex3f(-49.0, 97.6, -31.7);
    glVertex3f(-49.0, -30.0, -31.6);
    glVertex3f(-50.0, 97.7, -31.4);
    glVertex3f(-50.0, -30.0, -31.6);
    glVertex3f(-51.0, 93.0, -31.0);
    glVertex3f(-51.0, -30.0, -31.3);
    glVertex3f(-52.0, 89.0, -30.8);
    glVertex3f(-52.0, -30.0, -30.9);
    glVertex3f(-53.0, 85.0, -30.6);
    glVertex3f(-53.0, -30.0, -30.5);
    glVertex3f(-54.0, 80.0, -30.2);
    glVertex3f(-54.0, -30.0, -30.3);
    glEnd();

    glBegin(GL_LINES);//depan
    glColor3f(1.0, 1.0,0.0);
    glVertex3f(-26.0, 80.0, -69.8);
    glVertex3f(-26.0, -30.0, -69.8);
    glVertex3f(-27.0, 82.0, -69.6);
    glVertex3f(-27.0, -30.0, -69.6);
    glVertex3f(-28.0, 84.0, -69.4);
    glVertex3f(-28.0, -30.0, -69.4);
    glVertex3f(-29.0, 87.0, -69.0);
    glVertex3f(-29.0, -30.0, -69.0);
    glVertex3f(-30.0, 90.0, -68.7);
    glVertex3f(-30.0, -30.0, -68.7);
    glVertex3f(-31.0, 90.5, -68.4);
    glVertex3f(-31.0, -30.0, -68.4);
    glVertex3f(-32.0, 91.0, -68.1);
    glVertex3f(-32.0, -30.0, -68.1);
    glVertex3f(-33.0, 91.5, -68.0);
    glVertex3f(-33.0, -30.0, -68.0);
    glVertex3f(-34.0, 92.0, -67.5);
    glVertex3f(-34.0, -30.0, -67.5);
    glVertex3f(-35.0, 92.5, -67.3);
    glVertex3f(-35.0, -30.0, -67.3);
    glVertex3f(-36.0, 93.0, -67.0);
    glVertex3f(-36.0, -30.0, -67.0);
    glVertex3f(-37.0, 93.5, -66.6);
    glVertex3f(-37.0, -30.0, -66.7);
    glVertex3f(-38.0, 94.0, -66.3);
    glVertex3f(-38.0, -30.0, -66.4);
    glVertex3f(-39.0, 94.5, -66.1);
    glVertex3f(-39.0, -30.0, -66.1);
    glVertex3f(-40.0, 95.0, -65.7);
    glVertex3f(-40.0, -30.0, -65.8);
    glVertex3f(-41.0, 95.5, -65.5);
    glVertex3f(-41.0, -30.0, -65.5);
    glVertex3f(-42.0, 96.0, -65.2);
    glVertex3f(-42.0, -30.0, -65.3);
    glVertex3f(-43.0, 96.5, -64.9);
    glVertex3f(-43.0, -30.0, -65.0);
    glVertex3f(-44.0, 97.0, -64.6);
    glVertex3f(-44.0, -30.0, -64.7);
    glVertex3f(-45.0, 97.5, -64.3);
    glVertex3f(-45.0, -30.0, -64.4);
    glVertex3f(-46.0, 98.0, -64.0);
    glVertex3f(-46.0, -30.0, -64.1);
    glVertex3f(-47.0, 98.5, -63.9);
    glVertex3f(-47.0, -30.0, -63.9);
    glVertex3f(-48.0, 99.0, -63.5);
    glVertex3f(-48.0, -30.0, -63.5);
    glVertex3f(-49.0, 99.5, -63.2);
    glVertex3f(-49.0, -30.0, -63.2);
    glVertex3f(-50.0, 100.0, -63.0);
    glVertex3f(-50.0, -30.0, -63.0);
    glVertex3f(-51.0, 94.0, -62.8);
    glVertex3f(-51.0, -30.0, -62.8);
    glVertex3f(-52.0, 90.0, -62.4);
    glVertex3f(-52.0, -30.0, -62.4);
    glVertex3f(-53.0, 85.0, -62.1);
    glVertex3f(-53.0, -30.0, -62.1);
    glVertex3f(-54.0, 80.0, -61.8);
    glVertex3f(-54.0, -30.0, -61.8);
    glVertex3f(-55.0, 75.0, -61.5);
    glVertex3f(-55.0, -30.0, -61.5);
    glVertex3f(-56.0, 70.0, -61.5);
    glVertex3f(-56.0, -28.0, -61.1);
    glVertex3f(-57.0, 65.0, -60.9);
    glVertex3f(-57.0, -22.0, -60.9);
    glVertex3f(-58.0, 63.0, -60.7);
    glVertex3f(-58.0, -18.0, -60.7);
    glVertex3f(-59.0, 60.0, -60.5);
    glVertex3f(-59.0, -10.0, -60.5);
    glEnd();

    glBegin(GL_LINES);//depan
    glColor3f(0.0, 0.0,0.0);
    glVertex3f(-51.0, 98.4, -32.0);
    glVertex3f(-55.0, 80.0, -30.8);
    glVertex3f(-52.0, 98.5, -32.5);
    glVertex3f(-56.0, 87.0, -32.2);
    glEnd();
}

void gedungkanan(void){

    glBegin(GL_POLYGON);//atap
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-30.0, 95.0, -38.0);
    glVertex3f(-50.0, 98.0, -31.5);
    glVertex3f(-30.0, 95.0, -38.0);
    glVertex3f(-20.0, 90.0, -49.0);
    glVertex3f(-50.0, 98.0, -31.5);
    glVertex3f(-56.5, 100.0, -35.0);
    glVertex3f(-20, 90.0, -49.0);
    glVertex3f(-24.0, 90.0, -65.0);
    glVertex3f(-30.0, 90.0, -68.5);
    glVertex3f(-24.0, 90.0, -65.0);
    glVertex3f(-30.0, 90.0, -68.5);
    glVertex3f(-50.0, 100.0, -62.65);
    glVertex3f(-58.0, 100.0, -50.0);//kiri atas
    glVertex3f(-56.5, 100.0, -35.0);
    glVertex3f(-58.0, 100.0, -50.0);//weird kiri
    glVertex3f(-50.0, 100.0, -62.65);
    glEnd();

    glBegin(GL_POLYGON);//dpn atas
    glColor3f(1.0,0.5,0.0);
    glVertex3f(-54.0, 80.0, -30.3);
    glVertex3f(-28.8, 80.0, -38.5);
    glVertex3f(-30.0, 95.0, -38.0);
    glVertex3f(-50.0, 98.0, -31.5);
    glEnd();
    glBegin(GL_POLYGON);//dpn tengah
    glColor3f(1.0,1.5,0.0);
    glVertex3f(-55.0, 20.0, -30.0);
    glVertex3f(-25.0, 20.0, -40.0);
    glVertex3f(-28.8, 80.0, -38.5);
    glVertex3f(-55.0, 80.0, -30.0);
    glEnd();
    glBegin(GL_POLYGON);//dpn bawah
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-55.0, -30.0, -30.0);
    glVertex3f(-28.0, -30.0, -39.6);
    glVertex3f(-25.0, 20.0, -40.0);
    glVertex3f(-55.0, 20.0, -30.0);
    glEnd();

    glBegin(GL_POLYGON);//depan atas weird kanan
    glColor3f(1.0,0,1.0);
    glVertex3f(-20.0, 20.0, -46.0);
    glVertex3f(-25.0, 20.0, -40.0);
    glVertex3f(-30.0, 95.0, -38.0);
    glVertex3f(-20.0, 90.0, -49.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);//dpn bawah weird kanan
    glVertex3f(-28.0, -30.0, -39.6);
    glVertex3f(-20.0, -30.0, -50.0);
    glVertex3f(-20.0, 20.0, -46.0);
    glVertex3f(-25.0, 20.0, -40.0);
    glEnd();
    glBegin(GL_POLYGON);//dpn weird kiri
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-50.0, 98.0, -31.5);
    glVertex3f(-54.0, 80.0, -30.3);
    glVertex3f(-55.3, 80.0, -31.0);
    glVertex3f(-56.5, 100.0, -35.0);
    glEnd();
    glBegin(GL_POLYGON);//dpn weird kiri
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-55.0, 80.0, -30.0);
    glVertex3f(-54.0, 80.0, -30.3);
    glVertex3f(-55.3, 80.0, -31.0);
    glEnd();

    glBegin(GL_POLYGON);//kanan
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-20.0, -30.0, -50.0);
    glVertex3f(-20.0, 20.0, -46.0);
    glVertex3f(-25.0, 20.0, -70.0);
    glVertex3f(-25.0, -30.0, -70.0);
    glEnd();
    glBegin(GL_POLYGON);//kanan
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-20.0, 20.0, -46.0);
    glVertex3f(-20, 80.0, -48.0);
    glVertex3f(-25.0, 80.0, -70.0);
    glVertex3f(-25.0, 20.0, -70.0);
    glEnd();
    glBegin(GL_POLYGON);//kanan
    glColor3f(0.5,0.5,1.0);
    glVertex3f(-20, 80.0, -48.0);
    glVertex3f(-20, 90.0, -49.0);
    glVertex3f(-24.0, 90.0, -65.0);
    glVertex3f(-24.8, 80.0, -69);
    glEnd();

    glBegin(GL_POLYGON);//kanan weird
    glColor3f(1.5,1.5,1.0);
    glVertex3f(-26.0, 80.0, -69.71);
    glVertex3f(-30.0, 90.0, -68.5);
    glVertex3f(-24.0, 90.0, -65.0);
    glVertex3f(-24.8, 80.0, -69);
    glEnd();
    glBegin(GL_POLYGON);//segitiga kanan weird
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-26.0, 80.0, -69.71);
    glVertex3f(-24.8, 80.0, -69);
    glVertex3f(-25.0, 80.0, -70.0);
    glEnd();

    glBegin(GL_POLYGON);//blkng atas
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-54.5, 80.0, -61.5);
    glVertex3f(-26.0, 80.0, -69.71);
    glVertex3f(-30.0, 90.0, -68.5);
    glVertex3f(-50.0, 100.0, -62.65);
    glEnd();
    glBegin(GL_POLYGON);//blkng tengah atas
    glColor3f(0.0,0.2,1.0);
    glVertex3f(-59.0, 60.0, -60.30);
    glVertex3f(-25.0, 60.0, -70.0);
    glVertex3f(-25.0, 80.0, -70.0);
    glVertex3f(-54.5, 80.0, -61.5);
    glEnd();
    glBegin(GL_POLYGON);//blkng tengah bawah
    glColor3f(0.0,0.5,1.0);
    glVertex3f(-60.0, -10.0, -60.0);
    glVertex3f(-25.0, -10.0, -70.0);
    glVertex3f(-25.0, 60.0, -70.0);
    glVertex3f(-60.0, 60.0, -60.0);
    glEnd();
    glBegin(GL_POLYGON);//blkng tengah bawah
    glColor3f(1.0,0.5,0.0);
    glVertex3f(-56.0, -30.0, -60.9);
    glVertex3f(-25.0, -30.0, -70.0);
    glVertex3f(-25.0, -10.0, -70.0);
    glVertex3f(-59.0, -10.0, -60.3);
    glEnd();

    glBegin(GL_POLYGON);//skiri atas
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-55.3, 80.0, -31.0);
    glVertex3f(-59.0, 80.0, -54.5);
    glVertex3f(-58.0, 100.0, -50.0);
    glVertex3f(-56.5, 100.0, -35.0);
    glEnd();
    glBegin(GL_POLYGON);//skiri tengah atas
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-55.0, 60.0, -30.0);
    glVertex3f(-59.9, 60.0, -59.0);
    glVertex3f(-59.0, 80.0, -54.5);
    glVertex3f(-55.0, 80.0, -30.0);
    glEnd();
    glBegin(GL_POLYGON);//skiri tengah bawah
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-55.0, -10.0, -30.0);
    glVertex3f(-60.0, -10.0, -60.0);
    glVertex3f(-60.0, 60.0, -60.0);
    glVertex3f(-55.0, 60.0, -30.0);
    glEnd();
    glBegin(GL_POLYGON);//skiri bawah
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-55.0, -10.0, -30.0);
    glVertex3f(-59.9, -10.0, -59.0);
    glVertex3f(-59.1, -30.0, -56.0);
    glVertex3f(-55.0, -30.0, -30.0);
    glEnd();

    glBegin(GL_POLYGON);//weird belakang atas
    glColor3f(1.5,0.0,0.5);
    glVertex3f(-58.0, 100.0, -50.0);
    glVertex3f(-59.9, 60.0, -59.0);
    glVertex3f(-59.0, 60.0, -60.30);
    glVertex3f(-50.0, 100.0, -62.65);
    glEnd();
    glBegin(GL_POLYGON);//segitiga weird belakang atas
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-59.0, 60.0, -60.30);
    glVertex3f(-60.0, 60.0, -60.0);
    glVertex3f(-59.9, 60.0, -59.0);
    glEnd();
    glBegin(GL_POLYGON);//weird belakang bawah
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-56.0, -30.0, -60.9);
    glVertex3f(-59.0, -10.0, -60.3);
    glVertex3f(-59.9, -10.0, -59.0);
    glVertex3f(-59.1, -30.0, -56.0);
    glEnd();
    glBegin(GL_POLYGON);//segitiga weird belakang bawah
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-59.0, -10.0, -60.3);
    glVertex3f(-60.0, -10.0, -60.0);
    glVertex3f(-59.9, -10.0, -59.0);
    glEnd();

    glBegin(GL_LINES);//depan
    glColor3f(0.0, 0.0,0.0);
    glVertex3f(-26.0, 35.0, -39.5);
    glVertex3f(-26.0, 0.0, -39.5);
    glVertex3f(-27.0, 50.0, -39.0);
    glVertex3f(-27.0, -10.0, -39.5);
    glVertex3f(-28.0, 73.0, -38.0);
    glVertex3f(-28.0, -30.0, -38.5);
    glVertex3f(-29.0, 84.0, -38.0);
    glVertex3f(-29.0, -30.0, -38.5);
    glVertex3f(-30.0, 95.0, -38.0);
    glVertex3f(-30.0, -30.0, -38.5);
    glVertex3f(-31.0, 95.3, -37.6);
    glVertex3f(-31.0, -30.0, -38.2);
    glVertex3f(-32.0, 95.5, -37.3);
    glVertex3f(-32.0, -30.0, -37.5);
    glVertex3f(-33.0, 95.7, -36.8);
    glVertex3f(-33.0, -30.0, -37.1);
    glVertex3f(-34.0, 96.0, -36.7);
    glVertex3f(-34.0, -30.0, -36.8);
    glVertex3f(-35.0, 96.4, -36.3);
    glVertex3f(-35.0, -30.0, -36.3);
    glVertex3f(-36.0, 96.4, -35.9);
    glVertex3f(-36.0, -30.0, -36.0);
    glVertex3f(-37.0, 96.6, -35.7);
    glVertex3f(-37.0, -30.0, -36.0);
    glVertex3f(-38.0, 96.6, -35.3);
    glVertex3f(-38.0, -30.0, -35.7);
    glVertex3f(-39.0, 96.6, -34.8);
    glVertex3f(-39.0, -30.0, -35.5);
    glVertex3f(-40.0, 96.6, -34.6);
    glVertex3f(-40.0, -30.0, -35.1);
    glVertex3f(-41.0, 96.6, -34.2);
    glVertex3f(-41.0, -30.0, -34.8);
    glVertex3f(-42.0, 96.7, -34.0);
    glVertex3f(-42.0, -30.0, -34.4);
    glVertex3f(-43.0, 96.8, -33.7);
    glVertex3f(-43.0, -30.0, -34.0);
    glVertex3f(-44.0, 96.9, -33.4);
    glVertex3f(-44.0, -30.0, -33.6);
    glVertex3f(-45.0, 97.0, -33.0);
    glVertex3f(-45.0, -30.0, -33.3);
    glVertex3f(-46.0, 97.2, -32.7);
    glVertex3f(-46.0, -30.0, -33.0);
    glVertex3f(-47.0, 97.3, -32.3);
    glVertex3f(-47.0, -30.0, -32.7);
    glVertex3f(-48.0, 97.5, -32.0);
    glVertex3f(-48.0, -30.0, -31.8);
    glVertex3f(-49.0, 97.6, -31.7);
    glVertex3f(-49.0, -30.0, -31.6);
    glVertex3f(-50.0, 97.7, -31.4);
    glVertex3f(-50.0, -30.0, -31.6);
    glVertex3f(-51.0, 93.0, -31.0);
    glVertex3f(-51.0, -30.0, -31.3);
    glVertex3f(-52.0, 89.0, -30.8);
    glVertex3f(-52.0, -30.0, -30.9);
    glVertex3f(-53.0, 85.0, -30.6);
    glVertex3f(-53.0, -30.0, -30.5);
    glVertex3f(-54.0, 80.0, -30.2);
    glVertex3f(-54.0, -30.0, -30.3);
    glEnd();

    glBegin(GL_LINES);//depan
    glColor3f(1.0, 1.0,0.0);
    glVertex3f(-26.0, 80.0, -69.8);
    glVertex3f(-26.0, -30.0, -69.8);
    glVertex3f(-27.0, 82.0, -69.6);
    glVertex3f(-27.0, -30.0, -69.6);
    glVertex3f(-28.0, 84.0, -69.4);
    glVertex3f(-28.0, -30.0, -69.4);
    glVertex3f(-29.0, 87.0, -69.0);
    glVertex3f(-29.0, -30.0, -69.0);
    glVertex3f(-30.0, 90.0, -68.7);
    glVertex3f(-30.0, -30.0, -68.7);
    glVertex3f(-31.0, 90.5, -68.4);
    glVertex3f(-31.0, -30.0, -68.4);
    glVertex3f(-32.0, 91.0, -68.1);
    glVertex3f(-32.0, -30.0, -68.1);
    glVertex3f(-33.0, 91.5, -68.0);
    glVertex3f(-33.0, -30.0, -68.0);
    glVertex3f(-34.0, 92.0, -67.5);
    glVertex3f(-34.0, -30.0, -67.5);
    glVertex3f(-35.0, 92.5, -67.3);
    glVertex3f(-35.0, -30.0, -67.3);
    glVertex3f(-36.0, 93.0, -67.0);
    glVertex3f(-36.0, -30.0, -67.0);
    glVertex3f(-37.0, 93.5, -66.6);
    glVertex3f(-37.0, -30.0, -66.7);
    glVertex3f(-38.0, 94.0, -66.3);
    glVertex3f(-38.0, -30.0, -66.4);
    glVertex3f(-39.0, 94.5, -66.1);
    glVertex3f(-39.0, -30.0, -66.1);
    glVertex3f(-40.0, 95.0, -65.7);
    glVertex3f(-40.0, -30.0, -65.8);
    glVertex3f(-41.0, 95.5, -65.5);
    glVertex3f(-41.0, -30.0, -65.5);
    glVertex3f(-42.0, 96.0, -65.2);
    glVertex3f(-42.0, -30.0, -65.3);
    glVertex3f(-43.0, 96.5, -64.9);
    glVertex3f(-43.0, -30.0, -65.0);
    glVertex3f(-44.0, 97.0, -64.6);
    glVertex3f(-44.0, -30.0, -64.7);
    glVertex3f(-45.0, 97.5, -64.3);
    glVertex3f(-45.0, -30.0, -64.4);
    glVertex3f(-46.0, 98.0, -64.0);
    glVertex3f(-46.0, -30.0, -64.1);
    glVertex3f(-47.0, 98.5, -63.9);
    glVertex3f(-47.0, -30.0, -63.9);
    glVertex3f(-48.0, 99.0, -63.5);
    glVertex3f(-48.0, -30.0, -63.5);
    glVertex3f(-49.0, 99.5, -63.2);
    glVertex3f(-49.0, -30.0, -63.2);
    glVertex3f(-50.0, 100.0, -63.0);
    glVertex3f(-50.0, -30.0, -63.0);
    glVertex3f(-51.0, 94.0, -62.8);
    glVertex3f(-51.0, -30.0, -62.8);
    glVertex3f(-52.0, 90.0, -62.4);
    glVertex3f(-52.0, -30.0, -62.4);
    glVertex3f(-53.0, 85.0, -62.1);
    glVertex3f(-53.0, -30.0, -62.1);
    glVertex3f(-54.0, 80.0, -61.8);
    glVertex3f(-54.0, -30.0, -61.8);
    glVertex3f(-55.0, 75.0, -61.5);
    glVertex3f(-55.0, -30.0, -61.5);
    glVertex3f(-56.0, 70.0, -61.5);
    glVertex3f(-56.0, -28.0, -61.1);
    glVertex3f(-57.0, 65.0, -60.9);
    glVertex3f(-57.0, -22.0, -60.9);
    glVertex3f(-58.0, 63.0, -60.7);
    glVertex3f(-58.0, -18.0, -60.7);
    glVertex3f(-59.0, 60.0, -60.5);
    glVertex3f(-59.0, -10.0, -60.5);
    glEnd();
}

void gedungtengah (void){
    glBegin(GL_POLYGON);//depan kiri
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-20.0, -30.0, -50.0);
    glVertex3f(-10.0, -30.0, -55.0);
    glVertex3f(-10.0, 0.0, -55.0);
    glVertex3f(-20.0, 0.0, -50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);//dpn kanan
    glVertex3f(25.0, -30.0, -55.0);
    glVertex3f(35.0, -30.0, -50.0);
    glVertex3f(35.0, 0.0, -50.0);
    glVertex3f(25.0, 0.0, -55.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0);//dpn tngh
    glVertex3f(-10.0, -30.0, -55.0);
    glVertex3f(25.0, -30.0, -55.0);
    glVertex3f(25.0, 0.0, -55.0);
    glVertex3f(-10.0, 0.0, -55.0);
    glEnd();

    glBegin(GL_POLYGON);//blkng kiri
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-25.0, -30.0, -50.0-20);
    glVertex3f(-10.0, -30.0, -55.0-20);
    glVertex3f(-10.0, 0.0, -55.0-20);
    glVertex3f(-25.0, 0.0, -50.0-20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);//blkng kanan
    glVertex3f(25.0, -30.0, -55.0-20);
    glVertex3f(45.0, -30.0, -50.0-20);
    glVertex3f(45.0, 0.0, -50.0-20);
    glVertex3f(25.0, 0.0, -55.0-20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0);//blkng tngh
    glVertex3f(-10.0, -30.0, -55.0-20);
    glVertex3f(25.0, -30.0, -55.0-20);
    glVertex3f(25.0, 0.0, -55.0-20);
    glVertex3f(-10.0, 0.0, -55.0-20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0);//atas
    glVertex3f(25.0, 0.0, -55.0);
    glVertex3f(25.0, 0.0, -55.0-20);
    glVertex3f(-10.0, 0.0, -55.0-20);
    glVertex3f(-10.0, 0.0, -55.0);
    glEnd();

    glBegin(GL_POLYGON);//atas kiti
    glVertex3f(-10.0, 0.0, -55.0-20);
    glVertex3f(-25.0, 0.0, -50.0-20);
    glVertex3f(-20.0, 0.0, -50.0);
    glVertex3f(-10.0, 0.0, -55.0);
    glEnd();

    glBegin(GL_POLYGON);//atas kiti
    glVertex3f(45.0, 0.0, -50.0-20);
    glVertex3f(25.0, 0.0, -55.0-20);
    glVertex3f(25.0, 0.0, -55.0);
    glVertex3f(35.0, 0.0, -50.0);
    glEnd();
}


void alas(){
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.2,0.0);
    glVertex3f(-70.0,0.0,-30.0);
    glVertex3f(70.0,0.0,-30.0);
    glVertex3f(70.0,0.0,-80.0);
    glVertex3f(-70.0,0.0,-80.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(50.0,0.0,50.0);
    glVertex3f(70.0,0.0,50.0);
    glVertex3f(70.0,0.0,-80.0);
    glVertex3f(50.0,0.0,-80.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-70.0,0.0,50.0);
    glVertex3f(-50.0,0.0,50.0);
    glVertex3f(-50.0,0.0,-80.0);
    glVertex3f(-70.0,0.0,-80.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-10.0,0.0,-30.0);
    glVertex3f(-50.0,0.0,-30.0);
    glVertex3f(-50.0,0.0,-10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(10.0,0.0,-30.0);
    glVertex3f(50.0,0.0,-30.0);
    glVertex3f(50.0,0.0,-10.0);
    glEnd();
}

void bawahan (){
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.2,0.0);
    glVertex3f(-70.0,0.0,50.0);
    glVertex3f(-70.0,0.0,-80.0);
    glVertex3f(-70.0,-30.0,-80.0);
    glVertex3f(-70.0,-30.0,50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(70.0,0.0,50.0);
    glVertex3f(70.0,0.0,-80.0);
    glVertex3f(70.0,-30.0,-80.0);
    glVertex3f(70.0,-30.0,50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-70.0,0.0,-80.0);
    glVertex3f(70.0,0.0,-80.0);
    glVertex3f(70.0,-30.0,-80.0);
    glVertex3f(-70.0,-30.0,-80.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-70.0,0.0,50.0);
    glVertex3f(-50.0,0.0,50.0);
    glVertex3f(-50.0,-30.0,50.0);
    glVertex3f(-70.0,-30.0,50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(70.0,0.0,50.0);
    glVertex3f(50.0,0.0,50.0);
    glVertex3f(50.0,-30.0,50.0);
    glVertex3f(70.0,-30.0,50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(1,1,1,0.5);
    glVertex3f(50.0,0.0,50.0);
    glVertex3f(50.0,0.0,-10.0);
    glVertex3f(50.0,-30.0,-10.0);
    glVertex3f(50.0,-30.0,50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-50.0,0.0,50.0);
    glVertex3f(-50.0,0.0,-10.0);
    glVertex3f(-50.0,-30.0,-10.0);
    glVertex3f(-50.0,-30.0,50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-50.0,0.0,-10.0);
    glVertex3f(-50.0,-30.0,-10.0);
    glVertex3f(-10.0,-30.0,-30.0);
    glVertex3f(-10.0, 0.0,-30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(50.0,0.0,-10.0);
    glVertex3f(50.0,-30.0,-10.0);
    glVertex3f(10.0,-30.0,-30.0);
    glVertex3f(10.0, 0.0,-30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-10.0,0.0,-30.0);
    glVertex3f(-10.0,-30.0,-30.0);
    glVertex3f(10.0,-30.0,-30.0);
    glVertex3f(10.0, 0.0,-30.0);
    glEnd();
}

void body()
{
    glPushMatrix();//mata kanan
    glTranslatef(.17,1.1,.75);
    glRotatef(-45,0,0,1);
    glScalef(.9,.7,.7);
    glColor3f(1.0,1.0,1.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();

    glPushMatrix();//mata kiri
    glTranslatef(-.17,1.1,.75);
    glRotatef(45,0,0,1);
    glScalef(.9,.7,.7);
    glColor3f(1.0,1.0,1.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();

    glPushMatrix(); //kaki kiri
    glColor3ub(50,40,60);
    glTranslatef(.3,-.5,0);
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();

    glPushMatrix();//kaki kanan
    glColor3ub(50,40,60);
    glTranslatef(-.3,-.5,0);
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();

    glPushMatrix();//tangan kiri
    glColor3ub(255,90,0);
    glTranslatef(-.82,0,.1);
    glRotatef(90,0,1,0);
    glRotatef(-50,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();

    glPushMatrix();//tangan kanan
    glTranslatef(.82,0,.1);
    glRotatef(90,0,1,0);
    glRotatef(-130,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();

    glPushMatrix();//tangan kiri
    glColor3f(0.0,0.0,0.0);
    glColor3ub(0,185,0);
    glTranslatef(.82,0,.1);
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();

    glPushMatrix();//tangan kanan
    glColor3ub(0,185,0);
    glTranslatef(-.82,0,.1);
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();

    glPushMatrix();//mulut
    glTranslatef(0,.78,.74);
    glScalef(.4,.4,.1);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();

    glPushMatrix();//gigi
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.08,.72,.76);
    glTranslatef(.055,0,.005 );
    glutSolidCube(.035);
    glTranslatef(.055,0,0 );
    glutSolidCube(.035);
    glPopMatrix();

    glPushMatrix();//alis kiri
    glTranslatef(-.3,1.5,.97);;
    glRotatef(90,0,1,0);
    glRotatef(45,1,0,0);
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();

    glPushMatrix();//alis kanan
    glTranslatef(.3,1.5,.97);
    glRotatef(270,0,1,0);
    glRotatef(45,1,0,0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();


    glPushMatrix();//leher
    glColor3f(0.0,1.0,0.0);
    glTranslatef(0,.5,0);
    glScalef(.59,.59,.59);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(.1,1.0,20,20);
    glPopMatrix();

    glPushMatrix();//hepala
    glColor3ub(255,222,173);
    glTranslatef(0,1.2,0);
    glScalef(.9 ,.9,.9 );
    glColor3f(1.0,0.8,0.6);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();

    glPushMatrix();//sangul
    glColor3f(0.0,0.0,0.0);
    glTranslatef(0,2.2,0);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.18,100,100);
    glPopMatrix() ;

    glPushMatrix();//kaki kiri
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.3,-.5,0);
    glScalef(1.5,.3,1.5);

    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();

    glPushMatrix();//kaki kanan
    glColor3f(1.0,1.0,1.0);
    glTranslatef(.3,-.5,0);
    glScalef(1.5,.3,1.5);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();

    glPushMatrix();//jaket bawah
    glColor3f(0.0,0.0,0.0);
    glColor3ub(255,90,0);
    glTranslatef(0,-.2,0);
    glScalef(1,.7,1);
    glRotatef(90.0,1,0,0);
    gluDisk(gluNewQuadric(),0,.8,30,30);
    glPopMatrix();

    glPushMatrix();//jaket atas
    glColor3ub(255,90,0);
    glTranslatef(0,.5,0);
    glScalef(1,.7,1);
    glRotatef(90.0,1,0,0);
    gluCylinder(gluNewQuadric(),.6,.8,1,100,100);
    glPopMatrix();

    glPushMatrix();//pupil mata kiri
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();

    glPushMatrix();//pupil mata kanan
    glTranslatef(.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();

    glPushMatrix();//benik atas
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.1,.4,.85);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();

    glPushMatrix();//benik tengah
    glTranslatef(-.1,.15,.98);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();

    glPushMatrix();//benik bawah
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.1,-.1,.92);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void Chair(void) {

	// glTranslatef(0.0f, 0.0f, -14.0f);

	//glRotatef(10, 1.0f, 0.0f, 0.0f);
	//glRotatef(-10, 0.0f, 0.0f, 1.0f);
	//glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	//glRotatef(10, 1.0f, 0.0f, 0.0f);
	//glRotatef(-10, 0.0f, 0.0f, 1.0f);
	//glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glColor3f(0.4f, 0.302f, 0.0f);
	glBegin(GL_QUADS);

	//Front
	//
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);

	//Right
	//
	glVertex3f(2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);

	//Back
	//;
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//Left
	;
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);

	//top
	//

	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);

	//bottom
	;

	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//table front leg
	//front
	//

	glVertex3f(1.8f, -0.2f, 1.6f);
	glVertex3f(1.4f, -0.2f, 1.6f);
	glVertex3f(1.4f, -3.0f, 1.6f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//back
	//;

	glVertex3f(1.8f, -0.2f, 1.2f);
	glVertex3f(1.4f, -0.2f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);

	//right
	//Chair
	glVertex3f(1.8f, -0.2f, 1.6f);
	glVertex3f(1.8f, -0.2f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//left
	//;

	glVertex3f(1.4f, -0.2f, 1.6f);
	glVertex3f(1.4f, -0.2f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.6f);

	//back leg back
	//front
	//;

	glVertex3f(1.8f, -0.2f, -1.2f);
	glVertex3f(1.4f, -0.2f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);

	//back
	//;

	glVertex3f(1.8f, -0.2f, -1.6f);
	glVertex3f(1.4f, -0.2f, -1.6f);
	glVertex3f(1.4f, -3.0f, -1.6f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//right
	//

	glVertex3f(1.8f, -0.2f, -1.6f);
	glVertex3f(1.8f, -0.2f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//left
	//

	glVertex3f(1.4f, -0.2f, -1.6f);
	glVertex3f(1.4f, -0.2f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.6f);

	//leg left front
	//

	glVertex3f(-1.8f, -0.2f, 1.6f);
	glVertex3f(-1.4f, -0.2f, 1.6f);
	glVertex3f(-1.4f, -3.0f, 1.6f);
	glVertex3f(-1.8f, -3.0f, 1.6f);

	//back
	//;

	glVertex3f(-1.8f, -0.2f, 1.2f);
	glVertex3f(-1.4f, -0.2f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.2f);

	//right


	glVertex3f(-1.8f, -0.2f, 1.6f);
	glVertex3f(-1.8f, -0.2f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.6f);

	//left
	;

	glVertex3f(-1.4f, -0.2f, 1.6f);
	glVertex3f(-1.4f, -0.2f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.6f);

	//left leg back front

	//front
	;

	glVertex3f(-1.8f, -0.2f, -1.2f);
	glVertex3f(-1.4f, -0.2f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.2f);

	//back
	;

	glVertex3f(-1.8f, -0.2f, -1.6f);
	glVertex3f(-1.4f, -0.2f, -1.6f);
	glVertex3f(-1.4f, -3.0f, -1.6f);
	glVertex3f(-1.8f, -3.0f, -1.6f);

	//right


	glVertex3f(-1.8f, -0.2f, -1.6f);
	glVertex3f(-1.8f, -0.2f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.6f);

	//left


	glVertex3f(-1.4f, -0.2f, -1.6f);
	glVertex3f(-1.4f, -0.2f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.6f);

	//chair back
	//front

	//;
	//chair upper part
	glColor3f(0.902, 0.902, 0);
	glVertex3f(-1.8f, 1.2f, -1.8f);
	glVertex3f(1.8f, 1.2f, -1.8f);
	glVertex3f(1.8f, 3.5f, -1.8f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);

	//chair upper side
	glColor3f(1, 1, 0.4);
	glVertex3f(-1.8f, 1.2f, -1.80f);
	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(1.8f, 1.2f, -1.80f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	//chiar upper top
	glColor3f(1, 1, 0);
	glVertex3f(-1.8f, 3.5f, -1.80f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 1.2f, -1.80f);
	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -1.8f);

	// chair top legs

	glColor3f(0.2, 0.2, 0.0);
	//side walls
	glVertex3f(-1.2f, 1.2f, -1.20f);
	glVertex3f(-1.2f, 1.2f, -0.6f);
	glVertex3f(-1.2f, .2f, -0.6f);
	glVertex3f(-1.2f, .2f, -1.2f);

	glVertex3f(-.8f, 1.2f, -1.20f);
	glVertex3f(-.8f, 1.2f, -0.6f);
	glVertex3f(-.8f, .2f, -0.6f);
	glVertex3f(-.8f, .2f, -1.2f);

	//froont walls adnd back walls
	glVertex3f(-1.2f, 1.2f, -1.2f);
	glVertex3f(-0.8f, 1.2f, -1.2f);
	glVertex3f(-0.8f, .2f, -1.2f);
	glVertex3f(-1.2f, .2f, -1.2f);

	glVertex3f(-1.2f, 1.2f, -0.6f);
	glVertex3f(-0.8f, 1.2f, -0.6f);
	glVertex3f(-0.8f, .2f, -0.6f);
	glVertex3f(-1.2f, .2f, -0.6f);

	//side walls
	glVertex3f(1.2f, 1.2f, -1.20f);
	glVertex3f(1.2f, 1.2f, -0.6f);
	glVertex3f(1.2f, .2f, -0.6f);
	glVertex3f(1.2f, .2f, -1.2f);

	glVertex3f(.8f, 1.2f, -1.20f);
	glVertex3f(.8f, 1.2f, -0.6f);
	glVertex3f(.8f, .2f, -0.6f);
	glVertex3f(.8f, .2f, -1.2f);

	//froont walls adnd back walls
	glColor3f(0.2, 0.2, 0.0);
	glVertex3f(1.2f, 1.2f, -1.2f);
	glVertex3f(0.8f, 1.2f, -1.2f);
	glVertex3f(0.8f, .2f, -1.2f);
	glVertex3f(1.2f, .2f, -1.2f);

	glVertex3f(1.2f, 1.2f, -0.6f);
	glVertex3f(0.8f, 1.2f, -0.6f);
	glVertex3f(0.8f, .2f, -0.6f);
	glVertex3f(1.2f, .2f, -0.6f);

	//glVertex3f()

	glEnd();

}


void kipas(void)
{
    glTranslatef(0, 5, -5.0);
    glScalef(5, 5, 5);
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(1, 1.2, 1);
    glScalef(.5, .4, .5);
    glTranslatef(0, -2.0, 0);
    glScalef(1.0f, 0.7f, 1.0f);
    glTranslatef(0, -0.5, 0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();

    glPushMatrix();
    glTranslatef(0, -1.05, 0);
    glScalef(0.15, .15, .15);
    glTranslatef(0.0f, -2.2f, 0.0f);
    glBegin(GL_QUAD_STRIP);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(.3, .3, .3);
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, 1.55);
    glScalef(.25, .25, .25);
    glutSolidTorus(.1, .72, 25, 25);
    glPopMatrix();

    glPushMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.4);
    glTranslatef(-1, -1.55, 0);
    glScalef(2.5, .1, .75);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -1.55, 0);
    glScalef(0.05, .11, .05);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, -5);
    glScalef(1, 1, 2.4);
    glBegin(GL_QUAD_STRIP);
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.4);
    glTranslatef(-1, -1.55, 0);
    glScalef(2.5, .1, .75);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -1.55, 0);
    glScalef(0.05, .11, .05);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, -5);
    glScalef(1, 1, 2.4);
    glBegin(GL_QUAD_STRIP);

    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0, 1, 0);

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.4);
    glTranslatef(-1, -1.55, 0);
    glScalef(2.5, .1, .75);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -1.55, 0);
    glScalef(0.05, .11, .05);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, -5);
    glScalef(1, 1, 2.4);
    glBegin(GL_QUAD_STRIP);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glRotatef(270, 0, 1, 0);
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.4);
    glTranslatef(-1, -1.55, 0);
    glScalef(2.5, .1, .75);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -1.55, 0);
    glScalef(0.05, .11, .05);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, -5);
    glScalef(1, 1, 2.4);
    glBegin(GL_QUAD_STRIP);
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}


void ibox (){
    qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);

    gluCylinder(qobj, 10, 10, 30, 1000, 500);
}

void awan (){
    glLineWidth(4.0);
    float StartShape[12][2] = {
        {-15,100},{-5,100},{-5,100},{5,100},{5,105},{15,102},
        {15,90},{5,95},{5,10},{-5,10},{-5,25},{-15,25}
    };

    float EndShape[12][2] = {
        {-8,-15},{20,-15},{20,-10},{12,-10},{12,25},{2,25},
        {-5,20},{-5,15},{0,15},{0,-10},{-5,-10},{-8,-10}
    };

    float IntermediateShape [12][2];

    float VertexColor[12][3] = {
        {1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},
        {1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1}
    };

    static float Tween = 0.0 - deltat;

    if (Tween<1){
        Tween += deltat;
    }

    for (int Vtx = 0; Vtx<12; Vtx++){
        IntermediateShape[Vtx][0] = (1.0 - Tween)*StartShape[Vtx][0] + Tween*EndShape[Vtx][0];
        IntermediateShape[Vtx][1] = (1.0 - Tween)*StartShape[Vtx][1] + Tween*EndShape[Vtx][1];
    }

    glVertexPointer(2, GL_FLOAT, 0, IntermediateShape);
    glColorPointer(3, GL_FLOAT, 0, VertexColor);

    for (int i = 0; i < 10000000; i++);
    glDrawArrays(GL_POLYGON, 0, 12);
    glutPostRedisplay();

}

void tampil (){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);



    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-70.0,-30.0,50.0);
    glVertex3f(70.0,-30.0,50.0);
    glVertex3f(70.0,-30.0,-80.0);
    glVertex3f(-70.0,-30.0,-80.0);
    glEnd();


    glPushMatrix();
    glTranslated(0 ,30, 0);
    gedungkiri();
    gedungtengah();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15,30,-50);
    glRotatef(235,0,1,0);
    gedungkanan();
    glPopMatrix();

    glColor3f(0.6,0.6,0.6);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslated(0, 0, 29.9);
    ngon(0.0, 10.0, 20.0, 20.0, 60, 120.0);
    glPopMatrix();

    glColor4f(0.99,0.99,0.99, 0.6);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslated(0, 10, 0);
    ibox();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    ngon(0.0, 10.0, 10.0, 10.0, 60, 120.0);
    glPopMatrix();

    alas();
    bawahan();
    //awan();


    glTranslated(0 ,0.7, -35);
    glRotatef(180, 0, 1, 0);
    body();
    glPopMatrix();

    glTranslated(0 ,0.7, -35);
    //Chair();
    glPopMatrix();

    glTranslated(60 ,-2, -10);
    glScalef(.5,.5,.5);
    kipas();
    glPopMatrix();


    glutSwapBuffers();


}




void keyboard(unsigned char key, int x, int y){
    switch (key){
    case 'w':
    case 'W':
        dy++;
        break;

    case 'd':
    case 'D':
        glTranslatef(-3.0, 0.0, 0.0);
        break;

    case 's':
    case 'S':
        dy--;
        break;

    case 'a':
    case 'A':
        glTranslatef(3.0, 0.0, 0.0);
        break;

    case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;

    case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;

    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;

    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;

    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;

    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;

    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;

    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;

    case '5':
        if (is_depth){
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        } else {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi){
    if (tinggi == 0) tinggi = 1;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -20.0, -150.0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
}
