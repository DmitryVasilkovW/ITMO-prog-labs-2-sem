#ifndef UNTITLED5_LAB4_H
#define UNTITLED5_LAB4_H
#include <string>

class IGeoFig
{
public:

virtual void square() = 0;

virtual void perimeter() = 0;
};

class CVector2D
{
public:
	double x;
	double y;
};

class IPrintable
{
public:

virtual void draw() = 0;
};

class IDialogInitiable
{
public:
virtual void initFromDialog() = 0;
};

class BaseCObject
{
public:

virtual void classname() = 0;

virtual unsigned int size() = 0;
};

class Rectangle : public IGeoFig,  private IPrintable, public IDialogInitiable, BaseCObject
{
private:
	int size_;
	std::string name_;
public:
	CVector2D point;
	double side_a;
	double side_b;

	Rectangle();

	void perimeter() override;

	void square() override;

	void draw() override;

	void initFromDialog() override;

	void classname() override;

	unsigned int size() override;

	~Rectangle() = default;
};

class Parallelogram : public IGeoFig, private IPrintable, public IDialogInitiable, BaseCObject
{
private:
	int size_;
	std::string name_;
public:
	CVector2D point;
	double side_a;
	double side_b;
	double height;

	Parallelogram();

	void perimeter() override;

	void square() override;

	void draw() override;

	void initFromDialog() override;

	void classname() override;

	unsigned int size() override;

	~Parallelogram() = default;
};

#endif
