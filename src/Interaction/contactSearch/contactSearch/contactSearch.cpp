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

#include "contactSearch.hpp"
#include "streams.hpp"
#include "particles.hpp"


pFlow::contactSearch::contactSearch(
	const dictionary& dict,
	const box& domain,
 	const particles& prtcl,
 	const geometry& geom,
 	Timers& timers)
:
	domainBox_(domain),
	particles_(prtcl),
	geometry_(geom),
	ppTimer_("particle-particle contact search", &timers),
	pwTimer_("particle-wall contact search", &timers),
	dict_(dict)
{

}

const pFlow::pointStructure &pFlow::contactSearch::pStruct() const
{
   return particles_.pStruct();
}

pFlow::uniquePtr<pFlow::contactSearch> pFlow::contactSearch::create(
    const dictionary &dict,
    const box &domain,
    const particles &prtcl,
    const geometry &geom,
    Timers &timers)
{
	word baseMethName	= dict.getVal<word>("method");	

	auto model = angleBracketsNames("ContactSearch", baseMethName);

	REPORT(1)<<"Selecting contact search model . . ."<<END_REPORT;
	
	if( dictionaryvCtorSelector_.search(model))
	{
		auto objPtr = dictionaryvCtorSelector_[model] (dict, domain, prtcl, geom, timers);
		REPORT(2)<<"Model "<< Green_Text(model)<<" is created."<< END_REPORT;
		return objPtr;
	}
	else
	{
		printKeys
		( 
			fatalError << "Ctor Selector "<< model << " dose not exist. \n"
			<<"Avaiable ones are: \n\n"
			,
			dictionaryvCtorSelector_
		);
		fatalExit;
	}

	return nullptr;
}