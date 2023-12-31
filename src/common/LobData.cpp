/* Definition of LobData
   Copyright (C) 2018-2024 Adam Leszczynski (aleszczynski@bersler.com)

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

#include "LobData.h"

namespace OpenLogReplicator {
    LobDataElement::LobDataElement() :
            dba(0),
            offset(0) {
    }

    LobDataElement::LobDataElement(typeDba newDba, uint32_t newOffset) :
            dba(newDba),
            offset(newOffset) {
    }

    LobDataElement::~LobDataElement() {

    }

    bool LobDataElement::operator<(const LobDataElement& other) const {
        if (dba < other.dba)
            return true;

        if (dba > other.dba)
            return false;

        if (offset < other.offset)
            return true;

        return false;
    }


    LobData::LobData() :
            pageSize(0),
            sizePages(0),
            sizeRest(0) {
    }

    LobData::~LobData() {
        for (auto dataMapIt: dataMap) {
            uint8_t* ptr = dataMapIt.second;
            delete[] ptr;
        }
        dataMap.clear();
        indexMap.clear();
    }
}
