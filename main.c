#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
typedef struct{
char Ad[50];
char Soyad[50];
int KimlikNo;
int telefon;
char adres[50];
int CekilenTutar;
int Bakiye;
int YatirilanMiktar;
int MusteriNo;
int HesapNo;
int HesapNo2;
int HavaleyleGidenPara;
int YatirilanToplamPara;
int CekilenToplamPara;
int HesaptanCekilenToplamPara;
int HesabaYatirilanToplamPara;
int HesaptanHavaleYapilanMiktar;
int HesabaHavaleYapilanMiktar;
int HesaptanHavaleYapanKisininHesapNumarasi;
int HesabaHavaleYapanKisininHesapNumarasi;
time_t t;
}Musteri;

typedef struct {
    Musteri bmusteri;
    Musteri tmusteri;
}MusteriBT;

typedef struct{
    MusteriBT MS[100];
    int MSayisi;
}BankaOtomasyonu;

BankaOtomasyonu BO = {0};

void AnaMenu();
void Islem();
void BireyselMusteriEkleme();
void TicariMusteriEkleme();
void BaskaTicariHesapAcma();
void BaskaBireyselHesapAcma();
void TicariParaCekme();
void BireyselParaCekme();
void TicariParaYatirma();
void BireyselParaYatirma();
void TicariHavaleYapma();
void BireyselHavaleYapma();
void GelirGiderRaporu();
void TicariHesapOzeti();
void BireyselHesapOzeti();
void TicariHesapKapatma();
void BireyselHesapKapatma();

void AnaMenu(){
    int c,d;
    printf("\tMENU\n");
    printf("1.Yeni Musteri Ekleme\n");
    printf("2.Hesap Actirma\n");
    printf("3.Para Cekme\n");
    printf("4.Para Yatirma\n");
    printf("5.Hesaba Havale\n");
    printf("6.Banka Gelir-Gider Raporu\n");
    printf("7.Hesap Ozeti\n");
    printf("8.Hesap Kapama\n");
    printf("9.CIKIS\n");
    Islem();
    for(d=0;d<99;d++){
    printf("Devam etmek istiyorsaniz 1e istemiyorsaniz 2ye basiniz:");
    scanf("%d",&c);
        if(c==1)
        {
            printf("\tMENU\n");
            printf("1.Yeni Musteri Ekleme\n");
            printf("2.Hesap Actirma\n");
            printf("3.Para Cekme\n");
            printf("4.Para Yatirma\n");
            printf("5.Hesaba Havale\n");
            printf("6.Banka Gelir-Gider Raporu\n");
            printf("7.Hesap Ozeti\n");
            printf("8.Hesap Kapama\n");
            printf("9.CIKIS\n");
            Islem();
        }
        else
            break;
    }
}

void Islem(){
    int a,b,f,g,j,m;
     printf("Yapmak istediginiz islemi giriniz:\n");
     scanf("%d",&a);
     switch(a){
     case 1:
         printf("Ticari musteriyseniz 1 e , bireysel musteriyseniz 2 ye basiniz:");
         scanf("%d",&b);
        if(b==1)
        {
            TicariMusteriEkleme();
        }
        else{
            BireyselMusteriEkleme();
        }


        break;
    case 2:
        printf("Ticari musteriyseniz 1 e , bireysel musteriyseniz 2 ye basiniz:");
         scanf("%d",&f);
        if(f==1)
        {
            BaskaTicariHesapAcma();
        }
        else{
            BaskaBireyselHesapAcma();
        }
        break;
    case 3:
        printf("PARA CEKME....\n");
        printf("Ticari musteriyseniz 1 e , bireysel musteriyseniz 2 ye basiniz:");
        scanf("%d",&g);
        if(g==1)
            TicariParaCekme();
        else
            BireyselParaCekme();
        break;
    case 4:
        printf("PARA YATIRMA.....\n");
        printf("Ticari musteriyseniz 1 e , bireysel musteriyseniz 2 ye basiniz:");
        scanf("%d",&j);
        if(j==1)
            TicariParaYatirma();
        else
            BireyselParaYatirma();
        break;
    case 5:
        printf("HAVALE YAPMA.....\n");
        printf("Ticari musteriyseniz 1 e , bireysel musteriyseniz 2 ye basiniz:");
        scanf("%d",&m);
        if(m==1)
            TicariHavaleYapma();
        else
            BireyselHavaleYapma();
        break;
    case 6:
            GelirGiderRaporu();
        break;
    case 7:
        printf("Ticari musteriyseniz 1 e , bireysel musteriyseniz 2 ye basiniz:");
        scanf("%d",&m);
        if(m==1)
            TicariHesapOzeti();
        else
            BireyselHesapOzeti();
        break;
    case 8:
         printf("Ticari musteriyseniz 1 e , bireysel musteriyseniz 2 ye basiniz:");
        scanf("%d",&m);
        if(m==1)
            TicariHesapKapatma();
        else
            BireyselHesapKapatma();
        break;
    case 9:

        break;
    default:
        printf("HATALI ISLEM YAPTINIZ TEKRAR GIRINIZ!");
        AnaMenu();
        break;
     }
}

