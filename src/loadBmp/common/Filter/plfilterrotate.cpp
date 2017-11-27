/*
/--------------------------------------------------------------------
|
|      $Id: plfilterrotate.cpp,v 1.7 2004/06/15 10:26:13 uzadow Exp $
|
|      Copyright (c) 1996-1998 Ulrich von Zadow
|
\--------------------------------------------------------------------
*/

#include "plstdpch.h"
#include <math.h>

#include "plbitmap.h"
#include "plfilterrotate.h"
#include "plpoint.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PLFilterRotate::PLFilterRotate(AngleType a)
    : PLFilter(),
      m_Angle(a)
{}


PLFilterRotate::~PLFilterRotate()
{}


void PLFilterRotate::Apply(PLBmpBase * pBmpSource, PLBmp * pBmpDest) const
{
  // Only works for 32 bpp.
  PLASSERT (pBmpSource->GetBitsPerPixel() == 32);

  int oldWidth = pBmpSource->GetWidth();
  int oldHeight= pBmpSource->GetHeight();
  int newWidth = m_Angle == oneeighty ? oldWidth : oldHeight;
  int newHeight = m_Angle == oneeighty ? oldHeight : oldWidth;

  // Calculate the size of the new bitmap
  pBmpDest->Create (newWidth, newHeight, pBmpSource->GetBitsPerPixel(), 
                    pBmpSource->HasAlpha(), pBmpSource->IsGreyscale(), 
                    NULL, 0, pBmpSource->GetResolution());
  PLPixel32 pix;
  for (int newY = 0; newY < newHeight; ++newY)
  {
    for (int newX = 0; newX < newWidth; ++newX)
    {
      int oldX;
      int oldY;
      switch(m_Angle)
      {
        case ninety:
          oldX = newY;
          oldY = oldHeight - newX - 1;
          break;
        case oneeighty:
          oldX = oldWidth - newX - 1;
          oldY = oldHeight - newY - 1;
          break;
        case twoseventy:
          oldY = newX;
          oldX = oldWidth - newY - 1;
          break;
      }
      pix = pBmpSource->GetPixel(oldX,oldY);
      pBmpDest->SetPixel(newX,newY,pix);
    }
  }
}

/*
/--------------------------------------------------------------------
|
|      $Log: /Project/Springhead/bin/src/loadBmp/common/Filter/plfilterrotate.cpp $
 * 
 * 1     04/07/12 13:34 Hase
|      Revision 1.7  2004/06/15 10:26:13  uzadow
|      Initial nonfunctioning version of plbmpbase.
|
|      Revision 1.6  2003/11/05 15:17:26  artcom
|      Added ability to specify initial data in PLBitmap::Create()
|
|      Revision 1.5  2003/02/27 23:01:33  uzadow
|      Linux version of PLFilterRotate, nicer test output
|
|      Revision 1.4  2003/02/27 22:46:56  uzadow
|      Added plfilterrotate.
|
|      Revision 1.1  2002/02/05 09:40:54  david
|      pavel added rotate90 filter
|
\--------------------------------------------------------------------
*/
