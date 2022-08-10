#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int bolenlerToplami(int sayi)
{
	int sum=0;
	
	for(int i = 1 ; i <= (sayi / 2) + 1 ; i++){
	
		if(sayi % i == 0)
		{
			sum+=i;
		}
	}

	return sum;
}	

int isAbundant(int number){	return number < bolenlerToplami(number) ? true : false;	}

void yazdir(int arr[] , int boyut)
{
	for(int i = 0 ; i < boyut ; i++)
	{
		cout << arr[i] << endl;
	}
}

int main(){
		
	vector<int> AbundantV;
	vector<int> SumV;	
	int *SumAbundant = new int[28124];		
	vector<int> NotAbundantV;		
	
	for(int i = 0 ; i < 28124 ; i++)
		SumAbundant[i] = 0;
	
	for(int i = 12 ; i <= 28123 ; i++)
	{
		if(isAbundant(i))
		{
			AbundantV.push_back(i);
		}	
	}
	
	int uzunluk = AbundantV.size();

	for(int i = 0 ; i < uzunluk ; i++)
	{
		for(int j = 0 ; j < uzunluk ; j++)
		{
			if(AbundantV[i] + AbundantV[j] <= 28123)
				SumAbundant[AbundantV[i] + AbundantV[j]] = AbundantV[i] + AbundantV[j];
		}
	}
	
	int toplam = 0;
	
	for(int i = 0 ; i < 28124 ; i++){
		if(SumAbundant[i] == 0){
			toplam += i;
		}
	}
	
	cout << "Toplam = " << toplam << endl;
	
    return 0;
}


