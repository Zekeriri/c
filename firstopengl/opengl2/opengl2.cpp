#include <GL/freeglut.h>

void init();
void display();
void keyboard(unsigned char key, int x, int y); // ��Ӳ���
void mouse(int button, int state, int x, int y); // ��Ӳ���

// ��ʼ������
void init() {
    // ���ô��ڴ�С�ͱ���
    glutInitWindowSize(800, 600);
    glutCreateWindow("Graduation Invitation Card");

    // ���ûص�����
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    // ���������ʼ������
}

// ��Ⱦ����
void display() {
    // ��Ⱦ���뿨�����ݣ��������������򡢻��䡢��ľ��Ц�����ƹ⡢���ǡ��Ʋʵ�Ԫ��
    // ����ʹ��OpenGL�Ļ�ͼ�������л���
}

// ���̽�������
void keyboard(unsigned char key, int x, int y) {
    // ������̽��������ݰ���������ͬ�Ķ���
}

// ��꽻������
void mouse(int button, int state, int x, int y) {
    // ����������¼�������������������ͬ�Ķ���
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    init(); // ��ʼ��OpenGL����

    glutMainLoop(); // ������ѭ��

    return 0;
}
