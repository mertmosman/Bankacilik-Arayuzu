#pragma once
#include <iostream>
using namespace std;
class banka
{
public:
	banka(string _musteriAdi, int _hesapNo, float _bakiye);// Burada Destructor cagirdik.
	void musterininBilgisi();

	string getMusteriAdi();// Objectin ozelligini RETURN etmek ve (string or integer) olarak kullanmak icin get fonku kullanilir.
	int getHesapNo();
	float getBakiye();

	void setMusteriAdi(string _musteriAdi);// Objectin ozelligini degistirmek icin set fonkunu kullaniyoruz.
	void setHesapNo(int _hesapNo);
	void setBakiye(float _bakiye);
private:
	string musteriAdi;
	int hesapNo;
	float bakiye;
};