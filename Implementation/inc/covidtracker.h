/**
* @file covidtracker.h
* Tracks the latest covid-19 updates from different states of India.
*/


#ifndef COVIDTRACKER_H_INCLUDED
#define COVIDTRACKER_H_INCLUDED


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/**
* Validate the input given by user.
* @param[in] choice.
* @return valid or invalid choice.
* @note checks wheather the choice given by user is valid or not.
*/
int valid_choice(choice);


/**
* The user inputs the information such as the state name, active, recovered, deceased & other cases.Other cases include the migrated cases or non-COVID deaths.
*/
//void insert();
int insert();

/**
* All existing records are displayed along with state name, active, recovered, deceased & other cases. 
*/
void display();


/**
* State name is given as input to retrieve records of the respective state.
*/
void search();


/**
* This function is used to modify the existing records with latest updates of number of cases.
*/
void update();


/**
* This function is used to delete the existing record by entering the name of state.
*/
void delete();


#endif // COVIDTRACKER_H_INCLUDED