void BireyselMusteriEkleme(){
  MusteriBT TB;
    MusteriBT *zaman_bilgisi;

       printf("Bireysel musteri bilgilerini giriniz....\n");

       printf("Ad:");
       scanf("%s",TB.bmusteri.Ad);

       printf("Soyad:");
       scanf("%s",TB.bmusteri.Soyad);

       printf("Kimlik No:");
       scanf("%d",&TB.bmusteri.KimlikNo);

       printf("Telefon:");
       scanf("%d",&TB.bmusteri.telefon);

       printf("Adres:");
       scanf("%s",TB.bmusteri.adres);

      TB.bmusteri.Bakiye=0;
       srand(time(NULL));
       TB.bmusteri.MusteriNo=rand();
       printf("Musteri No:%d\n",TB.bmusteri.MusteriNo);


       srand(time(NULL));
       TB.bmusteri.HesapNo=rand();
       printf("Hesap No:%d\n",TB.bmusteri.HesapNo);
       printf("Bakiye:%d",TB.bmusteri.Bakiye);
       TB.bmusteri.t=time(NULL);
       zaman_bilgisi=localtime(&TB.bmusteri.t);
       printf("Islemin yapildigi tarih ve saat:%s",asctime(zaman_bilgisi));
       FILE *pt;
       pt=fopen("BireyselMusteriDosya.txt","a+");
       if(pt==NULL)
       {
           printf("Dosya acilamadi!\n");
           exit(1);
       }

       fprintf(pt,"%s",TB.bmusteri.Ad);
       fprintf(pt,"%s",TB.bmusteri.Soyad);
       fprintf(pt,"%d",TB.bmusteri.KimlikNo);
       fprintf(pt,"%d",TB.bmusteri.telefon);
       fprintf(pt,"%s",TB.bmusteri.adres);
       fprintf(pt,"%d",TB.bmusteri.MusteriNo);
       fprintf(pt,"%d",TB.bmusteri.HesapNo);
       fprintf(pt,"%d",TB.bmusteri.Bakiye);
       fprintf(pt,"%s",asctime(zaman_bilgisi));
       fclose(pt);

       BO.MS[BO.MSayisi] = TB;
       BO.MSayisi ++;
}

