// Mytime.h: interface for the CMytime class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTIME_H__74E97CE2_104B_437C_8DB7_AB3F7AA256E4__INCLUDED_)
#define AFX_MYTIME_H__74E97CE2_104B_437C_8DB7_AB3F7AA256E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<time.h>
class CMytime  
{
public:
	int GetYear() const;
	static CMytime  GetCurrentTime();
	CMytime();
	virtual ~CMytime();

private:
	time_t m_time;
};

#endif // !defined(AFX_MYTIME_H__74E97CE2_104B_437C_8DB7_AB3F7AA256E4__INCLUDED_)
