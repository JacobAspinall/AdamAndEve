#pragma once
class Subject;

class Observer
{
public:
	Observer() {};
	virtual ~Observer() {};
	virtual void update(Subject& subject) {};
};

