/**
* @brief Pinwheel implementation using OpenGL and GLUT for Computer Graphics.
* discipline of Computer Science degree in Universidade Federal de Alagoas
* @author Ricardo Vinicius
* @date 04 mar 2025
*
* A program that draws a Pinwheel like polygon based graphics, and animates
* using logic and GLUT functionalities
*
*/

#include <GL/gl.h>
#include <GL/glut.h>

#include <deque>
#include <iostream>
#include <valarray>

#include <vector>

using namespace std;

struct color_t {
  float r, g, b;
};

struct vertex_t {
  float x, y, z;
};

class Shape {
  public:
  color_t color{};
  virtual ~Shape() = default;
  virtual void draw() = 0;
};

class Triangle final : public Shape {
  vertex_t v1, v2, v3;

  public:
  Triangle(const color_t color, const vertex_t v1, const vertex_t v2,
          const vertex_t v3)
    : Shape() {
    this->color = color;
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
  }

  void draw() override {
    glBegin(GL_TRIANGLES);
      glColor3f(color.r, color.g, color.b);
      glVertex3f(v1.x, v1.y, v1.z);
      glVertex3f(v2.x, v2.y, v2.z);
      glVertex3f(v3.x, v3.y, v3.z);
    glEnd();
  }
};

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);

  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

vector<Shape*> shapes;
deque<color_t> colors_queue;

void animate(int value) {
  for (int i = 1; i < shapes.size(); i++) {
    shapes[i]->color = colors_queue[i % colors_queue.size()];
  }

  auto last = colors_queue.back();
  colors_queue.pop_back();
  colors_queue.push_front(last);

  glutPostRedisplay();
  glutTimerFunc(240, animate, 1);
}


void render() {
  glClear(GL_COLOR_BUFFER_BIT);

  for (const auto shape : shapes) {
    shape->draw();
  }

  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("OpenGL é Massa");
  glutInitWindowSize(500, 500);

  init();

  vertex_t center = {250.0, 250.0, 0.0};
  float triangle_height = 50.0;
  float half_side = triangle_height / sqrt(3);

  float column_height = 200;

  color_t grey = {0.5, 0.5, 0.5};
  auto triangle_base = Triangle(grey, center,
    {center.x + half_side, center.y - column_height, 0.0},
    {center.x - half_side, center.y - column_height, 0.0});
  shapes.push_back(&triangle_base);

  color_t red = {1.0, 0.0, 0.0};
  color_t green = {0.0, 1.0, 0.0};
  color_t blue = {0.0, 0.0, 1.0};
  color_t white = {1.0, 1.0, 1.0};

  colors_queue.push_back(red);
  colors_queue.push_back(green);
  colors_queue.push_back(blue);
  colors_queue.push_back(white);

  auto triangle_1 = Triangle(red, center,
    {center.x + half_side, center.y + triangle_height, 0.0},
    {center.x - half_side, center.y + triangle_height, 0.0});
  shapes.push_back(&triangle_1);

  auto triangle_2 = Triangle(green, center,
  {center.x + triangle_height, center.y + half_side, 0.0},
  {center.x + triangle_height, center.y - half_side, 0.0});
  shapes.push_back(&triangle_2);

  auto triangle_3 = Triangle(blue, center,
  {center.x - triangle_height, center.y + half_side, 0.0},
  {center.x - triangle_height, center.y - half_side, 0.0});
  shapes.push_back(&triangle_3);

  auto triangle_4 = Triangle(white, center,
  {center.x + half_side, center.y - triangle_height, 0.0},
  {center.x - half_side, center.y - triangle_height, 0.0});
  shapes.push_back(&triangle_4);

  glutDisplayFunc(render);
  glutTimerFunc(240, animate, 1);

  glutMainLoop();
  return 0;
}