void TicariMusteriEkleme(){
       MusteriBT BT;
       Musteri *zaman_bilgisi;
       BT.tmusteri.t=time(NULL);
       printf("Ticari musteri bilgilerini giriniz....\n");
       printf("Ad:");
       scanf("%s", BT.tmusteri.Ad);
       printf("Soyad:");
       scanf("%s", BT.tmusteri.Soyad);
       printf("Kimlik No:");
       scanf("%d",&BT.tmusteri.KimlikNo);
       printf("Telefon:");
       scanf("%d",&BT.tmusteri.telefon);
       printf("Adres:");
       scanf("%s",BT.tmusteri.adres);
       BT.tmusteri.Bakiye=0;


       srand(time(NULL));
       BT.tmusteri.MusteriNo=rand();
       printf("Musteri No:%d\n",BT.tmusteri.MusteriNo);


       srand(time(NULL));
       BT.tmusteri.HesapNo=rand();
       printf("Hesap No:%d\n",BT.tmusteri.HesapNo);
       printf("Bakiye:%d\n",BT.tmusteri.Bakiye);
       zaman_bilgisi=localtime(&BT.tmusteri.t);
       printf("Islenlerin yapildigi tarih ve saat:%s\n",asctime(zaman_bilgisi));
       FILE *pt;
       pt=fopen("TicariMusteriDosya.txt","a+");
       if(pt==NULL)
       {
           printf("Dosya acilamadi!\n");
           exit(1);
       }

       fprintf(pt,"%s  ",BT.tmusteri.Ad);
       fprintf(pt,"%s  ",BT.tmusteri.Soyad);
       fprintf(pt,"%d  ",BT.tmusteri.KimlikNo);
       fprintf(pt,"%d  ",BT.tmusteri.telefon);
       fprintf(pt,"%s  ",BT.tmusteri.adres);
       fprintf(pt,"%d  ",BT.tmusteri.MusteriNo);
       fprintf(pt,"%d  ",BT.tmusteri.HesapNo);
       fprintf(pt,"%d  ",BT.tmusteri.Bakiye);
       fprintf(pt,"%s  ",asctime(zaman_bilgisi));
       fclose(pt);

       BO.MS[BO.MSayisi] = BT;
       BO.MSayisi ++;
}

void BaskaTicariHesapAcma(){
    MusteriBT TB;
    Musteri *zaman_bilgisi;

    printf("HESAP ACTIRMA......\n");
    printf("Yeni hesap acmak istediginiz musteri numarasini giriniz:");
    scanf("%d",&TB.tmusteri.MusteriNo);


    srand(time(NULL));
    TB.tmusteri.HesapNo2=rand();
    if(TB.tmusteri.HesapNo2!=TB.tmusteri.HesapNo)
        printf("Yeni acilan hesabinizin numarasi:%d",TB.tmusteri.HesapNo2);
    else {
        TB.tmusteri.HesapNo2==0;
        BaskaTicariHesapAcma();
        TB.tmusteri.t=time(NULL);
    zaman_bilgisi=localtime(&TB.tmusteri.t);
    printf("Islemin yapildigi tarih ve saat:%s",asctime(zaman_bilgisi));
    }
     FILE *pt;
       pt=fopen("TicariMusteriDosya.txt","a+");
       if(pt==NULL)
       {
           printf("Dosya acilamadi!\n");
           exit(1);
       }

       fprintf(pt,"%d  ",TB.tmusteri.HesapNo2);
       fprintf(pt,"%s  ",asctime(zaman_bilgisi));
       fclose(pt);
}

void BaskaBireyselHesapAcma(){
    MusteriBT BT;
    Musteri *zaman_bilgisi;
    printf("HESAP ACTIRMA......\n");
    printf("Yeni hesap acmak istediginiz musteri numarasini giriniz:");
    scanf("%d",&BT.bmusteri.MusteriNo);


    srand(time(NULL));
    BT.bmusteri.HesapNo2=rand();
    if(BT.bmusteri.HesapNo2!=BT.bmusteri.HesapNo)
        printf("Yeni acilan hesabinizin numarasi:%d",BT.bmusteri.HesapNo2);
    else {
        BT.bmusteri.HesapNo2==0;
        BaskaBireyselHesapAcma();
    }
    BT.bmusteri.t=time(NULL);
    zaman_bilgisi=localtime(&BT.bmusteri.t);
    printf("Islemin yapildigi tarih ve saat:%s",asctime(zaman_bilgisi));
     FILE *pt;
       pt=fopen("BireyselMusteriDosya.txt","a+");
       if(pt==NULL)
       {
           printf("Dosya acilamadi!\n");
           exit(1);
       }
       fprintf(pt,"%d  ",BT.bmusteri.HesapNo2);
       fprintf(pt,"%s  ",asctime(zaman_bilgisi));
       fclose(pt);
}

