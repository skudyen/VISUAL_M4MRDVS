#include "sdk_api.h"
#include "func.h"
#include "config.h"

int main(int argc, char *argv[])
{
	/* Set up */
	DcHandle handle_cam;
	checkTC(DcSetInfoOutput(1, false, "./")); 
	printf("%s CALL API VERSION : %s", MSG_NOR, DcGetApiVersion());
	
	LxDeviceInfo see_info;
	LX_STATE frame = DcOpenDevice(OPEN_BY_IP, self_ip, &handle_cam, &see_info);
	
	/* Check camera */
	if (frame != LX_SUCCESS)
	{
		printf("%s OPEN CAMERA HAS BEEN FAIL %s", MSG_ERR, DcGetErrorString(frame));
		return (-1);
	}
	printf("%s Connection Successful || Camera Product: %d || Current IP: %s", MSG_NOR, see_info.dev_type, see_info.ip);


	DcSetIntValue(handle_cam, LX_INT_FIRST_EXPOSURE, 1000);
	DcSetIntValue(handle_cam, LX_INT_MIN_DEPTH, 500);
	DcSetIntValue(handle_cam, LX_INT_MAX_DEPTH, 3000);
	/*  RGB Camera  */
	DcSetBoolValue(handle_cam, LX_BOOL_ENABLE_2D_STREAM, true);
	DcSetIntValue(handle_cam, LX_INT_2D_IMAGE_OUTPUT_FORMAT, LX_2D_FORMAT_RGB);

	DcStartStream(handle_cam);
	printf("PRESS q TO EXIT");

	char waitkey;
	while(1)
	{
		waitkey == getchar();
		if (waitkey == 'q')
			break;
	}
	DcStopStream(handle_cam);
	DcCloseDevice(handle_cam);
	return(0);
}