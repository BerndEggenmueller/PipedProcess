#include <iostream>
#include <vector>
#include "PipedProcess/PipedProcess.h"

using namespace std;

int main(int argc, char *argv[])
{
	vector<char> buffer(1000000, '�');
    PipedProcess proc;
	proc.SetStdInData(&buffer[0], buffer.size());
	DWORD errorCode = proc.Run("DemoChildProc.exe", "");
	if (errorCode == NO_ERROR)
	{
		buffer = proc.FetchStdOutData();
		cout << buffer.size() << " bytes received" << endl;
	}
	else
	{
		if (proc.HasStdErrData())
		{
			buffer = proc.FetchStdErrData();
			cerr << &buffer[0] << endl;
		}
	}

    return errorCode;
}

