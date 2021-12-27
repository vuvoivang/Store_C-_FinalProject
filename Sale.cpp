#include "Sale.h"
void LoginMenu()
{
	system("cls");
	cout << "-------[GIAO DIEN DANG NHAP]-------" << endl;
	cout << "(1) Dang nhap." << endl;
	cout << "(2) Thoat." << endl;
}
void Menu()
{
	system("cls");
	cout << "-----------[QUAN LI CUA HANG]-----------" << endl;
	cout << "(1) Them/Xoa/Sua danh sach san pham." << endl;
	cout << "(2) Them/Xoa/Sua danh sach nhan vien." << endl;
	cout << "(3) Tao don hang." << endl;
	cout << "(4) Thong ke so luong don hang va tong doanh thu theo ngay." << endl;
	cout << "(5) Xuat tat ca san pham cua cua hang." << endl;
	cout << "(6) Xuat thong tin tat ca nhan vien cua cua hang." << endl;
	cout << "(7) Xuat tat ca don hang cua cua hang." << endl;
	cout << "(8) Dang xuat." << endl;
	cout << "(9) Thoat." << endl;
}
void SubMenuProduct()
{
	system("cls");
	cout << "-----[GIAO DIEN SAN PHAM]------" << endl;
	cout << "(1) Them mot san pham." << endl;
	cout << "(2) Xoa mot san pham." << endl;
	cout << "(3) Sua mot san pham." << endl;
	cout << "(4) Quay lai giao dien quan li cua hang." << endl;
}
void SubMenuStaff()
{
	system("cls");
	cout << "-----[QUAN LY NHAN VIEN]------" << endl;
	cout << "(1) Them mot nhan vien." << endl;
	cout << "(2) Xoa mot nhan vien." << endl;
	cout << "(3) Sua mot nhan vien." << endl;
	cout << "(4) Quay lai giao dien quan li cua hang." << endl;
}
void inputAPositiveNum(int& a)  // Hàm dùng để nhập một số nguyên dương kiểu int, kiểm tra điều kiện nhập chặt chẽ
{
	cin >> a;
	bool T = cin.fail();
	while (T || a <= 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le. Vui long nhap lai: ";
		cin >> a;
		T = cin.fail();
	}
}
bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int theDaysOfMonth(int month, int year) //Tinh so ngay cua thang tuong ung voi nam
{
	int numberOfDays;
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		numberOfDays = 31;
		break;
	case 4: case 6: case 9: case 11:
		numberOfDays = 30;
		break;
	case 2:
		if (isLeapYear(year))
		{
			numberOfDays = 29;
		}
		else
		{
			numberOfDays = 28;
		}
		break;
	}

	return numberOfDays;
}
void inputDay(Day& day)
{
	cout << "Nhap thang (1=< thang =<12): ";
	inputAPositiveNum(day.month);
	while (day.month > 12)
	{
		cout << "Khong hop le. Vui long nhap lai: ";
		inputAPositiveNum(day.month);
	}
	cout << "Nhap nam (>0) :";
	inputAPositiveNum(day.year);
	int theMaxDaysOfMonth = theDaysOfMonth(day.month, day.year);
	cout << "Nhap ngay (1=< ngay =<"<<theMaxDaysOfMonth<<"): ";
	inputAPositiveNum(day.day);
	while (day.day > theMaxDaysOfMonth)
	{
		cout << "Khong hop le. Vui long nhap lai ngay phu hop : ";
		inputAPositiveNum(day.day);
	}

}
bool isExistIDProduct(char* s, pNode* head)  
{
	pNode* p = head;
	while (p != NULL)
	{
		if (strcmp(s, p->pduct.ID) == 0) return true;
		p = p->pNext;
	}
	return false;
}
void inputStringWithLimitOfLength(char s[], int maxLength)
{
	char temp[101];
	cin.getline(temp, 101);
	while (strlen(temp) > maxLength)
	{
		cout << "Ban da nhap qua so luong ky tu toi da. Vui long nhap lai : " << endl;
		cin.getline(temp, 101);
	}
	strcpy(s, temp);
} 
void outputAProduct(product p)
{
	cout << "Ma san pham : " << p.ID << endl;
	cout << "Ten san pham : " << p.name << endl;
	cout << "Loai san pham : " << p.type << endl;
	cout << "Gia san pham : " << p.price << " dong" << endl;
}
void outputAStaff(staff s)
{
	cout << "Ma nhan vien : " << s.ID << endl;
	cout << "Ten dang nhap : " << s.loginName << endl;
	cout << "Mat khau : " << s.password << endl;
	cout << "Ho va ten : " << s.Name << endl;
}
void outputAnOrder(order o)
{
	cout << "Ngay tao don hang : " << o.dayCreate.day << "/" << o.dayCreate.month << "/" << o.dayCreate.year << endl;
	cout << "------ Danh sach cac san pham ------" << endl;
	for (int i = 0; i < o.n; i++)
	{
		cout << "San pham thu " << i + 1 << " :" << endl;
		outputAProduct(o.Product[i]);
		cout << "So luong cua san pham nay duoc mua : " << o.amountOfEveryProduct[i] << endl;
		cout << "-------------------" << endl;
	}
}

