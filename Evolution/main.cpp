


//#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, const char * argv[])
{
	setlocale(LC_ALL, "rus");
    
    int const m = 10, n = 10;
	int mas[m][n]; //граф
	mas[0][0] = 0; mas[0][1] = 45; mas[0][2] = 21; mas[0][3] = 11; mas[0][4] = 13; mas[0][5] = 5; mas[0][6] = 80; mas[0][7] = 71; mas[0][8] = 75; mas[0][9] = 64;
	mas[1][0] = 45; mas[1][1] = 0; mas[1][2] = 10; mas[1][3] = 73; mas[1][4] = 66; mas[1][5] = 92; mas[1][6] = 3; mas[1][7] = 8; mas[1][8] = 12; mas[1][9] = 13;
	mas[2][0] = 21; mas[2][1] = 10; mas[2][2] = 0; mas[2][3] = 17; mas[2][4] = 42; mas[2][5] = 25; mas[2][6] = 14; mas[2][7] = 68; mas[2][8] = 43; mas[2][9] = 50;
	mas[3][0] = 11; mas[3][1] = 73; mas[3][2] = 17; mas[3][3] = 0; mas[3][4] = 76; mas[3][5] = 21; mas[3][6] = 43; mas[3][7] = 26; mas[3][8] = 27; mas[3][9] = 9;
	mas[4][0] = 13; mas[4][1] = 66; mas[4][2] = 42; mas[4][3] = 76; mas[4][4] = 0; mas[4][5] = 59; mas[4][6] = 47; mas[4][7] = 71; mas[4][8] = 38; mas[4][9] = 46;
	mas[5][0] = 5; mas[5][1] = 92; mas[5][2] = 25; mas[5][3] = 21; mas[5][4] = 59; mas[5][5] = 0; mas[5][6] = 35; mas[5][7] = 31; mas[5][8] = 2; mas[5][9] = 15;
	mas[6][0] = 80; mas[6][1] = 3; mas[6][2] = 14; mas[6][3] = 43; mas[6][4] = 47; mas[6][5] = 35; mas[6][6] = 0; mas[6][7] = 19; mas[6][8] = 27; mas[6][9] = 63;
	mas[7][0] = 71; mas[7][1] = 8; mas[7][2] = 68; mas[7][3] = 26; mas[7][4] = 71; mas[7][5] = 31; mas[7][6] = 19; mas[7][7] = 0; mas[7][8] = 82; mas[7][9] = 73;
	mas[8][0] = 75; mas[8][1] = 12; mas[8][2] = 43; mas[8][3] = 27; mas[8][4] = 38; mas[8][5] = 2; mas[8][6] = 27; mas[8][7] = 82; mas[8][8] = 0; mas[8][9] = 20;
	mas[9][0] = 64; mas[9][1] = 13; mas[9][2] = 50; mas[9][3] = 9; mas[9][4] = 46; mas[9][5] = 15; mas[9][6] = 63; mas[9][7] = 73; mas[9][8] = 20; mas[9][9] = 0;
    
    /*for (int i=0; i<m; i++)
     {
     for (int j=0; j<n; j++)
     {
     cout << mas[i][j];
     cout<< " ";
     }
     cout << endl;
     }
     cout<<endl;*/
    
    //srand( time( 0 ) );
    
    bool repeat = false;
	int const individ = 100, gene = 10;
	int population[individ][gene];//популяция
	for (int i=0; i<individ; i++)
	{
        for (int j=0; j<gene; j++)
        {
            population[i][j] = rand() % 10;
            for (int k=0; k<j; k++)
            {
                if (population[i][j] == population[i][k])
                {
                    repeat = true;
                    break;
                }
            }
            if (repeat == true) break;
        }
        if (repeat == true)
        {
            i--;
            repeat = false;
        }
	}
    
    int generation = 0;
    int min = 100000000;
    
    
    while (generation < 100)
    {
        /*cout<<"Population"<<endl<<endl;
         
         for (int i=0; i<individ; i++)
         {
         for (int j=0; j<gene; j++)
         {
         cout << population[i][j];
         cout<< " ";
         }
         cout << endl;
         }
         cout<<endl;*/
        
        //ранжирование
        int const N=100, g=10;
        int rank [N][g]={0,0};
        
        int x1=0;
        int x2=0;
        int xr1[gene]={0}, xr2[gene]={0};
        
        
        int sumrank[N]={0};
        int sum = 0;
        for (int i = 0; i<100; i++)//проходим по индивидам
        {
            sum = 0;
            for (int j=0; j<(gene-1); j++)//проходим по генам. Длина
            {
                sum = sum + mas[population[i][j]][population[i][j+1]];
                
            }
            
            for (int k=0; k<individ; k++)//надо сравнить со всеми индивидами
            {
                if(sumrank[k]==0)
                {
                    sumrank[k]=sum;
                    for (int p=0; p<gene; p++)
                        rank[k][p]=population[i][p];
                    break;
                }
                
                if(sum >= sumrank[k])
                {
                    if (sum<sumrank[k+1])
                    {
                        for (int l=k+1; l<individ; l++)
                        {
                            if (sumrank[l]!=0)
                            {
                                if (sumrank[l+1]!=0)
                                {
                                    if (l%2==0) x1 = sumrank[l+1];
                                    else x2 = sumrank[l+1];
                                    
                                    if (l==k+1) sumrank[l+1]=sumrank[l];
                                    else if (l%2==0) sumrank[l+1]=x2;
                                    else sumrank[l+1]=x1;
                                    
                                    for (int p=0; p<gene; p++)
                                    {
                                        if (l%2==0) xr1[p]=rank[l+1][p];
                                        else xr2[p]=rank[l+1][p];
                                        if (l==k+1) rank[l+1][p]=rank[l][p];
                                        else if (l%2==0) rank[l+1][p]=xr2[p];
                                        else rank[l+1][p]=xr1[p];
                                    }
                                }
                                else
                                {
                                    if (l%2==0) x1 = sumrank[l+1];
                                    else x2 = sumrank[l+1];
                                    
                                    if (l==k+1) sumrank[l+1]=sumrank[l];
                                    else if (l%2==0) sumrank[l+1]=x2;
                                    else sumrank[l+1]=x1;
                                    
                                    for (int p=0; p<gene; p++)
                                    {
                                        if (l%2==0) xr1[p]=rank[l+1][p];
                                        else xr2[p]=rank[l+1][p];
                                        if (l==k+1) rank[l+1][p]=rank[l][p];
                                        else if (l%2==0) rank[l+1][p]=xr2[p];
                                        else rank[l+1][p]=xr1[p];
                                        
                                    }
                                    break;
                                }
                            }
                        }
                        sumrank[k+1]=sum;
                        for (int p=0; p<gene; p++)
                            rank[k+1][p]=population[i][p];
                        break;
                    }
                    
                    
                }
                
                else
                {
                    for (int l=k; l<individ; l++)
                    {
                        if (sumrank[l]!=0)
                        {
                            if (sumrank[l+1]!=0)
                            {
                                if (l%2==0) x1 = sumrank[l+1];
                                else x2 = sumrank[l+1];
                                
                                if (l==k) sumrank[l+1]=sumrank[l];
                                else if (l%2==0) sumrank[l+1]=x2;
                                else sumrank[l+1]=x1;
                                
                                for (int p=0; p<gene; p++)
                                {
                                    if (l%2==0) xr1[p]=rank[l+1][p];
                                    else xr2[p]=rank[l+1][p];
                                    if (l==k) rank[l+1][p]=rank[l][p];
                                    else if (l%2==0) rank[l+1][p]=xr2[p];
                                    else rank[l+1][p]=xr1[p];
                                }
                            }
                            else
                            {
                                if (l%2==0) x1 = sumrank[l+1];
                                else x2 = sumrank[l+1];
                                
                                if (l==k) sumrank[l+1]=sumrank[l];
                                else if (l%2==0) sumrank[l+1]=x2;
                                else sumrank[l+1]=x1;
                                
                                for (int p=0; p<gene; p++)
                                {
                                    if (l%2==0) xr1[p]=rank[l+1][p];
                                    else xr2[p]=rank[l+1][p];
                                    if (l==k) rank[l+1][p]=rank[l][p];
                                    else if (l%2==0) rank[l+1][p]=xr2[p];
                                    else rank[l+1][p]=xr1[p];
                                    
                                }
                                break;
                            }
                        }
                        
                    }
                    sumrank[k]=sum;
                    for (int p=0; p<gene; p++)
                        rank[k][p]=population[i][p];
                    break;
                }
            }
            
        }
        
        for (int i=0; i<individ; i++)
        {
            for (int j=0; j<gene; j++)
            {
                population[i][j] = rank[i][j];
            }
        }
        
        /*cout<<"Ranked population (First is the shortest)"<<endl<<endl;
         
         for (int i=0; i<individ; i++)
         {
         for (int j=0; j<gene; j++)
         {
         cout << rank[i][j];
         cout<< " ";
         }
         cout << endl;
         }
         cout<<endl;*/
        
        if (sumrank[0]<min) min = sumrank[0];
        else cout << "минимум не улучшился"<<endl;
        cout << sumrank[0] << " " << min << endl;
		for (int i = 0; i<gene; i++)
			cout << population[0][i];
        cout << endl << endl;
        
        double prob[individ] = {0};//определение условных вероятностей
        for (int i=0; i<individ; i++)
        {
            prob[i] = (100-i)/5050.f;
        }
        
        /*double summa = 0;
         for (int i=0; i<individ; i++)
         {
         summa = summa + prob[i];
         //cout << prob[i];
         //cout<< " ";
         }
         cout<<endl;*/
        
        
        int new_population[individ][gene] = {0,0};
        int check[2][gene];
        
        
        for (int i=0; i<individ; i++)
        {
			cout << i << " ";
            int cross[2][gene] = {0,0};
            int iter = 0;
            while (iter<2)
            {
                double point = (rand() % 100000)/100000.0;
                //cout<<point<<endl;
                int i = -1;
                double ind = 0;
                do
                {
                    i++;
                    ind = ind+prob[i];
                }
                while (point>ind);
                
                for(int j=0; j<gene; j++)
                    cross[iter][j] = population[i][j];
                
                /*sum = 0;
                 for (int j=0; j<(gene-1); j++)//проходим по генам. Длина
                 {
                 sum = sum + mas[population[i][j]][population[i][j+1]];
                 
                 }
                 if (sum == 167)
                 {
                 for (int l=0; l<gene; l++)
                 check [iter][l]=cross[iter][l];
                 }*/
                
                
                for(int j=0; j<gene; j++)//запрет на скрещивание индивида с собой
                {
                    if (cross[1][j] == cross[0][j])
                        repeat = true;
                    else
                    {
                        repeat = false;
                        break;
                    }
                }
                if (repeat == true)
                    iter--;
                
                iter++;
            }
            //пойти на индивида ещё раз. Зачем, пусть идёт на while заново
            
            int devide = 0;
            devide = rand()%9+1;
            for(int j=0; j<devide; j++)
            {
                new_population[i][j] = cross[0][j];
            }
            for(int j=devide; j<10; j++)
                new_population[i][j] = cross[1][j];
            
            
            
            for (int j=0; j<gene; j++)
            {
                for (int k=0; k<j; k++) //проверка на повторение генов внутри индивида
                {
                    if (new_population[i][j] == new_population[i][k])//берётся очередной ген и проверяется одинаковость с предыдущими
                    {
                        repeat = true;
                        break;
                    }
                }
                if (repeat == true) break;
            }
            if (repeat == true)
            {
                i--;
                repeat = false;
            }
            else
             {
             bool same = false;
             for(int k=0; k<i; k++)//проверка на повторение индивидов в новом поколении
             {
             for(int j=0; j<gene; j++)
             {
             if (new_population[k][j] == new_population[i][j])//берутся по очереди индивиды и сравниваются гены с текущим индивидом
             same = true;
             else
             {
             same = false;
             break;
             }
             }
             if (same == true)
             {
             i--;
             same = false;
             }
             }
             }
             /*   for(int j=0; j<gene; j++)
             cout << new_population[i][j];
             cout<<endl;*/
            
            
        }
        
        for (int i=0; i<individ; i++)
        {
            for (int j=0; j<gene; j++)
            {
                population[i][j] = new_population[i][j];
                new_population[i][j] = 0;
            }
        }
        
        generation++;
    }
    
    
    /*  for(int j=0; j<gene; j++)
     cout << cross[0][j];
     cout<<endl;
     
     
     for(int j=0; j<gene; j++)
     cout << cross[1][j];
     cout<<endl;*/
    
    
    
    //И вот почему нули?
    //Просто попробуй сам что-нибудь написать. Я сейчас у себя попробую. Кек
    
    //самый короткий
    /*int min = 100000000;
     int sum = 0;
     int num = 0;
     for (int i=0; i<individ; i++)
     {
     for (int j=0; j<gene-1; j++)
     {
     sum = sum + mas[population[i][j]][population[i][j+1]];
     }
     if (sum < min)
     {
     min = sum;
     num = i;
     }
     }
     
     cout << min << num;*/
    
	system ("pause");
    return 0;
}

