#include "stdafx.h"
#include "common.h"

std::wstring StringToUpper(std::wstring myString)
{
  const int length = myString.length();
  for(int i=0; i!=length; ++i)
  {
    myString[i] = toupper(myString[i]);
  }
  return myString;
}

std::wstring StringToLower(std::wstring myString)
{
  const int length = myString.length();
  for(int i=0; i!=length; ++i)
  {
    myString[i] = tolower(myString[i]);
  }
  return myString;
}

U32 StringToHex( const std::string& str )
{
	U32 value;
	stringstream convert ( str );			
	convert >> std::hex >> value;		//read seq_table as hexadecimal value
	return value;
}

wchar_t *GetFileWithBase(const wchar_t *f, const wchar_t *newfile)
{
	static wchar_t *ret;
	wchar_t *tp1;

#if PSS_STYLE==1
	tp1=((wchar_t *)wcsrchr (f,'/'));
#else
	tp1=((wchar_t *)wcsrchr (f,'\\'));
#if PSS_STYLE!=3
	{
		wchar_t *tp3;

		tp3=((wchar_t *)wcsrchr (f,'/'));
		if(tp1<tp3) tp1=tp3;
	}
#endif
#endif
	if(!tp1)
	{
		ret=(wchar_t*)malloc(wcslen(newfile)+1);
		wcscpy(ret,newfile);
	}
	else
	{
		ret=(wchar_t*)malloc((tp1-f+2+wcslen(newfile)) * sizeof(wchar_t));	// 1(NULL), 1(/).
		memcpy(ret,f,(tp1-f) * sizeof(wchar_t));
		ret[tp1-f]=L'/';
		ret[tp1-f+1]=0;
		wcscat(ret,newfile);
	}
	return(ret);
}
