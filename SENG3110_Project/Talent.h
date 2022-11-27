#pragma once
#include <string>
#include <map>
#include <winioctl.h>
#include <iostream>

using namespace std;

class Talent
{
	int userID;
	string firstName;
	string lastName;
	map<string, int> jobTypes;

public:
	Talent(int userID, string firstName, string lastName);
	void setFirstName(string firstName);
	void setLastName(string lastName);
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
};

class TalentLinkedList
{
public:
	Node* head;
	Node* sorted;

	void addTalent(Talent talent);
	void insertionSort(Node* node, string jobType);
	TalentLinkedList getTalents();
};