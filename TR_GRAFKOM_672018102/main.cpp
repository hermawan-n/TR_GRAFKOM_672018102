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
int dy = 0;
int pintu = 0;

float xa1=10, ya1=10, xb1=24, yb1=40, xa2=10, ya2=32, xb2=40, yb2=32, xa3=40, ya3=40, xb3=26, yb3=10, xa4=10, ya4=18, xb4=40, yb4=18, Mab1,Mab2,Mab3,Mab4,Cab1,Cab2,Cab3,Cab4,titik_x1,titik_y1,titik_x2,titik_y2,titik_x3,titik_y3,titik_x4,titik_y4;
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

void kipas(){
    glPushMatrix();
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
    glPopMatrix();
}

void garis(void){
    Mab1 = (yb1-ya1)/(xb1-xa1);
    Cab1 = ya1-(Mab1*xa1);

    Mab2 = (yb2-ya2)/(xb2-xa2);
    Cab2 = ya2-(Mab2*xa2);

    Mab3 = (yb3-ya3)/(xb3-xa3);
    Cab3 = ya3-(Mab3*xa3);

    Mab4 = (yb4-ya4)/(xb4-xa4);
    Cab4 = ya4-(Mab4*xa4);

    titik_x1 = (Cab2-Cab1)/(Mab1-Mab2);
    titik_x2 = (Cab4-Cab3)/(Mab3-Mab4);
    titik_x3 = (Cab3-Cab2)/(Mab2-Mab3);
    titik_x4 = (Cab1-Cab4)/(Mab4-Mab1);

    titik_y1 = (Mab1*titik_x1)+Cab1;
    titik_y2 = (Mab2*titik_x2)+Cab4;
    titik_y3 = (Mab3*titik_x3)+Cab3;
    titik_y4 = (Mab4*titik_x4)+Cab4;

//garis
    glBegin (GL_LINES);
    glColor3f(0, 0, 0);
        glVertex2i(xa1,ya1);
        glVertex2i(xb1,yb1);
    glColor3f(0, 0, 0);
        glVertex2i(xa2,ya2);
        glVertex2i(xb2,yb2);
    glColor3f(0, 0, 0);
        glVertex2i(xa3,ya3);
        glVertex2i(xb3,yb3);
    glColor3f(0, 0, 0);
        glVertex2i(xa4,ya4);
        glVertex2i(xb4,yb4);
    glEnd ();

//titik
    glPointSize(2.0);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
        glVertex2i(titik_x1,titik_y1);
        glVertex2i(titik_x2,titik_y2);
        glVertex2i(titik_x3,titik_y3);
        glVertex2i(titik_x4,titik_y4);
    glEnd();
}

