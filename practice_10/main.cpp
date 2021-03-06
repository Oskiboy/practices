#include <iostream>
#include "matrix.hpp"
#include "vector.hpp"
#include "graphics.hpp"

void testVectors(){
        //Creates matrix A and fills it.
    Matrix A(10, 3);
    A.fill(10);
    std::cout << A << std::endl;
    /*
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            A.set( i+j, i, j);
        }
    }
    */

    std::cout << "A: " << std::endl;
    std::cout << A << std::endl;

    //Testing printing of matrix and vectors
    Matrix B(10, 1);
    Vector a(15);
    std::cout << "B: " << std::endl;
    std::cout << B << std::endl;

    std::cout << "a: " << std::endl;
    std::cout << a << std::endl;
    
    //Copy ctor
    Vector b(B);
    b.set(20, 3);
    std::cout << "b: " << std::endl;
    std::cout << b << std::endl;

    //Creates vector d;
    Vector d(3);
    std::cout << "d: " << std::endl;
    std::cout << d << std::endl;

    double dot_product = d.dot(b);
    std::cout << "d * b = " << dot_product << std::endl;
    dot_product = d.dot(a);
    std::cout << "d * a = " << dot_product << std::endl;

    d.fill(5);
    std::cout << "d: " << std::endl;
    std::cout << d << std::endl;
    Matrix product = A * d;

    std::cout << "A.d = " << std::endl;
    std::cout << product << std::endl;
}

void testImageStuff() {
    Image test(250, 250);
    Color col(193,84,193);
    test.fill(col);

    Line line(Point(30,30), Point(70, 30), Color(200,200,200));
    Rectangle rect(Point(10,10), Point(50,50), Color(255, 0, 0));
    Circle circ(Point(30, 60), 10, Color(0, 255, 0));
    Circle circ_2(Point(70,60), 10, Color(0,255,0));
    Circle circ_3(Point(50,50), 50, Color(255,0,0));

    Canvas canvas;
    canvas.addShape(&line);
    canvas.addShape(&rect);
    canvas.addShape(&circ);
    canvas.addShape(&circ_2);
    canvas.addShape(&circ_3);
    canvas.rasterizeTo(test);
    saveImage(test, "test.bmp");
}


int main() {
    testVectors();
    testImageStuff();
    return 0;
}
