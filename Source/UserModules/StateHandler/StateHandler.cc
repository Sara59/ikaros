//
//	StateHandler.cc		This file is a part of the IKAROS project
//
//    Copyright (C) 2012 <Author Name>
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//    See http://www.ikaros-project.org/ for more information.
//
//  This example is intended as a starting point for writing new Ikaros modules
//  The example includes most of the calls that you may want to use in a module.
//  If you prefer to start with a clean example, use he module MinimalModule instead.
//

#include "StateHandler.h"
#include <time.h>
#include <stdlib.h> 
#include <iostream>
#include <chrono>
//typedef std::chrono::high_resolution_clock Clock;
using namespace std;

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;



void
StateHandler::Init()
{

    input1 = GetInputArray("INPUT1");
    input2 = GetInputArray("INPUT2");
    input3 = GetInputArray("INPUT3");
    //input4 = GetInputArray("INPUT4");
    //input5 = GetInputArray("INPUT5");

    output1 = GetOutputArray("OUTPUT1");
    output2 = GetOutputArray("OUTPUT2");
    output3 = GetOutputArray("OUTPUT3");
    //output4 = GetOutputArray("OUTPUT4");
    output5 = GetOutputArray("OUTPUT5");
	
	candyoutputred = GetOutputArray("CANDYOUTPUTRED");
	candyoutputgreen = GetOutputArray("CANDYOUTPUTGREEN");
	candyoutputblue = GetOutputArray("CANDYOUTPUTBLUE");

    //internal_input_array = create_array(3);
    //internal_output_array = create_array(3);

    internalState = 0;
    //startTime = 0;
    timerStarted = false;
    waitTime = 0;
    previousState = 0;
    lookAway = false;
    
	input1[0] = 0;
	input2[0] = 0;
	input3[0] = 0;
	//input4[0] = 0;
	
	nothingFound = false;
	
	/*candyoutput[0] = 0;
	candyoutput[1] = 0;
	candyoutput[2] = 1;
	candyoutput[3] = 0;
	candyoutput[4] = 0;
	candyoutput[5] = 1;
	candyoutput[6] = 1;
	candyoutput[7] = 1;
	candyoutput[8] = 0;
	candyoutput[9] = 0;
	candyoutput[10] = 1;
	candyoutput[11] = 1;*/
	
	for (int i=0;i<12;i++) candyoutputred[i] = 0;
	for (int i=0;i<12;i++) candyoutputgreen[i] = 0;
	for (int i=0;i<12;i++) candyoutputblue[i] = 0;

//./ikaros -R -t -r50 -p  ../Examples/Robots/EpiHead/EpiHead.ikc 

}



StateHandler::~StateHandler()
{
    
}

clock_t startTime;	

void
StateHandler::StartTimer()
{
	if (!(internalState == 0)) {
		startTime = clock();
		//auto start = Clock::now();
		waitTime = 1000000;
	
		if (internalState == 4 || internalState == 5){
			timerStarted = true;
		    waitTime = rand() % 100 + 50;
		    waitTime = waitTime/100;
			lookAway = false;
		} else if (internalState == 3){
			timerStarted = true;
		    waitTime = rand() % 200 + 50;
		    waitTime = waitTime/100;
		} else if (internalState == 2){
			timerStarted = true;
		    waitTime = rand() % 500 + 100;
		    waitTime = waitTime/100;
		    lookAway = true;
			cout << "inside timer if state 2" << endl;
		} else if (internalState == 1) {
			timerStarted = true;
		    waitTime = rand() % 200 + 50;
		    waitTime = waitTime/100;
			nothingFound = true;
		}
	}
}

