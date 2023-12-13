#pragma once
struct Header
{
	// Design of the Header struct was taken from the project overview. Credit to instructor.
	char _idLength;
	char _colorMapType;
	char _dataTypeCode;
	short _colorMapOrigin;
	short _colorMapLength;
	char _colorMapDepth;
	short _xOrigin;
	short _yOrigin;
	short _width;
	short _height;
	char _bitsPerPixel;
	char _imageDescriptor;

	Header(char idLength, char colorMapType, char dataTypeCode, short colorMapOrigin, short colorMapLength, char colorMapDepth, short xOrigin, short yOrigin, short width, short height, char bitsPerPixel, char imageDescriptor);
};

