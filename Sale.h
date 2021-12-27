#ifndef __SALE_H__
#define __SALE_H__
#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#pragma warning (disable:4996)
using namespace std;
struct product
{
	char ID[21];
	char name[51];
	char type[21];
	int price;

};
struct staff
{
	char ID[21];
	char loginName[31];
	char password[31];
	char Name[51];

};
struct Day
{
	int day;
	int month;
	int year;
};
struct order 
{
	Day dayCreate;
	int n; //So luong phan tu cua mang Product
	product* Product;
	int* amountOfEveryProduct; // Moi phan tu i trong mang tuong ung voi so luong cua san pham i trong mang Product
	int totalPrice;

};
struct productNode
{
	product pduct;
	productNode* pNext;
};
typedef struct productNode pNode;
struct staffNode
{
    staff Staff;
	staffNode* pNext;
};
typedef struct staffNode sNode;
struct orderNode
{
	order Order;
	orderNode* pNext;
};
typedef struct orderNode oNode;
void LoginMenu();
void Menu();
void SubMenuProduct();
void SubMenuStaff();
void inputAPositiveNum(int& a);
bool isLeapYear(int year);
int theDaysOfMonth(int month, int year);
void inputDay(Day& day);
bool isExistIDProduct(char* s, pNode* head);
void inputStringWithLimitOfLength(char s[], int maxLength);

void inputAProduct(product& p, pNode* head);
pNode* makeProductNode(product P);
bool addProductLast(pNode*& head, product P);
bool addAProduct(pNode*& head);
bool deleteAProduct(pNode*& head);
bool changeAProduct(pNode*& head);

bool isExistIDStaff(char* s, sNode* head);
bool isExistLoginNameStaff(char* s, sNode* head);
sNode* makeStaffNode(staff S);
bool addStaffLast(sNode*& head, staff S);
void inputAStaff(staff& s, sNode* head);
bool addAStaff(sNode*& head);
bool deleteAStaff(sNode*& head);
bool changeAStaff(sNode*& head);

int countProducts(pNode* head);
pNode* findIDInListProduct(char* s, pNode* head);
bool inputAnOrder(order& o, pNode* head);
oNode* makeOrderNode(order O);
bool addOrderLast(oNode*& head, order O);
bool addAnOrder(pNode* productHead, oNode*& orderHead);
void outputAProduct(product p);
void outputAnOrder(order o);
void satisticOfOrdersByDay(oNode*& orderHead);
void choice(int& Choice, int numberOfChoices);
bool LoginFunction(sNode* head);
void MainMenuFunction(pNode*& pHead, sNode*& sHead, oNode*& oHead, int Choice);
void RunProductMenu(pNode*& pHead);
void RunStaffMenu(sNode*& sHead);

void readListOfProductsFromFile(pNode*& pHead, const char* inputFile);
void readListOfStaffsFromFile(sNode*& sHead, const char* inputFile);
void readListOfOrdersFromFile(oNode*& oHead, const char* inputFile);

void writeListOfProductsToFile(pNode* pHead, const char* outputFile);
void writeListOfStaffsToFile(sNode* sHead, const char* outputFile);
void writeListOfOrdersToFile(oNode* oHead, const char* outputFile);

void outputListOfProducts(pNode* pHead);
void outputListOfStaffs(sNode* sHead);
void outputListOfOrders(oNode*& orderHead);

void releaseProductList(pNode* pHead);
void releaseStaffList(sNode* sHead);
void releaseOrderList(oNode*& oHead);

#endif