#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

RANDEVU SÝSTEMÝ

kullanýcý sisteme ad soyad ve tc no ile kayýt olur. kayýt olduktan sonra karþýsýna çýkan menüden yapmak istediði iþlemi seçer. iþlemler sýrasýyla; 

a) randevu oluþtur b) randevu iptal et c) randevularýmý görüntüle

*/
void asecenegi();
void bsecenegi();
void csecenegi();
void dosyadanOku();
void dosyayaYaz();
int toplamrandevusayisi(int sayi);
char randevular[10][50];
int randevuSayisi = 0;
int main(int argc, char *argv[]) {
	char ad[50], soyad[50];
    char tcNo[12];
    char randevular[10][50]; 
    int randevuSayisi = 0;
    char secim;
    int i=0;
    char sifre[10];
    const char dogru_sifre[] = "123"; 
void dosyadanOku();

    while (1) {
        printf("Sisteme giris icin yetki sifresini giriniz: ");
        gets(sifre); 

        if (strcmp(sifre, dogru_sifre) == 0) {
            printf("Giris yapiliyor...\n");
            break;
        } else {
            printf("Yanlis sifre girisi yaptiniz. Lutfen tekrar deneyiniz!!\n");
        }
    }
		
	
		
	

    
    printf("Adinizi giriniz: ");
 
    gets(ad);
    printf("Soyadinizi giriniz: ");
  
    gets(soyad);
    printf("TC kimlik numaranizi giriniz: ");
  
    gets(tcNo);

    printf("\n Hosgeldiniz, %s %s \n\n", ad, soyad);

    do { 
       
        printf("Yapmak istediginiz islemi seciniz:\n");
        printf("a) Randevu olustur. \n");
        printf("b) Randevu iptal et. \n");
        printf("c) Randevulari goruntule. \n");
        printf("d) Sistemden cikis. \n");
        printf("Seciminizi yapiniz: ");
        scanf(" %c", &secim);
        
        getchar(); 

        switch (secim) {
            case 'a':
              asecenegi();
                  break;

            case 'b':
            
            bsecenegi();
                
               break;

            case 'c':
             csecenegi();
                break;

            case 'd':
                
                printf("Cikis yapiliyor... Tesekkur ederiz!\n");
                void dosyayaYaz();

                break;

            default:
                printf("Gecersiz bir secim yaptiniz! Lutfen tekrar deneyin.\n\n");
        }
    } while (secim != 'd');
    
    
	return 0;
}

int toplamrandevusayisi(int sayi) {
    return sayi;
}
void asecenegi(){
	
	
	 if (randevuSayisi < 10) {
                    printf("Randevu tarihini ve saatini giriniz (orn: 12/12/2024 14:00): ");
                  gets(randevular[randevuSayisi]);
                    printf("Randevu tarihiniz: %s dir.",randevular);
                    randevuSayisi++;
                    printf("Randevunuz basariyla olusturulmustur. \n\n");
                } else {
                    printf("Maksimum randevu sayisina ulastiniz!\n\n");
                }
                dosyayaz();
              
	
}
void bsecenegi(){
	int i=0;

	if (randevuSayisi > 0) {
                    printf("Mevcut randevulariniz:\n");
                    for (i = 0; i < randevuSayisi; i++) {
                        printf("%d) %s\n", i + 1, randevular[i]);
                    }
                    int randevuiptal=0;
                    printf("Iptal etmek istediginiz randevunun numarasini giriniz: ");
                    scanf("%d", &randevuiptal);
                    if (randevuiptal > 0 && randevuiptal <= randevuSayisi) {
                        for ( i = randevuiptal - 1; i < randevuSayisi - 1; i++) {
                            strcpy(randevular[i], randevular[i + 1]);
                        }
                        randevuSayisi--;
                        printf("Randevu basariyla iptal edildi!\n\n");
                    } else {
                        printf("Gecersiz randevu numarasi girdiniz. Lütfen tekrar deneyiniz. \n\n");
                    }
                } else {
                    printf("Henuz kayitli bir randevunuz yoktur. \n\n");
                }
}
void csecenegi(){
	int i=0;
	if (randevuSayisi > 0) {
                	printf("Toplam randevu sayiniz: %d 'dir. ", toplamrandevusayisi(randevuSayisi)); //fonksiyon
                    printf("Mevcut randevulariniz:\n");
                    for (i = 0; i < randevuSayisi; i++) {
                        printf("%d) %s\n", i + 1, randevular[i]);
                    }
                    printf("\n");
                } else {
                    printf("Henuz kayitli bir randevunuz yok!\n\n");
                }
}

void dosyayaz() {
	int i=0;
   FILE *dosya;
   dosya = fopen("randevular.txt", "w"); 
    if (dosya == NULL) {
        printf("Dosyaya yazma hatasi!\n");
        return;
    }

    for ( i = 0; i < randevuSayisi; i++) {
        fprintf(dosya, "%s\n", randevular[i]); 
    }

    fclose(dosya);
}

