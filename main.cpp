#include <iostream>
#include <cstdint>
#include <cstring>
#include <cstddef>

using namespace std;

#define uint8 uint8_t
#define uint16 uint16_t
#define uint32 uint32_t
#define int8 int8_t
#define int16 int16_t
#define int32 int32_t
#define FALSE false
#define TRUE true
// Constant Definition
static const uint16_t DEATH_AGE = 80;

enum eCostTypes
{
    Meals = 0,
    Drinks,
    Gas,
    Mortgage,
    Dating
};

struct cost_t
{
	float meals;
	float drinks;
	float gas;
	float mortgage;
	float dating;
};

class CPerson
{
public:
		CPerson(uint16_t input_age){
			memset(&m_cost, 0, sizeof(m_cost));
			m_age = input_age;
			m_life_time = DEATH_AGE - m_age;
			cout << "Person object initialized.\nAge = " << m_age << "\tlife_duration: " << m_life_time << endl;
		}
		~CPerson();

		void Display(eCostTypes eCost)
		{
				switch (eCost){
				case Meals:
						cout << m_cost.meals << "\t\t\t" << m_cost.meals * 365 * 10 << "\t\t" << m_cost.meals * 365 * 30
								<< "\t\t" << m_cost.meals * 365 * m_life_time << endl;
        		break; 
		 		case Drinks:
						cout << m_cost.drinks << "\t\t\t" << m_cost.drinks * 365 * 10 << "\t\t" << m_cost.drinks * 365 * 30
						        << "\t\t" << m_cost.drinks * 365 * m_life_time << endl;
                break;
				case Gas:
						cout << m_cost.gas << "\t\t\t" << m_cost.gas * 365 * 10 << "\t\t" << m_cost.gas * 365 * 30
						        << "\t\t" << m_cost.gas * 365 * m_life_time << endl;
                break;
				case Mortgage:
						cout << m_cost.mortgage << "\t\t" << m_cost.mortgage * 365 * 10 << "\t\t" << m_cost.mortgage * 365 * 30
						        << "\t\t" << m_cost.mortgage * 365 * m_life_time << endl;
                break;
				case Dating:
						cout << m_cost.dating << "\t\t\t" << m_cost.dating * 365 * 10 << "\t\t" << m_cost.dating * 365 * 30
						         << "\t\t" << m_cost.dating * 365 * m_life_time << endl;
				break;
				default:
						cout << "Invalid option to display!" << endl;
				break;
				}
		}
		
		// This is the change the cost amount within member structure
		void ModifySetting(uint16_t item_num, float amount)
		{
				// Error checking: Amount need >= 0
				if (amount < 0)
				{
					cout << "Invalid amount" << amount << "!!! Will not modify.\n";
					item_num = 9999;
				}
				switch (item_num){
						case 1:
							m_cost.meals = amount;
						case 2:
							m_cost.drinks = amount;
						case 3:
							m_cost.gas = amount;
						case 4:
							m_cost.mortgage = amount;
						case 5:
							m_cost.dating = amount;
						default:
							cout << "Invalid item chosen!\n";
				}
		}
private:
	cost_t m_cost;
	uint16_t m_age;
	uint16_t m_life_time;
};

// Forward Declaration
void DisplayMenu(CPerson*);

// Main Function
int main()
{
		uint16_t cur_age;
		bool exit = FALSE;
		system("clear");
		cout << "Enter your age: ";
		cin >> cur_age;
		// Init CPerson Object
		CPerson* MainPerson = new CPerson(cur_age);
do
{
		cout << "=================================================================================\n";
		cout << "Choose an option: \n1. Display Menu \n2. Modify your cost setting\n3. Exit"<< endl;
		int nOption;
		cin >> nOption;
		switch (nOption){
			case 1:
			{	
				DisplayMenu(MainPerson);
				break;
			}
			case 2:
			{
				uint16_t item_num = 9999;
				float amount = 0.0f;
				cout << "Enter the item to be modified and amount: ";
				cin >> item_num >> amount;
				MainPerson->ModifySetting(item_num, amount);
				break;
			}
			case 3:
			{
				printf("Exiting the program!\n");
				exit = TRUE;
				break;
			}
			default:
			{
				printf("Incorrect input");
				break;
			}	
		}
}while(!exit);
		return 0;
}

void DisplayMenu(CPerson* MainPerson)
{
		cout << "\n\n\n\n\n";
		cout << "=======================================================================\n";
		cout << "|                Richard's Cost Analysis for Life Time(80)            |\n";
		cout << "=======================================================================\n";
		cout << "Itemized Cost\tDaily Cost\t10 Years Cost\t30 Years Cost\tLifeTime Cost\n";
		cout << "1. Meals\t"; 
		(void)MainPerson->Display(Meals);
		cout << "2. Drinks\t";
		(void)MainPerson->Display(Drinks);
		cout << "3. Gas\t\t";
		(void)MainPerson->Display(Gas);
		cout << "4. Mortgage Or Housing\t";
		(void)MainPerson->Display(Mortgage);
		cout << "5. Dating\t";
		(void)MainPerson->Display(Dating);
}
