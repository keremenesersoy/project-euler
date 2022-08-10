#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;


int fact(int number){
	if(number == 1 || number == 0)
		return 1;
	else
		return number * fact(number - 1);
}

void *change(char dizi[],int index)
{
	int temp;
	
	for(int i = index ; i < strlen(dizi); i++)
	{		
		for(int j = index; j < strlen(dizi); j++){
			
			if(dizi[i] < dizi[j])
			{
				temp = dizi[i];
				dizi[i] = dizi[j];
				dizi[j] = temp;
			}	
		}	
	}
}

void *indexChange(char dizi[] , int firstIndex , int SecondIndex){
	
	int temp = dizi[firstIndex];
	
	dizi[firstIndex] = dizi[SecondIndex];
	dizi[SecondIndex] = temp;
}
int main()
{
	
	char lexic[] = "0123456789";
	char lexic_2[] = "0123456789";

	int deger;
	printf("gacinci = ");
	scanf("%d",&deger);
	
	int uzunluk = strlen(lexic);	
	int kalan , bolen;	
	int arr[10];
	
	for(int i = 0 ; i < uzunluk; i++)
	{	
		if(deger == 0){
		
			for(int k = i ; k < uzunluk ; k++)
			{
				arr[k] = (int)lexic_2[k] - 48;	
			}
			
			printf("arr = ");
			
			for(int i = 0 ; i < uzunluk ; i++){
				printf("%d",arr[i]);
			}
			return 0;	
		}
		
		if(fact(uzunluk - 1 - i) <= deger)
		{	
			bolen = (int)(deger / fact(uzunluk - 1 - i)); // 4
			deger = deger % fact(uzunluk - 1 - i); // 4
			
			arr[i] = (int)lexic_2[i + bolen] - 48;
			indexChange(lexic_2,i,i+bolen);
			change(lexic_2,i+1);
		}
		else
		{
			bolen = 0;
			arr[i] = (int)lexic_2[i + bolen] - 48;
		}
			
	}	
    return 0;
}