void inputAProduct(product& p, pNode* head)
{
	cout << "Nhap ma san pham (toi da 20 ky tu, la duy nhat): ";
	inputStringWithLimitOfLength(p.ID, 20);
	while (isExistIDProduct(p.ID,head))
	{
		system("cls");
		cout << "Ma san pham cua ban nhap da ton tai!" << endl;
		cout << "Nhap lai ma cua san pham : ";
		inputStringWithLimitOfLength(p.ID, 20);
	}
	cout << "Nhap ten san pham (toi da 50 ky tu): ";
	inputStringWithLimitOfLength(p.name, 50);
	cout << "Nhap loai san pham (toi da 20 ky tu): ";
	inputStringWithLimitOfLength(p.type, 20);
	cout << "Nhap gia san pham (>0,don vi la dong) : ";
	inputAPositiveNum(p.price);
}
pNode* makeProductNode(product P) //Tạo node
{
	pNode* p = new pNode;
	if (p != NULL)
	{
		p->pduct = P;
		p->pNext = NULL;
	}
	return p;


}
bool addProductLast(pNode*& head, product P)
{
	pNode* p = makeProductNode(P);
	pNode* temp = head;
	if (p == NULL) return false;
	if (head == NULL)
	{
		head = p;
	}
	else {
		while (temp->pNext != NULL) temp = temp->pNext;
		temp->pNext = p;
	}
	return true;
}
bool addAProduct(pNode*& head)
{
	product p;
	inputAProduct(p,head);
	bool flag = addProductLast(head, p);
	return flag;
}
bool deleteAProduct(pNode*& head)
{
	pNode* p = head;
	if (p == NULL)
	{
		cout << "Danh sach khong co san pham nao.";
		return false;
	}
	char* ID = new char[21];
	if (ID == NULL) return false;
	cout << "Nhap ma san pham can xoa (toi da 20 ky tu): ";
	inputStringWithLimitOfLength(ID, 20);
	system("cls");
	bool isFound = false;
	if (strcmp(head->pduct.ID, ID) == 0)   // Kiem tra xoa o dau danh sach thi cap nhat lai head
	{
		cout << "** San pham duoc xoa ** " << endl;
		outputAProduct(p->pduct);
		head = head->pNext;
		delete p;
		isFound = true;

	}
	else 
	{
		pNode* preP = p;
		p = p->pNext;
		while (p != NULL)
		{
			if (strcmp(p->pduct.ID,ID) == 0)   
			{
				cout << "** San pham duoc xoa ** " << endl;
				outputAProduct(p->pduct);
				preP->pNext = p->pNext;
				delete p;
				isFound = true;
				break;
			}
			preP = p;
			p = p->pNext;
		}
	}
	if (!isFound) cout << "Khong the tim thay san pham co ma vua nhap.";
	delete[] ID;
	return isFound;
}
bool changeAProduct(pNode*& head)
{
	pNode* p = head;
	if (p == NULL)
	{
		cout << "Danh sach khong co san pham nao.";
		return false;
	}
	char* ID = new char[21];
	if (ID == NULL) return false;
	cout << "Nhap ma san pham can sua (toi da 20 ky tu): ";
	inputStringWithLimitOfLength(ID, 20);
	bool T = false;
	system("cls");
	while (p != NULL)
	{
		if (strcmp(p->pduct.ID, ID) == 0)
		{
			cout << "** San pham can sua ** " << endl;
			outputAProduct(p->pduct);
			cout << "Nhap cac thong tin sau de sua san pham : " << endl;
			cout << "Nhap ten san pham (toi da 50 ky tu): ";
			inputStringWithLimitOfLength(p->pduct.name, 50);
			cout << "Nhap loai san pham (toi da 20 ky tu): ";
			inputStringWithLimitOfLength(p->pduct.type, 20);
			cout << "Nhap gia san pham (>0,don vi la dong) : ";
			inputAPositiveNum(p->pduct.price);
			T = true;
			break;
		}
		p = p->pNext;
		

	}
	if (!T) cout << "Khong tim thay san pham can sua.";
	return T;
}

