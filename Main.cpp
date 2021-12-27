#include "Sale.h"
#include <vector>
void main()
{
	int Choice;
	pNode* pHead = NULL;
	sNode* sHead = NULL;
	oNode* oHead = NULL;
	readListOfProductsFromFile(pHead, "product.bin");
	readListOfStaffsFromFile(sHead, "staff.bin");
	readListOfOrdersFromFile(oHead, "order.bin");
	bool flagLogin = LoginFunction(sHead);
	while (flagLogin == true)
	{
		do 
		{
			system("cls");
			Menu();
			choice(Choice, 9);
			MainMenuFunction(pHead, sHead, oHead, Choice);
		} while (Choice!=8 && Choice != 9);

		if (Choice == 8)
		{
			flagLogin = LoginFunction(sHead);
		}
		else break;
	}
	writeListOfProductsToFile(pHead, "product.bin");
	writeListOfStaffsToFile(sHead, "staff.bin");
	writeListOfOrdersToFile(oHead, "order.bin");

	releaseProductList(pHead);
	releaseStaffList(sHead);
	releaseOrderList(oHead);
}