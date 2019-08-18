#include<iostream>
#include<conio.h>
using namespace std;
#define SIZE 5
struct process
{
	int srn;
	int Pid;
	int AT;
	int BT;
	int FT;
	int TAT;
	int WT;
};
int main()
{
	struct process P[SIZE];
	struct process temp;
	int arr[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		P[i].Pid = arr[i];
	}
	cout << "Enter the Arrival Time For The 5 Processes: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		P[i].AT = arr[i];
	}
	cout << "Enter The Burst Time For The 5 Processes:";
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		P[i].BT = arr[i];
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (P[j].AT > P[j + 1].AT)
			{
				temp = P[j];
				P[j] = P[j + 1];
				P[j + 1] = temp;
			}
		}
	}
	//FT
	P[-1].FT = 0;
	for (int i = 0; i < SIZE; i++)
	{
		P[i].FT = P[i].BT + P[i - 1].FT;
	}
	//TAT
	for (int i = 0; i < SIZE; i++)
	{
		P[i].TAT = P[i].FT - P[i].AT;
	}
	//WT
	for (int i = 0; i < SIZE; i++)
	{
		P[i].WT = P[i].TAT - P[i].BT;
	}
	cout << "Pid		AT		BT		FT		TAT		WT" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << P[i].Pid << "		" << P[i].AT << "		" << P[i].BT << "		" << P[i].FT << "		" << P[i].TAT << "		" << P[i].WT << endl;
	}
	cout << endl;
	//avgtat
	float avgtat = 0;
	for (int i = 0; i < SIZE; i++)
	{
		avgtat = avgtat + P[i].TAT;
	}
	avgtat = avgtat / 5;
	//avgwt
	float avgwt = 0;
	for (int i = 0; i < SIZE; i++)
	{
		avgwt = avgwt + P[i].WT;
	}
	avgwt = avgwt / 5;
	cout << "Average turn around time is :" << avgtat << " sec" << endl;
	cout << "Average wait time is :" << avgwt << " sec" << endl;
	_getch();
	return 0;
}