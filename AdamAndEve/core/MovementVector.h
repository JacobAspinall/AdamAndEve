#pragma once
class MovementVector
{
public:
	MovementVector();
	MovementVector(double x, double y) : x{ x }, y{ y } {};
	~MovementVector();

	double x = 0;
	double y = 0;
};