bool isExistIDStaff(char* s, sNode* head)
{
	sNode* p = head;
	while (p != NULL)
	{
		if (strcmp(s, p->Staff.ID) == 0) return true;
		p = p->pNext;
	}
	return false;
}
bool isExistLoginNameStaff(char* s, sNode* head)
{
	sNode* p = head;
	while (p != NULL)
	{
		if (strcmp(s, p->Staff.loginName) == 0) return true;
		p = p->pNext;
	}
	return false;
}
sNode* makeStaffNode(staff S) //Tạo node
{
	sNode* p = new sNode;
	if (p != NULL)
	{
		p->Staff = S;
		p->pNext = NULL;
	}
	return p;


}
bool addStaffLast(sNode*& head, staff S)
{
	sNode* p = makeStaffNode(S);
	sNode* temp = head;
	if (p == NULL) return false;
	if (head == NULL)
	{
		head = p;
	}
	else {
		while (temp->pNext != NULL) temp = temp->pNext;
		temp->pNext = p;
	}
	return true;
}
void inputAStaff(staff& s,sNode* head)
{
	cout << "Nhap ma nhan vien (toi da 20 ky tu,la duy nhat): ";
	inputStringWithLimitOfLength(s.ID, 20);
	while (isExistIDStaff(s.ID, head))
	{
		cout << "Ma nhan vien cua ban nhap da ton tai" << endl;
		cout << "Nhap lai ma cua nhan vien : ";
		inputStringWithLimitOfLength(s.ID, 20);
	}
	cout << "Nhap ten dang nhap (toi da 30 ky tu): ";
	inputStringWithLimitOfLength(s.loginName, 30);
	while (isExistLoginNameStaff(s.loginName, head))
	{
		cout << "Ten dang nhap da ton tai" << endl;
		cout << "Nhap lai ten dang nhap cua nhan vien : ";
		inputStringWithLimitOfLength(s.loginName, 30);
	}
	cout << "Nhap mat khau (toi da 30 ky tu): ";
	inputStringWithLimitOfLength(s.password, 30);
	cout << "Nhap ho va ten nhan vien (toi da 50 ky tu): ";
	inputStringWithLimitOfLength(s.Name, 50);

}
bool addAStaff(sNode*& head)
{
	staff p;
	inputAStaff(p, head);
	bool flag = addStaffLast(head, p);
	return flag;
}
bool deleteAStaff(sNode*& head)
{
	sNode* p = head;
	if (p == NULL)
	{
		cout << "Danh sach khong co nhan vien nao" << endl;
		system("pause");
		return false;
	}
	char* ID = new char[21];
	if (ID == NULL) return false;
	cout << "Nhap ma nhan vien can xoa (toi da 20 ky tu): ";
	inputStringWithLimitOfLength(ID, 20);
	bool isFound = false;
	system("cls");
	if (strcmp(head->Staff.ID, ID) == 0)   // Kiem tra xoa o dau danh sach thi cap nhat lai head
	{
		cout << "** Nhan vien duoc xoa ** " << endl;
		outputAStaff(head->Staff);
		head = head->pNext;
		delete p;
		isFound = true;

	}
	else {
		sNode* preP = p;
		p = p->pNext;
		while (p != NULL)
		{
			if (strcmp(p->Staff.ID,ID) == 0)
			{
				cout << "** Nhan vien duoc xoa ** " << endl;
				outputAStaff(p->Staff);
				preP->pNext = p->pNext;
				delete p;
				isFound = true;
				break;
			}
			preP = p;
			p = p->pNext;
		}
	}
	if (!isFound) cout << "Khong the tim thay nhan vien co ma vua nhap.";
	delete[] ID;
	return isFound;
}
bool changeAStaff(sNode*& head)
{
	sNode* p = head;
	if (p == NULL)
	{
		cout << "Danh sach khong co nhan vien nao" << endl;
		return false;
	}
	char* ID = new char[21];
	if (ID == NULL) return false;
	cout << "Nhap ma nhan vien can sua (toi da 20 ky tu): ";
	inputStringWithLimitOfLength(ID, 20);
	bool T = false;
	system("cls");
	while (p != NULL)
	{
		if (strcmp(p->Staff.ID, ID) == 0)
		{
			cout << "** Nhan vien ban muon thay doi ** " << endl;
			outputAStaff(p->Staff);
			cout << "Nhap cac thong tin sau de thay doi nhan vien : " << endl;
			char s[31];
			cout << "Nhap ten dang nhap (toi da 30 ky tu): ";
			inputStringWithLimitOfLength(s, 30);
			while (isExistLoginNameStaff(s, head))
			{
				if (strcmp(s, p->Staff.loginName) == 0) break;
				else
				{
					cout << "Ten dang nhap da ton tai" << endl;
					cout << "Nhap lai ten dang nhap cua nhan vien : ";
					inputStringWithLimitOfLength(s, 30);
				}
			}
			strcpy(p->Staff.loginName, s);
			cout << "Nhap mat khau (toi da 30 ky tu): ";
			inputStringWithLimitOfLength(p->Staff.password, 30);
			cout << "Nhap ho va ten nhan vien (toi da 50 ky tu): ";
			inputStringWithLimitOfLength(p->Staff.Name, 50);
			T = true;
			break;
		}
		p = p->pNext;
	}
	if (!T) cout << "Khong tim thay nhan vien can sua.";
	return T;
}