void TicariParaCekme(){
    MusteriBT TB;
    Musteri *zaman_bilgisi;
    printf("Hesap numarinizi giriniz:");
    scanf("%d",&TB.tmusteri.HesapNo);
    printf("Cekmek istediginiz tutari giriniz:");
    scanf("%d",&TB.tmusteri.CekilenTutar);
    if(TB.tmusteri.CekilenTutar>1500){
        printf("1 gunde cekebileceginiz maksimum tutar 1500dur!");
        TicariParaCekme();
    }
    else if(TB.tmusteri.Bakiye<TB.tmusteri.CekilenTutar){
        printf("Bakiyeniz yeterli degil!");
        TicariParaCekme();
        }
    else{
        TB.tmusteri.Bakiye -= TB.tmusteri.CekilenTutar;
        TB.tmusteri.HesaptanCekilenToplamPara+=TB.tmusteri.CekilenTutar;
        printf("Hesabinizdan %d TL cekilmistir.\n",TB.tmusteri.CekilenTutar);
        printf("Hesabinizdaki toplam bakiye %d TL dir.\n",TB.tmusteri.Bakiye);
    }
    TB.tmusteri.t=time(NULL);
    zaman_bilgisi=localtime(&TB.tmusteri.t);
    printf("Islemin yapildigi tarih ve saat:%s",asctime(zaman_bilgisi));

    FILE *pt;
    pt=fopen("TicariMusteriDosya.txt","a+");
    if(pt==NULL)
    {
        printf("Dosya acilamadi!\n");
        exit(1);
    }
    fprintf(pt,"%d  ",TB.tmusteri.Bakiye);
    fprintf(pt,"%s",asctime(zaman_bilgisi));
    fclose(pt);
    TB.tmusteri.CekilenToplamPara+=TB.tmusteri.CekilenTutar;
    FILE *cd;
    cd=fopen("rapor.txt","a+");
    if(cd==NULL)
    {
        printf("Dosya acilamadi!\n");
    }
    fprintf(cd,"%d",TB.tmusteri.CekilenToplamPara);
    fclose(cd);
   }

void BireyselParaCekme(){
    MusteriBT BT;
    Musteri *zaman_bilgisi;
    printf("Hesap numarinizi giriniz:");
    scanf("%d",&BT.bmusteri.HesapNo);
    printf("Cekmek istediginiz tutari giriniz:");
    scanf("%d",&BT.bmusteri.CekilenTutar);
    if(BT.bmusteri.CekilenTutar>750){
        printf("1 gunde cekebileceginiz maksimum tutar 750dir!");
        BireyselParaCekme();
    }
    else if(BT.bmusteri.Bakiye<BT.bmusteri.CekilenTutar){
        printf("Bakiyeniz yeterli degil!");
        BireyselParaCekme();
        }
    else{
        BT.tmusteri.Bakiye -=BT.bmusteri.CekilenTutar;
        BT.bmusteri.HesaptanCekilenToplamPara+=BT.bmusteri.CekilenTutar;
        printf("Hesabinizdan %d TL cekilmistir.\n",BT.bmusteri.CekilenTutar);
        printf("Hesabinizdaki toplam bakiye %d TL dir.\n",BT.bmusteri.Bakiye);
    }
       BT.bmusteri.t=time(NULL);
       zaman_bilgisi=localtime(&BT.bmusteri.t);
       printf("Islemin yapildigi tarih ve saat:%s",asctime(zaman_bilgisi));
    FILE *pt;
    pt=fopen("BireyselMusteriDosya.txt","a+");
    if(pt==NULL)
    {
        printf("Dosya acilamadi!\n");
        exit(1);
    }
    fprintf(pt,"%d  ",BT.bmusteri.Bakiye);
    fprintf(pt,"%s",asctime(zaman_bilgisi));
    fclose(pt);
    BT.bmusteri.CekilenToplamPara+=BT.bmusteri.CekilenTutar;
    FILE *cd;
    cd=fopen("rapor.txt","a+");
    if(cd==NULL)
    {
        printf("Dosya acilamadi!\n");
    }
    fprintf(cd,"%d",BT.bmusteri.CekilenToplamPara);
    fclose(cd);
   }

