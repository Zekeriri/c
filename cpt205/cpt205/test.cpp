#define FREEGLUT_STATIC
#include <GL/freeglut.h>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define black 0.0, 0.0 ,0.0
#define white 1, 1 , 1

float cameraX = 0.0;
float cameraY = -1;
float cameraZ = 5.0;
float cameraAngleY = 0.0;

float sensitivity = 0.1;

int windowWidth = 1200;
int windowHeight = 800;
int lastX = windowWidth / 2;  // ��ʼ��Ϊ��������
int lastY = windowHeight / 2;

bool mouseLocked = true;

float angle = 0.0;  // ��ʼ��ת�Ƕ�
int direction = 1;  // 1��ʾ����-1��ʾ����

GLfloat sunAmbient[] = { 1, 0, 0, 1.0 };  // ̫���Ļ�������ɫ
GLfloat sunDiffuse[] = { 1, 1, 1, 1.0 };  // ̫�������������ɫ

vector<GLuint> textures;
void setTexture();

void init() {
    glEnable(GL_DEPTH_TEST);

    glutSetCursor(GLUT_CURSOR_NONE); // �������ָ��

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //GLfloat ambientLight[] = { 0, 0, 0, 1.0 }; // ��������ɫΪ��ɫ
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
}
void update(int value) {
    angle += 1.0 * direction;  // ÿ�θ�����ת�Ƕ�

    if (angle > 0) {
        direction = -1;  // �л�Ϊ����
    }
    else if (angle < -90) {
        direction = 1;  // �л�Ϊ����
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);  // ������һ�ζ�ʱ��
}
void reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)width / (double)height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
void mouse(int x, int y) {
    if (mouseLocked) {
        int deltaX = x - lastX;
        int deltaY = y - lastY;

        // ����ˮƽ��ת
        cameraAngleY += deltaX * sensitivity * 0.01;

        // ���ƴ�ֱ��ת
        cameraY -= deltaY * sensitivity * 0.01; // ע�������Ǽ�������Ϊ��ֱ��������귽���෴
        if (cameraY > 4.8) cameraY = 4.8; // �������Ͽ���ͷ
        if (cameraY < -0.2) cameraY = -0.2; // �������¿���ͷ

        // �������λ�õ���������
        glutWarpPointer(windowWidth / 2, windowHeight / 2);

        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y) {
    float speed = 0.1;
    switch (key) {
    case 'w':
        cameraX += speed * sin(cameraAngleY);
        cameraZ -= speed * cos(cameraAngleY);
        break;
    case 's':
        cameraX -= speed * sin(cameraAngleY);
        cameraZ += speed * cos(cameraAngleY);
        break;
    case 'a':
        cameraX -= speed * cos(cameraAngleY);
        cameraZ -= speed * sin(cameraAngleY);
        break;
    case 'd':
        cameraX += speed * cos(cameraAngleY);
        cameraZ += speed * sin(cameraAngleY);
        break;
    case 'W':
        cameraX += speed * sin(cameraAngleY);
        cameraZ -= speed * cos(cameraAngleY);
        break;
    case 'S':
        cameraX -= speed * sin(cameraAngleY);
        cameraZ += speed * cos(cameraAngleY);
        break;
    case 'A':
        cameraX -= speed * cos(cameraAngleY);
        cameraZ -= speed * sin(cameraAngleY);
        break;
    case 'D':
        cameraX += speed * cos(cameraAngleY);
        cameraZ += speed * sin(cameraAngleY);
        break;
    case 27: // ASCII��27��ӦEsc��
        exit(0);
        break;
    }
    glutPostRedisplay();
}
void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        cameraAngleY -= 0.1;
        break;
    case GLUT_KEY_RIGHT:
        cameraAngleY += 0.1;
        break;
    }
    glutPostRedisplay();
}
void ReadImage(const char path[256]) {
    GLint imagewidth, imageheight, pixellength;
    GLubyte* pixeldata;
    FILE* pfile;
    fopen_s(&pfile, path, "rb");
    if (pfile == 0) exit(0);

    fseek(pfile, 0x0012, SEEK_SET);
    fread(&imagewidth, sizeof(imagewidth), 1, pfile);
    fread(&imageheight, sizeof(imageheight), 1, pfile);

    pixellength = imagewidth * 3;
    while (pixellength % 4 != 0) pixellength++;
    pixellength *= imageheight;

    pixeldata = (GLubyte*)malloc(pixellength);
    if (pixeldata == 0) exit(0);

    fseek(pfile, 54, SEEK_SET);
    fread(pixeldata, pixellength, 1, pfile);
    fclose(pfile);

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imagewidth, imageheight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixeldata);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    textures.push_back(textureID); // ������ ID ��ӵ�������

    free(pixeldata);
}

void setTexture() {
    ReadImage("textures/birch_planks.bmp"); //0
    ReadImage("textures/oak_planks.bmp");   //1
    ReadImage("textures/white_concrete.bmp"); //2
    ReadImage("textures/dark_oak_planks.bmp"); //3
    ReadImage("textures/light_gray_concrete.bmp"); //4
    ReadImage("textures/dark_oak_plank_slabs.bmp"); //5
    ReadImage("textures/glass.bmp"); //6
    ReadImage("textures/oak_trapdoor.bmp"); //7
    ReadImage("textures/iron_door.bmp"); //8
    ReadImage("textures/crafting_table_front.bmp"); //9
    ReadImage("textures/crafting_table_side.bmp"); //10
    ReadImage("textures/crafting_table_top.bmp"); //11
    ReadImage("textures/help.bmp"); //12
    ReadImage("textures/hint.bmp"); //13
}

