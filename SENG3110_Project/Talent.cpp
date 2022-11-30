#include "pch.h"
#include "Talent.h"

Talent::Talent() {
	userID = 000;
	firstName = "N/A";
	lastName = "N/A";
}

Talent::Talent(int uID, string fName, string lName) {
	userID = uID;
	firstName = fName;
	lastName = lName;
}

void Talent::setFirstName(string fName) {
	firstName = fName;
}

void Talent::setLastName(string lName) {
	lastName = lName;
}

void Talent::addJobType(string jobType, int jobCost) {
	jobTypes.insert(pair<string, int>(jobType, jobCost));
}

void Talent::removeJobType(string jobType) {
	jobTypes.erase(jobType);
}

void Talent::updateJobType(string jobType, int jobCost) {
	removeJobType(jobType);
	addJobType(jobType, jobCost);
}

int Talent::getJobCost(string jobType) {
	try {
		return jobTypes.at(jobType);
	}
	catch (const std::exception&) {
		return 0;
	}
}

bool Talent::checkJob(string jobType) {
	if (jobTypes.find(jobType) == jobTypes.end()) {
		return false;
	}
	else {
		return true;
	}
}


/// Node
Node::Node(Talent tal, Node* node) {
	talent = tal;
	next = node;
}


/// Linked List
void TalentLinkedList::addTalent(Talent talent) {
	Node* newTalent = new Node(talent, head);
	newTalent->talent = talent;
	newTalent->next = head;
	head = newTalent;
}

void TalentLinkedList::insertionSort(Node* node, string jobType) {
	sorted = NULL;
	Node* current = node;

	while (current != NULL) {
		Node* next = current->next;

		//Check if Current Talent offeres selected job
		if ((current->talent).checkJob(jobType) || 1 == 1) {
			if (sorted == NULL || (sorted->talent).getJobCost(jobType) >= (current->talent).getJobCost(jobType)) {
				current->next = sorted;
				sorted = current;
			}
			else {
				Node* newCurrent = sorted;

				while (newCurrent->next != NULL && (newCurrent->next->talent).getJobCost(jobType) < (current->talent).getJobCost(jobType)) {
					newCurrent = newCurrent->next;
				}
				current->next = newCurrent->next;
				newCurrent->next = current;
			}
		}
		current = next;
	}
	node = sorted;
}

TalentLinkedList TalentLinkedList::getTalents() {
	//Create Talent Classes
	Talent tal1 = Talent(001, "Gus", "Johnson");
	Talent tal2 = Talent(002, "Adam", "Ioe");
	Talent tal3 = Talent(003, "Liam", "Park");
	Talent tal4 = Talent(004, "John", "Piper");
	Talent tal5 = Talent(005, "Eger", "Foir");

	//Add Jobs to Talents
	tal1.addJobType("Plumber", 12);
	tal1.addJobType("Flooring", 23);
	tal2.addJobType("Carpenter", 43);
	tal2.addJobType("Plumber", 39);
	tal2.addJobType("Roofer", 26);
	tal3.addJobType("Electrician", 30);
	tal4.addJobType("Plumber", 43);
	tal4.addJobType("Flooring", 87);
	tal5.addJobType("Painter", 23);
	tal5.addJobType("Carpenter", 14);
	tal5.addJobType("Flooring", 27);
	tal5.addJobType("Electrician", 32);
	tal5.addJobType("Pool Cleaning", 120);

	//Create Nodes
	TalentLinkedList talentList;
	talentList.head = NULL;
	talentList.addTalent(tal1);
	talentList.addTalent(tal2);
	talentList.addTalent(tal3);
	talentList.addTalent(tal4);
	talentList.addTalent(tal5);

	return talentList;
}

vector<Talent> TalentLinkedList::convertLinkedList(Node* node) {
	Node* current = node;
	vector<Talent> talents;

	while (current != NULL) {
		talents.push_back(current->talent);
		current = current->next;
	}

	return talents;
}