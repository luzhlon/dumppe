#pragma once
#include <memory>
#include <string>
#include <Windows.h>
static const WORD  DOS_SIGNATURE = IMAGE_DOS_SIGNATURE;
static const DWORD PE_SIGNATURE = IMAGE_NT_SIGNATURE;

class PEImage
{
public:
	std::shared_ptr<std::string> getImage();
	DWORD PEImage::getImageSize();
	std::string getSectionHeaders();
	std::string getDOSStub();
	std::string getNTHeaders();
	DWORD getSectionAlignment();
	DWORD getFileAlignment();
	std::string getSections();

	static PEImage fromMemory(ULONG_PTR imageBase);
private:
	PEImage();
	LONG getNTHeaderOffset();
	
	std::shared_ptr<std::string> m_image;
	DWORD m_imageSize;
};