/////////DEFINE STRUCT 

#define ID_BASIC_COMMAND		1
#define	ID_REGISTRATION			ID_BASIC_COMMAND + 1
#define ID_HEART_BEAT			ID_BASIC_COMMAND + 2
#define ID_MAKE_CALL			ID_BASIC_COMMAND + 3
#define ID_COMMAND_MAKE_CALL	ID_BASIC_COMMAND + 4
#define ID_SEND_DATA			ID_BASIC_COMMAND + 6
	

typedef struct
{
	int nId;

	char szPrivateIp[20];
	int nPrivatePort;

	char szPublicIp[20];
	int nPublicPort;

	char szName[20]	;
}CommonStruct;