int countProducts(pNode* head)
{
	int i = 0;
	pNode* p = head;
	while (p != NULL)
	{
		i++;
		p = p->pNext;
	}
	return i;
}
pNode* findIDInListProduct(char* s, pNode* head)
{
	pNode* p = head;
	while (p != NULL)
	{
		if (strcmp(s, p->pduct.ID) == 0) return p;
		p = p->pNext;
	}
	return p;
}
bool inputAnOrder(order& o,pNode* head)
{
	if (head == NULL) //Neu danh sach san pham thuoc cua hang rong thi khong tao duoc don hang
	{
		cout << "Cua hang hien tai khong co san pham nao de ban" << endl;
		return false; 
	}
	cout << "Nhap ngay,thang,nam tao don hang:" << endl;
	inputDay(o.dayCreate);
	cout << "Nhap so luong san pham : ";
	inputAPositiveNum(o.n);
	int countProduct = countProducts(head);
	while (o.n > countProduct)
	{
		cout << "Vuot qua so luong san pham cua cua hang. Vui long nhap lai : ";
		inputAPositiveNum(o.n);
	}
	o.Product = new product[o.n];
	if (o.Product == NULL) return false;
	o.amountOfEveryProduct = new int[o.n];
	if (o.amountOfEveryProduct == NULL) return false;
	o.totalPrice = 0;
	char* ID = new char[20];
	pNode* p;
	if (ID == NULL) return false;
	for (int i = 0; i < o.n; i++)
	{
		bool flag = false;
		cout << "San pham thu " << i + 1 << " :" << endl;
		cout << "Nhap ma san pham (toi da 20 ky tu): ";
		cin.ignore();
		inputStringWithLimitOfLength(ID, 20);
		p = findIDInListProduct(ID, head);
		while (p == NULL)
		{
			cout << "Khong tim thay san pham nay.Vui long nhap lai ma san pham (toi da 20 ky tu): ";
			inputStringWithLimitOfLength(ID, 20);
			p = findIDInListProduct(ID, head);
		}
		for (int j = 0; j < i; j++) //Kiem tra ma san pham co trung voi ma san pham da nhap truoc do
		{
			if (strcmp(ID, o.Product[j].ID) == 0)
			{
				cout << "San pham co ma vua nhap da co trong don hang.San pham nay se duoc cong don." << endl;
				o.n--;
				i--;
				int temp;
				cout << "Nhap so luong cua san pham nay : ";
				inputAPositiveNum(temp);
				o.amountOfEveryProduct[j] += temp;
				o.totalPrice += o.Product[j].price * temp;
				flag = true;
				break;
			}
		}
		if (flag) continue;
		o.Product[i] = p->pduct;
		cout << "Nhap so luong cua san pham nay : ";
		inputAPositiveNum(o.amountOfEveryProduct[i]);
		o.totalPrice += o.Product[i].price * o.amountOfEveryProduct[i];
	}
	delete[] ID;
	return true;
	
}
oNode* makeOrderNode(order O) //Tạo node luu don hang
{
	oNode* p = new oNode;
	if (p != NULL)
	{
		p->Order = O;
		p->pNext = NULL;
	}
	return p;
}
bool addOrderLast(oNode*& head, order O)
{
	oNode* p = makeOrderNode(O);
	oNode* temp = head;
	if (p == NULL) return false;
	if (head == NULL)
	{
		head = p;
	}
	else {
		while (temp->pNext != NULL) temp = temp->pNext;
		temp->pNext = p;
	}
	return true;
}
bool addAnOrder(pNode* productHead,oNode*& orderHead)
{
	order O;
	bool flag1 = inputAnOrder(O, productHead);
	bool flag2 = addOrderLast(orderHead, O);
	return flag1 && flag2;
}
void satisticOfOrdersByDay(oNode*& orderHead)
{
	Day day;
	cout << "Nhap ngay can thong ke cac don hang : " << endl;
	inputDay(day);
	oNode* temp = orderHead;
	bool isFound = false;
	int i = 0;
	long long totalPriceOfDay = 0;
	system("cls");
	while (temp != NULL)
	{
		if (temp->Order.dayCreate.day == day.day && temp->Order.dayCreate.month == day.month && temp->Order.dayCreate.year == day.year)
		{
			if (!isFound)
			{
				cout << "Cac don hang trong ngay nay : " << endl;
				isFound = true;
			}
			i++;
			cout << "*** Don hang thu " << i << " :" << endl;
			outputAnOrder(temp->Order);
			totalPriceOfDay += temp->Order.totalPrice;
		}
		temp = temp->pNext;
	}
	if (isFound)
	{
		cout << "----------------------------" << endl;
		cout << "Trong ngay nay co " << i << " don hang va tong doanh thu la : " << totalPriceOfDay << " dong" << endl;
	}
	if (!isFound) cout << "Ngay nay khong co don hang nao!" << endl;

}

