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


#ifndef __particles_hpp__
#define __particles_hpp__

#include "dynamicPointStructure.hpp"
#include "demComponent.hpp"

namespace pFlow
{


class particles
:
	public observer,
	public demComponent
{
private:
	
	/// dynamic point structure for particles center mass
	dynamicPointStructure 	dynPointStruct_;

	// - name of shapes - this is managed by particles 
	//wordPointField&  		shapeName_;

	// id of particles on host
	int32PointField_D		id_;

	// property id on device
	int8PointField_D 		propertyId_;

	// diameter / boundig sphere size of particles on device
	realPointField_D		diameter_;

	// mass of particles field 
	realPointField_D 		mass_;

	// - acceleration on device
	realx3PointField_D 	accelertion_;

	/// contact force field
	realx3PointField_D     contactForce_;

	/// contact torque field
	realx3PointField_D     contactTorque_;	

	
	
	void zeroForce()
	{
		WARNING<<"fill contactTorque"<<END_WARNING;
		//contactForce_.fill(zero3);
	}

	void zeroTorque()
	{
		WARNING<<"fill contactTorque"<<END_WARNING;
		//contactTorque_.fill(zero3);
	}
protected:

	inline auto& dynPointStruct()
	{
		return dynPointStruct_;
	}

	inline auto& pointPosition()
	{
		return dynPointStruct_.pointPosition();	
	}

	inline 
	auto& velocity()
	{
		return dynPointStruct_.velocity();
	}

public:

	// type info
	TypeInfo("particles");

	explicit particles(systemControl& control);


	inline const auto& dynPointStruct()const 
	{
		return dynPointStruct_;
	}	

	inline auto size()const{
		return dynPointStruct_.size();
	}

	inline auto capacity() const{
		return dynPointStruct_.capacity();
	}
	
	inline auto numActive()const
	{
		return dynPointStruct_.numActive();
	}
	
	inline bool isAllActive()const
	{
		return dynPointStruct_.isAllActive();
	}

	inline 
	const auto& pointPosition()const
	{
		return dynPointStruct_.pointPosition();
	}

	inline 
	const auto& velocity()const
	{
		return dynPointStruct_.velocity();
	}

	inline 
	const auto& diameter()const
	{
		return diameter_;
	}

	inline 
	auto& diameter()
	{
		return diameter_;
	}

	inline 
	const auto& mass()const
	{
		return mass_;
	}

	inline auto& mass()	
	{
		return mass_;
	}

	inline 
	const auto& accelertion()const
	{
		return accelertion_;
	}

	inline 
	auto& accelertion()
	{
		return accelertion_;
	}

	inline 
	auto& contactForce() 
	{
		return contactForce_;
	}

	inline
	const auto& contactForce() const
	{
		return contactForce_;
	}

	inline
	auto& contactTorque()
	{
		return contactTorque_;
	}

	inline
	const auto& contactTorque() const 
	{
		return contactTorque_;
	}

	inline 
	const auto& propertyId()const
	{
		return propertyId_;
	}

	inline 
	auto& propertyId()
	{
		return propertyId_;
	}

	/*inline const auto& shapeName()const{
		return shapeName_;
	}*/

	/*inline auto& shapName(){
		return shapeName_;
	}*/

	bool beforeIteration() override;

	/*virtual
	bool insertParticles
	(
		const realx3Vector& position,
	 	const wordVector&  shapes,
	 	const setFieldList& setField
	 ) = 0;*/

	

	virtual
	realx3PointField_D& rAcceleration() = 0;

	virtual
	const realx3PointField_D& rAcceleration() const = 0;

	/*virtual
	const realVector_D& boundingSphere()const = 0;*/

	virtual 
	word shapeTypeName()const = 0;

	virtual
	void boundingSphereMinMax(real & minDiam, real& maxDiam)const = 0;

	

}; // particles

} // pFlow

#endif //__particles_hpp__
