#include <iostream>

using namespace std;



struct Islem
{
	int giris[5][5] = { 3,2,5,1,4,
						6,2,1,0,7,
						3,0,0,2,0,
						1,1,3,2,2,
						0,3,1,0,0 };

	int cekirdekMatrisi[100][100];
	int sonucMatrisi[100][100];
	int cekirdekBoyut;
	int sonucBoyut;
	int kaymaMiktari;

};

Islem hesapla;
int girisBoyut;

void hesaplamaKontrolu()
{
	int hesaplamaKontrol = 1, matrisKontrol, kaymaKontrol, cekirdekKontrol;

	// matrislerin hesaplanabilir olup olmadigini kontrol etmek icin bir donguye giriyoruz.
	while (hesaplamaKontrol)
	{
		cout << "Cekirdek matrisinin boyutunu giriniz : ";
		cin >> hesapla.cekirdekBoyut;

		// cekirdek matrisinin boyutunun dogru tanimlanip tanimlanmadigini kontrol etmek icin donguye giriyoruz.
		cekirdekKontrol = 1;
		while (cekirdekKontrol)
		{
			if (hesapla.cekirdekBoyut >= girisBoyut)
			{
				cout << " Cekirdek boyutu giris matrisinin boyutuyla esit veya buyuk olamaz ! Yeni cekirdek boyutu girin : ";
				cin >> hesapla.cekirdekBoyut;
			}
			else {
				cekirdekKontrol = 0;
			}
		}

		cout << " Kayma miktarini giriniz : ";
		cin >> hesapla.kaymaMiktari;

		// kayma miktarinin 0 olup olmadigini kontrol etmek icin bir donguye giriyoruz.
		kaymaKontrol = 1;
		while (kaymaKontrol)
		{
			if (hesapla.kaymaMiktari == 0)
			{
				cout << " Kayma miktari 0 olamaz ! Yeni kayma degeri girin : ";
				cin >> hesapla.kaymaMiktari;
			}
			else {
				kaymaKontrol = 0;
			}
		}

		// matrislerin hesaplanabilir oldugunu anlamak icin bu formulu kullandim.
		matrisKontrol = (girisBoyut - hesapla.cekirdekBoyut) % hesapla.kaymaMiktari;

		// giris matrisiyle kayma miktarinin farkinin cekirdek boyutuna esit oldugu durumlar haric 
		// yukaridaki formul 0 cikiyorsa matrisi islemimizde kullanabiliriz. burada onu sorguluyorum.
		if (matrisKontrol != 0 || (girisBoyut - hesapla.kaymaMiktari) == hesapla.cekirdekBoyut)
		{
			cout << " Bu islem hesaplanamaz. Lutfen yeni degerler giriniz." << endl;
		}
		else
		{
			hesapla.sonucBoyut = ((girisBoyut - hesapla.cekirdekBoyut) / hesapla.kaymaMiktari) + 1;
			hesaplamaKontrol = 0;
		}
	}
}
void matrisleriDoldur() {

	// cekirdek matrisinin elemanlarýný kullanicadan istiyorum.
	for (int i = 0; i < hesapla.cekirdekBoyut; i++)
	{
		for (int j = 0; j < hesapla.cekirdekBoyut; j++)
		{
			cout << "Cekirdek[" << i << "][" << j << "] = ";
			cin >> hesapla.cekirdekMatrisi[i][j];
		}
	}

	// simdilik sonuc matrisinin icine tum degerleri icin 0 atiyorum.
	for (int i = 0; i < hesapla.sonucBoyut; i++)
	{
		for (int j = 0; j < hesapla.sonucBoyut; j++)
		{
			hesapla.sonucMatrisi[i][j] = 0;
		}
	}
}
void hesaplama() {

	// bu dongude x sonuc matrisinin satirini kontrol ederken m degeri satirda kaydirma miktarini kontrol ediyor.
	for (int x = 0, m = 0; x < hesapla.sonucBoyut; x++, m += hesapla.kaymaMiktari)
	{
		//bu dongude y sonuc matrisinin sutununu kontrol ederken n degeri sutunda kaydirma miktarini kontrol ediyor.
		for (int y = 0, n = 0; y < hesapla.sonucBoyut; y++, n += hesapla.kaymaMiktari)
		{
			// bu dongude cekirdek matrisiyle giris matrisini ust uste getirip karsilik gelen elemanlari carpiyoruz.
			// carpilan tum degerler sonuc matrisinin xy indisli elemanýnýn icinde toplam þeklinde yaziliyor.
			for (int i = 0; i < hesapla.cekirdekBoyut; i++)
			{
				for (int j = 0; j < hesapla.cekirdekBoyut; j++)
				{
					hesapla.sonucMatrisi[x][y] += hesapla.giris[i + m][j + n] * hesapla.cekirdekMatrisi[i][j];
				}
			}
		}
	}
}
void sonucMatrisiniYazdir() {

	// sonuc matrisini ekrana yazdirmak icin bu donguye giriyoruz.
	cout << endl << "  Sonuc Matrisi" << endl;
	for (int i = 0; i < hesapla.sonucBoyut; i++)
	{
		for (int j = 0; j < hesapla.sonucBoyut; j++)
		{
			cout << "  " << hesapla.sonucMatrisi[i][j] << "  ";
		}
		cout << endl;
	}
}

int main()
{
	//giris matrisinin boyutunu belirlemek icin dizinin ilk sirasinin hafizadaki boyutunu alip 4e boluyorum.
	girisBoyut = sizeof(hesapla.giris[0]) / 4;
	

	// kullanacagimiz matrislerin uygun olup olmadigini anlamak icin bu fonksiyonu cagiriyorum.
	hesaplamaKontrolu();
	// matrislerin icini doldurmak icin bu fonksiyonu cagiriyorum.
	matrisleriDoldur();
	//sonuc matrisini olusturmak icin bu fonksiyonu cagiriyorum.
	hesaplama();
	//hesaplama sonucunda olusan sonuc matrisini yazdirmak icin bu fonksiyonu cagiriyorum.
	sonucMatrisiniYazdir();

	system("pause");
}
