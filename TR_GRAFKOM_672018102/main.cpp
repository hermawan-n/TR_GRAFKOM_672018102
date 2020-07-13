#include <windows.h>
#include <gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse (int button, int state, int x, int y);
void mouseMotion(int x, int y);
int dy;
void test();

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

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


void test(){
}


void tampil (){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    //=================================bawah=====================
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-70.0,-30.0,50.0);
    glVertex3f(70.0,-30.0,50.0);
    glVertex3f(70.0,-30.0,-80.0);
    glVertex3f(-70.0,-30.0,-80.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0, 0);//dpn
    glVertex3f(-55.0, -30.0, -30.0);
    glVertex3f(-25.0, -30.0, -40.0);
    glVertex3f(-25.0, 20.0, -40.0);
    glVertex3f(-55.0, 20.0, -30.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);//dpn aliyen
    glVertex3f(-25.0, -30.0, -40.0);
    glVertex3f(-20.0, -30.0, -50.0);
    glVertex3f(-21.0, 20.0, -46.0);
    glVertex3f(-25.0, 20.0, -40.0);
    glEnd();

    glBegin(GL_POLYGON);//blkng
    glVertex3f(-60.0, -30.0, -60.0);
    glVertex3f(-25.0, -30.0, -70.0);
    glVertex3f(-25.0, 100.0, -70.0);
    glVertex3f(-60.0, 100.0, -60.0);
    glEnd();

    glBegin(GL_POLYGON);//skiri
    glVertex3f(-55.0, -30.0, -30.0);
    glVertex3f(-60.0, -30.0, -60.0);
    glVertex3f(-60.0, 100.0, -60.0);
    glVertex3f(-55.0, 100.0, -30.0);
    glEnd();

    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);//kanan
    glVertex3f(-20.0, -30.0, -50.0);
    glVertex3f(-25.0, 100.0, -40.0);
    glVertex3f(-25.0, 100.0, -70.0);
    glVertex3f(-25.0, -30.0, -70.0);
    glEnd();

    glColor3f(1.0,0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-21.0, 20.0, -46.0);
    glVertex3f(-25.0, 20.0, -40.0);
    glVertex3f(-30.0, 100.0, -35.0);
    glVertex3f(-25.0, 100.0, -40.0);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-55.0, 20.0, -30.0);
    glVertex3f(-25.0, 20.0, -40.0);
    glVertex3f(-30.0, 100.0, -35.0);
    glVertex3f(-55.0, 100.0, -30.0);
    glEnd();
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
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
