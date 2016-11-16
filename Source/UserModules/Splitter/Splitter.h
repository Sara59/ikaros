//
//	 This file is a part of the IKAROS project
//        A C++ wrapper for IKC module MovementDetector
//
//    Copyright (C) 2016	Rasmus Olofzon
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

#ifndef Splitter_
#define Splitter_

#include "IKAROS.h"

class Splitter: public Module {
public:
    static Module * Create(Parameter * p) {return new Splitter(p);};
    
    Splitter(Parameter * p) : Module(p) {};
    virtual ~Splitter();

    void    Init();
    void    Tick();
	
    float  	*		getX;
	float 	*		getY;
	float	**		changeMatrix;
	
	float	*		mean1;
	float	*		mean2;
    float 	*		mean3;
	float 	*		mean4;
	float 	*		mean5;
	float 	*		mean6;
	float 	*		Xout;
	float 	*		Yout;
	
	int			incrementX;
	int			incrementY;
};

#endif
