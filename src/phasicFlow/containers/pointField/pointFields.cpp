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


#include "pointFields.hpp"
#include "createBoundaryFields.hpp"


template class pFlow::pointField<pFlow::int8, pFlow::HostSpace>; 
createBaseBoundary(pFlow::int8, pFlow::HostSpace);
createBoundary(pFlow::int8, pFlow::HostSpace, exit);

template class pFlow::pointField<pFlow::int8>; 
createBaseBoundary(pFlow::int8, void);
createBoundary(pFlow::int8, void, exit);

template class pFlow::pointField<pFlow::real, pFlow::HostSpace>; 
createBaseBoundary(pFlow::real, pFlow::HostSpace);
createBoundary(pFlow::real, pFlow::HostSpace, exit);


template class pFlow::pointField<pFlow::real>; 
createBaseBoundary(pFlow::real, void);
createBoundary(pFlow::real, void, exit);


/*template class pFlow::pointField<pFlow::VectorSingle, pFlow::int8, pFlow::HostSpace>; 

template class pFlow::pointField<pFlow::VectorSingle, pFlow::int16>; 

template class pFlow::pointField<pFlow::VectorSingle, pFlow::int16, pFlow::HostSpace>; 

template class pFlow::pointField<pFlow::VectorSingle, pFlow::int32>; 

template class pFlow::pointField<pFlow::VectorSingle, pFlow::int32, pFlow::HostSpace>; 

template class pFlow::pointField<pFlow::VectorSingle, pFlow::int64>; 

template class pFlow::pointField<pFlow::VectorSingle, pFlow::int64, pFlow::HostSpace>; 

template class pFlow::pointField<pFlow::VectorSingle, pFlow::uint32>; 

template class pFlow::pointField<pFlow::VectorSingle, pFlow::uint32, pFlow::HostSpace>;

template class pFlow::pointField<pFlow::VectorSingle, pFlow::label>; 

template class pFlow::pointField<pFlow::VectorSingle, pFlow::label, pFlow::HostSpace>;

template class pFlow::pointField<pFlow::VectorSingle, pFlow::real>; 

template class pFlow::pointField<pFlow::VectorSingle, pFlow::real, pFlow::HostSpace>;

template class pFlow::pointField<pFlow::VectorSingle, pFlow::realx3>; 

template class pFlow::pointField<pFlow::VectorSingle, pFlow::realx3, pFlow::HostSpace>;*/



