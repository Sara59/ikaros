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

#ifndef small_MvmntDetChooser_
#define small_MvmntDetChooser_

#include "IKAROS.h"

class small_MvmntDetChooser: public Module {
public:
    static Module * Create(Parameter * p) {return new small_MvmntDetChooser(p);};
    
    small_MvmntDetChooser(Parameter * p) : Module(p) {};
    virtual ~small_MvmntDetChooser();

    void    Init();
    void    Tick();
	
    float  	*		demandAtt;
	float 	*		region;
	float	*		stateIn;
	float	*		getX;
	float	*		getY;
	
	float	*		stateOut;
	float	*		weightOut;
    float 	**		coordsOut;
	
	int				incrementX;
	int				incrementY;
	int				x1, x2, x3;
	int				y1, y2;
};

#endif
