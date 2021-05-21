# Double Pendulum Simulation
Creating a simulation of double pendulum and analysing its behavior for various initial conditions

**Motivation:** https://www.youtube.com/watch?v=n7JK4Ht8k8M&t=148s

**Differential Equations Link:** https://www.myphysicslab.com/pendulum/double-pendulum-en.html

![image](https://user-images.githubusercontent.com/22321159/119180006-4b374300-ba8d-11eb-9fd7-1cea622215db.png)

**Differential Equation Solver:** 4th order Runge-Kutta Method

**Requirements:** OpenCV(C++), CUDA

**Files Description**
* runge_kutta_solver.cpp - simulates a double pendulum with given parameters.
    * Parameters that can be modified - theta1, theta2, m1, m2, l1, l2, h

* runge_kutta_solver_class.hpp - simulator writted in form of class
    * Parameters - theta1, theta2, m1, m2, l1, l2, h

* theta_space - creates a 2D-space for values of theta1 and theta2
    * Parameters - row and col of the mat

**For compiling any file:**  ```make <file_name>```
 
TODO: integration with CUDA
