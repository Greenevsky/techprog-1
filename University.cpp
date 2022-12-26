#include <iostream>
#include "University.h"

using namespace std;

University::University() : FCs("") {}
University::University(string fcs) : FCs(fcs) {}
University::University(const University& tmp) {
	this->FCs = tmp.FCs;
}
University::~University() { this->FCs = ""; }

void University::set_FCs(std::string fcs) { this->FCs = fcs; }

string University::get_FCs() { return this->FCs; }

void University::change_b(int id) {
	if (id == 1) {
		cout << "Enter FCs: "; getline(cin, FCs);
	}
}