void
StateHandler::Tick()
{
         cout << "\t-------- NEW TICK ----------" << endl;
		 cout << "INTERNALSTATE: " <<  internalState << "\n";
         cout << "PREVIOUSSTATE: " <<  previousState << "\n";

    //checks if any module wants to change state.
    cout << "Closest value " << input1[0] << "\n";
    cout << "Face value " << input2[0] << "\n";
	cout << "DisMovement value " << input3[0] << "\n";
	//cout << "SmallMovement value " << input4[0] << "\n";
	
	switch ((int)internalState) {
		case 0:
			for (int i=0;i<12;i++) candyoutputblue[i] = 0;
			for (int i=0;i<12;i++) candyoutputgreen[i] = 0;
			for (int i=0;i<12;i++) candyoutputred[i] = 0;
			for (int i=0;i<12;i+=2) candyoutputblue[i] = 1;
			break;
		case 2:
			for (int i=0;i<12;i++) candyoutputblue[i] = 0;
			for (int i=0;i<12;i++) candyoutputred[i] = 0;
			for (int i=0;i<12;i++) candyoutputgreen[i] = 1;
			break;
		case 3:
			for (int i=0;i<12;i+=2) candyoutputgreen[i] = 0;
			break;
		case 5:
			for (int i=0;i<12;i++) candyoutputgreen[i] = 0;
			for (int i=0;i<12;i++) candyoutputblue[i] = 0;
			for (int i=0;i<12;i++) candyoutputred[i] = 0;
			for (int i=0;i<12;i+=2) candyoutputgreen[i] = 1;
			for (int i=1;i<12;i+=4) candyoutputred[i] = 1;
	}
	
	bool closest = false;
	bool face = false;
	bool d_md = false;
	//bool s_md = false;
	
	if (input1[0] != internalState) closest = true;
	if (input2[0] != internalState) face = true;
	if (input3[0] != internalState) d_md = true;
	//if (input4[0] != internalState) s_md = true;
	
	if (internalState != 2 && internalState != 3) {
		lookAway = false;
	}
	
	float chosen = internalState;
	//cout << "d_md = " << d_md << endl;
	if (internalState == float(0)) {
		//cout << "inside internalState = 0\n";
		if (d_md) {
			//cout << "inside d_md if" << endl;
			chosen = input3[0];
		}
		else if (face) chosen = input2[0];
	} else if (internalState == 1) {
		if (face) {
			chosen = input2[0];
			nothingFound = false;
		}
		else if (d_md) chosen = input3[0];
	} else if (internalState == 2) {
		//if (s_md) chosen = input4[0];
		 if (closest) chosen = input1[0];
		else if (face) chosen = input2[0];
	} else if (internalState == 4) {
		//if (s_md) chosen = input4[0];
	} else if (internalState == 5) {
		if (closest) chosen = input1[0];
	}
    cout << "chosen = " << chosen << endl;
	if (chosen != internalState && chosen != 0 && internalState != 3) {
		cout << "inside chosen if" << endl;
		if(chosen == 10){
			previousState = 0;
			internalState = 0;
		} else {
			previousState = internalState;
	    	internalState = chosen;
			StartTimer();
		}
	} else {
		previousState = internalState;
	}
	
	cout << "chosen = " << chosen << endl;
 	cout << "INTERNALSTATE2: " <<  internalState << "\n";
    cout << "PREVIOUSSTATE2: " <<  previousState << "\n";
	
    /*if (input1[0] != previousState){
		
    } else if (input2[0] != previousState){
		previousState = internalState;
	    internalState = input2[0];
		StartTimer();
    } else if (input3[0] != previousState){
		previousState = internalState;
	    internalState = input3[0];
		StartTimer();
    } else if (input4[0] != previousState){
		previousState = internalState;
	    internalState = input4[0];
		StartTimer();
    }*/
	
	

    if (timerStarted){
		clock_t end = clock();	
		//auto end = Clock::now();
		//time_t end = time(0);
		//double t = difftime(end, startTime);
		clock_t wow = (end - startTime);
		double t = wow / CLOCKS_PER_SEC;
		//double t = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()/1000;
		//double t = (end - star);
		
		cout << "\tt = " << t << " & " << "waitTime = " << waitTime << endl;
		cout << "\tlookAway = " << lookAway << endl;
		if (t > waitTime){
		    if (lookAway){
				cout << "INSIDE lookAway IF \n";
				previousState = 3;
				internalState = 3;
				waitTime = rand() % 150 + 150;
				waitTime = waitTime/100;
				startTime = clock();
				timerStarted = true;
				lookAway = false;
		    } else if (nothingFound){
				cout << "inside nothingFound if" << endl;
				internalState = 0; 
				startTime = 0;
			    timerStarted = false;
			    waitTime = 0;
				nothingFound = false;
		    } else {
				internalState = 2; 
				startTime = clock();
			    timerStarted = true;
			    waitTime = rand() % 400 + 400;
				waitTime /= 100;
				lookAway = true;
		    }
		}
    }  
   
    output1[0] = internalState;
    output2[0] = internalState;
    output3[0] = internalState;
    //output4[0] = internalState;
    output5[0] = internalState;

}

// Install the module. This code is executed during start-up.

static InitClass init("StateHandler", &StateHandler::Create, "Source/UserModules/StateHandler/");
