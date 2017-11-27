/*
/--------------------------------------------------------------------
|
|      $Id: plfilter.cpp,v 1.3 2004/06/15 10:26:13 uzadow Exp $
|
|      Copyright (c) 1996-2002 Ulrich von Zadow
|
\--------------------------------------------------------------------
*/

#include "plstdpch.h"
#include "plfilter.h"
#include "plbmpbase.h"
#include "plbitmap.h"
#include "planybmp.h"


PLFilter::PLFilter() : PLObject()
{

}

PLFilter::~PLFilter()
{

}

void PLFilter::ApplyInPlace(PLBmp * pBmp) const
{
  // Use a bitmap class that's guaranteed to work on all platforms as
  // temporary storage.
  PLAnyBmp TempBmp;  
  Apply (pBmp, &TempBmp);
  *pBmp = TempBmp;
}

void PLFilter::Apply(PLBmpBase * pBmpSource, PLBmp * pBmpDest) const
{
  *pBmpDest = *pBmpSource;
  ApplyInPlace (pBmpDest);
}

/*
/--------------------------------------------------------------------
|
|      $Log: /Project/Springhead/bin/src/loadBmp/common/Filter/plfilter.cpp $
 * 
 * 1     04/07/12 13:34 Hase
|      Revision 1.3  2004/06/15 10:26:13  uzadow
|      Initial nonfunctioning version of plbmpbase.
|
|      Revision 1.2  2002/03/31 13:36:42  uzadow
|      Updated copyright.
|
|      Revision 1.1  2001/09/16 19:03:23  uzadow
|      Added global name prefix PL, changed most filenames.
|
|      Revision 1.9  2001/02/04 14:31:52  uzadow
|      Member initialization list cleanup (Erik Hoffmann).
|
|      Revision 1.8  2001/01/15 15:05:31  uzadow
|      Added PLBmp::ApplyFilter() and PLBmp::CreateFilteredCopy()
|
|      Revision 1.7  2000/01/16 20:43:15  anonymous
|      Removed MFC dependencies
|
|      Revision 1.6  1999/12/14 12:29:47  Ulrich von Zadow
|      no message
|
|      Revision 1.5  1999/12/10 01:27:27  Ulrich von Zadow
|      Added assignment operator and copy constructor to
|      bitmap classes.
|
|      Revision 1.4  1999/12/08 16:31:40  Ulrich von Zadow
|      Unix compatibility
|
|      Revision 1.3  1999/11/27 18:45:48  Ulrich von Zadow
|      Added/Updated doc comments.
|
|      Revision 1.2  1999/10/21 18:48:03  Ulrich von Zadow
|      no message
|
|      Revision 1.1  1999/10/21 16:05:17  Ulrich von Zadow
|      Moved filters to separate directory. Added Crop, Grayscale and
|      GetAlpha filters.
|
|      Revision 1.1  1999/10/19 21:29:44  Ulrich von Zadow
|      Added filters.
|
|
\--------------------------------------------------------------------
*/
