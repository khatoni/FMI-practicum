#pragma once
class Interval {
private:
	int first_number;
	int second_number;
public:
	Interval()=default;
	Interval(const int , const int );
	~Interval() = default;
	size_t length();
	bool isInInterval(const int);
	size_t primeNumbers();
	size_t palindromeNumbers();
	size_t noSameDigits();
	bool power2();
	Interval intersection(const Interval&);
	bool subInterval(const Interval&);
	void print();
};