void drawCuboid_whole_textures(float cx, float cy, float cz, float length, float width, float height, int a, int b, int c, int d, int e, int f) {
    float l = length / 2.0f;
    float w = width / 2.0f;
    float h = height / 2.0f;

    glEnable(GL_TEXTURE_2D);

    // front
    glBindTexture(GL_TEXTURE_2D, textures[a]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(cx - l, cy - h, cz + w);
    glTexCoord2f(1.0, 0.0); glVertex3f(cx + l, cy - h, cz + w);
    glTexCoord2f(1.0, 1.0); glVertex3f(cx + l, cy + h, cz + w);
    glTexCoord2f(0.0, 1.0); glVertex3f(cx - l, cy + h, cz + w);
    glEnd();

    // back
    glBindTexture(GL_TEXTURE_2D, textures[b]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(cx - l, cy - h, cz - w);
    glTexCoord2f(1.0, 0.0); glVertex3f(cx + l, cy - h, cz - w);
    glTexCoord2f(1.0, 1.0); glVertex3f(cx + l, cy + h, cz - w);
    glTexCoord2f(0.0, 1.0); glVertex3f(cx - l, cy + h, cz - w);
    glEnd();

    // left
    glBindTexture(GL_TEXTURE_2D, textures[c]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(cx - l, cy - h, cz - w);
    glTexCoord2f(1.0, 0.0); glVertex3f(cx - l, cy - h, cz + w);
    glTexCoord2f(1.0, 1.0); glVertex3f(cx - l, cy + h, cz + w);
    glTexCoord2f(0.0, 1.0); glVertex3f(cx - l, cy + h, cz - w);
    glEnd();

    // right
    glBindTexture(GL_TEXTURE_2D, textures[d]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(cx + l, cy - h, cz - w);
    glTexCoord2f(1.0, 0.0); glVertex3f(cx + l, cy - h, cz + w);;
    glTexCoord2f(1.0, 1.0); glVertex3f(cx + l, cy + h, cz + w);
    glTexCoord2f(0.0, 1.0); glVertex3f(cx + l, cy + h, cz - w);
    glEnd();

    // top
    glBindTexture(GL_TEXTURE_2D, textures[e]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(cx - l, cy + h, cz - w);
    glTexCoord2f(1.0, 0.0); glVertex3f(cx - l, cy + h, cz + w);
    glTexCoord2f(1.0, 1.0); glVertex3f(cx + l, cy + h, cz + w);
    glTexCoord2f(0.0, 1.0); glVertex3f(cx + l, cy + h, cz - w);
    glEnd();

    // bottom
    glBindTexture(GL_TEXTURE_2D, textures[f]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(cx - l, cy - h, cz - w);
    glTexCoord2f(1.0, 0.0); 	glVertex3f(cx + l, cy - h, cz - w);
    glTexCoord2f(1.0, 1.0); 	glVertex3f(cx + l, cy - h, cz + w);
    glTexCoord2f(0.0, 1.0); 	glVertex3f(cx - l, cy - h, cz + w);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
void drawCuboid(float cx, float cy, float cz, float length, float width, float height, float r, float g, float b) {
    float l = length / 2.0f;
    float w = width / 2.0f;
    float h = height / 2.0f;

    glColor3f(r, g, b);

    glBegin(GL_QUADS);
    // ǰ��
    glVertex3f(cx - l, cy - h, cz + w);
    glVertex3f(cx + l, cy - h, cz + w);
    glVertex3f(cx + l, cy + h, cz + w);
    glVertex3f(cx - l, cy + h, cz + w);

    // ����
    glVertex3f(cx - l, cy - h, cz - w);
    glVertex3f(cx - l, cy + h, cz - w);
    glVertex3f(cx + l, cy + h, cz - w);
    glVertex3f(cx + l, cy - h, cz - w);

    // ����
    glVertex3f(cx - l, cy - h, cz - w);
    glVertex3f(cx - l, cy - h, cz + w);
    glVertex3f(cx - l, cy + h, cz + w);
    glVertex3f(cx - l, cy + h, cz - w);

    // ����
    glVertex3f(cx + l, cy - h, cz - w);
    glVertex3f(cx + l, cy + h, cz - w);
    glVertex3f(cx + l, cy + h, cz + w);
    glVertex3f(cx + l, cy - h, cz + w);

    // ����
    glVertex3f(cx - l, cy + h, cz - w);
    glVertex3f(cx - l, cy + h, cz + w);
    glVertex3f(cx + l, cy + h, cz + w);
    glVertex3f(cx + l, cy + h, cz - w);

    // ����
    glVertex3f(cx - l, cy - h, cz - w);
    glVertex3f(cx + l, cy - h, cz - w);
    glVertex3f(cx + l, cy - h, cz + w);
    glVertex3f(cx - l, cy - h, cz + w);
    glEnd();

}

void draw_birch_planks(float x,float y,float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 1;
    float width = 1;
    float height = 1;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1, 1, 1);

    // ���ò�������
    GLfloat planks_birch_Ambient[] = { 0.8, 0.8, 0.8, 1.0 };   // �����⣨�ʶ�������
    GLfloat planks_birch_Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };   // �����䣨�����������䣩
    GLfloat planks_birch_Specular[] = { 0.2, 0.2, 0.2, 1.0 };  // ���淴�䣨�ʶ�������
    GLfloat planks_birch_Shininess = 10.0;                      // �����


    glMaterialfv(GL_FRONT, GL_AMBIENT, planks_birch_Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, planks_birch_Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, planks_birch_Specular);
    glMaterialf(GL_FRONT, GL_SHININESS, planks_birch_Shininess);

    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 0, 0, 0, 0, 0, 0);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}
void draw_oak_planks(float x, float y, float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 1;
    float width = 1;
    float height = 1;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1, 1, 1);

    // ���ò�������
    GLfloat Ambient[] = { 0.8, 0.8, 0.8, 1.0 };   // �����⣨�ʶ�������
    GLfloat Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };   // �����䣨�����������䣩
    GLfloat Specular[] = { 0.2, 0.2, 0.2, 1.0 };  // ���淴�䣨�ʶ�������
    GLfloat Shininess = 10.0;                      // �����


    glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
    glMaterialf(GL_FRONT, GL_SHININESS, Shininess);

    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 1,1,1,1,1,1);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}
void draw_white_concrete(float x, float y, float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 1;
    float width = 1;
    float height = 1;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1, 1, 1);

    // ���ò�������
    GLfloat Ambient[] = { 0.8, 0.8, 0.8, 1.0 };   // �����⣨�ʶ�������
    GLfloat Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };   // �����䣨�����������䣩
    GLfloat Specular[] = { 0.8, 0.8, 0.8, 1.0 };  // ���淴�䣨�ʶ�������
    GLfloat Shininess = 50.0;                      // �����


    glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
    glMaterialf(GL_FRONT, GL_SHININESS, Shininess);

    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 2,2,2,2,2,2);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}
