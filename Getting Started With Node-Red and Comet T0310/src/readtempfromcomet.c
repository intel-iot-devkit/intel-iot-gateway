/*
* Copyright (c) 2015 Intel Corporation.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#include <stdio.h>
#include <errno.h>
 
#include </usr/include/modbus/modbus.h>
 
int main() 
{
 
    modbus_t *mb;
    uint16_t tab_reg[32];
    int rc;
 
    mb = modbus_new_rtu("/dev/ttyS0", 9600, 'N', 8, 1);
    if (mb == NULL) {
	fprintf(stderr, "Unable to create the libmodbus context\n");
	return -1;
    }

	//modbus_set_debug(mb, TRUE); 

    rc = modbus_set_slave(mb, 1);
    if (rc != 0) {
        fprintf(stderr, "set slave failed: %s\n", modbus_strerror(errno));
        modbus_free(mb);
        return -1;
    }

    modbus_rtu_set_serial_mode(mb, MODBUS_RTU_RS232);
    rc = modbus_connect(mb);
    if (rc != 0) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(mb);
        return -1;
    }

    rc = modbus_read_registers(mb, 0x030, 1, tab_reg);
    if (rc == -1) {
        fprintf(stderr, "write failed: %d %s\n", errno, modbus_strerror(errno));
        modbus_free(mb);
        return -1;
    }
    printf("%d\n", tab_reg[0]);

    modbus_close(mb);
    modbus_free(mb);

    return 0;
}
