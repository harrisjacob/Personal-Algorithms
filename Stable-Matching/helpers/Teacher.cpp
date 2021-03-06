#include <ostream>
#include "teacher.h"

Teacher::Teacher():preferences{nullptr}{
	Name = "Empty Name";
	id = -1;
	matched = nullptr;
	prefPosition = 0;
}

Teacher::~Teacher(){}

Student* Teacher::getPrefAt(int index){
	return preferences[index];
}

Student* Teacher::getHighPref(){ return preferences[prefPosition++]; }

void Teacher::setHighPref(int hpref){ prefPosition = hpref; }

void Teacher::setPref(int pref, Student* student){
	preferences[pref] = student;
}

int Teacher::getPrefOf(Student* student){
	for(int i=0; i < 10; i++){
		if (preferences[i] == student) return i;
	}
	return 11;
}


std::string Teacher::getName(){
	return Name;
}

void Teacher::setName(std::string name){
	Name = name;
}

int Teacher::getID(){ return id; }

void Teacher::setID(int newID){
	id = newID;
}

bool Teacher::isMatched(){
	return (matched) ? true : false;
}

Student* Teacher::getMatched(){ return matched; }

void Teacher::setMatched(Student* student){
	matched = student;
}

int Teacher::getPrefPosition(){ return prefPosition; }

std::ostream & operator<<(std::ostream & os, Teacher & teacher){

        os << "Name: " <<teacher.getName() << std::endl;
        os << "Teacher ID: "<<teacher.getID()<<std::endl;
        os << "Matched: "<< ((teacher.isMatched()) ? "True\n" : "False\n" )<< std::endl;
        return os;
}