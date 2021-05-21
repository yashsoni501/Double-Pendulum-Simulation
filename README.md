# Double Pendulum Simulation
Creating a simulation of double pendulum and analysing its behavior for various initial conditions

**Motivation:** https://www.youtube.com/watch?v=n7JK4Ht8k8M&t=148s

**Differential Equations Link:** https://www.myphysicslab.com/pendulum/double-pendulum-en.html

$θ_1' = ω_1$

$θ_2' = ω_2$

$ω_1' = \frac{−g (2 m_1 + m_2) sin θ_1 − m_2 g sin(θ_1 − 2 θ_2) − 2 sin(θ_1 − θ_2) m_2 (ω_2^2 L_2 + ω_1^2 L_1 cos(θ_1 − θ_2))} {L_1 (2 m_1 + m_2 − m_2 cos(2 θ_1 − 2 θ_2))}$

$ω_2' = \frac{2 sin(θ_1−θ_2) (ω_1^2 L_1 (m_1 + m_2) + g(m_1 + m_2) cos θ_1 + ω_2^2 L_2 m_2 cos(θ_1 − θ_2))}{L_2 (2 m_1 + m_2 − m_2 cos(2 θ_1 − 2 θ_2))}$



**Requirements:** OpenCV(C++), CUDA

**Files Description**
* runge_kutta_solver.cpp - simulates a double pendulum with given parameters.
    * Parameters that can be modified - theta1, theta2, m1, m2, l1, l2, h

* runge_kutta_solver_class.hpp - simulator writted in form of class
    * Parameters - theta1, theta2, m1, m2, l1, l2, h

* theta_space - creates a 2D-space for values of theta1 and theta2
    * Parametes - row and col of the mat

**For compiling any file:**  ```make <file_name>```
 
TODO: integration with CUDA