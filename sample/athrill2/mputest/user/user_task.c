//#include "service_call.h"
#include "kernel_service.h"
#include "test_reg.h"

unsigned char user_stack_data[USER_STACK_SIZE] __attribute__ ((section(".bss_noclr_user")));

void user_task(void)
{
	SrvUint32 data;
	ServiceReturnType ret;

	ret = svc_get_data(0, &data);
	if (ret == SERVICE_E_OK) {
		data++;
		(void)svc_set_data(0, data);
	}
	return;
}
