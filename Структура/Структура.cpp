// Створіть структуру, що описує простий дріб. Реалізуйте арифметичні операції з дробами: суму, різницю, множення, ділення. 
//Врахувати можливість скорочення дробів і перетворення з неправильного дробу на простий.
#include <iostream>
#include<Windows.h>
#include<algorithm>
using namespace std;
struct Drob {
	int chiselnyk;//чисельник дробу
	int znamennyk;//знаменник дробу
	int x;//число яке додається до дроба чи віднімається або на яке множиться або ділиться дріб	
	int NOD(int chiselnyk, int  znamennyk)// ф-н пошук найбільшого спілього дільника
	{
		if (znamennyk == 0) return chiselnyk;
		return NOD(znamennyk, chiselnyk % znamennyk);
	}
	void reduce()//ф-н скорочеення дроба
	{
		int nod = NOD(chiselnyk, znamennyk);
		chiselnyk /= nod;
		znamennyk /= nod;
		cout << "Перетворений дріб =  " << chiselnyk<<"/"<<znamennyk<<endl;
	}
	void inputDrob()//ф-н введення чисельника і знаменника
	{
		cout << "Введіть чисельник :";
		cin>> chiselnyk;
		cout << "Введіть знаменник :";
		cin>> znamennyk;
	}
	void mnozhDrob()//ф-н множення дроба на число
	{
		cout << "Введіть множник" << endl;
		cin >> x;
		chiselnyk *= x;
		cout << "Дроб:  " << chiselnyk << '/' << znamennyk << endl;
	}
	void dilDrob()//ф-н ділення дроба а число
	{
		cout << "Введіть дільник" << endl;
		cin >> x;
		znamennyk *= x;
		cout << "Дроб:  " << chiselnyk << '/' << znamennyk << endl;

	}
	void sumDrob()//ф-н додавання до дроба числа
	{
		cout << "Введіть доданок" << endl;
		cin >> x;
		chiselnyk += (x * znamennyk);
		cout << "Дроб:  " << chiselnyk << '/' << znamennyk << endl;
	}
	void vidDrob()//ф-н віднімання від дроба числа
	{
		cout << "Введіть від'ємник" << endl;
		cin >> x;
		chiselnyk -= (x * znamennyk);
		cout << "Дроб:  " << chiselnyk << '/' << znamennyk << endl;

	}
	void printDrob()//ф-н друку дроба
	{
		cout << "Введений дріб :  " << chiselnyk << '/' << znamennyk << endl;
	}
	void peretvorDrob() {//ф-н перетворення дроба з неправильного на простий
		int ch;
		int newch;
		if ((chiselnyk > znamennyk)&&(znamennyk >1)) {
			ch= chiselnyk / znamennyk;
			newch = chiselnyk - (ch * znamennyk);
			cout << ch << " цілі " << newch << '/' << znamennyk;
		}
		else if( znamennyk == 1) {
			cout << "Перетворений дріб =  "<<chiselnyk<<endl;

		}
	}	
};
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int  m=0;
	Drob drib;
	drib.inputDrob();	//ф-н введення чисельника і знаменника
	drib.printDrob();//ф-н друку дроба

    cout << "1:Додати число до дроба :" << endl<<endl;
	cout << "2:Відняти від дроба число :" << endl<<endl;
	cout << "3:Помножити дроб на число :" << endl<<endl;
	cout << "4:Поділити дроб на число :" << endl<<endl;
	cout << "\nВиберіть необхідну функцію  :" << '\n';
	
	cin >> m;
		switch (m)
		{
		case 1:
			drib.sumDrob();//ф-н додавання до дроба число
			drib.reduce();//ф-н скорочеення дроба
			drib.peretvorDrob();//ф-н перетворення дроба з неправильного на простий
			break;
		case 2:			
			drib.vidDrob();//ф-н віднімання від дроба числа
			drib.reduce();//ф-н скорочеення дроба
			drib.peretvorDrob();//ф-н перетворення дроба з неправильного на простий
			break;
		case 3:			
			drib.mnozhDrob();//ф-н множення дроба на число
			drib.reduce();//ф-н скорочеення дроба
			drib.peretvorDrob();//ф-н перетворення дроба з неправильного на простий
			break;
		case 4:
			drib.dilDrob();//ф-н ділення дроба на число
			drib.reduce();//ф-н скорочеення дроба
			drib.peretvorDrob();//ф-н перетворення дроба з неправильного на простий
			break;
		default: {
			cout << "Ви ввели не коректну функцію " << endl;
			 }
		}	
	return 0;
}