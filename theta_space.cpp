#include "runge_kutta_solver_class.hpp"
#include <iostream>
#include<opencv2/opencv.hpp>

int main()
{
    namedWindow("colorSpace", 0);

    int row=250;
    int col=250;
    Mat space(row, col, CV_8UC3, Scalar(0,0,0));

    simulation * arr[row][col];

    double theta1 = -PI;
    double theta2 = -PI;

    for(int i=0;i<row;i++)
    {
        theta1 = -PI;
        for(int j=0;j<col;j++)
        {
            arr[i][j] = new simulation(theta1, theta2, 1,1,1,1,0.05);
            theta1 += 2*PI/col; 
        }
        theta2 += 2*PI/row;
    }

    pair<double, double> theta;
    // theta = arr[row/2][col/2]->get_thetas();
    // cout<<theta.first<<" "<<theta.second<<endl;
    for(int t=0;t>-1;t++)
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                arr[i][j]->perform_runge_kutta_step();
                theta = arr[i][j]->get_thetas();
                space.at<Vec3b>(Point(i,j)) = {(theta.first+PI)/2/PI*255, (theta.second+PI)/2/PI*255, 0};
            }
        }

        imshow("colorSpace", space);
        waitKey(10);
    }
}