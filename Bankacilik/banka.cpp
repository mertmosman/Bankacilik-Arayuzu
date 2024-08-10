#include <iostream>
#include "banka.h"

banka::banka(string _musteriAdi,int _hesapNo,float _bakiye)
{
	musteriAdi = _musteriAdi;
	hesapNo = _hesapNo;
	bakiye = _bakiye;
}

void banka::musterininBilgisi()
{
	cout << "\nMusterinin Adi: " << musteriAdi << endl << "Musteri Hesap No: " << hesapNo<<endl << "Toplam Bakiye: " << bakiye << endl;
}

string banka::getMusteriAdi()
{
	return musteriAdi;
}

int banka::getHesapNo()
{
	return hesapNo;
}

float banka::getBakiye()
{
	return bakiye;
}

void banka::setMusteriAdi(string _musteriAdi)
{
	musteriAdi = _musteriAdi;
}

void banka::setHesapNo(int _hesapNo)
{
	hesapNo = _hesapNo;
}

void banka::setBakiye(float _bakiye)
{
	bakiye = _bakiye;
}