/*
/--------------------------------------------------------------------
|
|      $Id: plbmpinfo.cpp,v 1.4 2002/11/27 21:48:45 uzadow Exp $
|
|      Copyright (c) 1996-2002 Ulrich von Zadow
|
\--------------------------------------------------------------------
*/

#include "plstdpch.h"

#include "plbmpinfo.h"

#include <stdio.h>
#ifndef WIN32
#include <strings.h>
#include <string.h>
#endif

const char szInfoFormatString[] =
    "{ Size: (%i, %i), bpp: %i, Resolution: (%i, %i), Alpha: %i, Greyscale: %i }";

PLBmpInfo::PLBmpInfo (const PLPoint& Size, int bpp, const PLPoint& Resolution,
                      bool bAlphaChannel, bool bIsGreyscale)
{
  SetBmpInfo (Size, bpp, Resolution, bAlphaChannel, bIsGreyscale);
}

PLBmpInfo::PLBmpInfo (const char * pszInfo)
{
  int Alpha;
  int IsGreyscale;
  int NumFields = sscanf (pszInfo, szInfoFormatString,
          &m_Size.x, &m_Size.y, &m_bpp, &m_Resolution.x, &m_Resolution.y,
           &Alpha, &IsGreyscale);
  m_bAlphaChannel = (Alpha != 0);
  m_bIsGreyscale = (IsGreyscale != 0);
  PLASSERT (NumFields == 7);
}

void PLBmpInfo::SetBmpInfo (const PLPoint& Size, int bpp, const PLPoint& Resolution,
                            bool bAlphaChannel, bool bIsGreyscale)
{
  m_Size = Size;
  m_bpp = bpp;
  m_Resolution = Resolution;
  m_bAlphaChannel = bAlphaChannel;
  m_bIsGreyscale = bIsGreyscale;
}

void PLBmpInfo::SetBmpInfo (const PLBmpInfo& SrcInfo)
{
  *this = SrcInfo;
}

void PLBmpInfo::AsString (char * psz, int len) const
{
  char sz[1024];
  sprintf (sz, szInfoFormatString,
           m_Size.x, m_Size.y, m_bpp, m_Resolution.x, m_Resolution.y,
           m_bAlphaChannel, m_bIsGreyscale);
  PLASSERT ((int)strlen (sz) < len);
  strcpy (psz, sz);
}

bool PLBmpInfo::operator == (const PLBmpInfo & Other) const
{
  return (m_Size == Other.GetSize() && m_bpp == Other.GetBitsPerPixel()  &&
          m_Resolution == Other.GetResolution() && m_bAlphaChannel == Other.HasAlpha() &&
          m_bIsGreyscale == Other.IsGreyscale());
}

/*
/--------------------------------------------------------------------
|
|      $Log: /Project/Springhead/bin/src/loadBmp/common/plbmpinfo.cpp $
 * 
 * 1     04/07/12 13:34 Hase
|      Revision 1.4  2002/11/27 21:48:45  uzadow
|      Added include for more portability.
|
|      Revision 1.3  2002/11/06 22:43:00  uzadow
|      Win32 compatibility
|
|      Revision 1.2  2002/11/04 22:40:13  uzadow
|      Updated for gcc 3.1
|
|      Revision 1.1  2002/08/04 20:17:57  uzadow
|      Added PLBmpInfo class, ability to extract metainformation from images without loading the whole image and proper greyscale support.
|      Major improvements in tests.
|      Update to VS .NET
|
|
\--------------------------------------------------------------------
*/

