#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp; // proportional part
	this->Ki = Ki; //integral part
	this->Kd = Kd; //differential part

	this->p_error = 0.0;
	this->i_error = 0.0;
	this->d_error = 0.0;
	this->all_square_error = 0.0;
	this->num = 1;
}

void PID::UpdateError(double cte) {
	all_square_error = all_square_error / num;
	num++;

	this->d_error = cte - this->p_error;
	this->p_error = cte;
	this->i_error += cte;
}

double PID::TotalError() {
	result = 0;

	result = this->Kp*this->p_error + this->Ki*this->i_error + this->Kd*this->d_error;
	return result;
}

