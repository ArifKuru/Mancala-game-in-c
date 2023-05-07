#include <stdio.h>

// Tahtayý yazdýrma fonksiyonu
void yaz(int p[],int size){
	int j,k;
	for(j=6;j>=1;j--){
		printf("  %d ",p[j]);	}
		printf("\n %d                     %d\n",p[7],p[14]);
	for(k=8;k<=13;k++){
		printf("  %d ",p[k]);
}
printf("\n");
}
// Oyuncunun hamlesini index düzenine göre çeviren fonksiyon
int oyun(int hamle,int player){
	int haml;
	if(player%2==0){
		haml=hamle+7;
	}
	else {
		haml=7-hamle;
	}
	return haml;
}
// Sýranýn kontrolü
int turn(int player){
	if(player%2==0){
		return 2;
	}
	else { return 1;
	}
}
// Kazananý belirleme fonksiyonu
int winner(int p[],int size){
	if(p[7]>p[14]){
		return 1;
	}
	else{ if(p[7]<p[14]){return 2;
	}
	else { return 3;
	}
	}
}
// Toplama fonksiyonu 1.oyuncu
int sum1(int p[],int size){
	int i,t;
	t=0;
	for(i=1;i<=6;i++){
		t+=p[i];
	}
	return t;
}
// Toplama fonksiyonu 1.oyuncu
int sum2(int p[],int size){
	int i,t;
	t=0;
	for(i=8;i<=13;i++){
		t+=p[i];
	}
	return t;
}
int main(void){
	int k,i,j,hamle,haml,counter,ctrl;
	int p[18];
	int player=1;
	// Tahtayý ilk deðerlerine ayarlama
	for(i=0;i<=14;i++){
		if((i)%7==0 || (i)%7==0){
			p[i]=0;
		}
		else{
		(p[i]=4);}
	}
	
	
	// Yazdýrma
	printf("WELCOME THE MANCALA GAME\n");
	printf("PLEASE ENTER THE COLUMN NUMBER OF THE MOVE YOU WANT TO PLAY\n");
	printf("( 1   2   3   4   5   6 )-column numbers for player 1\n");
	yaz(p,18);
    printf("( 1   2   3   4   5   6 )-column numbers for player 2\n");
    
    
    
    
     // Oyunun ana döngüsü
     ctrl=0;
	while(ctrl!=1){
printf("\nPlayer %d 's turn\n",turn(player));
scanf("%d",&hamle);
if(hamle>6 || hamle<1){
	printf("\nPlease try another number\n");
}
else{
haml=oyun(hamle,player);
//oyuncu sýrasýný deðistirme 
player+=1;
if(p[haml]!=0){
	// bir taþ varsa bir yana atýlýr
	if(p[haml]==1){
		counter++;
		p[haml]=0;
	}
	// seçilen kuyuyu 1 olana kadar azaltmak,counter kuyudan alýnan taþ sayýsý
	while(p[haml]>1){
		p[haml]--;
		counter++;
	}
	// taþlarý saat yönünün tersine daðýtma 
	while(counter>=1){
		// eðer 1.oyuncu taþý hazinesine denk getirirse sýra deðiþmez 
		if(haml+1==7 && counter==1){if(turn(player)==2){
		player-=1;}
		else{
			//eðer 2.oyuncu 1.oyuncunun hazinesine denk gelirse orayi pas geçer
			p[7]-=1;
			counter+=1;
			
		}}
		// eðer 2. oyuncu taþý hazinesine denk getirirse sýra deðiþmez
		if(haml+1==14 && counter==1){if(turn(player)==1){
			player-=1;}
			else{
				// eðer 1.oyuncu 2.oyuncunun hazinesine denk gelirse orayi pas geçer
				p[14]-=1;
				counter+=1;
			}
		}
		//index düzenine göre 14 den sonra 1 gelmeli
		if(haml+1>14){
		haml=0;}
		// eðer oyuncunun son taþý kendi boþ kuyusuna gelirse ve karþýsýnda taþ var hepsini hazinesine alýr 
		if(turn(player)==2){if(p[haml+1]==0 && p[14-(haml+1)]!=0 && haml+1<=6 && counter==1){
			p[7]+=1;
			p[7]+=p[14-(haml+1)];
			p[14-(haml+1)]=0;
			p[haml+1]=-1;
		}
		}
		// eðer oyuncunun son taþý kendi boþ kuyusuna gelirse ve karþýsýnda taþ var hepsini hazinesine alýr 
		if(turn(player)==1){if(p[haml+1]==0 && p[14-(haml+1)]!=0 && haml+1>=8 && counter==1){
			p[14]+=1;
			p[14]+=p[14-(haml+1)];
			p[14-(haml+1)]=0;
			p[haml+1]=-1;
					}
		// eðer oyuncunun son taþý rakip kuyularýndan birini çift yaparsa tüm taþlari hazinesine alýnýr
		}
		if(turn(player)==2){if(haml+1>=8 && haml+1!=14 && counter==1 && (p[haml+1]+1)%2==0){
			p[7]+=p[haml+1]+1;
			p[haml+1]=-1;
			
		}
		// eðer oyuncunun son taþý rakip kuyularýndan birini çift yaparsa tüm taþlari hazinesine alýnýr
		}
		if(turn(player)==1){if(haml+1<=6 && counter==1 && (p[haml+1]+1)%2==0)
		{
			p[14]+=p[haml+1]+1;
			p[haml+1]=-1;
		}
		}
		
		haml++;
		p[haml]++;
		counter--;
		
		
	}
	// oyunun bitmesi için 2 oyuncudan birinin kuyularýnda taþ kalmamasý lazým
	yaz(p,18);
	if(sum1(p,18)==0 || sum2(p,18)==0){
			ctrl=1; 
}
	}


else { printf("\nPlease try another number\n");
player-=1;
}}
}

// oyunu ilk bitiren diðer oyuncunun kuyularýnda kalan taþlarý hazinesine alýr
if(sum1(p,18)==0){p[7]+=sum2(p,18);
}
else{p[14]+=sum1(p,18);
}




// hazinesinde en çok taþ olan kazanýr 
    // Kazananý belirleme
if(winner(p,18)==1){
	printf("\nPlayer 1 wins!\n");
	printf("SCORES %d-%d",p[7],p[14]);
}
else { if(winner(p,18)==2){
printf("\nPlayer 2 wins!\n\n");
printf("SCORES %d-%d",p[7],p[14]);}
else { printf("\nIt's a tie!\n");
       printf("SCORES 24-24");
}
}
}















