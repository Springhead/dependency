/*
/--------------------------------------------------------------------
|
|      $Id: plsgidec.h,v 1.1 2003/06/01 21:12:06 uzadow Exp $
|
|      Copyright (c) 1996-2002 Ulrich von Zadow
|
\--------------------------------------------------------------------
*/

#ifndef INCL_PLSGIDEC
#define INCL_PLSGIDEC

#ifndef INCL_PLPICDEC
#include "plpicdec.h"
#endif

//! SGI rgb file decoder. 
class PLSGIDecoder : public PLPicDecoder
{
  typedef struct {
    PLWORD  Magic;
    PLBYTE  Storage;
    PLBYTE  bpc;              // bytes per color: 1 = bytes, 2 = shorts
    PLWORD  Dimension;        // 1 = single row, 2 = B/W, 3 = RGB
    PLWORD  XSize;            // width in pixels
    PLWORD  YSize;            // height in pixels
    PLWORD  ZSize;            // # of channels; GRAY=1, RGB=3, RGBA=4
    PLULONG PixMin, PixMax;   // min/max pixel values
    PLULONG Dummy1;
    char    Name[80];
    PLULONG Colormap;
  } SGIHeader;

public:
  //! Creates a decoder
  PLSGIDecoder
    ();

  //! Destroys a decoder
  virtual ~PLSGIDecoder
    ();

   //!
  virtual void Open (PLDataSource * pDataSrc);

  //! Fills the bitmap with the image. 
  virtual void GetImage (PLBmp & Bmp);

private:
  void readHeader
    ( SGIHeader * pHeader,
      PLDataSource * pDataSrc
    );

  SGIHeader m_Header;
};

#endif
/*
/--------------------------------------------------------------------
|
|      $Log: /Project/Springhead/bin/src/loadBmp/common/plsgidec.h $
 * 
 * 1     04/07/12 13:34 Hase
|      Revision 1.1  2003/06/01 21:12:06  uzadow
|      Added sgi rgb file format.
|
|
|
\--------------------------------------------------------------------
*/
