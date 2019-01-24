#include "project.h"
#include "pi2c.h"
#include "d21.h"
int main(int argv, char** argc)
{
	printf("init\n");
	pi2c_init();
	d21_init();

	printf("hey\n");
	pi2c_quick_read(&d21, D21_ID_TEST);
	send_firmware_size();
	printf("hi\n");
	return 0;

}