void TicariParaYatirma(){
    MusteriBT TB;

    Musteri *zaman_bilgisi;
     int aranan;
    printf("Hesap numarinizi giriniz:");
    scanf("%d",&aranan);

    FILE *pt;
    pt=fopen("TicariMusteriDosya.txt","r+");

    aranan==TB.tmusteri.HesapNo;
    fscanf(pt,"%d %d %d %s %s %s",
           &TB.tmusteri.HesapNo,
           &TB.tmusteri.KimlikNo,
           &TB.tmusteri.Bakiye,
           TB.tmusteri.Ad,
           TB.tmusteri.Soyad
           );
           fclose(pt);

    printf("Yatirmak istediginiz tutari giriniz:");
    scanf("%d",&TB.tmusteri.YatirilanMiktar);

     TB.tmusteri.Bakiye=0;
    TB.tmusteri.Bakiye += TB.tmusteri.YatirilanMiktar;
    TB.tmusteri.HesabaYatirilanToplamPara+=TB.tmusteri.YatirilanMiktar;
    printf("Hesabiniza %d TL yatirilmistir.\n",TB.tmusteri.YatirilanMiktar);
    printf("Hesabinizdaki toplam tutar %d TL dir.\n",TB.tmusteri.Bakiye);
   TB.tmusteri.t=time(NULL);
   zaman_bilgisi=localtime(&TB.tmusteri.t);
   printf("Islemin yapildigi tarih ve saat:%s\n",asctime(zaman_bilgisi));


    pt=fopen("TicariMusteriDosya.txt","a+");
    if(pt==NULL)
    {
        printf("Dosya acilamadi!\n");
        exit(1);
    }
    fprintf(pt,"%d",TB.tmusteri.Bakiye);
    fprintf(pt,"%s",asctime(zaman_bilgisi));
    fclose(pt);
    TB.tmusteri.YatirilanToplamPara+=TB.tmusteri.YatirilanMiktar;
    FILE *cd;
    cd=fopen("rapor.txt","a+");
    if(cd==NULL)
    {
        printf("Dosya acilamadi!\n");
    }
    fprintf(cd,"%d",TB.tmusteri.YatirilanToplamPara);
    fclose(cd);
   }

void BireyselParaYatirma(){
    MusteriBT BT;
    Musteri *zaman_bilgisi;
    int aranan;
    printf("Hesap numarinizi giriniz:");
    scanf("%d",&aranan);

    FILE *pt;
    pt=fopen("BireyselMusteriDosya.txt","r");

    aranan==BT.bmusteri.HesapNo;
    fscanf(pt,"%d %d %d %s %s %s",
           &BT.bmusteri.HesapNo,
           &BT.tmusteri.KimlikNo,
           &BT.bmusteri.Bakiye,
           BT.bmusteri.Ad,
           BT.bmusteri.Soyad
           );
           fclose(pt);
    printf("Yatirmak istediginiz tutari giriniz:");
    scanf("%d",&BT.bmusteri.YatirilanMiktar);
    BT.bmusteri.Bakiye=0;
    BT.tmusteri.Bakiye += BT.bmusteri.YatirilanMiktar;
    BT.bmusteri.HesabaYatirilanToplamPara += BT.bmusteri.YatirilanMiktar;
     printf("Hesabiniza %d TL yatirilmistir.\n",BT.bmusteri.YatirilanMiktar);
    printf("Hesabinizdaki toplam tutar %d TL dir.\n",BT.bmusteri.Bakiye);
     BT.bmusteri.t=time(NULL);
     zaman_bilgisi=localtime(&BT.bmusteri.t);
     printf("Islemin yapildigi tarih ve saat:%s\n",asctime(zaman_bilgisi));

    pt=fopen("BireyselMusteriDosya.txt","a+");
    if(pt==NULL)
    {
        printf("Dosya acilamadi!\n");
        exit(1);
    }
    fprintf(pt,"%d  ",BT.bmusteri.Bakiye);
    fprintf(pt,"%s",asctime(zaman_bilgisi));
    fclose(pt);
    BT.bmusteri.YatirilanToplamPara+=BT.bmusteri.YatirilanMiktar;
    FILE *cd;
    cd=fopen("rapor.txt","a+");
    if(cd==NULL)
    {
        printf("Dosya acilamadi!\n");
    }
    fprintf(cd,"%d",BT.bmusteri.YatirilanToplamPara);
    fclose(cd);
   }

