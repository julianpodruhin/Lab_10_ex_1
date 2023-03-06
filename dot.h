#ifndef DOT_H_
#define DOT_H_

class Dot
{
private:
	double x;
	double y;
public:
	Dot();
	Dot(double x, double y);
	double distanceTo(Dot point) const;
};

#endif