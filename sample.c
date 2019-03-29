#define PCRE_STATIC

#include <ntddk.h>
#include "pcre_regex.h"

//ULONG _fltused;


//char* pattern = "^(http|https|ftp|mms|rtsp|gopher|ftps|sftp|telnet)\\://([a-zA-Z0-9\\.\\-]+(\\:[a-zA-Z0-9\\.&amp;%\\$\\-]+)*@)*((25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9])\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[0-9])|localhost|([a-zA-Z0-9\\-_]+\\.)*[a-zA-Z0-9\\-_]+\\.(com|net|org|gov|edu|int|mil|biz|arpa|info|name|pro|aero|coop|museum|[a-zA-Z]{2}))(\\:[0-9]+)*(/\\S*)?$";
//2012/10/27 Regex Fixed http://www.qq.com.. this url is bsod
//Must head is http|https|ftp|mms|rtsp|gopher|ftps|sftp|telnet
//char* pattern = "^(http|https|ftp|mms|rtsp|gopher|ftps|sftp|telnet)\\://([a-zA-Z0-9\\.\\-]+(\\:[a-zA-Z0-9\\.&amp;%\\$\\-]+)*@)*((25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9])\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[0-9])|localhost|([a-zA-Z0-9\\-_]+\\.)*[a-zA-Z0-9\\-_]+\\.(com|net|org|gov|edu|int|mil|biz|arpa|info|name|pro|aero|coop|museum|[a-zA-Z]{2}|?))(\\:[0-9]+)*(/\\S*)?$";
//not must head
char* pattern = "(((file|gopher|news|nntp|telnet|http|ftp|https|ftps|sftp)://)|(www\.))+(([a-zA-Z0-9\._-]+\.[a-zA-Z]{2,6})|([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}))(/[a-zA-Z0-9\&amp;%_\./-~-]*)?";

void OnUnload(IN PDRIVER_OBJECT DriverObject)
{
	DbgPrint("OnUnload Called! \n");
}

NTSTATUS DriverEntry(IN PDRIVER_OBJECT theDriverObject, IN PUNICODE_STRING theRegisterPath)
{
	ANSI_STRING aDbgString,aDbgString1,aDbgString2;

	char* src_address = "http://www.qq.com";
	char* src_address1 = "http://192.168.2000";
	char* src_address2 = "www.qq.com";

	DbgPrint("DriverEntry loaded! \n");
	theDriverObject->DriverUnload = OnUnload;
	
	if(_ismatch(src_address,pattern) != -1)
	{
		RtlInitAnsiString(&aDbgString,src_address);
		DbgPrint("%Z =>URL is Matched!!\n",&aDbgString);
	}else{
		RtlInitAnsiString(&aDbgString,src_address);
		DbgPrint("%Z =>URL Not Match!!\n",&aDbgString);
	}

	if(_ismatch(src_address1,pattern) != -1)
	{
		RtlInitAnsiString(&aDbgString1,src_address1);
		DbgPrint("%Z =>URL is Matched!!\n",&aDbgString1);
	}else{
		RtlInitAnsiString(&aDbgString1,src_address1);
		DbgPrint("%Z =>URL Not Match!!\n",&aDbgString1);
	}

	if(_ismatch(src_address2,pattern) != -1)
	{
		RtlInitAnsiString(&aDbgString2,src_address2);
		DbgPrint("%Z =>URL is Matched!!\n",&aDbgString2);
	}else{
		RtlInitAnsiString(&aDbgString2,src_address2);
		DbgPrint("%Z =>URL Not Match!!\n",&aDbgString2);
	}

	return STATUS_SUCCESS;
}