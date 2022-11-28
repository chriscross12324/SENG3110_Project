#pragma once
#include <string>
#include <map>
#include <winioctl.h>
#include <iostream>
#include <list>

using namespace std;

class Talent
{
public:
	int userID;
	string firstName;
	string lastName;
	map<string, int> jobTypes;

	Talent();
	Talent(int uID, string fName, string lName);
	void setFirstName(string fName);
	void setLastName(string lName);
	void addJobType(string jobType, int jobCost);
	void removeJobType(string jobType);
	void updateJobType(string jobType, int jobCost);
	int getJobCost(string jobType);
	bool checkJob(string jobType);
};

class Node
{
public:
	Talent talent;
	Node* next;

	Node(Talent tal, Node* next);
};

class TalentLinkedList
{
public:
	Node* head;
	Node* sorted;

	void addTalent(Talent talent);
	void insertionSort(Node* node, string jobType);
	void getTalents();
	list<Talent> convertLinkedList(Node* node);
};