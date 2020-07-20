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
    gluPerspective(70.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -30.0, -150.0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
}
