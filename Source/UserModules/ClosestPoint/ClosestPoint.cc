//
//	MyModule.cc		This file is a part of the IKAROS project
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

#include "ClosestPoint.h"
#include <iostream>
#include <math.h>
using namespace std;

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;


void
ClosestPoint::Init()
{


    depth 		= GetInputMatrix("DEPTH");
    depthX		= GetInputSizeX("DEPTH");
    depthY		= GetInputSizeY("DEPTH");
        output 		= GetOutputMatrix("OUTPUT");
    connected		= InputConnected("DEPTH");

    
}



ClosestPoint::~ClosestPoint()
{

    

}



void
ClosestPoint::Tick()
{
    if (connected){
        //cout << "depth: " <<  fixed << depth[50][50];
    }
    redc = red;
    greenc = green;
    bluec = blue;
    depthc = depth;

	
    float small = 100000;
    int smallestRow = 0;
    int smallestCol = 0;
    //double *values[20]; 
    int divider = 20;
    int depthYY= (depthY)/divider;
    int depthXX= (depthX)/divider;
    int numberOfParts = depthYY*depthXX;



    int count = 0;
    int count2 = 0;
 
    double views[numberOfParts];

    while (count < numberOfParts-depthXX){
	views[count] = 0;
	int correctPixels = 0;
        for (int i = (count % depthXX)*divider; i <= (count % depthXX)*divider+divider; ++i){
	    for (int j = 0+(count2*divider); j < (count2*divider)+divider; ++j){
		//cout << "X: " << i;
		//cout << "Y: " << j;
		//cout << "count: " << count;
		//cout << "count2: " << count2;
		if (depth[j][i] < 10000 && depth[j][i] > 500){
		    views[count] += depth[j][i];
		    correctPixels++;
		    //cout << "depth: " <<  fixed << depth[j][i];
		}
		
		
	    }   
        }
	
	//cout << "DONE WITH: " << count << "!!!!";
	views[count] = views[count] / (correctPixels);
	cout << "Value of count " << count << ": " << views[count];
	if (count%depthXX == 0) {
	    count2++;
	}
	
	count++;
	
	
    }

    double smallest = 100000;
    double smallestPart = 0;
    
    for (int i = 0; i <= 40; i+=depthXX){
	if (!(i-1 < 0 && i+1 > numberOfParts-depthXX)){
	    views[i-1] = 10001;
	    views[i] = 10001;
	}
    }

    for (int i = 0; i < numberOfParts; i++){
	if (views[i] < smallest && !(views[i] < 10) && !(views[i] > 10000)){
	    smallest = views[i];
	    smallestPart = i;
	}
    }
    cout << "Value of smallest input: " << smallest << ", smallest part is: " << smallestPart;
    output[2][3] = smallest;
    int smallestPartInt = smallestPart;
    //middle coord
    double xCoord = (smallestPartInt%depthXX)*divider+(divider/2);
    double yCoord = floor(smallestPartInt/depthXX)*divider+(divider/2);
    output[0][3] = xCoord;
    output[1][3] = yCoord;
    output[0][0] = 1;
    output[1][1] = 1;
    output[2][2] = 1;
    output[3][3] = 1;


//LEGACY CODE, DEPTH WITH ONLY ONE PIXEL AND NO CHECKS
    //int nrows = depthX;
    //int ncols = depthY;
/*
    //int closestDistance = 100000;
    //int closestPart = 0;
    for (int i = 20; i < depthY-20; ++i) {
        for (int j = 20; j < depthX-20; ++j){
	    float value = depth[i][j];
            if (small > value && value > 5){
		
		cout << "value: " << value;
                float small = value;
		//int smallestRow = i;
		//int smallestCol = j;
		output[0] = i;
    		output[1] = j;
		output[2] = small;

            }
        }

    }
*/

/*sum = sum / (depthYY*depthXX);
	if (sum < closestDistance){
		closestPart = count;
		closestDistance = sum;
		output[0] = closestPart;
		output[1] = closestDistance;
	}
	*/

    //not really interesting right now, mostly to try draw an area around the closest point
/*
    int rowDiff1 = depthX-(smallestRow+50);
    if (rowDiff1 < 0){
        rowDiff1 = smallestRow+50+rowDiff1;
    }
    int rowDiff2 = smallestRow-50;
    if (rowDiff2 < 0){
        rowDiff2 = smallestRow-50-rowDiff2;
    }
    int colDiff1 = depthY-(smallestCol+50);
    if (colDiff1 < 0){
	colDiff1 = smallestCol+50+colDiff1;
    }
    int colDiff2 = smallestCol-50;
    if (colDiff2 < 0) {
	colDiff2 = smallestRow-50-rowDiff2;
    }

    for (int i = 0; i <rowDiff1; ++i){
        redc[smallestRow+i][smallestCol] = 0;
        greenc[smallestRow+i][smallestCol] = 0;
        bluec[smallestRow+i][smallestCol] = 0;
	depthc[smallestRow+i][smallestCol] = 0;
    }
    for (int i = 0; i <rowDiff2; ++i){
        redc[smallestRow-i][smallestCol] = 0;
        greenc[smallestRow-i][smallestCol] = 0;
        bluec[smallestRow-i][smallestCol] = 0;
	depthc[smallestRow-i][smallestCol] = 0;
    }
    for (int i = 0; i <colDiff1; ++i){
        redc[smallestRow][smallestCol+i] = 0;
        greenc[smallestRow][smallestCol+i] = 0;
	bluec[smallestRow][smallestCol+i] = 0;
	depthc[smallestRow][smallestCol+i] = 0;
    }
    for (int i = 0; i <colDiff2; ++i){
        redc[smallestRow][smallestCol-i] = 0;
        greenc[smallestRow][smallestCol-i] = 0;
	bluec[smallestRow][smallestCol-i] = 0;
	depthc[smallestRow][smallestCol-i] = 0;
    }
*/

}



// Install the module. This code is executed during start-up.

static InitClass init("ClosestPoint", &ClosestPoint::Create, "Source/UserModules/ClosestPoint/");


