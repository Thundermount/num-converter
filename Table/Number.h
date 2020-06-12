#pragma once
#include <iostream>
#include <bitset>
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace System;
ref class Number
{
public:
	Number(int n);
	Number(String^ s, bool hex);
	void DectoBinary();
	void DectoOct();
	void DectoHex();
	void BinarytoDec();
	void OcttoDec();
	void HextoDec();
	String^ GetNumber();
private:
	int n;
	String^ s;
};

