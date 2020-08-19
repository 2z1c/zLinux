#include <iostream>
using namespace std;

class Shape
{
protected:
  int width, height;

public:
  Shape(int a = 0, int b = 0)
  {
    width = a;
    height = b;
  }
  //! virtual  声明为纯虚函数，需要子类必须声明一个 area 结构
  virtual int area() = 0;
};
class Rectangle : public Shape
{
public:
  Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
  int area()
  {
    float ret = (width * height);
    cout << "Rectangle class area :" <<ret <<endl;
    return ret;
  }
};
class Triangle : public Shape
{
public:
  Triangle(int a = 0, int b = 0) : Shape(a, b) {}
  int area()
  {
    float ret = (width * height / 2);
    cout << "Triangle class area :"<< ret << endl;
    return ret;
  }
};
// 程序的主函数
int main()
{
  Shape *shape;
  Rectangle rec(10, 7);
  Triangle tri(10, 5);

  // 存储矩形的地址
  shape = &rec;
  // 调用矩形的求面积函数 area
  shape->area();
  rec.area();

  // 存储三角形的地址
  shape = &tri;
  // 调用三角形的求面积函数 area
  shape->area();
  tri.area();
  return 0;
}