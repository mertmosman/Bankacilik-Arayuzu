#include <iostream>
#include <list>
#include "banka.h"
using namespace std;

void menuGosterici()
{
	cout << "* * * * * * * * *" << endl <<
		"* Hosgeldiniz!  *" << endl <<
		"* * * * * * * * *" << endl;
	cout << "1.Musteri Ekle" << endl << "2.Hesaba Para Aktar" << endl << "3.Hesaptan Para Cek" << endl << "4.Musteri Bilgisi Goster" << endl << "5.Tum Musterileri Goster" << endl<<"6.Sistemden Cik"<<endl;
}

void musteriEkle(list<banka>*kisi)
{
	string adi, soyadi, isim;
	cout << "Musteri Adini Giriniz: ";
	cin >> adi >> soyadi;
	isim = adi +" "+ soyadi;
	cout << "\nMusterinin Hesap Numarasini Giriniz: ";
	int no;
	cin >> no;
	cout << "\nBaslangic Para Miktarini Giriniz: ";
	float bakiye = 0;
	cin >> bakiye;
	banka kullanici(isim, no, bakiye);
	kisi->push_back(kullanici);// Kullanici objectini kisi listesine ekler.
	cout << endl;
}

void paraAktar(list<banka>* kisi)
{
	list<banka>::iterator itr;// Iterator atadik.
	cout << "Islem yapmak istediginiz musterinin no'sunu girin: ";
	int hesapNum;
	cin >> hesapNum;
	cout << "\nEklemek istediginiz para miktarini girin: ";
	float para;
	cin >> para;
	for (itr = kisi->begin(); itr != kisi->end(); itr++)// Iteratorla for dongusu boyle yapýlýr.
	{
		if (itr->getHesapNo() == hesapNum)
		{
			itr->setBakiye(itr->getBakiye()+para);//set burada degistirmek, get ise baslangic degerine ulasmak icin kullanildi.
		}
		else
		{
			cout << "Gecersiz bilgi. Tekrar deneyiniz. " << endl;
			continue;
		}
	}
	cout << endl;
}

void paraCek(list<banka>* kisi)
{
	list<banka>::iterator itr;
	cout << "Islem yapmak istediginiz musterinin no'sunu girin: ";
	int hesapNum;
	cin >> hesapNum;
	cout << "\nCekmek istediginiz para miktarini girin: ";
	float para;
	cin >> para;
	for (itr = kisi->begin(); itr != kisi->end(); itr++)
	{
		if (itr->getHesapNo() == hesapNum)
		{
			if ((itr->getBakiye() - para) < 0)
			{
				cout << "Yetersiz Bakiye." << endl;
				continue;
			}
			else
			{
				itr->setBakiye((itr->getBakiye() - para));
			}
		}
	}
	cout << endl;
}

void musteriBilgisi(list<banka>* kisi)
{
	list<banka>::iterator itr;
	cout << "Bilgilerini gormek istediginiz musterinin hesap numarasini girin: ";
	int hesapNo;
	cin >> hesapNo;
	for (itr = kisi->begin(); itr != kisi->end(); itr++)
	{
		if (itr->getHesapNo() == hesapNo)
		{
			itr->musterininBilgisi();
		}
		else
		{
			cout << "Gecersiz bilgi. Tekrar deneyiniz. " << endl;
			continue;
		}
	}
	cout << endl;
}

void musteriListele(list<banka>*kisi)
{
	list<banka>::iterator itr;
	for (itr = kisi->begin(); itr != kisi->end(); itr++)
	{
		itr->musterininBilgisi();
	}
}

int main()
{
	list<banka>* musteri = new list<banka>;
	int sayi = 0;
	do 
	{
		menuGosterici();
		cin >> sayi;
		cout << endl;
		if (sayi == 1)
		{
			musteriEkle(musteri);
		}
		else if (sayi == 2)
		{
			paraAktar(musteri);
		}
		else if (sayi == 3)
		{
			paraCek(musteri);
		}
		else if (sayi == 4)
		{
			musteriBilgisi(musteri);
		}
		else if (sayi == 5)
		{
			musteriListele(musteri);
		}
		else if (sayi == 6)
		{
			cout << "Goodbye..!" << endl;
			return 0;
		}
		else
		{
			cout << "Hatali islem. Sisteme yeniden giriniz." << endl;
			continue;
		}
	} while (sayi != 6);
}