int countDigitOfNumber(int n)
{
	if (n < 0) n = -n;
	int i = 0;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return i;
}
bool isAllDigit(char s[])
{
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] < '0' || s[i]>'9')
		{
			return false;
		}
	}
	return true;
}
void choice(int& Choice, int numberOfChoices) // Hàm nhập lựa chọn từ người dùng, kiểm soát điều kiện rất chặt chẽ
{
	char temp[50];
	cout << "Nhap lua chon cua ban : ";
	cin.getline(temp,50);
	int countDigit = countDigitOfNumber(numberOfChoices);
	while (1)
	{
		while (strlen(temp) > countDigit || !isAllDigit(temp))
		{
			cout << "Khong hop le. Vui long nhap lai lua chon : ";
			cin.getline(temp, 50);
		}
		Choice = atoi(temp);
		if (Choice < 1 || Choice > numberOfChoices)
		{
			cout << "Khong hop le. Vui long nhap lai lua chon : ";
			cin.getline(temp, 50);
		}
		else break;
	};
	system("cls");
}
bool LoginFunction(sNode* head) 
{
	system("cls");
	LoginMenu();
	int numberChoice;
	choice(numberChoice, 2);
	if (numberChoice == 1)
	{
		char LoginName[31], Password[31];
		cout << "Nhap ten dang nhap (toi da 30 ky tu): ";
		inputStringWithLimitOfLength(LoginName, 30);
		cout << "Nhap mat khau (toi da 30 ky tu): ";
		inputStringWithLimitOfLength(Password, 30);
		system("cls");
		if (strcmp(LoginName, "Admin") == 0 && strcmp(Password, "123456") == 0)
		{
			cout << "Dang nhap thanh cong!" << endl;
			system("pause");
			return true;
		}
		else
		{
			sNode* temp = head;
			if (temp == NULL)
			{
				cout << "Dang nhap that bai vi tai khoan khong ton tai" << endl;
				system("pause");
				return LoginFunction(head);
			}
			bool flag = false;
			while (temp != NULL)
			{
				if (strcmp(LoginName, temp->Staff.loginName) == 0)
				{
					if (strcmp(Password, temp->Staff.password) == 0)
					{
						cout << "Dang nhap thanh cong!" << endl;
						system("pause");
						flag = true;
						return true;
					}
					else
					{
						cout << "Dang nhap that bai.Mat khau chua dung" << endl;
						system("pause");
						system("cls");
						return LoginFunction(head);
					}
				}
				temp = temp->pNext;
			}
			if (!flag)
			{
				cout << "Dang nhap that bai vi tai khoan khong ton tai" << endl;
				system("pause");
				system("cls");
				return LoginFunction(head);
			}

		}
	}
	else return false;
}
void MainMenuFunction(pNode*& pHead, sNode*& sHead, oNode*& oHead, int Choice)
{
	bool flag;
	switch (Choice)
	{
	case 1:
		RunProductMenu(pHead);
		break;
	case 2:
		RunStaffMenu(sHead);
		break;
	case 3:
		flag = addAnOrder(pHead, oHead);
		if (flag)
		{
			cin.ignore();
			system("cls");
		}
		if (flag) cout << "Tao don hang thanh cong" << endl;
		else cout << "Tao don hang that bai " << endl;
		system("pause");
		break;
	case 4:
		satisticOfOrdersByDay(oHead);
		system("pause");
		cin.ignore();
		break;
	case 5:
		outputListOfProducts(pHead);
		system("pause");
		break;
	case 6:
		outputListOfStaffs(sHead);
		system("pause");
		break;
	case 7:
		outputListOfOrders(oHead);
		system("pause");
		break;

	case 8:
		cout << "Dang xuat thanh cong!" << endl;
		system("pause");
		break;
	case 9:
		break;

	}
}
void RunProductMenu(pNode*& pHead)
{
	int numberChoice;
	bool flag;
	do
	{
		system("cls");
		SubMenuProduct();
		choice(numberChoice, 4);
		switch (numberChoice)
		{
		case 1:
			flag = addAProduct(pHead);
			if(flag) cin.ignore();
			system("cls");
			if (flag) cout << "Them vao thanh cong" << endl;
			else cout << "Them vao that bai " << endl;
			system("pause");
			break;
		case 2:
			flag = deleteAProduct(pHead);
			if (flag) cout << "Xoa thanh cong" << endl;
			else cout << "Xoa that bai " << endl;
			system("pause");
			break;
		case 3:
			flag = changeAProduct(pHead);
			if(flag) cin.ignore();
			if (flag) cout << "Sua thanh cong" << endl;
			else cout << "Sua that bai " << endl;
			system("pause");
			break;
		case 4:
			break;
		}
	} while (numberChoice != 4);
}
void RunStaffMenu(sNode*& sHead)
{
	int numberChoice;
	bool flag;
	do
	{
		system("cls");
		SubMenuStaff();
		choice(numberChoice, 4);
		switch (numberChoice)
		{
		case 1:
			flag = addAStaff(sHead);
			system("cls");
			if (flag) cout << "Them vao thanh cong" << endl;
			else cout << "Them vao that bai " << endl;
			system("pause");
			break;
		case 2:
			flag  = deleteAStaff(sHead);
			if (flag) cout << "Xoa thanh cong" << endl;
			else cout << "Xoa that bai " << endl;
			system("pause");
			break;
		case 3:
			flag = changeAStaff(sHead);
			if (flag) cout << "Sua thanh cong" << endl;
			else cout << "Sua that bai " << endl;
			system("pause");
			break;
		case 4:
			break;

		}
	} while (numberChoice != 4);
}
void readListOfProductsFromFile(pNode*& pHead, const char* inputFile)
{
	ifstream fIn(inputFile, ios::in | ios::binary | ios::ate);
	if (fIn.is_open())
	{
		product temp;
		int n = (int)fIn.tellg() / sizeof(product);
		fIn.seekg(0, ios::beg);
		for (int i = 0; i < n; i++)
		{
			fIn.read((char*)&temp, sizeof(product));
			addProductLast(pHead, temp);
		}
		fIn.close();
	}
}
void readListOfStaffsFromFile(sNode*& sHead, const char* inputFile)
{
	ifstream fIn(inputFile, ios::in | ios::binary | ios::ate);
	if (fIn.is_open())
	{
		staff temp;
		int n = (int)fIn.tellg() / sizeof(staff);
		fIn.seekg(0, ios::beg);
		for (int i = 0; i < n; i++)
		{
			fIn.read((char*)&temp, sizeof(staff));
			addStaffLast(sHead, temp);
		}
		fIn.close();
	}
}
void readListOfOrdersFromFile(oNode*& oHead, const char* inputFile)
{
	ifstream fIn(inputFile, ios::in | ios::binary);
	if (fIn.is_open())
	{
		fIn.seekg(0, ios::beg);
		Day dayRead;
		fIn.read((char*)&dayRead, sizeof(Day));  
		//Doc truoc ngay vao bien dayRead, roi kiem tra doc duoc hay khong(cuoi file hay chua) bang eof.() vi eof.() tra ve true khi cuoi file va khong doc duoc nua
		while (!fIn.eof())
		{
			order temp;
			temp.dayCreate = dayRead;
			// De trong vong lap de moi lan lap se tao mot order moi, cap phat 2 mang Product va amountOfEveryProduct, sau do them vao List 
			// Order cua lan lap nay khac hoan toan voi order cua lan lap truoc vi tao moi va cap phat moi
			// Doc so luong phan tu mang Product
			fIn.read((char*) & (temp.n), sizeof(int));
			temp.Product = new product[temp.n];
			temp.amountOfEveryProduct = new int[temp.n];
			for (int i = 0; i < temp.n; i++)
			{
				fIn.read((char*)&(temp.Product[i]), sizeof(product));
			}
			for (int i = 0; i < temp.n; i++)
			{
				fIn.read((char*) & (temp.amountOfEveryProduct[i]), sizeof(int));
			}
			fIn.read((char*)&(temp.totalPrice), sizeof(int));
			addOrderLast(oHead, temp);
			fIn.read((char*)&dayRead, sizeof(Day));
		}
		fIn.close();
	}
}