void TicariHavaleYapma(){
    MusteriBT TB;
    MusteriBT TBT;
    Musteri *zaman_bilgisi;
    printf("Hesap numarinizi giriniz:");
    scanf("%d",&TB.tmusteri.HesapNo);
    printf("Havale yapmak istediginiz hesabin numarasini giriniz:");
    scanf("%d",&TBT.tmusteri.HesapNo);
    TB.tmusteri.HesaptanHavaleYapanKisininHesapNumarasi=TBT.tmusteri.HesapNo;
    printf("Havale yapacaginiz miktari giriniz:");
    scanf("%d",&TB.tmusteri.HavaleyleGidenPara);
    if(TB.tmusteri.Bakiye<TB.tmusteri.HavaleyleGidenPara){
        printf("Yeterli bakiyeniz yok!\n");
        TicariHavaleYapma();
    }

    TB.tmusteri.Bakiye==0;
    TBT.tmusteri.Bakiye==0;
    TB.tmusteri.Bakiye -= TB.tmusteri.HavaleyleGidenPara;
    TBT.tmusteri.Bakiye+= TB.tmusteri.HavaleyleGidenPara;
    TB.tmusteri.HesaptanHavaleYapilanMiktar=TB.tmusteri.HavaleyleGidenPara;
     TB.tmusteri.t=time(NULL);
     zaman_bilgisi=localtime(&TB.tmusteri.t);
     printf("Islemin yapildigi tarih ve saat:%s",asctime(zaman_bilgisi));
    FILE *pt;
    pt=fopen("TicariMusteriDosya.txt","a+");
    if(pt==NULL)
    {
        printf("Dosya acilamadi!\n");
        exit(1);
    }
    fprintf(pt,"%d  ",TB.tmusteri.Bakiye);
    fprintf(pt,"%d  ",TBT.tmusteri.Bakiye);
    fprintf(pt,"%s",asctime(zaman_bilgisi));
    fclose(pt);
}

void BireyselHavaleYapma(){
    MusteriBT BT;
    MusteriBT BTB;
    Musteri *zaman_bilgisi;
    printf("Hesap numarinizi giriniz:");
    scanf("%d",&BT.bmusteri.HesapNo);
    printf("Havale yapmak istediginiz hesabin numarasini giriniz:");
    scanf("%d",&BT.bmusteri.HesapNo);
    printf("Havale yapacaginiz miktari giriniz:");
    scanf("%d",&BT.bmusteri.HavaleyleGidenPara);
    BT.bmusteri.HesaptanHavaleYapanKisininHesapNumarasi=BTB.bmusteri.HesapNo;
    if(BT.bmusteri.HesapNo<BT.bmusteri.HavaleyleGidenPara){
        printf("Yeterli bakiyeniz yok!");
        BireyselHavaleYapma();
    }
    BT.bmusteri.Bakiye -=BT.bmusteri.HavaleyleGidenPara;
    BTB.bmusteri.Bakiye= BTB.bmusteri.Bakiye + (BT.bmusteri.HavaleyleGidenPara*98/100);
      BT.bmusteri.HesaptanHavaleYapilanMiktar=BT.bmusteri.HavaleyleGidenPara;
      BT.bmusteri.t=time(NULL);
      zaman_bilgisi=localtime(&BT.bmusteri.t);
      printf("Islemin yapildigi tarih ve saat:%s",asctime(zaman_bilgisi));
    FILE *pt;
    pt=fopen("BireyselMusteriDosya.txt","a+");
    if(pt==NULL)
    {
        printf("Dosya acilamadi!\n");
        exit(1);
    }
    fprintf(pt,"%d  ",BT.bmusteri.Bakiye);
    fprintf(pt,"%d  ",BTB.bmusteri.Bakiye);
    fprintf(pt,"%s",asctime(zaman_bilgisi));
    fclose(pt);
}