void draw_dark_oak_planks(float x, float y, float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 0.25;
    float width = 0.25;
    float height = 1;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1, 1, 1);

    // ���ò�������
    GLfloat Ambient[] = { 0.8, 0.8, 0.8, 1.0 };   // �����⣨�ʶ�������
    GLfloat Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };   // �����䣨�����������䣩
    GLfloat Specular[] = { 0.2, 0.2, 0.2, 1.0 };  // ���淴�䣨�ʶ�������
    GLfloat Shininess = 10.0;                      // �����


    glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
    glMaterialf(GL_FRONT, GL_SHININESS, Shininess);

    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 3, 3, 3, 3, 3, 3);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}
void draw_light_gray_concrete(float x, float y, float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 1;
    float width = 1;
    float height = 1;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1, 1, 1);

    // ���ò�������
    GLfloat Ambient[] = { 0.8, 0.8, 0.8, 1.0 };   // �����⣨�ʶ�������
    GLfloat Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };   // �����䣨�����������䣩
    GLfloat Specular[] = { 0.8, 0.8, 0.8, 1.0 };  // ���淴�䣨�ʶ�������
    GLfloat Shininess = 50.0;                      // �����


    glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
    glMaterialf(GL_FRONT, GL_SHININESS, Shininess);

    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 4,4,4,4,4,4);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}
void draw_dark_oak_plank_slabs(float x, float y, float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 1;
    float width = 1;
    float height = 0.5;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1, 1, 1);

    // ���ò�������
    GLfloat Ambient[] = { 0.8, 0.8, 0.8, 1.0 };   // �����⣨�ʶ�������
    GLfloat Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };   // �����䣨�����������䣩
    GLfloat Specular[] = { 0.2, 0.2, 0.2, 1.0 };  // ���淴�䣨�ʶ�������
    GLfloat Shininess = 10.0;                      // �����


    glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
    glMaterialf(GL_FRONT, GL_SHININESS, Shininess);

    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 5,5,5,5,3,3);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}
void draw_glass(float x, float y, float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 2;
    float width = 1;
    float height = 2;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1, 1, 1);

    GLfloat glassAmbient[] = { 0.2, 0.2, 0.2, 0.5 };   // �����⣨����Ϊ�ʶ������Ļ�ɫ����͸��������Ϊ0.5
    GLfloat glassDiffuse[] = { 1.0, 1.0, 1.0, 0.5 };   // �����������䣬͸��������Ϊ0.5
    GLfloat glassSpecular[] = { 1.0, 1.0, 1.0, 1.0 };  // �����ľ��淴��
    GLfloat glassShininess = 100.0;                    // �߷����

    glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, glassSpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, glassShininess);



    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 6,6,6,6,6,6);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}
void draw_oak_tardoor(float x, float y, float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 1;
    float width = 0.1;
    float height = 1;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1, 1, 1);

    // ���ò�������
    GLfloat Ambient[] = { 0.8, 0.8, 0.8, 1.0 };   // �����⣨�ʶ�������
    GLfloat Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };   // �����䣨�����������䣩
    GLfloat Specular[] = { 0.2, 0.2, 0.2, 1.0 };  // ���淴�䣨�ʶ�������
    GLfloat Shininess = 10.0;                      // �����


    glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
    glMaterialf(GL_FRONT, GL_SHININESS, Shininess);

    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 7, 7, 1, 1, 1, 1);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}
void draw_iron_door(float x, float y, float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 1;
    float width = 0.1;
    float height = 2;
    glPushMatrix();
    glTranslatef(x, y, z);

    glTranslatef(-0.5, 0, 0);   // ƽ�Ƶ���ת����
    glRotatef(angle, 0.0, 1.0, 0.0);  // ��Y����ת
    glTranslatef(0.5, 0, 0);  // ƽ�ƻ���

    // ���ò�������
    GLfloat Ambient[] = { 0.8, 0.8, 0.8, 1.0 };   // �����⣨�ʶ�������
    GLfloat Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };   // �����䣨�����������䣩
    GLfloat Specular[] = { 0.2, 0.2, 0.2, 1.0 };  // ���淴�䣨�ʶ�������
    GLfloat Shininess = 10.0;                      // �����

    glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
    glMaterialf(GL_FRONT, GL_SHININESS, Shininess);

    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 8, 8, 2, 2, 2, 2);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}
