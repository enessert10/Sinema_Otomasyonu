#include <stdio.h>
#include <stdlib.h>

//PROGRAMIN PAROLASI : enes


    enum izleyici
    {
        ogrenci=1,
        tam
    };



      enum salon
    {
        Red=1,
        Green,
        Blue
    };





    enum matine
    {
        matine1=1,
        matine2,
        matine3,
        matine4,
        matine5
    };




    void dolukoltuklar()
    {
        FILE *fc;
        int dolusaln,dolumtne,dolukltuk;
        fc=fopen("secimler.txt","r");

        while(!feof(fc))
        {
            fscanf(fc,"%d %d %d",&dolusaln,&dolumtne,&dolukltuk);
            printf("%d.salon %d.matine %d.koltuk DOLU!\n",dolusaln,dolumtne,dolukltuk);
        }

        fclose(fc);
    }






    void kazanc()
    {
        FILE *fa;
        int toplam=0,hucret=0;
        fa=fopen("kazanc.txt","r");

        while(!feof(fa))
        {
            toplam+=hucret;
            fscanf(fa,"%d",&hucret);
        }
        printf("%d TL\n",toplam);

    }




    void biletsatisi()
    {
    enum izleyici izlyci;
    enum salon saln;
    enum matine mtne;
    int *pdolusaln,*pdolumtne,*pdolukltuk;
    int i,koltuk,secim,ucret,dolusaln,dolumtne,dolukltuk,y,dolu;

    FILE *fc;

     pdolusaln=&dolusaln;
     pdolumtne=&dolumtne;
     pdolukltuk=&dolukltuk;



     printf("Ogrenci-->1\nTam-->2\n"); scanf("%d",&izlyci);

      if(izlyci==1)
      {
         ucret=20;
      }
      else if(izlyci==2)
      {
         ucret=30;
      }

      FILE *fa;
      fa=fopen("kazanc.txt","a");

      fprintf(fa,"%d\n",ucret);

      fclose(fa);

    printf("Film izlemek icin lutfen bir salon seciniz\n");
    printf("1-Red\n2-Green\n3-Blue\n");
    scanf("%d",&saln);
    printf("Film izlemek icin lutfen bir matine seciniz\n1 - 2 - 3 - 4- 5\n"); scanf("%d",&mtne);

    fc=fopen("secimler.txt","r");


 for(i=1;i<51;i++)
 {
        dolu=0;
           while(!feof(fc))
           {
        fscanf(fc,"%d %d %d\n",pdolusaln,pdolumtne,pdolukltuk);

        if(saln==*pdolusaln && mtne==*pdolumtne && i==*pdolukltuk)
            {
                dolu=1;
            }
        else
            {

            }
    }

    fclose(fc);

    fc=fopen("secimler.txt","r");

    if(dolu==0)
    {
        printf("%d-",i);
    }
    }
    printf("\n");
    fclose(fc);
       fc=fopen("secimler.txt","a");

         printf("Lutfen bir koltuk numarasi seciniz\n");
         scanf("%d",&koltuk);
         fprintf(fc,"%d %d %d\n",saln,mtne,koltuk);

       fclose(fc);
    }


int main()
{
    enum izleyici izlyci;
    enum salon saln;
    enum matine mtne;
    int secim,j,ucret,koltuk,dolusaln,dolumtne,dolukltuk,dolu,y,i=0,hata=0,x;
    int *pdolusaln,*pdolumtne,*pdolukltuk;

    FILE *fc,*fd;
    pdolusaln=&dolusaln;
    pdolumtne=&dolumtne;
    pdolukltuk=&dolukltuk;
    char parola[100],parolaoku[100],grlnparola[100],k[30];
    fd=fopen("parola.txt","r");

    strcpy(parola,parolaoku);
      while( !feof(fd) )
   {

           fscanf(fd,"%s",k);
           for(j=0;j<30;j++)
           {
               if( k[j]!='\0')
                k[j] = (char) (((int) k[j]+1));

           }
    }

      x:
     printf("\n PAROLAYI GIRINIZ:");
     gets(grlnparola);
     if (strcmp(k,grlnparola)==0)
     {
     printf("\n PAROLA KABUL EDILDI\n\n");
      y:

    fc=fopen("secimler.txt","a");

    printf("*******SECÝM EKRANI*******\n");

    printf("--------------------------\n");

    printf("Bilet satisi     -->1\n");

    printf("Dolu koltuklar   -->2\n");

    printf("Toplam kazanc    -->3\n");

    printf("CIKIS            -->4\n");
    scanf("%d",&secim);

    switch (secim)
    {

      case 1:
      {
          biletsatisi();
      }

      break;

      case 2:
      {
         dolukoltuklar();
      }

      break;

      case 3:
      {
          kazanc();
      }

      break;

      case 4:
      {
          exit(1);
      }

      break;
    }goto y;

     }

     else
     {
         printf("\n HATALI PAROLA GIRDINIZ!\n\n");
        goto x;
     }
    return 0;
}

