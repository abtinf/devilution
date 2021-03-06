/*
 * UNPUBLISHED -- Rights  reserved  under  the  copyright  laws  of the
 * United States.  Use  of a copyright notice is precautionary only and
 * does not imply publication or disclosure.
 *
 * THIS DOCUMENTATION CONTAINS CONFIDENTIAL AND PROPRIETARY INFORMATION
 * OF    BLIZZARD   ENTERTAINMENT.    ANY   DUPLICATION,  MODIFICATION,
 * DISTRIBUTION, OR DISCLOSURE IS STRICTLY PROHIBITED WITHOUT THE PRIOR
 * EXPRESS WRITTEN PERMISSION OF BLIZZARD ENTERTAINMENT.
 */

#include "../types.h"

//----- (00452831) --------------------------------------------------------
bool __cdecl SystemSupported()
{
	bool v0; // di
	struct _OSVERSIONINFOA VersionInformation; // [esp+4h] [ebp-94h]

	v0 = 0;
	memset(&VersionInformation, 0, 0x94u);
	VersionInformation.dwOSVersionInfoSize = 148;
	if ( GetVersionExA(&VersionInformation)
	  && VersionInformation.dwPlatformId == 2
	  && VersionInformation.dwMajorVersion >= 5 )
	{
		v0 = 1;
	}
	return v0;
}

//----- (00452885) --------------------------------------------------------
bool __cdecl RestrictedTest()
{
	bool v0; // si
	FILE *v2; // eax
	char Buffer[260]; // [esp+4h] [ebp-104h]

	v0 = 0;
	if ( SystemSupported() && GetWindowsDirectoryA(Buffer, 0x104u) )
	{
		strcat(Buffer, "\\Diablo1RestrictedTest.foo");
		v2 = fopen(Buffer, "wt");
		if ( v2 )
		{
			fclose(v2);
			remove(Buffer);
		}
		else
		{
			v0 = 1;
		}
	}
	return v0;
}

//----- (004528F7) --------------------------------------------------------
bool __cdecl ReadOnlyTest()
{
	bool v0; // si
	char *v1; // eax
	FILE *v2; // eax
	char Filename[260]; // [esp+4h] [ebp-104h]

	v0 = 0;
	if ( GetModuleFileNameA(ghInst, Filename, 0x104u) )
	{
		v1 = strrchr(Filename, '\\');
		if ( v1 )
		{
			strcpy(v1 + 1, "Diablo1ReadOnlyTest.foo");
			v2 = fopen(Filename, "wt");
			if ( v2 )
			{
				fclose(v2);
				remove(Filename);
			}
			else
			{
				v0 = 1;
			}
		}
	}
	return v0;
}