void lantai (){
    //lantai
    glLineWidth(1.0);
    glPushMatrix();
    glTranslatef(-80, -29.9, -40);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50, -29.9, -40);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20, -29.9, -40);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, -29.9, -40);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glLineWidth(1.0);
    glPushMatrix();
    glTranslatef(-64, -29.9, -10);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64+30, -29.9, -10);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64+30+30, -29.9, -10);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glLineWidth(1.0);
    glPushMatrix();
    glTranslatef(-64+30+30+30, -29.9, -10);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-78, -29.9, 20);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-78+30, -29.9, 20);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-78+30+30, -29.9, 20);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-78+30+30+30, -29.9, 20);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-62, -29.9, 50);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-62, -29.9, 50);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-62+30, -29.9, 50);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-62+30+30, -29.9, 50);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-62+30+30+30, -29.9, 50);
    glRotatef(270, 1, 0, 0);
    garis();
    glPopMatrix();

    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-70, -29.9, 40);
    glVertex3f(70, -29.9, 40);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(-70, -29.9, 32);
    glVertex3f(70, -29.9, 32);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(-70, -29.9, 18);
    glVertex3f(70, -29.9, 18);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(-70, -29.9, 32-30);
    glVertex3f(70, -29.9, 32-30);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(-70, -29.9, 32-30-14);
    glVertex3f(70, -29.9, 32-30-14);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(-70, -29.9, 32-30-30);
    glVertex3f(70, -29.9, 32-30-30);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(-70, -29.9, 32-30-30-14);
    glVertex3f(70, -29.9, 32-30-30-14);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(-70, -29.9, 32-30-30-30);
    glVertex3f(70, -29.9, 32-30-30-30);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(-70, -29.9, 32-30-30-30-14);
    glVertex3f(70, -29.9, 32-30-30-30-14);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(-40, -29.9, -80);
    glVertex3f(-70, -29.9, -15.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(-40+14, -29.9, -80);
    glVertex3f(-70, -29.9, -15.5+29.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(-40+14+16, -29.9, -80);
    glVertex3f(-70+4, -29.9, 40);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(54, -29.9, 40);
    glVertex3f(70, -29.9, 5.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(54-16, -29.9, 40);
    glVertex3f(70, -29.9, 5.5-33.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(54-16-14, -29.9, 40);
    glVertex3f(70, -29.9, 5.5-33.5-30.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(54-16-14-16, -29.9, 40);
    glVertex3f(64, -29.9, -80);
    glEnd();
}

void lemari (){
    glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_QUADS);

    //blkng
	glVertex3f(-1.5f, 0.5f, -1.5f);
	glVertex3f(-1.5f, 4.5f, -1.5f);
	glVertex3f(1.5, 4.5f, -1.5f);
	glVertex3f(1.5f, 0.5f, -1.5f);

    //kanan
    glVertex3f(-1.5f, 0.5f, -1.5f);
	glVertex3f(-1.5f, 4.5f, -1.5f);
	glVertex3f(-1.5, 4.5f, 0.5f);
	glVertex3f(-1.5f, 0.5f, 0.5f);

    //kiri
    glVertex3f(1.5f, 0.5f, -1.5f);
	glVertex3f(1.5f, 4.5f, -1.5f);
	glVertex3f(1.5, 4.5f, 0.5f);
	glVertex3f(1.5f, 0.5f, 0.5f);

    //dpn
    glVertex3f(-1.5f, 0.5f, 0.5f);
	glVertex3f(-1.5f, 4.5f, 0.5f);
	glVertex3f(1.5, 4.5f, 0.5f);
	glVertex3f(1.5f, 0.5f, 0.5f);

    glColor3f(0.2f, 0.0f, 0.2f);
    //samping
	glVertex3f(-1.5f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.5f, -1.5f);
	glVertex3f(-1.2, 0.5f, -1.5f);
	glVertex3f(-1.2f, 0.0f, -1.5f);

    glVertex3f(-1.5f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.5f, -1.5f);
	glVertex3f(-1.5, 0.5f, 0.5f);
	glVertex3f(-1.5f, 0.0f, 0.5f);

    glVertex3f(-1.2f, 0.0f, -1.5f);
	glVertex3f(-1.2f, 0.5f, -1.5f);
	glVertex3f(-1.2, 0.5f, 0.5f);
	glVertex3f(-1.2f, 0.0f, 0.5f);

    glVertex3f(-1.5f, 0.0f, 0.5f);
	glVertex3f(-1.5f, 0.5f, 0.5f);
	glVertex3f(-1.2, 0.5f, 0.5f);
	glVertex3f(-1.2f, 0.0f, 0.5f);

    //sampingkanan
	glVertex3f(1.5f, 0.0f, -1.5f);
	glVertex3f(1.5f, 0.5f, -1.5f);
	glVertex3f(1.2f, 0.5f, -1.5f);
	glVertex3f(1.2f, 0.0f, -1.5f);

    glVertex3f(1.5f, 0.0f, -1.5f);
	glVertex3f(1.5f, 0.5f, -1.5f);
	glVertex3f(1.5f, 0.5f, 0.5f);
	glVertex3f(1.5f, 0.0f, 0.5f);

    glVertex3f(1.2f, 0.0f, -1.5f);
	glVertex3f(1.2f, 0.5f, -1.5f);
	glVertex3f(1.2f, 0.5f, 0.5f);
	glVertex3f(1.2f, 0.0f, 0.5f);

    glVertex3f(1.5f, 0.0f, 0.5f);
	glVertex3f(1.5f, 0.5f, 0.5f);
	glVertex3f(1.2f, 0.5f, 0.5f);
	glVertex3f(1.2f, 0.0f, 0.5f);

    glEnd();

    //garis
    glColor3f(0.149f, 0.149f, 0.149f);
    glBegin(GL_LINES);

    glVertex3f(-1.4f, 0.6f, 0.501f);
	glVertex3f(-1.4f, 4.4f, 0.501f);

	glVertex3f(-1.4f, 4.4f, 0.501f);
	glVertex3f(1.4f, 4.4f, 0.501f);

    glVertex3f(1.4f, 0.6f, 0.501f);
	glVertex3f(1.4f, 4.4f, 0.501f);

    glVertex3f(-1.4f, 0.6f, 0.501f);
	glVertex3f(1.4f, 0.6f, 0.501f);

    //garis tengah
    glVertex3f(0.0f, 0.6f, 0.501f);
	glVertex3f(0.0f, 4.4f, 0.501f);

    glEnd();

    //pegangan
    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef( 0.1f, 2.5f, 0.5f);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glutSolidTorus(0.03f, 0.1f, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( -0.1f, 2.5f, 0.5f);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glutSolidTorus(0.03f, 0.1f, 100, 100);
    glPopMatrix();
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

    glPushMatrix();
    glTranslated(-60,-1,0);
    kipas();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-60,-1,30);
    kipas();
    glPopMatrix();

    glPushMatrix();
    glTranslated(60,-1,0);
    kipas();
    glPopMatrix();

    glPushMatrix();
    glTranslated(60,-1,30);
    kipas();
    glPopMatrix();

    lantai();

    glPushMatrix();
    glScaled(5,5,5);
    glTranslated(-12.4,-6,0);
    glRotatef(90,0,1,0);
    lemari();
    glPopMatrix();

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

void ibox (){
    qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);

    gluCylinder(qobj, 10, 10, 30, 1000, 500);
}

void awan (){
    int i;
    float StartShape[12][2] = {
        {-15,100},{-5,105},{0,120},{5,105},{10,120},{15,105},
        {25,100},{15,95},{10,80},{5,95},{0,80},{-5, 95}
    };

    float EndShape[12][2] = {
        {-5+5+5+40,105},{0+5+5+40,120},{5+5+5+40,105},{10+5+5+40,120},{15+5+5+40,105},
        {25+40+5+5,100},{15+40+5+5,95},{10+40+5+5,80},{5+40+5+5,95},{0+40+5+5,80},{-5+40+5+5, 95},{-15+5+5+40,100}
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

    for (i = 0; i < 10000000; i++);
        glDrawArrays(GL_POLYGON, 0, 12);

    glutPostRedisplay();
}

void manusia (){
    glPushMatrix();//mata kanan
    glTranslatef(0.17,1.1,0.75);
    glRotatef(-45,0,0,1);
    glScalef(0.9,0.7,0.7);
    glColor3f(1.0,1.0,1.0);
    gluSphere(gluNewQuadric(),0.3,100,100);
    glPopMatrix();

    glPushMatrix();//mata kiri
    glTranslatef(-0.17,1.1,0.75);
    glRotatef(45,0,0,1);
    glScalef(0.9,0.7,0.7);
    glColor3f(1.0,1.0,1.0);
    gluSphere(gluNewQuadric(),0.3,100,100);
    glPopMatrix();

    glPushMatrix(); //kaki kiri
    glColor3ub(50,40,60);
    glTranslatef(0.3,-0.5,0);
    glRotatef(-90.0,1,0,0);
    glScalef(0.8,0.8,0.8);
    gluCylinder(gluNewQuadric(),0.5,0.5,0.5,30,6);
    glPopMatrix();

    glPushMatrix();//kaki kanan
    glColor3ub(50,40,60);
    glTranslatef(-0.3,-0.5,0);
    glRotatef(-90.0,1,0,0);
    glScalef(0.8,0.8,0.8);
    gluCylinder(gluNewQuadric(),0.5,0.5,0.5,30,6);
    glPopMatrix();

    glPushMatrix();//tangan kiri
    glColor3ub(255,90,0);
    glTranslatef(-0.82,0,0.1);
    glRotatef(90,0,1,0);
    glRotatef(-50,1,0,0);
    gluCylinder(gluNewQuadric(),0.15,0.15,0.48,30,6);
    glPopMatrix();

    glPushMatrix();//tangan kanan
    glTranslatef(0.82,0,0.1);
    glRotatef(90,0,1,0);
    glRotatef(-130,1,0,0);
    gluCylinder(gluNewQuadric(),0.15,0.15,0.48,30,6);
    glPopMatrix();

    glPushMatrix();//tangan kiri
    glColor3f(0.0,0.0,0.0);
    glColor3ub(0,185,0);
    glTranslatef(.82,0,0.1);
    glScalef(0.4,0.3,0.3);
    gluSphere(gluNewQuadric(),0.4,100,100);
    glPopMatrix();

    glPushMatrix();//tangan kanan
    glColor3ub(0,185,0);
    glTranslatef(-0.82,0,0.1);
    glScalef(0.4,0.3,0.3);
    gluSphere(gluNewQuadric(),0.4,100,100);
    glPopMatrix();

    glPushMatrix();//mulut
    glTranslatef(0,0.78,0.74);
    glScalef(0.4,0.4,0.1);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),0.4,100,100);
    glPopMatrix();

    glPushMatrix();//gigi
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-0.08,0.72,0.76);
    glTranslatef(0.055,0,0.005 );
    glutSolidCube(0.035);
    glTranslatef(0.055,0,0 );
    glutSolidCube(0.035);
    glPopMatrix();

    glPushMatrix();//alis kiri
    glTranslatef(-0.3,1.5,0.97);;
    glRotatef(90,0,1,0);
    glRotatef(45,1,0,0);
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),0.05,0.01,0.3,4,6);
    glPopMatrix();

    glPushMatrix();//alis kanan
    glTranslatef(0.3,1.5,0.97);
    glRotatef(270,0,1,0);
    glRotatef(45,1,0,0);
    gluCylinder(gluNewQuadric(),0.05,0.01,0.3,4,6);
    glPopMatrix();

    glPushMatrix();//leher
    glColor3f(0.0,1.0,0.0);
    glTranslatef(0,.5,0);
    glScalef(0.59,0.59,0.59);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(0.1,1.0,20,20);
    glPopMatrix();

    glPushMatrix();//hepala
    glColor3ub(255,222,173);
    glTranslatef(0,1.2,0);
    glScalef(0.9 ,0.9,0.9 );
    glColor3f(1.0,0.8,0.6);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();

    glPushMatrix();//sangul
    glColor3f(0.0,0.0,0.0);
    glTranslatef(0,2.2,0);
    glScalef(0.9,0.9,0.9);
    gluSphere(gluNewQuadric(),0.18,100,100);
    glPopMatrix() ;

    glPushMatrix();//kaki kiri
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-0.3,-0.5,0);
    glScalef(1.5,0.3,1.5);

    gluSphere(gluNewQuadric(),0.3,100,100);
    glPopMatrix();

    glPushMatrix();//kaki kanan
    glColor3f(1.0,1.0,1.0);
    glTranslatef(0.3,-.5,0);
    glScalef(1.5,0.3,1.5);
    gluSphere(gluNewQuadric(),0.3,100,100);
    glPopMatrix();

    glPushMatrix();//jaket bawah
    glColor3f(0.0,0.0,0.0);
    glColor3ub(255,90,0);
    glTranslatef(0,-0.2,0);
    glScalef(1,0.7,1);
    glRotatef(90.0,1,0,0);
    gluDisk(gluNewQuadric(),0,0.8,30,30);
    glPopMatrix();

    glPushMatrix();//jaket atas
    glColor3ub(255,90,0);
    glTranslatef(0,0.5,0);
    glScalef(1,.7,1);
    glRotatef(90.0,1,0,0);
    gluCylinder(gluNewQuadric(),0.6,0.8,1,100,100);
    glPopMatrix();

    glPushMatrix();//pupil mata kiri
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-.17,1.1,.88);
    glScalef(0.9,0.9,0.9);
    gluSphere(gluNewQuadric(),0.1,100,100);
    glPopMatrix();

    glPushMatrix();//pupil mata kanan
    glTranslatef(0.17,1.1,0.88);
    glScalef(0.9,0.9,0.9);
    gluSphere(gluNewQuadric(),0.1,100,100);
    glPopMatrix();

    glPushMatrix();//benik atas
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.1,.4,.85);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),0.04,100,100);
    glPopMatrix();

    glPushMatrix();//benik tengah
    glTranslatef(-0.1,0.15,0.98);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),0.04,100,100);
    glPopMatrix();

    glPushMatrix();//benik bawah
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-0.1,-0.1,0.92);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),0.04,100,100);
    glPopMatrix();
}

