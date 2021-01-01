/* Oracle Redo OpCode: 11.12
   Copyright (C) 2018-2021 Adam Leszczynski (aleszczynski@bersler.com)

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

#include "OpCode0B0C.h"
#include "OracleAnalyzer.h"
#include "RedoLogRecord.h"

using namespace std;

namespace OpenLogReplicator {

    OpCode0B0C::OpCode0B0C(OracleAnalyzer *oracleAnalyzer, RedoLogRecord *redoLogRecord) :
            OpCode(oracleAnalyzer, redoLogRecord) {
    }

    OpCode0B0C::~OpCode0B0C() {
    }

    void OpCode0B0C::process(void) {
        OpCode::process();
        uint64_t fieldNum = 0, fieldPos = 0;
        uint16_t fieldLength = 0;

        oracleAnalyzer->nextField(redoLogRecord, fieldNum, fieldPos, fieldLength);
        //field: 1
        ktbRedo(fieldPos, fieldLength);

        if (!oracleAnalyzer->nextFieldOpt(redoLogRecord, fieldNum, fieldPos, fieldLength))
            return;
        //field: 2
        kdoOpCode(fieldPos, fieldLength);

        if (oracleAnalyzer->dumpRedoLog >= 1) {
            if ((redoLogRecord->op & 0x1F) == OP_QMD) {
                for (uint64_t i = 0; i < redoLogRecord->nrow; ++i)
                    oracleAnalyzer->dumpStream << "slot[" << i << "]: " << dec << oracleAnalyzer->read16(redoLogRecord->data+redoLogRecord->slotsDelta + i * 2) << endl;
            }
        }
    }
}
