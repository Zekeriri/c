#define FREEGLUT_STATIC
#include <GL/freeglut.h>
#include <cmath>
#include <iostream>

float rotationAngle = 0.0f; // Initial rotation angle
bool continueClicked = false; // Mouse click flag
bool secondScene = false; // Flag for the second scene

void drawRectangle(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}
void drawStar() {
    glPushMatrix();
    glTranslatef(0.0f, 0.7f, 0.0f);
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.05f, 0.15f);
    glVertex2f(0.05f, 0.15f);
    glEnd();
    glPopMatrix();
}
void drawFilledPolygon(float scale, float xOffset, float yOffset) {
    //glClear(GL_COLOR_BUFFER_BIT);

    // 设置点的颜色
    glColor3f(1.0f, 1.0f, 1.0f);

    // 定义点的坐标并应用缩放和偏移
    GLfloat points[5][2] = {
        {-0.1f, 0.25f},
        {0.18f, 0.25f},
        {-0.1f, 0.0f},
        {0.1f, 0.0f},
        {0.0f, -0.2f}
    };

    for (int i = 0; i < 5; i++) {
        points[i][0] = points[i][0] * scale + xOffset;
        points[i][1] = points[i][1] * scale + yOffset;
    }

    // 绘制点
    glBegin(GL_POINTS);
    for (int i = 0; i < 5; i++) {
        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();

    // 填充五边形
    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; i++) {
        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();

    glFlush();
}
void drawShieldBottom() {
    //glClear(GL_COLOR_BUFFER_BIT);

    // 设置盾牌底部的颜色
    glColor3f(7.0f / 255.0f, 29.0f / 255.0f, 116.0f / 255.0f);

    // 定义三个控制点，左半部分
    float x0 = -0.23f;
    float y0 = 0.2f;
    float x1 = -0.25f;
    float y1 = -0.4f;
    float x2 = 0.0f;
    float y2 = -0.6f;

    // 绘制左半部分的弧形，使用GL_POLYGON来填充颜色
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; i++) {
        float t = static_cast<float>(i) / 100.0f;
        float one_minus_t = 1.0f - t;
        float x = one_minus_t * one_minus_t * x0 + 2.0f * one_minus_t * t * x1 + t * t * x2;
        float y = one_minus_t * one_minus_t * y0 + 2.0f * one_minus_t * t * y1 + t * t * y2;
        glVertex2f(x, y);
    }
    glEnd();

    // 对称绘制右半部分
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; i++) {
        float t = static_cast<float>(i) / 100.0f;
        float one_minus_t = 1.0f - t;
        float x = -one_minus_t * one_minus_t * x0 - 2.0f * one_minus_t * t * x1 - t * t * x2; // 反向 x 坐标
        float y = one_minus_t * one_minus_t * y0 + 2.0f * one_minus_t * t * y1 + t * t * y2;
        glVertex2f(x, y);
    }
    glEnd();

    // 绘制中间的三角形并填充颜色
    glBegin(GL_POLYGON);
    glVertex2f(x0, y0);
    glVertex2f(-x0, y0);
    glVertex2f(x2, y2);
    glEnd();

    glFlush();
}
void drawBadge() {
    // 绘制圆形
    const int segments = 100;  // 椭圆的线段数
    const GLfloat xRadius = 0.0625;  // x轴半径
    const GLfloat yRadius = 0.1;  // y轴半径
    glBegin(GL_POLYGON);  // 使用GL_POLYGON来绘制填充的椭圆
    glColor3f(1.0, 1.0, 1.0); 

    for (int i = 0; i < segments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);
        float x = xRadius * cos(theta);
        float y = yRadius * sin(theta);
        glVertex2f(x, y - 0.1);
    }

    glEnd();

    // 绘制正方形
    drawRectangle(-0.08, -0.18, 0.08, -0.22, 1.0, 1.0, 1.0);
}
void drawScene1() {
    // First scene drawing code
    drawRectangle(-1.0f, -0.92f, 1.0f, -0.84f, 0.2f, 0.2f, 0.2f);
    drawRectangle(-1.0f, -0.94f, 1.0f, -0.92f, 1.0f, 1.0f, 0.0f);
    drawRectangle(-1.0f, -0.84f, 1.0f, -0.82f, 1.0f, 1.0f, 0.0f);
    drawStar();
    //draw school badge
    drawShieldBottom();
    drawFilledPolygon(0.35, 0.13, 0);
    drawFilledPolygon(0.35, -0.13, 0);
    drawFilledPolygon(0.5, -0, -0.4);
    drawBadge();
}

