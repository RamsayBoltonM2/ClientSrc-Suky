#include <crash_reporter/CrashRpt.h>
#include <tchar.h>


// Install crash reporting
int SetEterExceptionHandler()
{
	CR_INSTALL_INFO info;
	memset(&info, 0, sizeof(CR_INSTALL_INFO));
	info.cb = sizeof(CR_INSTALL_INFO);  
	info.pszAppName = _T("Metin2"); // Define application name.
	info.pszAppVersion = _T("1.0.0"); // Define application version.
	// URL for sending error reports over HTTP.
	info.pszUrl = _T("http://metin2.co.nz/crashrpt.php");                    
	// Install all available exception handlers.
	info.pszEmailSubject = _T("DEV_CLIENT Error Report");  
	info.pszEmailTo = _T("support@metin2.co.nz");    
	info.dwFlags |= CR_INST_ALL_POSSIBLE_HANDLERS; 
	// Use binary encoding for HTTP uploads (recommended).
	// info.dwFlags |= CR_INST_HTTP_BINARY_ENCODING;     --Deprecated
	info.dwFlags |= CR_INST_SEND_QUEUED_REPORTS; 
	// Provide privacy policy URL
	info.pszPrivacyPolicyURL = _T("http://metin2.co.nz/err_privacy.html");
	info.dwFlags |= CR_INST_APP_RESTART; // Restarts the app after crash

	info.uPriorities[CR_HTTP] = 2;  // First try send report over HTTP 
	info.uPriorities[CR_SMTP] = 1;  // Second try send report over SMTP  


	int nResult = crInstall(&info);
	if(nResult!=0)
	{
		TCHAR buff[256];
		crGetLastErrorMsg(buff, 256);
		MessageBox(NULL, buff, _T("crInstall error"), MB_OK);
		return 1;
	}

	// Take screenshot of the app window at the moment of crash
	// crAddScreenshot2(CR_AS_VIRTUAL_SCREEN|CR_AS_USE_JPEG_FORMAT, 95);
#ifdef _DEBUG
	crAddFile2(_T("log.txt"), NULL, _T("Log File"), CR_AF_MAKE_FILE_COPY);
#endif
	crAddFile2(_T("syserr.txt"), NULL, _T("ErrorLog File"), CR_AF_MAKE_FILE_COPY);
	return 1;
}

int RemoveEterException()
{
	crUninstall();
	return 1;
}