/*
 * Copyright (c) 2010-2016 Stephane Poirier
 *
 * stephane.poirier@oifii.org
 *
 * Stephane Poirier
 * 3532 rue Ste-Famille, #3
 * Montreal, QC, H2X 2L1
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

// spiregreadwrite.cpp : Defines the entry point for the console application.
//

#include "spiregreadwrite.h"


//int _tmain(int argc, _TCHAR* argv[])
int main()
{
	/*
	static DWORD v1, v2;

	HKEY hKey = OpenKey(HKEY_LOCAL_MACHINE,L"SOFTWARE\\MyCompany");

	v1 = GetVal(hKey, L"Value1");
	v2 = GetVal(hKey, L"Value2");

	v1 += 5;
	v2 += 2;

	SetVal(hKey, L"Value1", v1);
	SetVal(hKey, L"Value2", v2);

	RegCloseKey(hKey);
	*/

	/*
	DWORD datatowrite = 9999;
	RegWriteDWORD(HKEY_LOCAL_MACHINE,L"SOFTWARE\\MyCompany",L"PremierDWORD", datatowrite);
	*/
	RegWriteDWORD(HKEY_LOCAL_MACHINE,L"SOFTWARE\\MyCompany",L"PremierDWORD", 9999);

	DWORD datatoread = RegReadDWORD(HKEY_LOCAL_MACHINE,L"SOFTWARE\\MyCompany",L"PremierDWORD");
	
	printf("%d",datatoread);

	std::wstring data=L"teststring 10 9 8 7 6 5 4 3 2 1 1 2 3 4 5 6 7 8 9 10";
	RegWriteSZ(HKEY_LOCAL_MACHINE,L"SOFTWARE\\MyCompany",L"PremierSZ", data);

	std::wstring mywstring;
	mywstring = RegReadSZ(HKEY_LOCAL_MACHINE,L"SOFTWARE\\MyCompany",L"PremierSZ");
	MessageBox(NULL, mywstring.c_str(), L"yo", MB_OK);
	return 0;
}
