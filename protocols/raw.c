/*	
	Copyright (C) 2013 CurlyMo
	
	This file is part of the Raspberry Pi 433.92Mhz transceiver.

    Raspberry Pi 433.92Mhz transceiver is free software: you can redistribute 
	it and/or modify it under the terms of the GNU General Public License as 
	published by the Free Software Foundation, either version 3 of the License, 
	or (at your option) any later version.

    Raspberry Pi 433.92Mhz transceiver is distributed in the hope that it will 
	be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Raspberry Pi 433.92Mhz transceiver. If not, see 
	<http://www.gnu.org/licenses/>
*/

#include "raw.h"

void rawParseRaw() {
}

void rawParseCode() {
}

int rawParseBinary() {
	return 0;
}

void rawCreateCode(struct options *options) {
	char *code = getOption(options,'c');
	char *pch;
	int i=0;
	pch = strtok(code," ");
	while(pch != NULL) {
		raw.raw[i]=atoi(pch);
		pch = strtok(NULL, " ");
		i++;
	}
	raw.rawLength=i;
}

void rawPrintHelp() {
	printf("\t -c --code=\"raw\"\t\traw code devided by spaces\n\t\t\t\t\t(just like the output of debug)\n");
}

void rawInit() {
		
	strcpy(raw.id,"raw");
	strcpy(raw.desc,"Raw codes");
	raw.header[0] = 0;
	raw.header[1] = 0;
	raw.low = 0;
	raw.high = 0;
	raw.footer = 0;
	raw.multiplier[0] = 0;
	raw.multiplier[1] = 0;
	raw.rawLength = 0;
	raw.binaryLength = 0;	
	raw.repeats = 0;

	raw.bit = 0;	
	raw.recording = 0;	
	
	struct option rawOptions[] = {
		{"code", required_argument, NULL, 'c'},
		{0,0,0,0}
	};

	raw.options=setOptions(rawOptions);	
	raw.parseRaw=&rawParseRaw;
	raw.parseCode=&rawParseCode;
	raw.parseBinary=&rawParseBinary;
	raw.createCode=&rawCreateCode;
	raw.printHelp=&rawPrintHelp;
	
	protocol_register(&raw);
}