void writeListOfProductsToFile(pNode* pHead, const char* outputFile)
{
	if (pHead == NULL) return;
	ofstream fOut(outputFile, ios::out | ios::binary);
	if (fOut.is_open())
	{
		fOut.seekp(0, ios::beg);
		pNode* temp = pHead;
		while (temp != NULL)
		{
			fOut.write((char*)&(temp->pduct), sizeof(product));
			temp = temp->pNext;
		}
		fOut.close();
	}
}
void writeListOfStaffsToFile(sNode* sHead, const char* outputFile)
{
	if (sHead == NULL) return;
	ofstream fOut(outputFile, ios::out | ios::binary);
	if (fOut.is_open())
	{
		fOut.seekp(0, ios::beg);
		sNode* temp = sHead;
		while (temp != NULL)
		{
			fOut.write((char*) & (temp->Staff), sizeof(staff));
			temp = temp->pNext;
		}
		fOut.close();
	}
}
void writeListOfOrdersToFile(oNode* oHead, const char* outputFile)
{
	if (oHead == NULL) return;
	ofstream fOut(outputFile, ios::out | ios::binary);
	if (fOut.is_open())
	{
		fOut.seekp(0, ios::beg);
		oNode* temp = oHead;
		while (temp != NULL)
		{
			fOut.write((char*)&(temp->Order.dayCreate), sizeof(Day));
			fOut.write((char*)&(temp->Order.n), sizeof(int));
			for (int i = 0; i < temp->Order.n; i++)
			{
				fOut.write((char*)&(temp->Order.Product[i]), sizeof(product));
			}
			for (int i = 0; i < temp->Order.n; i++)
			{
				fOut.write((char*) & (temp->Order.amountOfEveryProduct[i]), sizeof(int));
			}
			fOut.write((char*) & (temp->Order.totalPrice), sizeof(int));
			temp = temp->pNext;
		}
		fOut.close();
	}
}

