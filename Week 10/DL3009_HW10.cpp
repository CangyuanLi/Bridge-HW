//HW10 - DL3009

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee;

template <class T>
class LListNode;

template <class T>
class LList;

template <class T>
void printOutput(const LListNode<T>*& head);

void openInputFile(ifstream& inFile);

template <class T>
int maxPayEmpID(LListNode<T>*& head);

class Employee {
private:
	int empID;
	int empHoursWorked;
	double empHourlyWage;
	double empTotPay;
	string empName;
public:
	//constructors:
	Employee() :empID(0), empHoursWorked(0), empHourlyWage(0), empTotPay(0), empName("") {}
	Employee(int ID, double wage, string name) : empID(ID), empHourlyWage(wage), empName(name), empHoursWorked(0), empTotPay(0) {}
	Employee(int ID, int hours, double wage, double totPay, string name) : empID(ID), empHoursWorked(hours), empHourlyWage(wage), empTotPay(totPay), empName(name) {}

	//need to add getters setters:
	const string& getName() const { return empName; }
	int getID() const { return empID; }
	void addWorkHours(int hours) { this->empHoursWorked += hours; }
	double getTotPay() const { return empTotPay; }
	int getHoursWorked() { return this->empHoursWorked;  }
	void setTotPay() { this->empTotPay = (this->empHourlyWage * this->empHoursWorked); }
};

template <class T>
class LListNode {
public:
	T data;
	LListNode<T>* next;

	LListNode() :data(T()), next(nullptr) {}
	LListNode(T newdata = T(), LListNode<T>* newNext = nullptr) : data(newdata), next(newNext) {} 
	
	//getter setter
	Employee& getData() { return this->data; }
	
	//friend set
	friend class LList<T>; //ok becuase the class was pre-defined
};

template <class T>
class LList {
private: 
	LListNode<T>* head;
	LListNode<T>* recursiveCopy(LListNode<T>* rhs); 
public: 
	LList() : head(nullptr) {}
	LList(const LList& rhs) :head(nullptr) { *this = rhs; }
	~LList() { clear(); }
	void insertAtHead(T newdata);
	bool isEmpty()const { return head == nullptr; }
	void clear(); 
	void insertAtEnd(T newdata); 
	LListNode<T>* getHead() const { return this->head; }
};

template <class T>
LListNode<T>* LList<T>::recursiveCopy(LListNode<T>* rhs) {
	if (rhs == nullptr)
		return nullptr;
	else
		return new LListNode<T>(rhs->data, recursiveCopy(rhs->next)); 
}

template <class T>
void LList<T>::insertAtHead(T newdata) {
	LListNode<T>* tempPtr = new LListNode<T>; 
	tempPtr->data = newdata; 
	tempPtr->next = head; 
	head = tempPtr; 
}

template <class T>
void LList<T>::insertAtEnd(T newdata) {
	if (isEmpty()) {
		head = new LListNode<T>(newdata); 
	}
	else {
		LListNode<T>* temp = new LListNode<T>(newdata);
		LListNode<T>* end = head;
		while (end->next != nullptr)
			end = end->next;
		end->next = temp;
	}
}

template <class T>
void LList<T>::clear() {
	LListNode<T>* tempPtr = head; 
	while (tempPtr != nullptr) {
		LListNode<T>* discardPtr = tempPtr; 
		tempPtr = tempPtr->next; 
		delete discardPtr; 
	}
}

void openInputFile(ifstream& inFile) {
	string filename;
	cout << "Enter filename:";
	cin >> filename;
	inFile.open(filename);

	while (!inFile) {
		cout << "File failed to open.\n";
		cout << "Enter filename:";
		cin >> filename;
		inFile.clear();
		inFile.open(filename);
	}
}

void printOutput(LListNode<Employee>* head) { 
	string empName;
	double empTotPay;

	cout << "\n********Payroll Information********\n";

	for (LListNode<Employee>* i = head; i != nullptr; i = i->next) {
		empName = i->getData().getName();
		empTotPay = i->getData().getTotPay();
		cout << empName << ", $" << empTotPay << endl;
	}
	cout << "***********End Payroll*************\n";
}

template <class T>
int maxPayEmpID(LListNode<T>*& head) {
	double maxPay = 0;
	int maxID = -1;

	for (LListNode<T>* i = head; i != nullptr; i = i->next()) {
		maxPay = i->getData().getTotPay();
		maxID = i->getData().getID();
	}
	return maxID;
}

//merge sort functions below: 
template <class T>
LListNode<T>* merge(LListNode<T>* a, LListNode<T>* b) {
	//base case
	if (a == nullptr)
		return b;
	if (b == nullptr)
		return a;

	//recursive case
	//taking head pointer
	LListNode<T>* c; 

	if (a->getData().getTotPay() > b->getData().getTotPay()) {
		c = a; 
		c->next = merge(a->next, b);
	}
	else {
		c = b; 
		c->next = merge(a, b->next);
	}
	return c;
}

template <class T>
LListNode<T>* mid_point(LListNode<T>* head) {
	//base case
	if (head == nullptr || head->next == nullptr)
		return head;
	
	//recursive
	LListNode<T>* fast = head; 
	LListNode<T>* slow = head;

	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next;

		if (fast->next == nullptr)
			break; 

		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

template <class T>
LListNode<T>* merge_sort(LListNode<T>* head) {
	
	//base case, length 0 or 1
	if (head == nullptr || head->next == nullptr)
		return head; 

	//recursive case
	//step 1: divide linked list into two equal linked lists
	LListNode<T>* mid = mid_point(head); 
	LListNode<T>* a = head;
	LListNode<T>* b = mid->next;

	mid->next = nullptr; 

	//step 2: recursively sort smaller linked lists
	a = merge_sort(a);
	b = merge_sort(b); 

	//step 3: merge sorted linked lists
	LListNode<T>* c = merge(a, b); 

	return c;
}

int main() {
	ifstream inFile; //file processing
	
	//for employee class
	int empID;
	double empHourlyWage;
	string empName;

	LList<Employee> list; 

	//func to open
	openInputFile(inFile); 
	
	//first file emps.txt
	while (inFile >> empID) {
		inFile >> empHourlyWage; 
		
		inFile.ignore(9999, ' '); 
		getline(inFile, empName); 

		Employee employee(empID, empHourlyWage, empName); 

		list.insertAtEnd(employee); 
	}
	cout << "File 1 (emps.txt) inputs read successfully.\n";
	inFile.close();

	//func to open file 2
	openInputFile(inFile);
	int empWorkHours; 
	LListNode<Employee>* i = list.getHead(); 

	//second file hours.txt
	while (inFile >> empID) {
		inFile >> empWorkHours;

		inFile.ignore(9999, '\n');

		//iterate list to find employee
		for (LListNode<Employee>* i = list.getHead(); i != nullptr; i = i->next) {
			if (i->getData().getID() == empID) {
				i->getData().addWorkHours(empWorkHours);
				i->getData().setTotPay(); 
			}
		}		
	}
	cout << "File 2 (hours.txt) inputs read successfully.\n";
	inFile.close(); 

	cout << "\nPre-sorted:"; 
	printOutput(list.getHead());

	cout << "\nPost-sorted:";
	
	LListNode<Employee>* sortedHead = merge_sort(list.getHead()); 

	printOutput(sortedHead);
}