void lift(){

    glBegin(GL_POLYGON);
    glColor3f(0.4,0.4,0.4);
    glVertex3f(-50.0+3, 0.0, -60.0);
    glVertex3f(-30.0-3, 0.0, -60.0);
    glVertex3f(-30.0-3, 29.9, -60.0);
    glVertex3f(-50.0+3, 29.9, -60.0);
    glEnd();

    glPushMatrix();
    glTranslated(-pintu, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-50.0+3, 0.0, -50.0);
    glVertex3f(-40.0, 0.0, -50.0);
    glVertex3f(-40.0, 29.9, -50.0);
    glVertex3f(-50.0+3, 29.9, -50.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex3f(-40.0, 0.0, -50.0);
    glVertex3f(-40.0, 29.9, -50.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(pintu, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-40.0, 0.0, -50.0);
    glVertex3f(-30.0-3, 0.0, -50.0);
    glVertex3f(-30.0-3, 29.9, -50.0);
    glVertex3f(-40.0, 29.9, -50.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex3f(-40.0, 0.0, -50.0);
    glVertex3f(-40.0, 29.9, -50.0);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.4,0.4,0.4);
    glVertex3f(-50.0+3, 0.0, -60.0);
    glVertex3f(-50.0+3, 0.0, -50.0);
    glVertex3f(-50.0+3, 29.9, -50.0);
    glVertex3f(-50.0+3, 29.9, -60.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4,0.4,0.4);
    glVertex3f(-30.0-3, 0.0, -60.0);
    glVertex3f(-30.0-3, 0.0, -50.0);
    glVertex3f(-30.0-3, 29.9, -50.0);
    glVertex3f(-30.0-3, 29.9, -60.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-50.0+3, 0.0, -60.0);
    glVertex3f(-30.0-3, 0.0, -60.0);
    glVertex3f(-30.0-3, 0.0, -50.0);
    glVertex3f(-50.0+3, 0.0, -50.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-50.0+3, 29.9, -60.0);
    glVertex3f(-30.0-3, 29.9, -60.0);
    glVertex3f(-30.0-3, 29.9, -50.0);
    glVertex3f(-50.0+3, 29.9, -50.0);
    glEnd();

    glPushMatrix();
    glTranslated(-40 ,3, -60);
    glScalef(5,5,5);
    manusia();
    glPopMatrix();
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
    glTranslatef(0, 30, -100);
    awan();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, 70, -90);
    glRotatef(180, 0, 1, 0);
    awan();
    glPopMatrix();

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
    glTranslated(0, 0, 29.7);
    ngon(0.0, 10.0, 20.0, 20.0, 60, 120.0);
    glPopMatrix();

    alas();
    bawahan();

    glColor4f(0.99,0.99,0.99, 0.6);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslated(0, 10, 0);
    ibox();
    glPopMatrix();

    glPushMatrix();
    glColor4f(0.99,0.99,0.99, 0.6);
    glRotatef(90, 1, 0, 0);
    ngon(0.0, 10.0, 10.0, 10.0, 60, 120.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,dy,0);
    lift();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0 ,5, -35);
    glScalef(5,5,5);
    manusia();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0 ,5, -60);
    glScalef(5,5,5);
    glRotatef(180, 0, 1, 0);
    manusia();
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
    case 'w':
    case 'W':
        if (pintu == 0 && dy < 60){
            dy++;
        }
        break;

    case 'x':
    case 'X':
        if (dy == 60 || dy == 0){
                if (pintu < 6){
                    pintu++;
                }
        }
        break;

    case 'z':
    case 'Z':
        if (dy == 60 || dy == 0){
                if (pintu > 0){
                    pintu--;
                }
        }
        break;

    case 's':
    case 'S':
        if (pintu == 0 && dy > 0){
            dy--;
        }
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
    gluPerspective(70.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -30.0, -150.0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
}
