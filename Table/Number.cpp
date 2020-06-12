#include "Number.h"



Number::Number(int n)
{
	this->n = n;
}
Number::Number(String^ s, bool hex)
{
	if (hex) this->s = s;
	else {
		this->n = Convert::ToInt32(s);
	}
}

void Number::DectoBinary() {
	int n = this->n;
	this->n = Convert::ToInt32(gcnew String(std::bitset<8>(n).to_string().c_str()));
}
void Number::DectoOct() {
	int decimalNum = this->n;
	int octalNum = 0, placeValue = 1;
	while (decimalNum != 0) {
		octalNum += (decimalNum % 8) * placeValue;
		decimalNum /= 8;
		placeValue *= 10;
	}
	this->n = octalNum;
}
void Number::DectoHex() {
	char buffer[33];
	itoa(this->n, buffer, 16);
	this->s = gcnew String(buffer);
	this->n = NULL;
}
void Number::BinarytoDec() {
	long bin, dec = 0, rem, num, base = 1;
	num = this->n;
	bin = num;
	while (num > 0)
	{
		rem = num % 10;
		dec = dec + rem * base;
		base = base * 2;
		num = num / 10;
	}
	this->n = dec;
}
void Number::OcttoDec() {
	String^ s = this->s;
	int res = 0;
	for (int i = 0; i < s->Length; ++i) {
		res *= 8;
		res += (s[i] - '0');
	}
	this->n = res;
	this->s = "";
}
void Number::HextoDec() {
	String^ num = this->s;
	int len = num->Length;
	int base = 1;
	int temp = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (num[i] >= '0' && num[i] <= '9') {
			temp += (num[i] - 48)*base;
			base = base * 16;
		}
		else if (num[i] >= 'A' && num[i] <= 'F') {
			temp += (num[i] - 55)*base;
			base = base * 16;
		}
	}
	this->n = temp;
	this->s = "";
}
String^ Number::GetNumber() {
	if (this->n != NULL) return this->n.ToString();
	else return this->s;
}
