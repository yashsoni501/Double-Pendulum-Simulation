
#include<iostream>
#include<opencv2/opencv.hpp>

#define PI 3.141592653589793

using namespace std;
using namespace cv;

double theta1 = 0;
double theta2 = 0;

double g = 9.8;
double m1 = 1;
double m2 = 1;
double l1 = 1;
double l2 = 1;

double h = 0.025;

double omega1 = 0;
double omega2 = 0;

double f1(double t1, double t2, double w1, double w2)
{
    return w1;
}

double f2(double t1, double t2, double w1, double w2)
{
    return w2;
}

double f3(double t1, double t2, double w1, double w2)
{
    return (-g*(2*m1+m2)*sin(t1)-m2*g*sin(t1-2*t2)-2*sin(t1-t2)*m2*(w2*w2*l2+w1*w1*l1*cos(t1-t2)))/(l1*(2*m1+m2-m2*cos(2*t1-2*t2)));
}

double f4(double t1, double t2, double w1, double w2)
{
    return (2*sin(t1-t2)*(w1*w1*l1*(m1+m2)+g*(m1+m2)*cos(t1)+w2*w2*l2*m2*cos(t1-t2)))/(l2*(2*m1+m2-m2*cos(2*t1-2*t2)));
}

void runge_kutta_step()
{
    double k[4][4];
    
    double (*func_ptr[])(double, double, double, double) = {f1, f2, f3, f4};

    double coeff[] = {0, 0.5, 0.5, 1};
    
    for(int i=0;i<4;i++)
    {
        k[0][i] = h*func_ptr[i](theta1, theta2, omega1, omega2);
    }

    for(int i=1;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            k[i][j] = h*func_ptr[j](theta1 + coeff[i]*k[i-1][0], theta2 + coeff[i]*k[i-1][1], omega1 + coeff[i]*k[i-1][2], omega2 + coeff[i]*k[i-1][3]);
        }
    }

    theta1 = theta1 + (k[0][0]+2*k[1][0]+2*k[2][0]+k[3][0])/6;
    theta2 = theta2 + (k[0][1]+2*k[1][1]+2*k[2][1]+k[3][1])/6;
    omega1 = omega1 + (k[0][2]+2*k[1][2]+2*k[2][2]+k[3][2])/6;
    omega2 = omega2 + (k[0][3]+2*k[1][3]+2*k[2][3]+k[3][3])/6;
}

void plot()
{
    Mat img(500, 500, CV_8UC3, Scalar(0,0,0));
    namedWindow("simulation", 1);

    line(img, Point(0, 200), Point(499, 200), Scalar(255, 255, 255), 3);

    Point mid = {249, 200};
    Point rope1 = {mid.x + l1*100*sin(theta1), mid.y + l1*100*cos(theta1)};
    Point rope2 = {rope1.x + l2*100*sin(theta2), rope1.y + l2*100*cos(theta2)};
    
    line(img, mid, rope1, Scalar(0, 255, 0), 2);
    line(img, rope1, rope2, Scalar(0, 255, 0), 2);

    circle(img, rope1, min(15.0, m1*5), Scalar(0,0,255), -1);
    circle(img, rope2, min(15.0, m2*5), Scalar(0,0,255), -1);

    imshow("simulation", img);
}

int main()
{
    theta1 = PI/2;
    theta2 = PI/4;

    m1 = 1;
    m2 = 1;
    l1 = 1;
    l2 = 1;

    plot();
    waitKey(0);
    
    while(1)
    {
        runge_kutta_step();

        plot();
        waitKey(int(1000*h));
    }
}