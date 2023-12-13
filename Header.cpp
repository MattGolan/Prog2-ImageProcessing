#include "Header.h"

Header::Header(char idLength, char colorMapType, char dataTypeCode, short colorMapOrigin, short colorMapLength, char colorMapDepth, short xOrigin, short yOrigin, short width, short height, char bitsPerPixel, char imageDescriptor)
{
	_idLength = idLength;
	_colorMapType = colorMapType;
	_dataTypeCode = dataTypeCode;
	_colorMapOrigin = colorMapOrigin;
	_colorMapLength = colorMapLength;
	_colorMapDepth = colorMapDepth;
	_xOrigin = xOrigin;
	_yOrigin = yOrigin;
	_width = width;
	_height = height;
	_bitsPerPixel = bitsPerPixel;
	_imageDescriptor = imageDescriptor;
}