void GelirGiderRaporu(){
           MusteriBT BT;
           MusteriBT TB;
           int BankadanCekilenToplamPara;
           int BankayaYatirilanToplamPara;
           FILE *cd;
           cd=fopen("rapor.txt","a+");
           if(cd==NULL){
            printf("Dosya acilamadi!\n");
            exit(1);
           }
           fscanf(cd,"%d",&BT.bmusteri.CekilenToplamPara);
           printf("Bireysel musterilerin bankadan cektigi toplam para:%d\n",BT.bmusteri.CekilenToplamPara);
           fscanf(cd,"%d",&TB.tmusteri.CekilenToplamPara);
           printf("Ticari musterilerin bankadan cektigi toplam para:%d\n",TB.tmusteri.CekilenToplamPara);
           fscanf(cd,"%d",&BT.bmusteri.YatirilanToplamPara);
           printf("Bireysel musterilerin bankaya yatirdigi toplam para:%d\n",BT.bmusteri.YatirilanToplamPara);
           fscanf(cd,"%d",&TB.tmusteri.YatirilanToplamPara);
           printf("Ticari musterilerin bankaya yatirdigi toplam para:%d\n",TB.tmusteri.YatirilanToplamPara);

          BankadanCekilenToplamPara = BT.bmusteri.CekilenToplamPara+TB.tmusteri.CekilenToplamPara;
          BankayaYatirilanToplamPara=BT.bmusteri.YatirilanToplamPara + TB.tmusteri.YatirilanToplamPara;
          printf("Bankadan cikan toplam para:%d\n",BankadanCekilenToplamPara);
          printf("Bankaya giren toplam para:%d\n",BankayaYatirilanToplamPara);
        fcole(cd);
      }

void TicariHesapOzeti(){
    MusteriBT TB;
    FILE *pt;
    FILE *dk;
    pt=fopen("TicariMusteriDosya.txt","r");
    dk=fopen("dekont.txt","a+");
    printf("Hesap numaranizi giriniz:");
    scanf("%d",&TB.tmusteri.HesapNo);
    fread(&TB.tmusteri.HesabaYatirilanToplamPara,sizeof(int),1,pt);
    fread(&TB.tmusteri.HesaptanCekilenToplamPara,sizeof(int),1,pt);
    fread(&TB.tmusteri.HesaptanHavaleYapanKisininHesapNumarasi,sizeof(int),1,pt);
    fread(&TB.tmusteri.HesaptanHavaleYapilanMiktar,sizeof(int),1,pt);
    fprintf(dk,"%d  ",TB.tmusteri.HesabaYatirilanToplamPara);
    fprintf(dk,"%d  ",TB.tmusteri.HesaptanCekilenToplamPara);
    fprintf(dk,"%d  ",TB.tmusteri.HesaptanHavaleYapanKisininHesapNumarasi);
    fprintf(dk,"%d  ",TB.tmusteri.HesaptanHavaleYapilanMiktar);
    printf("Hesabiniza yatirilan toplam para : %d ",TB.tmusteri.HesabaYatirilanToplamPara);
    printf("Hesabinizdan cekilen toplam para : %d ",TB.tmusteri.HesaptanCekilenToplamPara);
    printf("Hesabinizdan baska hesaba yapilan havale miktari : %d ",TB.tmusteri.HesaptanHavaleYapanKisininHesapNumarasi);
    printf("Hesabinizdan baska hesaba havale yapan kisinin hesap numarasi : %d ",TB.tmusteri.HesaptanHavaleYapilanMiktar);
    fclose(pt);
    fclose(dk);
}

