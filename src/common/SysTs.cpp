/* Definition of schema SYS.TS$
   Copyright (C) 2018-2023 Adam Leszczynski (aleszczynski@bersler.com)

This file is part of OpenLogReplicator.

OpenLogReplicator is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation; either version 3, or (at your option)
any later version.

OpenLogReplicator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License
along with OpenLogReplicator; see the file LICENSE;  If not see
<http://www.gnu.org/licenses/>.  */

#include "SysTs.h"

namespace OpenLogReplicator {
    SysTs::SysTs(typeRowId& newRowId, typeTs newTs, const char* newName, uint32_t newBlockSize, bool newTouched) :
            rowId(newRowId),
            ts(newTs),
            name(newName),
            blockSize(newBlockSize),
            touched(newTouched) {
    }

    bool SysTs::operator!=(const SysTs& other) const {
        return (other.rowId != rowId) || (other.ts != ts) || (other.name != name) || (other.blockSize != blockSize);
    }
}