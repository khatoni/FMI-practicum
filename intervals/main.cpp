#include<iostream>
#include"Interval.h"
Interval::Interval(int first,int second) {
	if (first > second) {
		Interval();
	}
	else {
		first_number = first;
		second_number = second;
	}
}
size_t Interval::length() {
	return second_number - first_number;
}
bool Interval::isInInterval(const int number) {
	return number >= first_number && number <= second_number;
}

bool primenumber(const int a) {
	bool flag = 1;
	for (int i = 2; i <= a / 2; i++) {
		if (a % i == 0) {
			flag = 0;
		}
	}
	return flag;
}
size_t Interval::primeNumbers() {
	size_t counter = 0;
	for (int i = first_number; i <= second_number; i++) {
		if (primenumber(i)) {
			counter++;
		}
	}
	return counter;
}
bool isPalindrome( int a) {
	int b = 0;
	if (a < 10) {
		return true;
	}
	else {
		while (a != 0) {
			b = b * 10 + a % 10;
			a /= 10;
		}
	}
	return b == a;
}
size_t Interval::palindromeNumbers() {
	size_t counter = 0;
	for (int i = first_number; i <= second_number; i++) {
		if (isPalindrome(i)) {
			counter++;
		}
	}
	return counter;
}
bool sameDigits(int a) {
	if (a < 10) {
		return 0;
	}
	else {
		while (a != 0) {
			int num = a % 10;
			a = a / 10;
			if (a % 10 == num) {
				return 1;
				break;
			}
		}
	}
}
size_t Interval::noSameDigits() {
	size_t counter=0;
	for (int i = first_number; i <= second_number; i++) {
		if (sameDigits(i) == 0) {
			counter++;
		}
	}
	return counter;
}
bool power(int a) {
	if (a % 2 != 0) {
		return false;
	}
	else if (a == 1) {
		return true;
	}
	else {
		while (a %2==0) {
			a = a / 2;
		}
		if (a == 1) {
			return true;
		}
		else {
			return false;
		}
	}
}
bool Interval::power2() {
	return power(first_number) && power(second_number);
}
Interval Interval::intersection(const Interval& other) {
	Interval tmp;
	if (this->first_number <= other.first_number) {
		tmp.first_number = other.first_number;
	}
	else {
		tmp.first_number = this->first_number;
	}
	if (this->second_number <= other.second_number) {
		tmp.second_number = this->second_number;

	}
	else {
		tmp.second_number = other.second_number;
	}
	return tmp;
}
bool Interval::subInterval(const Interval& other) {
	return this->first_number <= other.first_number && this->second_number >= other.second_number;
}
void Interval::print() {
	std::cout << this->first_number << " " << this->second_number;
}
int main() {
	Interval t1(3, 16); // [3, 10]
	Interval t2(4, 16); // [4, 14]
	Interval t3; // [0, 0]
	t3 = t1.intersection(t2);
	std::cout << t3.power2();
	std::cout << t2.subInterval(t1);
	return 0;
}