void BireyselHesapOzeti(){
    MusteriBT BT;
    FILE *pt;
    FILE *dk;
    pt=fopen("TicariMusteriDosya.txt","r");
    dk=fopen("dekont.txt","a+");
    printf("Hesap numaranizi giriniz:");
    scanf("%d",&BT.bmusteri.HesapNo);
    fread(&BT.bmusteri.HesabaYatirilanToplamPara,sizeof(int),1,pt);
    fread(&BT.bmusteri.HesaptanCekilenToplamPara,sizeof(int),1,pt);
    fread(&BT.bmusteri.HesaptanHavaleYapanKisininHesapNumarasi,sizeof(int),1,pt);
    fread(&BT.bmusteri.HesaptanHavaleYapilanMiktar,sizeof(int),1,pt);
    fprintf(dk,"%d  ",BT.bmusteri.HesabaYatirilanToplamPara);
    fprintf(dk,"%d  ",BT.bmusteri.HesaptanCekilenToplamPara);
    fprintf(dk,"%d  ",BT.bmusteri.HesaptanHavaleYapanKisininHesapNumarasi);
    fprintf(dk,"%d  ",BT.bmusteri.HesaptanHavaleYapilanMiktar);
    printf("Hesabiniza yatirilan toplam para : %d ",BT.bmusteri.HesabaYatirilanToplamPara);
    printf("Hesabinizdan cekilen toplam para : %d ",BT.bmusteri.HesaptanCekilenToplamPara);
    printf("Hesabinizdan baska hesaba yapilan havale miktari : %d ",BT.bmusteri.HesaptanHavaleYapanKisininHesapNumarasi);
    printf("Hesabinizdan baska hesaba havale yapan kisinin hesap numarasi : %d ",BT.bmusteri.HesaptanHavaleYapilanMiktar);
    fclose(pt);
    fclose(dk);
}

void TicariHesapKapatma(){
     MusteriBT TB;
     int sil;
     printf("Kapatmak istediginiz hesabin numarasini giriniz:");
     scanf("%d",&sil);
     int say=0;
     FILE *pt;
     FILE *yc;
     pt=fopen("TicariMusteriDosya.txt","r");
     yc=fopen("GeciciDosya.txt","w+");
     while (fscanf(pt,"%s %s %d %d %s",TB.tmusteri.Ad,TB.tmusteri.Soyad,&TB.tmusteri.KimlikNo,&TB.tmusteri.telefon,TB.tmusteri.adres)!= EOF)
  {

   if(sil==TB.tmusteri.HesapNo){
    printf("Hesap kapandý");
   }
   else {
    fprintf(yc,"%s %s %d %d %s",TB.tmusteri.Ad,TB.tmusteri.Soyad,TB.tmusteri.KimlikNo,TB.tmusteri.telefon,TB.tmusteri.adres);
   }

   getch();
   fclose(pt);
   fclose(yc);
remove ("TicariMusteriDosya.txt");
rename ("GeciciDosya.txt","TicariMusteriDosya.txt");
        printf("Hesabiniz kapatilmistir\n");

  }
      }

void BireyselHesapKapatma(){

      MusteriBT BT;
     int sil;
     printf("Kapatmak istediginiz hesabin numarasini giriniz:");
     scanf("%d",&sil);
     int say=0;
     FILE *pt;
     FILE *yc;
     pt=fopen("TicariMusteriDosya.txt","r");
     yc=fopen("GeciciDosya.txt","w+");
     while (fscanf(pt,"%s %s %d %d %s",BT.bmusteri.Ad,BT.bmusteri.Soyad,&BT.bmusteri.KimlikNo,&BT.bmusteri.telefon,BT.bmusteri.adres)!= EOF)
  {
      if(BT.bmusteri.Bakiye==0){
   if(sil==BT.bmusteri.HesapNo){
    printf("Hesap kapandý");
   }
   else {
    fprintf(yc,"%s %s %d %d %s",BT.bmusteri.Ad,BT.bmusteri.Soyad,BT.bmusteri.KimlikNo,BT.bmusteri.telefon,BT.bmusteri.adres);
   }

   getch();
   fclose(pt);
   fclose(yc);
remove ("TicariMusteriDosya.txt");
rename ("GeciciDosya.txt","TicariMusteriDosya.txt");
        printf("Hesabiniz kapatilmistir\n");
      }
  else {
    printf("Hesabinizda para oldugu icin kapatilamiyor.Lutfen hesabinizdaki parayi cektikten sonra tekrar deneyin.\n");
  }
  }
      }

int main()
  {
    AnaMenu();

    return 0;
  }