void draw_crafting_table(float x, float y, float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 1;
    float width = 1;
    float height = 1;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1, 1, 1);

    // ���ò�������
    GLfloat Ambient[] = { 0.8, 0.8, 0.8, 1.0 };   // �����⣨�ʶ�������
    GLfloat Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };   // �����䣨�����������䣩
    GLfloat Specular[] = { 0.2, 0.2, 0.2, 1.0 };  // ���淴�䣨�ʶ�������
    GLfloat Shininess = 10.0;                      // �����


    glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
    glMaterialf(GL_FRONT, GL_SHININESS, Shininess);

    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 9, 9, 10, 10, 11, 11);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}
void draw_help_sign(float x, float y, float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 1.34;
    float width = 0.05;
    float height = 0.5;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1, 1, 1);

    // ���ò�������
    GLfloat Ambient[] = { 0.8, 0.8, 0.8, 1.0 };   // �����⣨�ʶ�������
    GLfloat Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };   // �����䣨�����������䣩
    GLfloat Specular[] = { 0.2, 0.2, 0.2, 1.0 };  // ���淴�䣨�ʶ�������
    GLfloat Shininess = 10.0;                      // �����


    glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
    glMaterialf(GL_FRONT, GL_SHININESS, Shininess);

    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 12, 12, 1,1,1,1);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}
void draw_hint_sign(float x, float y, float z) {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;
    float length = 1.34;
    float width = 0.05;
    float height = 0.5;
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1, 1, 1);

    // ���ò�������
    GLfloat Ambient[] = { 0.8, 0.8, 0.8, 1.0 };   // �����⣨�ʶ�������
    GLfloat Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };   // �����䣨�����������䣩
    GLfloat Specular[] = { 0.2, 0.2, 0.2, 1.0 };  // ���淴�䣨�ʶ�������
    GLfloat Shininess = 10.0;                      // �����


    glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
    glMaterialf(GL_FRONT, GL_SHININESS, Shininess);

    drawCuboid_whole_textures(centerX, centerY, centerZ, length, width, height, 13, 13, 1, 1, 1, 1);
    glPopMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
}



