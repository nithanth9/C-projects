//Header Section    Nithanth Sivakumar  Final Exam
//This program will calculate the tax based on the selected filing status and the taxable income. 
#include <iostream>
#include<string>
using namespace std;
//declaring variables
int getStatusData();
float getTaxableIncome();
float calcTaxAmount(int, float);
void displayResults(int, float, float);
string fillingStatus[4] = { "Single filer","Married filling jointly", "Married filling separately", "Head of the household" };

int main()//main function
{
	int statusCode = 0;
	statusCode = getStatusData();

	float taxableIncome = 0.0;
	taxableIncome = getTaxableIncome();

	float taxAmount = 0.0;
	taxAmount = calcTaxAmount(statusCode, taxableIncome);
	displayResults(statusCode, taxableIncome, taxAmount);
	return 0;
}

int getStatusData()//Function that will ask the user to input their filing status. Will show an error message if an unrecognized filing status number is entered.
{
	int state;

	cout << "Status Code Descriptions : " << endl;
	cout << "1. Single filer" << endl;
	cout << "2. Married filing jointly" << endl;
	cout << "3. Married filing separately" << endl;
	cout << "4. Head of the household" << endl;
	cout << "9. Exit " << endl;
	do
	{
		cout << "Enter your filing status code : ";
		cin >> state;

		if ((state <= 9 && state > 4) || state > 9)
		{
			cout << "Wrong Input. Enter an acceptable number. " << endl;
			continue;
		}

	} while ((state <= 9 && state > 4) || state > 9);

	return state;
}

float getTaxableIncome()//Function that asks the user to enter the taxable income and wil show an error message if the taxable income entered is less than or equal to 3000.
{

	float taxIncome;
	do
	{
		cout << endl << "Enter the Taxable income : ";
		cin >> taxIncome;

		if (taxIncome <= 3000)
		{
			cout << "Taxable income should be greater than 3000 " << endl;
			continue;
		}
	} while (taxIncome <= 3000);

	return taxIncome;

}

float calcTaxAmount(int statusCode, float taxableIncome)//Function that will calculated the tax from the taxable income.
{

	float taxAmount = 0.0;
	float taxRate[6] = { 12, 16, 20, 28, 32, 40 };

	if (statusCode == 1)
	{
		if (taxableIncome < 7550)
			taxAmount = (taxRate[0] / 100)* taxableIncome;

		else if (taxableIncome < 30650)
			taxAmount = ((taxRate[1] / 100) * (taxableIncome - 7550)) + 906;

		else if (taxableIncome < 74200)
			taxAmount = ((taxRate[2] / 100) * (taxableIncome - 30650)) + 906 + 3696;

		else if (taxableIncome < 154800)
			taxAmount = ((taxRate[3] / 100) * (taxableIncome - 74200)) + 906 + 3696 + 8710;

		else if (taxableIncome < 336550)
			taxableIncome = ((taxRate[4] / 100) * (taxableIncome - 154800)) + 906 + 3696 + 8710 + 22568;

		else if (taxableIncome > 336550)
			taxableIncome = ((taxRate[5] / 100) * (taxableIncome - 336550)) + 906 + 3696 + 8710 + 22568 + 58160;

	}
	else if (statusCode == 2)
	{

		if (taxableIncome < 15100)
			taxAmount = (taxRate[0] / 100) * taxableIncome;

		else if (taxableIncome < 61300)
			taxAmount = ((taxRate[1] / 100) * (taxableIncome - 15100)) + 1812;

		else if (taxableIncome < 123700)
			taxAmount = ((taxRate[2] / 100) * (taxableIncome - 61300)) + 1812 + 7392;

		else if (taxableIncome < 188450)
			taxAmount = ((taxRate[3] / 100) * (taxableIncome - 123700)) + 1812 + 7392 + 12480;

		else if (taxableIncome < 336550)
			taxableIncome = ((taxRate[4] / 100) * (taxableIncome - 188450)) + 1812 + 7392 + 12480 + 18130;

		else if (taxableIncome > 336550)
			taxableIncome = ((taxRate[5] / 100) * (taxableIncome - 336550)) + 1812 + 7392 + 12480 + 18130 + 47392;

	}
	else if (statusCode == 3)
	{
		if (taxableIncome < 7550)
			taxAmount = (taxRate[0] / 100)* taxableIncome;

		else if (taxableIncome < 30650)
			taxAmount = ((taxRate[1] / 100) * (taxableIncome - 7550)) + 906;

		else if (taxableIncome < 61850)
			taxAmount = ((taxRate[2] / 100) * (taxableIncome - 30650)) + 906 + 3696;

		else if (taxableIncome < 94225)
			taxAmount = ((taxRate[3] / 100) * (taxableIncome - 61850)) + 906 + 3696 + 6240;

		else if (taxableIncome < 168275)
			taxableIncome = ((taxRate[4] / 100) * (taxableIncome - 94225)) + 906 + 3696 + 6240 + 9065;

		else if (taxableIncome > 168275)
			taxableIncome = ((taxRate[5] / 100) * (taxableIncome - 168275)) + 906 + 3696 + 6240 + 9065 + 23696;
	}
	else if (statusCode == 4)
	{
		if (taxableIncome < 10750)
			taxAmount = (taxRate[0] / 100) * taxableIncome;

		else if (taxableIncome < 41050)
			taxAmount = ((taxRate[1] / 100) * (taxableIncome - 10750)) + 1290;

		else if (taxableIncome < 106000)
			taxAmount = ((taxRate[2] / 100) * (taxableIncome - 41050)) + 1290 + 4848;

		else if (taxableIncome < 171650)
			taxAmount = ((taxRate[3] / 100) * (taxableIncome - 106000)) + 1290 + 4848 + 12990;

		else if (taxableIncome < 336550)
			taxableIncome = ((taxRate[4] / 100) * (taxableIncome - 171650)) + 1290 + 4848 + 12990 + 18382;

		else if (taxableIncome > 336550)
			taxableIncome = ((taxRate[5] / 100) * (taxableIncome - 336550)) + 1290 + 4848 + 12990 + 18382 + 52768;
	}

	return taxAmount;
}

void displayResults(int statusCode, float taxableIncome, float taxAmount)//Function that will display the filing status, taxable income, and tax amount using cout statements.
{

	cout << endl;
	cout << "Filing Status : " << fillingStatus[statusCode - 1] << endl;
	cout << "Taxable income : " << taxableIncome << endl;
	cout << "Tax amount : " << taxAmount << endl;

}