#include <iostream>

using namespace std;


class Shape
{
    public:
        int angles;
        int width;
        int height;

        Shape(
            int _angles,
            int _width,
            int _height
        ): angles(_angles), width(_width), height(_height)
        {
            cout << "Calling Shape constructor" << endl;
        }

        ~Shape() {
            cout << "Calling Shape destructor" << endl;
        }

        virtual int getArea() = 0;
};

class Triangle : public Shape
{
    public:
        Triangle(int _width, int _height) : Shape(3, _width, _height)
        {
            cout << "Calling Triangle constructor" << endl;
        }

        int getArea()
        {
            return width * height / 2;
        }

        ~Triangle() {
            cout << "Calling Triangle destructor" << endl;
        }
};

class Rectangle : public Shape
{
    public:
        Rectangle(int _width, int _height) : Shape(4, _width, _height)
        {
            cout << "Calling Rectangle constructor" << endl;
        }

        int getArea()
        {
            return width * height;
        }

        ~Rectangle() {
            cout << "Calling Rectangle destructor" << endl;
        }
};

void displayArea(Shape& shape) {
    cout << shape.getArea() << endl;
}


// Another beautiful comment
// Beautiful comment
int main()
{
    Triangle triangle1(10, 5);
    Rectangle rectangle1(8, 4);

    cout << triangle1.getArea() << endl;
    cout << rectangle1.getArea() << endl;

    displayArea(triangle1);
    displayArea(rectangle1);

    delete &triangle1;
    delete &rectangle1;

    return 0;
}