void draw_house()
{
    draw_help_sign(-1, -0.5, 1.15);
    draw_hint_sign(0, 0.5, -6.48);
    draw_crafting_table(0, -0.5, -6);
    // �ػ�
    {
        draw_oak_planks(1, -1.5, 1);
        draw_oak_planks(1, -1.5, 2);
        draw_oak_planks(1, -1.5, 3);
        draw_oak_planks(1, -1.5, 4);
        draw_oak_planks(1, -1.5, 5);
        draw_oak_planks(1, -1.5, 0);

        draw_oak_planks(-1, -1.5, 1);
        draw_oak_planks(-1, -1.5, 2);
        draw_oak_planks(-1, -1.5, 3);
        draw_oak_planks(-1, -1.5, 4);
        draw_oak_planks(-1, -1.5, 5);
        draw_oak_planks(-1, -1.5, 0);

        draw_oak_planks(0, -1.5, 1);
        draw_oak_planks(0, -1.5, 2);
        draw_oak_planks(0, -1.5, 3);
        draw_oak_planks(0, -1.5, 4);
        draw_birch_planks(0, -1.5, 5);
        draw_oak_planks(0, -1.5, 0);


        draw_oak_planks(-5, -1.5, -1);
        draw_oak_planks(-4, -1.5, -1);
        draw_oak_planks(-3, -1.5, -1);
        draw_oak_planks(-2, -1.5, -1);
        draw_oak_planks(-1, -1.5, -1);
        draw_oak_planks(0, -1.5, -1);
        draw_oak_planks(1, -1.5, -1);
        draw_oak_planks(2, -1.5, -1);
        draw_oak_planks(3, -1.5, -1);
        draw_oak_planks(4, -1.5, -1);

        draw_oak_planks(-5, -1.5, -2);
        draw_oak_planks(-4, -1.5, -2);
        draw_oak_planks(-3, -1.5, -2);
        draw_oak_planks(-2, -1.5, -2);
        draw_oak_planks(-1, -1.5, -2);
        draw_oak_planks(0, -1.5, -2);
        draw_oak_planks(1, -1.5, -2);
        draw_oak_planks(2, -1.5, -2);
        draw_oak_planks(3, -1.5, -2);
        draw_oak_planks(4, -1.5, -2);

        draw_oak_planks(-5, -1.5, -3);
        draw_oak_planks(-4, -1.5, -3);
        draw_oak_planks(-3, -1.5, -3);
        draw_oak_planks(-2, -1.5, -3);
        draw_oak_planks(-1, -1.5, -3);
        draw_oak_planks(0, -1.5, -3);
        draw_oak_planks(1, -1.5, -3);
        draw_oak_planks(2, -1.5, -3);
        draw_oak_planks(3, -1.5, -3);
        draw_oak_planks(4, -1.5, -3);

        draw_oak_planks(-5, -1.5, -4);
        draw_oak_planks(-4, -1.5, -4);
        draw_oak_planks(-3, -1.5, -4);
        draw_oak_planks(-2, -1.5, -4);
        draw_oak_planks(-1, -1.5, -4);
        draw_oak_planks(0, -1.5, -4);
        draw_oak_planks(1, -1.5, -4);
        draw_oak_planks(2, -1.5, -4);
        draw_oak_planks(3, -1.5, -4);
        draw_oak_planks(4, -1.5, -4);

        draw_oak_planks(-5, -1.5, -5);
        draw_oak_planks(-4, -1.5, -5);
        draw_oak_planks(-3, -1.5, -5);
        draw_oak_planks(-2, -1.5, -5);
        draw_oak_planks(-1, -1.5, -5);
        draw_oak_planks(0, -1.5, -5);
        draw_oak_planks(1, -1.5, -5);
        draw_oak_planks(2, -1.5, -5);
        draw_oak_planks(3, -1.5, -5);
        draw_oak_planks(4, -1.5, -5);

        draw_oak_planks(-5, -1.5, -6);
        draw_oak_planks(-4, -1.5, -6);
        draw_oak_planks(-3, -1.5, -6);
        draw_oak_planks(-2, -1.5, -6);
        draw_oak_planks(-1, -1.5, -6);
        draw_oak_planks(0, -1.5, -6);
        draw_oak_planks(1, -1.5, -6);
        draw_oak_planks(2, -1.5, -6);
        draw_oak_planks(3, -1.5, -6);
        draw_oak_planks(4, -1.5, -6);

        draw_oak_planks(-5, -1.5, -7);
        draw_oak_planks(-4, -1.5, -7);
        draw_oak_planks(-3, -1.5, -7);
        draw_oak_planks(-2, -1.5, -7);
        draw_oak_planks(-1, -1.5, -7);
        draw_oak_planks(0, -1.5, -7);
        draw_oak_planks(1, -1.5, -7);
        draw_oak_planks(2, -1.5, -7);
        draw_oak_planks(3, -1.5, -7);
        draw_oak_planks(4, -1.5, -7);

        draw_oak_planks(-5, -1.5, -8);
        draw_oak_planks(-4, -1.5, -8);
        draw_oak_planks(-3, -1.5, -8);
        draw_oak_planks(-2, -1.5, -8);
        draw_oak_planks(-1, -1.5, -8);
        draw_oak_planks(0, -1.5, -8);
        draw_oak_planks(1, -1.5, -8);
        draw_oak_planks(2, -1.5, -8);
        draw_oak_planks(3, -1.5, -8);
        draw_oak_planks(4, -1.5, -8);
    }

    // ǽ
    {
        draw_iron_door(-0, 0, -2);

        draw_light_gray_concrete(-4, 1.5, -2);
        //draw_light_gray_concrete(-3, 1.5, -2);
        //draw_light_gray_concrete(-2, 1.5, -2);
        draw_oak_tardoor(-3, 1.5, -2);
        draw_oak_tardoor(-2, 1.5, -2);
        draw_light_gray_concrete(-1, 1.5, -2);
        draw_light_gray_concrete(-0, 1.5, -2);
        draw_light_gray_concrete(1, 1.5, -2);
        draw_light_gray_concrete(2, 1.5, -2);
        draw_light_gray_concrete(3, 1.5, -2);

        draw_light_gray_concrete(-4, 2.5, -2);
        draw_light_gray_concrete(-3, 2.5, -2);
        draw_light_gray_concrete(-2, 2.5, -2);
        draw_light_gray_concrete(-1, 2.5, -2);
        draw_light_gray_concrete(-0, 2.5, -2);
        draw_light_gray_concrete(1, 2.5, -2);
        draw_light_gray_concrete(2, 2.5, -2);
        draw_light_gray_concrete(3, 2.5, -2);

        draw_light_gray_concrete(-4, 1.5, -7);
        draw_light_gray_concrete(-3, 1.5, -7);
        draw_light_gray_concrete(-2, 1.5, -7);
        draw_light_gray_concrete(-1, 1.5, -7);
        draw_light_gray_concrete(-0, 1.5, -7);
        draw_light_gray_concrete(1, 1.5, -7);
        draw_light_gray_concrete(2, 1.5, -7);
        draw_light_gray_concrete(3, 1.5, -7);

        draw_light_gray_concrete(-4, 2.5, -7);
        draw_light_gray_concrete(-3, 2.5, -7);
        draw_light_gray_concrete(-2, 2.5, -7);
        draw_light_gray_concrete(-1, 2.5, -7);
        draw_light_gray_concrete(-0, 2.5, -7);
        draw_light_gray_concrete(1, 2.5, -7);
        draw_light_gray_concrete(2, 2.5, -7);
        draw_light_gray_concrete(3, 2.5, -7);

        draw_light_gray_concrete(-4, 1.5, -3);
        draw_light_gray_concrete(-4, 1.5, -4);
        draw_light_gray_concrete(-4, 1.5, -5);
        draw_light_gray_concrete(-4, 1.5, -6);

        draw_light_gray_concrete(-4, 2.5, -3);
        draw_light_gray_concrete(-4, 2.5, -4);
        draw_light_gray_concrete(-4, 2.5, -5);
        draw_light_gray_concrete(-4, 2.5, -6);

        draw_light_gray_concrete(3, 1.5, -3);
        draw_light_gray_concrete(3, 1.5, -4);
        draw_light_gray_concrete(3, 1.5, -5);
        draw_light_gray_concrete(3, 1.5, -6);

        draw_light_gray_concrete(3, 2.5, -3);
        draw_light_gray_concrete(3, 2.5, -4);
        draw_light_gray_concrete(3, 2.5, -5);
        draw_light_gray_concrete(3, 2.5, -6);
    }
    {
        draw_white_concrete(-4,3.5,-3);
        draw_white_concrete(-4,3.5,-4);
        draw_white_concrete(-4,3.5,-5);
        draw_white_concrete(-4,3.5,-6);
        draw_white_concrete(-4, 4.5, -4);
        draw_white_concrete(-4, 4.5, -5);

        draw_white_concrete(3, 3.5, -3);
        draw_white_concrete(3, 3.5, -4);
        draw_white_concrete(3, 3.5, -5);
        draw_white_concrete(3, 3.5, -6);
        draw_white_concrete(3, 4.5, -4);
        draw_white_concrete(3, 4.5, -5);

        draw_white_concrete(-4, -0.5, -2);
        draw_white_concrete(-3, -0.5, -2);
        draw_white_concrete(-2, -0.5, -2);
        draw_white_concrete(-1, -0.5, -2);
        //draw_white_concrete(-0, -0.5, -2);
        draw_white_concrete(1, -0.5, -2);
        draw_white_concrete(2, -0.5, -2);
        draw_white_concrete(3, -0.5, -2);

        draw_white_concrete(-4, 0.5, -2);
        //draw_white_concrete(-3, 0.5, -2);
        //draw_white_concrete(-2, 0.5, -2);
        draw_oak_tardoor(-3, 0.5, -2);
        draw_oak_tardoor(-2, 0.5, -2);
        draw_white_concrete(-1, 0.5, -2);
        //draw_white_concrete(-0, 0.5, -2);
        draw_white_concrete(1, 0.5, -2);
        draw_white_concrete(2, 0.5, -2);
        draw_white_concrete(3, 0.5, -2);

        draw_white_concrete(-4, -0.5, -7);
        draw_white_concrete(-3, -0.5, -7);
        draw_white_concrete(-2, -0.5, -7);
        draw_white_concrete(-1, -0.5, -7);
        draw_white_concrete(-0, -0.5, -7);
        draw_white_concrete(1, -0.5, -7);
        draw_white_concrete(2, -0.5, -7);
        draw_white_concrete(3, -0.5, -7);

        draw_white_concrete(-4, 0.5, -7);
        draw_white_concrete(-3, 0.5, -7);
        draw_white_concrete(-2, 0.5, -7);
        draw_white_concrete(-1, 0.5, -7);
        draw_white_concrete(-0, 0.5, -7);
        draw_white_concrete(1, 0.5, -7);
        draw_white_concrete(2, 0.5, -7);
        draw_white_concrete(3, 0.5, -7);

        draw_white_concrete(-4, -0.5, -3);
        draw_white_concrete(-4, -0.5, -4);
        draw_white_concrete(-4, -0.5, -5);
        draw_white_concrete(-4, -0.5, -6);

        draw_white_concrete(-4, 0.5, -3);
        draw_white_concrete(-4, 0.5, -4);
        draw_white_concrete(-4, 0.5, -5);
        draw_white_concrete(-4, 0.5, -6);

        draw_white_concrete(3, -0.5, -3);
        draw_white_concrete(3, -0.5, -4);
        draw_white_concrete(3, -0.5, -5);
        draw_white_concrete(3, -0.5, -6);

        draw_white_concrete(3, 0.5, -3);
        draw_white_concrete(3, 0.5, -4);
        draw_white_concrete(3, 0.5, -5);
        draw_white_concrete(3, 0.5, -6);
    }
    // ̨��
    {
        draw_dark_oak_plank_slabs(-5, 2.25, -1);
        draw_dark_oak_plank_slabs(-4, 2.25, -1);
        draw_dark_oak_plank_slabs(-3, 2.25, -1);
        draw_dark_oak_plank_slabs(-2, 2.25, -1);
        draw_dark_oak_plank_slabs(-1, 2.25, -1);
        //draw_dark_oak_plank_slabs(-0, 2.25, -1);
        draw_dark_oak_plank_slabs(1, 2.25, -1);
        draw_dark_oak_plank_slabs(2, 2.25, -1);
        draw_dark_oak_plank_slabs(3, 2.25, -1);
        draw_dark_oak_plank_slabs(4, 2.25, -1);

        draw_dark_oak_plank_slabs(-5, 2.75, -1.5);
        draw_dark_oak_plank_slabs(-4, 2.75, -1.5);
        draw_dark_oak_plank_slabs(-3, 2.75, -1.5);
        draw_dark_oak_plank_slabs(-2, 2.75, -1.5);
        draw_dark_oak_plank_slabs(-1, 2.75, -1.5);
        draw_dark_oak_plank_slabs(-0, 2.75, -1.5);
        draw_dark_oak_plank_slabs( 1, 2.75, -1.5);
        draw_dark_oak_plank_slabs( 2, 2.75, -1.5);
        draw_dark_oak_plank_slabs( 3, 2.75, -1.5);
        draw_dark_oak_plank_slabs( 4, 2.75, -1.5);

        draw_dark_oak_plank_slabs(-5, 3.25, -2);
        draw_dark_oak_plank_slabs(-4, 3.25, -2);
        draw_dark_oak_plank_slabs(-3, 3.25, -2);
        draw_dark_oak_plank_slabs(-2, 3.25, -2);
        draw_dark_oak_plank_slabs(-1, 3.25, -2);
        draw_dark_oak_plank_slabs(-0, 3.25, -2);
        draw_dark_oak_plank_slabs( 1, 3.25, -2);
        draw_dark_oak_plank_slabs( 2, 3.25, -2);
        draw_dark_oak_plank_slabs( 3, 3.25, -2);
        draw_dark_oak_plank_slabs( 4, 3.25, -2);

        draw_dark_oak_plank_slabs(-5, 3.75, -2.5);
        draw_dark_oak_plank_slabs(-4, 3.75, -2.5);
        draw_dark_oak_plank_slabs(-3, 3.75, -2.5);
        draw_dark_oak_plank_slabs(-2, 3.75, -2.5);
        draw_dark_oak_plank_slabs(-1, 3.75, -2.5);
        draw_dark_oak_plank_slabs(-0, 3.75, -2.5);
        draw_dark_oak_plank_slabs( 1, 3.75, -2.5);
        draw_dark_oak_plank_slabs( 2, 3.75, -2.5);
        draw_dark_oak_plank_slabs( 3, 3.75, -2.5);
        draw_dark_oak_plank_slabs( 4, 3.75, -2.5);

        draw_dark_oak_plank_slabs(-5, 4.25, -3);
        draw_dark_oak_plank_slabs(-4, 4.25, -3);
        draw_dark_oak_plank_slabs(-3, 4.25, -3);
        draw_dark_oak_plank_slabs(-2, 4.25, -3);
        draw_dark_oak_plank_slabs(-1, 4.25, -3);
        draw_dark_oak_plank_slabs(-0, 4.25, -3);
        draw_dark_oak_plank_slabs( 1, 4.25, -3);
        draw_dark_oak_plank_slabs( 2, 4.25, -3);
        draw_dark_oak_plank_slabs( 3, 4.25, -3);
        draw_dark_oak_plank_slabs( 4, 4.25, -3);

        draw_dark_oak_plank_slabs(-5, 4.75, -3.5);
        draw_dark_oak_plank_slabs(-4, 4.75, -3.5);
        draw_dark_oak_plank_slabs(-3, 4.75, -3.5);
        draw_dark_oak_plank_slabs(-2, 4.75, -3.5);
        draw_dark_oak_plank_slabs(-1, 4.75, -3.5);
        draw_dark_oak_plank_slabs(-0, 4.75, -3.5);
        draw_dark_oak_plank_slabs( 1, 4.75, -3.5);
        draw_dark_oak_plank_slabs( 2, 4.75, -3.5);
        draw_dark_oak_plank_slabs( 3, 4.75, -3.5);
        draw_dark_oak_plank_slabs( 4, 4.75, -3.5);

        draw_dark_oak_plank_slabs(-5, 5.25, -4);
        draw_dark_oak_plank_slabs(-4, 5.25, -4);
        draw_dark_oak_plank_slabs(-3, 5.25, -4);
        draw_dark_oak_plank_slabs(-2, 5.25, -4);
        draw_dark_oak_plank_slabs(-1, 5.25, -4);
        draw_dark_oak_plank_slabs(-0, 5.25, -4);
        draw_dark_oak_plank_slabs( 1, 5.25, -4);
        draw_dark_oak_plank_slabs( 2, 5.25, -4);
        draw_dark_oak_plank_slabs( 3, 5.25, -4);
        draw_dark_oak_plank_slabs( 4, 5.25, -4);

        draw_dark_oak_plank_slabs(-5, 5.75, -4.5);
        draw_dark_oak_plank_slabs(-4, 5.75, -4.5);
        draw_dark_oak_plank_slabs(-3, 5.75, -4.5);
        draw_dark_oak_plank_slabs(-2, 5.75, -4.5);
        draw_dark_oak_plank_slabs(-1, 5.75, -4.5);
        draw_dark_oak_plank_slabs(-0, 5.75, -4.5);
        draw_dark_oak_plank_slabs( 1, 5.75, -4.5);
        draw_dark_oak_plank_slabs( 2, 5.75, -4.5);
        draw_dark_oak_plank_slabs( 3, 5.75, -4.5);
        draw_dark_oak_plank_slabs( 4, 5.75, -4.5);

        draw_dark_oak_plank_slabs(-5, 5.25, -5);
        draw_dark_oak_plank_slabs(-4, 5.25, -5);
        draw_dark_oak_plank_slabs(-3, 5.25, -5);
        draw_dark_oak_plank_slabs(-2, 5.25, -5);
        draw_dark_oak_plank_slabs(-1, 5.25, -5);
        draw_dark_oak_plank_slabs(-0, 5.25, -5);
        draw_dark_oak_plank_slabs( 1, 5.25, -5);
        draw_dark_oak_plank_slabs( 2, 5.25, -5);
        draw_dark_oak_plank_slabs( 3, 5.25, -5);
        draw_dark_oak_plank_slabs( 4, 5.25, -5);

        
        draw_dark_oak_plank_slabs(-5, 4.75, -5.5);
        draw_dark_oak_plank_slabs(-4, 4.75, -5.5);
        draw_dark_oak_plank_slabs(-3, 4.75, -5.5);
        draw_dark_oak_plank_slabs(-2, 4.75, -5.5);
        draw_dark_oak_plank_slabs(-1, 4.75, -5.5);
        draw_dark_oak_plank_slabs(-0, 4.75, -5.5);
        draw_dark_oak_plank_slabs( 1, 4.75, -5.5);
        draw_dark_oak_plank_slabs( 2, 4.75, -5.5);
        draw_dark_oak_plank_slabs( 3, 4.75, -5.5);
        draw_dark_oak_plank_slabs( 4, 4.75, -5.5);

        draw_dark_oak_plank_slabs(-5, 4.25, -6);
        draw_dark_oak_plank_slabs(-4, 4.25, -6);
        draw_dark_oak_plank_slabs(-3, 4.25, -6);
        draw_dark_oak_plank_slabs(-2, 4.25, -6);
        draw_dark_oak_plank_slabs(-1, 4.25, -6);
        draw_dark_oak_plank_slabs(-0, 4.25, -6);
        draw_dark_oak_plank_slabs( 1, 4.25, -6);
        draw_dark_oak_plank_slabs( 2, 4.25, -6);
        draw_dark_oak_plank_slabs( 3, 4.25, -6);
        draw_dark_oak_plank_slabs( 4, 4.25, -6);

        draw_dark_oak_plank_slabs(-5, 3.75, -6.5);
        draw_dark_oak_plank_slabs(-4, 3.75, -6.5);
        draw_dark_oak_plank_slabs(-3, 3.75, -6.5);
        draw_dark_oak_plank_slabs(-2, 3.75, -6.5);
        draw_dark_oak_plank_slabs(-1, 3.75, -6.5);
        draw_dark_oak_plank_slabs(-0, 3.75, -6.5);
        draw_dark_oak_plank_slabs( 1, 3.75, -6.5);
        draw_dark_oak_plank_slabs( 2, 3.75, -6.5);
        draw_dark_oak_plank_slabs( 3, 3.75, -6.5);
        draw_dark_oak_plank_slabs( 4, 3.75, -6.5);

        draw_dark_oak_plank_slabs(-5, 3.25, -7);
        draw_dark_oak_plank_slabs(-4, 3.25, -7);
        draw_dark_oak_plank_slabs(-3, 3.25, -7);
        draw_dark_oak_plank_slabs(-2, 3.25, -7);
        draw_dark_oak_plank_slabs(-1, 3.25, -7);
        draw_dark_oak_plank_slabs(-0, 3.25, -7);
        draw_dark_oak_plank_slabs( 1, 3.25, -7);
        draw_dark_oak_plank_slabs( 2, 3.25, -7);
        draw_dark_oak_plank_slabs( 3, 3.25, -7);
        draw_dark_oak_plank_slabs( 4, 3.25, -7);

        draw_dark_oak_plank_slabs(-5, 2.75, -7.5);
        draw_dark_oak_plank_slabs(-4, 2.75, -7.5);
        draw_dark_oak_plank_slabs(-3, 2.75, -7.5);
        draw_dark_oak_plank_slabs(-2, 2.75, -7.5);
        draw_dark_oak_plank_slabs(-1, 2.75, -7.5);
        draw_dark_oak_plank_slabs(-0, 2.75, -7.5);
        draw_dark_oak_plank_slabs( 1, 2.75, -7.5);
        draw_dark_oak_plank_slabs( 2, 2.75, -7.5);
        draw_dark_oak_plank_slabs( 3, 2.75, -7.5);
        draw_dark_oak_plank_slabs( 4, 2.75, -7.5);

        draw_dark_oak_plank_slabs(-5, 2.25, -8);
        draw_dark_oak_plank_slabs(-4, 2.25, -8);
        draw_dark_oak_plank_slabs(-3, 2.25, -8);
        draw_dark_oak_plank_slabs(-2, 2.25, -8);
        draw_dark_oak_plank_slabs(-1, 2.25, -8);
        draw_dark_oak_plank_slabs(-0, 2.25, -8);
        draw_dark_oak_plank_slabs( 1, 2.25, -8);
        draw_dark_oak_plank_slabs( 2, 2.25, -8);
        draw_dark_oak_plank_slabs( 3, 2.25, -8);
        draw_dark_oak_plank_slabs( 4, 2.25, -8);


        draw_dark_oak_plank_slabs(0, 3.25, 1);
        draw_dark_oak_plank_slabs(0, 3.25, 0);

        draw_dark_oak_plank_slabs(-0.5, 2.75, 0);
        draw_dark_oak_plank_slabs(-1, 2.25, 0);
        draw_dark_oak_plank_slabs(-0.5, 2.75, 1);
        draw_dark_oak_plank_slabs(-1, 2.25, 1);

        draw_dark_oak_plank_slabs(0.5, 2.75, 0);
        draw_dark_oak_plank_slabs(1, 2.25, 0);
        draw_dark_oak_plank_slabs(0.5, 2.75, 1);
        draw_dark_oak_plank_slabs(1, 2.25, 1);

        draw_dark_oak_planks(1, 1.5, 1);
        draw_dark_oak_planks(1, 0.5, 1);
        draw_dark_oak_planks(1, -0.5, 1);

        draw_dark_oak_planks(-1, 1.5, 1);
        draw_dark_oak_planks(-1, 0.5, 1);
        draw_dark_oak_planks(-1, -0.5, 1);

    }
    
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    setTexture();
    // ���ù۲��ӽ�
    glLoadIdentity();
    gluLookAt(
        cameraX, cameraY, cameraZ,
        cameraX + 5.0 * sin(cameraAngleY), cameraY, cameraZ - 5.0 * cos(cameraAngleY),
        0.0, 1.0, 0.0
    );

    // ������յ���ɫ
    glClearColor(0.7, 0.9, 1.0, 1.0); // ����ɫ

    // ����̫����Դ��λ�ú���ɫ
    GLfloat sunPosition[] = { 0, 4.0, 0, 1.0 }; // ̫��λ��
    glLightfv(GL_LIGHT0, GL_POSITION, sunPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, sunAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sunDiffuse);

    draw_house();

    glDisable(GL_BLEND);
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("My House");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);  // ���õ�һ�ζ�ʱ��
    glutPassiveMotionFunc(mouse); // ʹ��glutPassiveMotionFunc����������ƶ��¼�
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    init();

    glutMainLoop();

    return 0;
}