void drawQuadrilateral(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}
void drawScene2() {
    // Second scene drawing code
    glClearColor(95.0f / 255.0f, 197.0f / 255.0f, 193.0f / 255.0f, 0.5f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //draw background
    drawRectangle(-1.0f, -1.0f, 1.0f, -0.75f, 173.0f / 255.0f, 116.0f / 255.0f, 47.0f / 255.0f);
    drawQuadrilateral(-0.1, 0.5, 0.7, 0.2,  0.7, -0.75,-0.1, -0.75, 141.0 / 255.0, 147.0 / 255.0, 163.0 / 255.0);
    drawQuadrilateral(-0.6, 0.1, -0.1, 0.5,  -0.1, -0.75,-0.6, -0.75, 232.0/255.0, 191.0/255.0, 173.0/255.0);
    //draw building
    drawQuadrilateral(0.3,0.35 ,0.4 , 0.31, 0.5, -0.4,0.33, -0.35, 75.0/255.0, 96.0/255.0, 138.0/255.0);
    drawQuadrilateral(0.3,-0.3 ,0.7 , -0.3, 0.7, -0.6,0.3, -0.3, 75.0 / 255.0, 96.0 / 255.0, 138.0 / 255.0);
    drawQuadrilateral(-0.1,-0.1 ,-0.1 , -0.4, 0.5, -0.45,0.6, -0.3, 75.0 / 255.0, 96.0 / 255.0, 138.0 / 255.0);

    drawQuadrilateral(-0.1,-0.1 ,-0.1 , -0.4, -0.4, -0.5,-0.35, -0.35, 35.0 / 255.0, 65.0 / 255.0, 99.0 / 255.0);
    drawQuadrilateral(-0.48,-0.53 ,-0.48 , -0.35, -0.35, -0.35,-0.4, -0.5, 35.0 / 255.0, 65.0 / 255.0, 99.0 / 255.0);
    drawQuadrilateral(-0.4,0.26 ,-0.3,0.34 , -0.3, 0.1, -0.37,0.05, 35.0 / 255.0, 65.0 / 255.0, 99.0 / 255.0);

}

void renderScene(void) {
    glClearColor(48.0f / 255.0f, 56.0f / 255.0f, 65.0f / 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if (secondScene) {
        drawScene2();
    }
    else {
        drawScene1();
    }

    glColor3f(1.0f, 1.0f, 1.0f);
    const char* text = secondScene ? "Celebrate Your Success: XJTLU's 2024 Graduation Ceremony" : "Join Us for the 2024 XJTLU Graduation Celebration!";
    int textLength = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)text);
    glRasterPos2f(-0.5f + (0.5f - (float)textLength / 800.0f), 0.6f);

    for (int i = 0; text[i]; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }

    if (!continueClicked) {
        const char* continueText = "Click Mouse to Continue";
        int continueTextLength = glutBitmapLength(GLUT_BITMAP_9_BY_15, (const unsigned char*)continueText);
        glRasterPos2f(-0.5f + (0.5f - (float)continueTextLength / 800.0f), -0.9f);
        for (int i = 0; continueText[i]; i++) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, continueText[i]);
        }
    }

    glutSwapBuffers();
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (!continueClicked) {
            continueClicked = true;
        }
        else {
            secondScene = true;
        }
    }
}

void timer(int value) {
    rotationAngle += 0.20f;
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 500);
    glutCreateWindow("2024 XJTLU Graduation Ceremony");

    glutDisplayFunc(renderScene);
    glutTimerFunc(0, timer, 0);
    glutMouseFunc(mouseClick);

    glutMainLoop();

    return 0;
}