void outputListOfProducts(pNode* pHead)
{
	pNode* temp = pHead;
	if (temp == NULL)
	{
		cout << "Danh sach khong co san pham nao" << endl;
		return;
	}
	system("cls");
	cout << "--------[DANH SACH SAN PHAM]---------" << endl;
	int i = 0;
	while (temp != NULL)
	{
		i++;
		cout << "** San pham thu " << i << " ** " << endl;
		outputAProduct(temp->pduct);
		cout << "----------------" << endl;
		temp = temp->pNext;
	}
}
void outputListOfStaffs(sNode* sHead)
{
	sNode* temp = sHead;
	if (temp == NULL)
	{
		cout << "Danh sach khong co nhan vien nao" << endl;
		return;
	}
	system("cls");
	cout << "--------[DANH SACH NHAN VIEN]---------" << endl;
	int i = 0;
	while (temp != NULL)
	{
		i++;
		cout << "** Nhan vien thu " << i << " ** " << endl;
		outputAStaff(temp->Staff);
		cout << "---------------------"<<endl;
		temp = temp->pNext;
	}
}
void outputListOfOrders(oNode*& orderHead)
{
	oNode* temp = orderHead;
	if (temp == NULL)
	{
		cout << "Danh sach khong co don hang nao" << endl;
		return;
	}
	int i = 0;
	system("cls");
	cout << "------------[DANH SACH DON HANG]-------------" << endl;
	while (temp != NULL)
	{
		i++;
		cout << "** Don hang thu " << i << " **" << endl;
		outputAnOrder(temp->Order);
		cout << "--------------------------------------" << endl;
		temp = temp->pNext;
	}
	

}

void releaseProductList(pNode* pHead)
{
	pNode* p = pHead;
	pNode* temp = p;
	if (p == NULL) return;
	while (p != NULL)
	{
		p = p->pNext;
		delete temp;
		temp = p;
	}
	pHead = NULL;
}
void releaseStaffList(sNode* sHead)
{
	sNode* p = sHead;
	sNode* temp = p;
	if (p == NULL) return;
	while (p != NULL)
	{
		p = p->pNext;
		delete temp;
		temp = p;
	}
	sHead = NULL;
}
void releaseOrderList(oNode*& oHead)
{
	oNode* p = oHead;
	oNode* temp = p;
	if (p == NULL) return;
	while (p != NULL)
	{
		p = p->pNext;
		if (temp->Order.n > 0)
		{
			delete[] temp->Order.Product;
			delete[] temp->Order.amountOfEveryProduct;
		}
		delete temp;
		temp = p;
	}
	oHead = NULL;
}
