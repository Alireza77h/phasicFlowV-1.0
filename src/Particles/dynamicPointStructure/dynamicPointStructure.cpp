/*------------------------------- phasicFlow ---------------------------------
      O        C enter of
     O O       E ngineering and
    O   O      M ultiscale modeling of
   OOOOOOO     F luid flow       
------------------------------------------------------------------------------
  Copyright (C): www.cemf.ir
  email: hamid.r.norouzi AT gmail.com
------------------------------------------------------------------------------  
Licence:
  This file is part of phasicFlow code. It is a free software for simulating 
  granular and multiphase flows. You can redistribute it and/or modify it under
  the terms of GNU General Public License v3 or any other later versions. 
 
  phasicFlow is distributed to help others in their research in the field of 
  granular and multiphase flows, but WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

-----------------------------------------------------------------------------*/

#include "dynamicPointStructure.hpp"
#include "systemControl.hpp"

pFlow::dynamicPointStructure::dynamicPointStructure
(
	systemControl& control
)
:
	pointStructure(control),
	velocity_
	(
		objectFile(
			"velocity",
			"",
			objectFile::READ_ALWAYS,
			objectFile::WRITE_ALWAYS
			),
		*this,
		zero3
	),
	integrationMethod_
	(
		control.settingsDict().getVal<word>("integrationMethod")
	)
{
	REPORT(1)<< "Creating integration method "<<
		Green_Text(integrationMethod_)<<" for dynamicPointStructure."<<END_REPORT;

	integrationPos_ = integration::create
	(
		"pStructPosition",
		*this,
		integrationMethod_,
		pointPosition()
	);

	if( !integrationPos_ )
	{
		fatalErrorInFunction<<
		"  error in creating integration object for dynamicPointStructure (position). \n";
		fatalExit;
	}
	
	integrationVel_ = integration::create
	(
		"pStructVelocity",
		*this,
		integrationMethod_,
		velocity_.field()
	);

	if( !integrationVel_ )
	{
		fatalErrorInFunction<<
		"  error in creating integration object for dynamicPointStructure (velocity). \n";
		fatalExit;
	}


	WARNING << "Initialization of integrationPos_ and integrationVel_ should be doen!"<<END_WARNING;
	
	/*if(!integrationPos_->needSetInitialVals()) return;

	
		
	auto [minInd, maxInd] = pStruct().activeRange();
	int32IndexContainer indexHD(minInd, maxInd);
	
	auto n = indexHD.size();
	auto index = indexHD.indicesHost();

	realx3Vector pos(n,RESERVE());
	realx3Vector vel(n,RESERVE());
	const auto hVel = velocity().hostVector();
	const auto hPos = pStruct().pointPosition().hostVector();

	for(auto i=0; i<n; i++)
	{
		pos.push_back( hPos[index(i)]);
		vel.push_back( hVel[index(i)]);
	}


	REPORT(2)<< "Initializing the required vectors for position integratoin "<<endREPORT;
	integrationPos_->setInitialVals(indexHD, pos);

	REPORT(2)<< "Initializing the required vectors for velocity integratoin\n "<<endREPORT;
	integrationVel_->setInitialVals(indexHD, vel);*/

}

bool pFlow::dynamicPointStructure::predict
(
	real dt,
	realx3PointField_D& acceleration
)
{
	//auto& pos = pStruct().pointPosition();

	//if(!integrationPos_().predict(dt, pos.VectorField(), velocity_.VectorField() ))return false;
	//if(!integrationVel_().predict(dt, velocity_.VectorField(), acceleration.VectorField()))return false;

	return true;
}

bool pFlow::dynamicPointStructure::correct
(
	real dt,
	realx3PointField_D& acceleration
)
{
	//auto& pos = pStruct().pointPosition();
	
	//if(!integrationPos_().correct(dt, pos.VectorField(), velocity_.VectorField() ))return false;
	
	//if(!integrationVel_().correct(dt, velocity_.VectorField(), acceleration.VectorField()))return false;

	return true;	
}

/*FUNCTION_H
pFlow::uniquePtr<pFlow::int32IndexContainer> pFlow::dynamicPointStructure::insertPoints
(
	const realx3Vector& pos,
	const List<eventObserver*>& exclusionList
)
{
	auto newIndicesPtr = pointStructure::insertPoints(pos, exclusionList);

	// no new point is inserted
	if( !newIndicesPtr ) return newIndicesPtr;

	if(!integrationPos_().needSetInitialVals()) return newIndicesPtr;

	auto hVel = velocity_.hostVector();
	auto n = newIndicesPtr().size();
	auto index = newIndicesPtr().indicesHost();

	realx3Vector velVec(n, RESERVE());
	for(auto i=0; i<n; i++)
	{
		velVec.push_back( hVel[ index(i) ]);
	}

	integrationPos_->setInitialVals(newIndicesPtr(), pos );
	integrationVel_->setInitialVals(newIndicesPtr(), velVec );
	
	return newIndicesPtr;

}*/


/*bool pFlow::dynamicPointStructure::update(
	const eventMessage& msg) 
{
	if( msg.isInsert())
	{
		
		if(!integrationPos_->needSetInitialVals())return true;

		const auto indexHD = pStruct().insertedPointIndex();

	
		auto n = indexHD.size();

		if(n==0) return true;

		auto index = indexHD.indicesHost();

		realx3Vector pos(n,RESERVE());
		realx3Vector vel(n,RESERVE());
		const auto hVel = velocity().hostVector();
		const auto hPos = pStruct().pointPosition().hostVector();

		for(auto i=0; i<n; i++)
		{
			pos.push_back( hPos[index(i)]);
			vel.push_back( hVel[index(i)]);
		}


		
		integrationPos_->setInitialVals(indexHD, pos);

		integrationVel_->setInitialVals(indexHD, vel);		

	}

	return true;
}*/