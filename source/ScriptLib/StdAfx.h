#pragma once

#include "../eterLib/StdAfx.h"
#include "../eterGrnLib/StdAfx.h"

//#include <crtdbg.h>
#ifdef _DEBUG
	#undef _DEBUG
	#include "../../extern/include/Python-2.7/Python.h"
	#define _DEBUG
#else
	#include "../../extern/include/Python-2.7/Python.h"
#endif
#include "../../extern/include/Python-2.7/node.h"
#include "../../extern/include/Python-2.7/grammar.h"
#include "../../extern/include/Python-2.7/token.h"
#include "../../extern/include/Python-2.7/parsetok.h"
#include "../../extern/include/Python-2.7/errcode.h"
#include "../../extern/include/Python-2.7/compile.h"
#include "../../extern/include/Python-2.7/symtable.h"
#include "../../extern/include/Python-2.7/eval.h"
#include "../../extern/include/Python-2.7/marshal.h"

#include "PythonUtils.h"
#include "PythonLauncher.h"
#include "PythonMarshal.h"
#include "Resource.h"

void initdbg();

// PYTHON_EXCEPTION_SENDER
class IPythonExceptionSender
{
	public:
		void Clear()
		{
			m_strExceptionString = "";
		}

		void RegisterExceptionString(const char * c_szString)
		{
			m_strExceptionString += c_szString;
		}

		virtual void Send() = 0;

	protected:
		std::string m_strExceptionString;
};

extern IPythonExceptionSender * g_pkExceptionSender;

void SetExceptionSender(IPythonExceptionSender * pkExceptionSender);
// END_OF_PYTHON_EXCEPTION_SENDER
